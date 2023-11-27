// Memory.h
#pragma once

#ifndef MEMORY_H
#define MEMORY_H

#include "Common.h"

class Memory {
private:
    Byte* memory;
    Word memorySize;

public:
    Memory();
    ~Memory();

    void SetMaxMemory(const Word memorysize);
    const Byte ReadMemory(const Word address);
    void WriteMemory(const Byte byte, const Word address);
    Byte* GetMemory();
    void LoadROM(const char* filename, const Word baseaddress);
    void DisplayMemory();

    // New methods to access specific memory regions
    Byte* GetScreenMemory();
    Byte* GetColorMemory();
    const Byte* GetCharacterROM();
};

#endif // MEMORY_H
