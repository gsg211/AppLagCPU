//
// Created by tudor on 5/9/26.
//

#ifndef AMD_APPLAG_IMODULE_H
#define AMD_APPLAG_IMODULE_H

#include <thread>

class IModule {
public:
    virtual void Start() = 0;

private:
    std::jthread m_moduleThread;
};

#endif //AMD_APPLAG_IMODULE_H
