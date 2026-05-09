//
// Created by tudor on 5/9/26.
//
#include "Decoder.h"
#include <iostream>
#include <mutex>
#include <utility>

Decoder::Decoder(const TimingPtr &timing, const StringThreadSafeQueuePtr& instructionQueue, const MessageThreadSafeQueuePtr& messageQueue) {
    if (timing == nullptr) {
        std::cerr<<"Can't load null timing module\n";
    }
    m_timing = timing;
    m_instructionQueue = instructionQueue;
    m_decodeQueue = messageQueue;
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