//
// Created by sabin on 5/9/26.
//
#include "RegisterBank.h"

void RegisterBank::setRegisterValue(uint16_t register_id, uint16_t value) {
    this->registerBank[register_id] = value;
}

void RegisterBank::copyRegisterValues(uint16_t dest, uint16_t src) {
    this->registerBank[dest] = this->registerBank[src];
}

void RegisterBank::clearFlagRegister(uint16_t registerId) {
    this->flagRegister=0;
}

void RegisterBank::setFlagRegisterFlag(uint16_t flag_id, bool value) {
    this->flagRegister |= value << flag_id;
}

bool RegisterBank::getFlagRegister(uint16_t flag_id) const {
    return this->flagRegister & (1<<flag_id);
}

uint16_t RegisterBank::getRegisterValue(uint16_t register_id) const {
    return this->registerBank[register_id];
}

void RegisterBank::setStackPointer(uint16_t value) {
    this->stackPointer = value;
}

uint16_t RegisterBank::getStackPointer() {
    return this->stackPointer;
}

void RegisterBank::setInstructionPointer(uint16_t value) {
    this->instructionPointer = value;
}

uint16_t RegisterBank::getInstructionPointer() const {
    return this->instructionPointer;
}

void RegisterBank::incrementInstructionPointer(uint16_t amount) {
    this->instructionPointer += amount;
}

void RegisterBank::incrementStackPointer(uint16_t amount) {
    this->stackPointer += amount;
}
