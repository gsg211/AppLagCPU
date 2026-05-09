//
// Created by tudor on 5/9/26.
//

#ifndef AMD_APPLAG_DECODER_H
#define AMD_APPLAG_DECODER_H

#include <thread>
#incldue "Timing.h"
#include "IModule.h"

class Decoder : public IModule
{
public:
    Decoder(const TimingPtr& timing);
    void Start()override;

private:
    TimingPtr m_timing;
};

#endif //AMD_APPLAG_DECODER_H
