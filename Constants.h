//
// Created by codrin on 5/9/26.
//

#ifndef AMD_APPLAG_CONSTANTS_H
#define AMD_APPLAG_CONSTANTS_H
#include <cstdint>
constexpr const uint16_t ADDR_SIZE_BYTES = 2;
constexpr const uint16_t DATA_SIZE_BYTES = 2;
constexpr const uint16_t WORD_SIZE_BYTES = 2;
constexpr const uint16_t CLK_PERIOD_ms = 1000;

constexpr const char* const MSG_WRITE_MEM = "WRITE_MEM";
constexpr const char* const MSG_READ_MEM  = "READ_MEM";

constexpr const char* const MSG_ALU_SRC_A = "ALU_SRC_A";
constexpr const char* const MSG_ALU_SRC_B = "ALU_SRC_B";

constexpr const char* const DATA_TAG_IMM       = "DATA_TAG_IMM";
constexpr const char* const DATA_TAG_REG       = "DATA_TAG_REG";
constexpr const char* const DATA_TAG_NULL      = "DATA_TAG_NULL";
constexpr const char* const DATA_TAG_MEM       = "DATA_TAG_MEM";
constexpr const char* const DATA_TAG_ADDR      = "DATA_TAG_ADDR";
constexpr const char* const DATA_TAG_REG1_ADDR = "DATA_TAG_REG1_ADDR";
constexpr const char* const DATA_TAG_REG2_ADDR = "DATA_TAG_REG2_ADDR";

constexpr uint8_t ALU_SRC_NULL = 0;
constexpr uint8_t ALU_SRC_IMM = 1;
constexpr uint8_t ALU_SRC_REG = 2;
constexpr uint8_t ALU_SRC_MEM = 3;
constexpr uint8_t ALU_SRC_ADDR = 4;

constexpr const char* const MSG_WRITE_REG = "WRITE_REG";
constexpr const char* const MSG_READ_REG  = "READ_REG";

constexpr const char* const MSG_IMM_PARAM = "IMM_PARAM";

constexpr int ENC_NULL  = 1;
constexpr int ENC_IMM   = 2;
constexpr int ENC_ADDRESS  = 3;
constexpr int ENC_SP_REGISTER  = 4;
constexpr int ENC_STACK_BASE = 5;
constexpr int ENC_STACK_SIZE = 6;
constexpr int ENC_R0  = 8;
constexpr int ENC_R7  = 15;
constexpr int ENC_ADDR_R0  = 24;
constexpr int ENC_ADDR_R7  = 31;

#endif //AMD_APPLAG_CONSTANTS_H