#include "DataPath.h"

DataPath::DataPath() 
    : m_timing(std::make_shared<Timing>()),
      m_instructionQueue(std::make_shared<ThreadSafeQueue<std::string>>()),
      m_decodeToExecuteQueue(std::make_shared<ThreadSafeQueue<Message>>()),
      m_dataQueue(std::make_shared<ThreadSafeQueue<DataPacket>>()),
      decoder(m_timing, m_instructionQueue, m_decodeToExecuteQueue, m_dataQueue),
      executor(m_timing, m_instructionQueue, m_decodeToExecuteQueue)
{
}

void DataPath::start() {
    if (m_timing) {
        m_timing->start();
    }

    // Ambele module moștenesc IModule, deci au Start()
    decoder.Start();
    executor.Start();
}

void DataPath::stop() {
    decoder.Stop();
    executor.Stop();

    if (m_timing) {
        m_timing->stop();
    }
}

void DataPath::loadInstruction(const std::string& instruction) {
    if (m_instructionQueue) {
        m_instructionQueue->push(instruction);
    }
}