#pragma once

#ifndef SID_H
#define SID_H

#include "Common.h"
#include "Clock.h"
#include "Memory.h"

class SID
{
private:
    Memory memory;
public:
    SID();
    ~SID();
    void Init( Memory memory );
};

#endif