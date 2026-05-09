//
// Created by sabin on 5/9/26.
//

#include "Alu.h"

uint16_t Alu::getResult() const {
    return this->result;
}

void Alu::setSourceA(uint16_t value) {
    this->sourceA = value;
}

void Alu::setSourceB(uint16_t value) {
    this->sourceB = value;
}

void Alu::add() {
    result=sourceA+sourceB;
}

void Alu::sub() {
    result=sourceA-sourceB;

}

void Alu::mul() {
    result=sourceA*sourceB;

}

void Alu::div() {
    result=sourceA/sourceB;

}

void Alu::cmp() {
    result = sourceA > sourceB ? 1 : -1;
    result = sourceA == sourceB ? 0 :result;
}
