#pragma once

#ifndef EMULATOR_H
#define EMULATOR_H

#include "Common.h"

#include "Video.h"
#include "Memory.h"
#include "VICII.h"
#include "CPU.h"
#include "SID.h"
#include "Clock.h"

class Emulator
{    
private:
    
    bool emulatorRunning;
    unsigned int memory_size;

            //todo trigger vic run cycle

public:
    Memory *memory;
    Clock *clock;
    VICII *vic;
    CPU *cpu;
    SID *sid;
    Video *video;
    Emulator( Clock &clock, Memory &memory, VICII &vic, CPU &cpu, SID &sid, Video &video );
    ~Emulator();
    void StartupTitle();
    void DisplayLicense();
    void Wait ( unsigned int milliseconds );
    void Start();
    void Run();
    void Stop();
    
};

#endif
