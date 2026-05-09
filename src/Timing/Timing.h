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
    std::condition_variable& TimingConditionVariable() { return m_timingConditionVariable; }
    std::mutex& TimingMutex() { return m_timingMutex; }
    bool IsActive() { return m_tick.load(); }

private:
    void run();

private:
    std::mutex m_timingMutex;
    std::condition_variable m_timingConditionVariable;
    std::atomic_bool m_tick = false;

    std::jthread m_timingThread;
    std::atomic_bool m_running = true;
};
typedef std::shared_ptr<Timing> TimingPtr;

#endif //AMD_APPLAG_TIMING_H