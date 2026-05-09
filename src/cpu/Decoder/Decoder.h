//
// Created by tudor on 5/9/26.
//

#ifndef AMD_APPLAG_DECODER_H
#define AMD_APPLAG_DECODER_H

#include <thread>
#include "IModule.h"
#include "Timing.h"
#include <queue>
#include "Utils.h"
#include "ThreadSafeQueue/ThreadSafeQueue.h"

class Decoder : public IModule
{
public:
    Decoder(const TimingPtr& timing, const StringThreadSafeQueuePtr& instructionQueue, const MessageThreadSafeQueuePtr& messageQueue, const DataThreadSafeQueuePtr& dataQueue);
    Decoder(const Decoder&) = delete;
    Decoder& operator=(const Decoder&) = delete;
    Decoder(Decoder&&) = delete;
    Decoder& operator=(Decoder&&) = delete;
    ~Decoder() = default;

public:
    void Start()override;
    void Stop()override;

private:
    void DecodeLoop();

public:
    StringThreadSafeQueuePtr m_instructionQueue;
    MessageThreadSafeQueuePtr m_decodeQueue;
    DataThreadSafeQueuePtr m_dataQueue;

private:
    std::mutex m_decoderMutex;
    std::mutex m_decoderMessagesMutex;

    TimingPtr m_timing;
};

#endif //AMD_APPLAG_DECODER_H