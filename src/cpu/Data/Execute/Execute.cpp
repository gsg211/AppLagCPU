//
// Created by sabin on 5/9/26.
//

#include "Execute.h"

#include <iostream>

Execute::Execute(const TimingPtr &timing, const StringThreadSafeQueuePtr &instructionQueue,
                 const MessageThreadSafeQueuePtr &messageQueue) {
    if (timing == nullptr) {
        std::cerr<<"Can't load null timing module\n";
    }
    m_timing = timing;
}

void Execute::ExecuteLoop() {
    std::cout<<"Started execute loop!\n";
    auto decodingWorkLbd = [this] {
        std::unique_lock<std::mutex> lock(m_executeMessagesMutex);


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

void Execute::Start() {
    if (m_timing == nullptr) {
        std::cerr<<"Can't start decoding loop\n";
    }
    m_moduleThread = std::jthread(&Execute::ExecuteLoop, this);
}

void Execute::Stop() {
    bool notRunning = false;
    m_isRunning.compare_exchange_strong(notRunning, m_isRunning);
}

void Execute::setAluA(uint16_t value) {
    this->alu.setSourceA(value);
}

void Execute::setAluB(uint16_t value) {
    this->alu.setSourceB(value);
}

uint16_t Execute::getAluResult() const {
    return this->alu.getResult();
}
