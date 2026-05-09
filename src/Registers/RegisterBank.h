//
// Created by sabin on 5/9/26.
//

#ifndef AMD_APPLAG_REGISTERBANK_H
#define AMD_APPLAG_REGISTERBANK_H
#include <array>
#include <cstdint>

class RegisterBank {
    private:
        std::array<uint16_t, 8> registerBank{};
        uint16_t instructionPointer{};
        uint16_t stackPointer{};
        uint16_t flagRegister{};
    public:
        void setRegisterValue(uint16_t register_id, uint16_t value);
        uint16_t getRegisterValue(uint16_t register_id) const;

        void copyRegisterValues(uint16_t dest, uint16_t src);

        void setStackPointer(uint16_t value);
        uint16_t getStackPointer();

        void setInstructionPointer(uint16_t value);
        uint16_t getInstructionPointer() const;

        void incrementInstructionPointer(uint16_t amount);
        void incrementStackPointer(uint16_t amount);

        void clearFlagRegister(uint16_t registerId);

        void setFlagRegisterFlag(uint16_t flag_id, bool value);
        bool getFlagRegister(uint16_t flag_id) const;

};

#endif //AMD_APPLAG_REGISTERBANK_H
