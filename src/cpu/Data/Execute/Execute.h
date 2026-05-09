//
// Created by sabin on 5/9/26.
//

#ifndef AMD_APPLAG_EXECUTE_H
#define AMD_APPLAG_EXECUTE_H
#include "Alu.h"
#include "IModule.h"
#include "Timing.h"
#include "ThreadSafeQueue/ThreadSafeQueue.h"
#include "Utils.h"

class Execute : public IModule {
private:
    Alu alu{};
    TimingPtr m_timing;
    void ExecuteLoop();
    std::mutex m_executeMutex;
    std::mutex m_executeMessagesMutex;

public:
    StringThreadSafeQueuePtr m_instructionQueue;
    MessageThreadSafeQueuePtr m_decodeQueue;
public:
    Execute(const TimingPtr &timing, const StringThreadSafeQueuePtr& instructionQueue, const MessageThreadSafeQueuePtr& messageQueue);
    void Start() override;
    void Stop() override;

    void setAluA(uint16_t value);
    void setAluB(uint16_t value);
    uint16_t getAluResult() const;
};


#endif //AMD_APPLAG_EXECUTE_H
