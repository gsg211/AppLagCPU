//
// Created by sabin on 5/9/26.
//

#ifndef AMD_APPLAG_DATAPATH_H
#define AMD_APPLAG_DATAPATH_H

#include "Decoder.h"
#include "Execute.h"
#include "Memory.h"
#include "RegisterBank.h"
#include "Timing.h"
#include "ThreadSafeQueue/ThreadSafeQueue.h"

class DataPath {
private:
    // Sincronizare și comunicare
    TimingPtr m_timing;
    StringThreadSafeQueuePtr m_instructionQueue;
    MessageThreadSafeQueuePtr m_decodeToExecuteQueue;
    DataThreadSafeQueuePtr m_dataQueue;

    // Componente Hardware
    RegisterBank registers;
    Memory memory;

    // Unități Funcționale
    Decoder decoder;
    Execute executor;

public:
    DataPath();
    ~DataPath() = default;

    void start();
    void stop();
    void loadInstruction(const std::string& instruction);
};


#endif //AMD_APPLAG_DATAPATH_H
