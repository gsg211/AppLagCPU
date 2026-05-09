//
// Created by codrin on 5/9/26.
//

#include "CodeMem.h"
#include <fstream>
std::string CodeMem::readInsturction(uint16_t address) {
    return   codeMem[address];
}


CodeMem::CodeMem(std::string filename) {
    std::ifstream file(filename);
    uint16_t currentAddress = 0;
    std::string line;
    while (file.good()) {
        file >> line;
        if (line[0] == '#') {
            currentAddress = std::stoul(line.substr(1), nullptr, 16);
        } else {
            codeMem[currentAddress] = line;
            // each 16-bit word = 4 hex chars
            currentAddress += line.size() / 4;
        }
    }
}