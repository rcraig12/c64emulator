#pragma once

#ifndef CLOCK_H
#define CLOCK_H

#include "Common.h"
#include "VICII.h"

class Clock
{
private:
    VICII *vic;
    unsigned int tick;
    
public:
    Clock();
    ~Clock();
    void Tick();
    unsigned int GetTick();
};

#endif

