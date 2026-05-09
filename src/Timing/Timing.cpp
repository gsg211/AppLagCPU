//
// Created by tudor on 5/9/26.
//
#include "Timing.h"

constexpr const uint16_t CLOCK_DELAY_MSECS = 5;

Timing::Timing() {}

void Timing::start() {
    m_timingThread.
}

void Timing::stop() {
    bool newIsRunning = false;
    m_running.compare_exchange_strong(newIsRunning, m_running);
}

void Timing::run() {
    while (m_running.load()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(CLOCK_DELAY_MSECS));
        m_timingConditionVariable.notify_all();
    }
}
