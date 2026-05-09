//
// Created by codrin on 5/9/26.
//

#ifndef AMD_APPLAG_CODEMEM_H
#define AMD_APPLAG_CODEMEM_H
#include <array>
#include <cstdint>
#include <map>
#include <map>
#include <vector>
#include <string>
#include "../../Constants.h"


class CodeMem {
    private: std::map<uint16_t, std::string> codeMem;
    public: std::string readInsturction(uint16_t address);
    public: CodeMem(std::string filename);
};


#endif //AMD_APPLAG_CODEMEM_H
