//
// Created by tudor on 5/9/26.
//

#ifndef AMD_APPLAG_TIMING_H
#define AMD_APPLAG_TIMING_H

#include <condition_variable>
#include <thread>

class Timing {
public:
    Timing();
    Timing(const Timing&) = delete;
    Timing(const Timing&&) = delete;
    Timing& operator=(const Timing&) = delete;
    Timing& operator=(const Timing&&) = delete;
    ~Timing() = default;

public:
    void start();
    void stop();

private:
    void run();

private:
    std::jthread m_timingThread;
    std::condition_variable m_timingConditionVariable;
    std::atomic_bool m_running = true;
};

#endif //AMD_APPLAG_TIMING_H
