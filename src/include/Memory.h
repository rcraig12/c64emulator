#pragma once

#ifndef MEMORY_H
#define MEMORY_H

#include "Common.h"

class Memory
{
private:
    Byte* memory;

public:
    Memory();
    ~Memory();
    
    void SetMaxMemory( const Word memorysize );
    const Byte ReadMemory( const unsigned short address);
    void WriteMemory( const Byte byte, const Word address );
    Byte* GetMemory();
    void LoadROM( const char* filename , const Word baseaddress);
    void DisplayMemory();
};

#endif