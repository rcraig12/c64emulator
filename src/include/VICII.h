#pragma once

#ifndef VICII_H
#define VICII_H

#include "Common.h"

class Emulator;
class Memory;
class Clock;

typedef unsigned short WORD;
typedef unsigned char BYTE;



class VICII
{
private:
    Emulator *emulator;
    Memory *memory;
    Clock *clock;
    unsigned int tick;

public:
    VICII();
    ~VICII();
    void Init( Emulator *emulator, Clock *clock, Memory *memory );

    // Events
    void On_Clock_Event( unsigned int tick );

};

#endif
