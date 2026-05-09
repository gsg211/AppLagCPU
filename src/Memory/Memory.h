//
// Created by sabin on 5/9/26.
//

#ifndef AMD_APPLAG_MEMORY_H
#define AMD_APPLAG_MEMORY_H
#include <array>
#include <atomic>
#include <cstdint>
#include <locale>

class Memory {
private:
    std::array<std::array<uint8_t, 8>, 8192> cpu_memory{};
public:
    std::atomic_bool memRead;
    std::atomic_bool memWrite;

    std::array<uint8_t,8>& getLine(uint16_t address);
    uint16_t readWord(uint16_t address);
    uint8_t readByte(uint16_t address);
    void loadWord(uint16_t address, uint16_t value);
    void loadByte(uint16_t address, uint8_t value);
};


#endif //AMD_APPLAG_MEMORY_H
