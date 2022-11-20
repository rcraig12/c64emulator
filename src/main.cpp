#include "Common.h"

#include "Memory.h"
#include "VICII.h"
#include "CPU.h"
#include "SID.h"
#include "Clock.h"
#include "Emulator.h"

int main(){

    Memory memory;    
    VICII vic;
    CPU cpu;
    SID sid;
    Clock clock;
    Emulator emulator( clock, memory, vic, cpu, sid );

    return 0;

}
