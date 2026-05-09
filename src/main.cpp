#include <iostream>
#include "Timing.h"
#include <mutex>

int main() {
    auto timingTest = Timing();
    timingTest.start();

    std::condition_variable& cv = timingTest.TimingConditionVariable();
    std::mutex& mutex = timingTest.TimingMutex();

    while (true) {
        {
            std::unique_lock lk(mutex);
            cv.wait(lk, [&timingTest]{ std::cout<<"hi\n"; return timingTest.IsActive();});
        }
    }

    return 0;
}
