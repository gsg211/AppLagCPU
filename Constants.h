//
// Created by codrin on 5/9/26.
//

#ifndef AMD_APPLAG_CONSTANTS_H
#define AMD_APPLAG_CONSTANTS_H
#include <cstdint>
constexpr const uint16_t ADDR_SIZE_BYTES = 2;
constexpr const uint16_t DATA_SIZE_BYTES = 2;
constexpr const uint16_t WORD_SIZE_BYTES = 2;
constexpr const uint16_t CLK_PERIOD_ms = 5;

constexpr const char* const MSG_WRITE_MEM = "WRITE_MEM";
constexpr const char* const MSG_READ_MEM  = "READ_MEM";

constexpr const char* const MSG_WRITE_REG = "WRITE_REG";
constexpr const char* const MSG_READ_REG  = "READ_REG";

constexpr const char* const MSG_IMM_PARAM = "IMM_PARAM";




#endif //AMD_APPLAG_CONSTANTS_H
