//
// Created by tudor on 5/9/26.
//
#include "Decoder.h"
#include <iostream>
#include <mutex>
#include <cstdint>
#include <string>
#include <utility>

#include "../../../Constants.h"

Decoder::Decoder(const TimingPtr &timing, const StringThreadSafeQueuePtr& instructionQueue, const MessageThreadSafeQueuePtr& messageQueue, const DataThreadSafeQueuePtr& dataQueue)
    : m_instructionQueue(instructionQueue)
    , m_decodeQueue(messageQueue)
    , m_dataQueue(dataQueue)
{
    if (timing == nullptr) {
        std::cerr<<"Can't load null timing module\n";
    }
    m_timing = timing;
    if (m_decodeQueue == nullptr || m_dataQueue == nullptr || m_instructionQueue == nullptr) {
        std::cerr<<"Can't use nullptr queues\n";
        exit(-1);
    }
}

void Decoder::Start() {
    if (m_timing == nullptr) {
        std::cerr<<"Can't start decoding loop\n";
    }
    m_moduleThread = std::jthread(&Decoder::DecodeLoop, this);
}

void Decoder::DecodeLoop() {
    std::cout<<"Started decode loop!\n";
    auto decodingWorkLbd = [this] {
        std::unique_lock<std::mutex> lock(m_decoderMutex);

        auto instructionOpt = m_instructionQueue->pop();
        if (instructionOpt.has_value()) {
            std::string instruction = instructionOpt.value();
            std::string headerStr = instruction.substr(instruction.length() - 2, 2);
            auto headerBytes = static_cast<uint16_t>(std::stoul(headerStr, nullptr, 16));

            uint8_t opcode = (headerBytes >> 10) & 0x3F; // [15:10]
            uint8_t src1   = (headerBytes >> 5)  & 0x1F; // bits [9:5]
            uint8_t src2   =  headerBytes        & 0x1F; // bits [4:0]
            uint16_t param1 = 0;
            uint16_t param2 = 0;

            std::string paramStr;
            if (instruction.length() == 4) {
                paramStr = instruction.substr(instruction.length() - 4, 2);

            }
            if (instruction.length() == 6) {
                paramStr = instruction.substr(instruction.length() - 6, 2);
            }

            bool readReg  = false;
            bool writeReg = false;

            bool readMem  = false;
            bool writeMem = false;

            switch (src1) {
                case ENC_NULL: {
                    m_decodeQueue->push({MSG_ALU_SRC_A, ALU_SRC_NULL});
                }
                    break;
                case ENC_IMM: {
                    m_decodeQueue->push({MSG_ALU_SRC_A, ALU_SRC_IMM});
                    m_dataQueue->push({DATA_TAG_IMM, param1} );
                }
                    break;
                case ENC_ADDRESS: {
                    m_decodeQueue->push({MSG_ALU_SRC_B, ALU_SRC_ADDR});
                    m_dataQueue->push({DATA_TAG_ADDR, param1} );
                    readMem = true;
                }
                    break;
                default: {
                    if (src1 >= ENC_R0 && src1 < ENC_ADDR_R0) {
                        uint8_t currentRegister = src1 - ENC_R0;
                        readReg = true;
                        m_dataQueue->push({DATA_TAG_REG1_ADDR, currentRegister} );
                    }
                    else if (src1 >= ENC_ADDR_R0 && src2 <= ENC_ADDR_R7) {
                        uint8_t currentAddrRegister = src1 - ENC_ADDR_R0;
                        readReg = true;
                        writeMem = true;
                        m_dataQueue->push({DATA_TAG_REG1_ADDR, currentAddrRegister} );
                    }
                }
                    break;
            }

            switch (src2) {
                case ENC_NULL: {
                    m_decodeQueue->push({MSG_ALU_SRC_B, ALU_SRC_NULL});
                }
                    break;
                case ENC_IMM: {
                    m_decodeQueue->push({MSG_ALU_SRC_B, ALU_SRC_IMM});
                    m_dataQueue->push({DATA_TAG_IMM, param2} );
                }
                    break;
                case ENC_ADDRESS: {
                    m_decodeQueue->push({MSG_ALU_SRC_B, ALU_SRC_ADDR});
                    m_dataQueue->push({DATA_TAG_ADDR, param2} );
                    readMem = true;
                }
                    break;
                default: {
                    if (src2 >= ENC_R0 && src1 < ENC_ADDR_R0) {
                        uint16_t currentRegister = src1 - ENC_R0;
                        writeReg = true;
                        m_dataQueue->push({DATA_TAG_REG2_ADDR, currentRegister} );
                    }
                    else if (src2 >= ENC_ADDR_R0 && src2 <= ENC_ADDR_R7) {
                        uint16_t currentAddrRegister = src1 - ENC_ADDR_R0;
                        readReg = true;
                        writeMem = true;
                        m_dataQueue->push({DATA_TAG_REG2_ADDR, currentAddrRegister} );
                    }
                }
                    break;
            }

            m_decodeQueue->push({MSG_READ_MEM, static_cast<uint8_t>(readMem)});
            m_decodeQueue->push({MSG_WRITE_MEM, static_cast<uint8_t>(writeMem)});
            m_decodeQueue->push({MSG_READ_REG, static_cast<uint8_t>(readReg)});
            m_decodeQueue->push({MSG_WRITE_REG, static_cast<uint8_t>(writeReg)});

            m_dataQueue->push({DATA_TAG_NULL, 0} );
        }

        return m_timing->IsActive();
    };

    while (m_isRunning.load()) {

        while (true) {
            {
                if (m_timing == nullptr) {
                    std::cerr<<"Timer died. stopping loop\n";
                    break;
                }

                std::unique_lock lock(m_timing->TimingMutex());
                m_timing->TimingConditionVariable().wait(lock, decodingWorkLbd);
            }
        }
    }
}

void Decoder::Stop() {
    bool notRunning = false;
    m_isRunning.compare_exchange_strong(notRunning, m_isRunning);
}