//
// Created by sabin on 5/9/26.
//

#ifndef AMD_APPLAG_EXECUTE_H
#define AMD_APPLAG_EXECUTE_H
#include "Alu.h"


class Execute {
    private:
        Alu alu;
    public:
        uint16_t setAluA(uint16_t value);
        uint16_t setAluB(uint16_t value);
        uint16_t getAluResult() const;

};



#endif //AMD_APPLAG_EXECUTE_H
