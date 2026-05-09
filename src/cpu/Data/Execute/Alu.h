//
// Created by sabin on 5/9/26.
//

#ifndef AMD_APPLAG_ALU_H
#define AMD_APPLAG_ALU_H
#include <cstdint>


class Alu {
private:
    uint16_t sourceA;
    uint16_t sourceB;
    uint16_t result;
public:
    uint16_t getResult() const;
    void setSourceA(uint16_t value);
    void setSourceB(uint16_t value);

    void add();
    void sub();
    void mul();
    void div();
    void cmp();
};
#endif //AMD_APPLAG_ALU_H
