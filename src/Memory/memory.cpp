#include "memory.h"

std::array<uint8_t, 8>& memory::getLine(uint16_t address) {
    return this->cpu_memory.at(address / 8);
}

uint16_t memory::readWord(uint16_t address) {
    if (this->memRead.load()) {
        return -1;
    }
    uint8_t low = readByte(address);
    uint8_t high = readByte(address + 1);
    return (static_cast<uint16_t> (high) << 8) | low;
}

uint8_t memory::readByte(uint16_t address) {
    if (!this->memRead.load()) {
        return -1;
    }
    return cpu_memory.at(address / 8).at(address % 8);
}

void memory::loadWord(uint16_t address, uint16_t value) {
    if (!this->memWrite.load()) {
        return ;
    }
    uint8_t high,low;
    high = value>>8 & 0xFF;
    low =  value & 0xff;
    loadByte(address, low);
    loadByte(address + 1, high);
}

void memory::loadByte(uint16_t address, uint8_t value) {
    if (!this->memWrite.load()) {
        return ;
    }
    this->cpu_memory.at(address / 8).at(address % 8) = value;
}
