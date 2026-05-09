//
// Created by tudor on 5/9/26.
//

#ifndef AMD_APPLAG_IMODULE_H
#define AMD_APPLAG_IMODULE_H

#include <thread>
#include <atomic>

class IModule {
public:
    virtual void Start() = 0;
    virtual void Stop() = 0;

protected:
    std::jthread m_moduleThread;
    std::atomic_bool m_isRunning = true;
};

#endif //AMD_APPLAG_IMODULE_H
