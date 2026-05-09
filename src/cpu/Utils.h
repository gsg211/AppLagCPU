//
// Created by tudor on 5/9/26.
//

#ifndef AMD_APPLAG_UTILS_H
#define AMD_APPLAG_UTILS_H

#include <string>

struct Message {
    std::string m_messageType;
    uint8_t m_msgData;
};

struct DataPacket {
    std::string m_dataTag;
    uint16_t m_dataPacket;
};

#endif //AMD_APPLAG_UTILS_H