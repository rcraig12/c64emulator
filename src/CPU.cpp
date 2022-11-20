#include "CPU.h"

CPU::CPU()
{
}

CPU::~CPU()
{
}

// CPU Opcode Section

void CPU::INS_BRK_IMPL()
{
    printf("BRK Called!\n");
}

void CPU::INS_ORA_X_IND()
{
    printf("ORA X, indirect Called!\n");
}

void CPU::INS_JAM_0X02()
{
    printf("BRK Called!\n");
}

void CPU::INS_SLO_X_IND()
{
    printf("BRK Called!\n");
}

void CPU::INS_NOP_ZPG()
{
    printf("BRK Called!\n");
}

void CPU::INS_ORA_ZPG()
{
    printf("BRK Called!\n");
}

void CPU::INS_ASL_ZPG()
{
    printf("BRK Called!\n");
}

void CPU::INS_SLO_ZPG ()
{
    printf("BRK Called!\n");
}

void CPU::INS_PHP_IMPL()
{
    printf("BRK Called!\n");
}

void CPU::INS_ORA_IMM()
{
    printf("BRK Called!\n");
}

void CPU::INS_ASL_IMP()
{
    printf("BRK Called!\n");
}

void CPU::INS_ANC_IMM_0x0b()
{
    printf("BRK Called!\n");
}

void CPU::INS_NOP_ABS()
{
    printf("BRK Called!\n");
}

void CPU::INS_ORA_ABS()
{
    printf("BRK Called!\n");
}

void CPU::INS_ASL_ABS()
{
    printf("BRK Called!\n");
}

void CPU::INS_SLO_ABS()
{
    printf("BRK Called!\n");
}

void CPU::INS_BPL_REL()
{
    printf("BRK Called!\n");
}

void CPU::INS_ORA_IND_Y()
{
    printf("BRK Called!\n");
}

void CPU::INS_JAM_0x12()
{
    printf("BRK Called!\n");
}

void CPU::INS_SLO_IND_Y()
{
    printf("BRK Called!\n");
}

void CPU::INS_NOP_ZPG_X_0x14()
{
    printf("BRK Called!\n");
}

void CPU::INS_ORA_ZPG_X()
{
    printf("BRK Called!\n");
}

void CPU::INS_ASL_ZPG_X()
{
    printf("BRK Called!\n");
}

void CPU::INS_SLO_ZPG_X()
{
    printf("BRK Called!\n");
}

void CPU::INS_CLC_IMPL()
{
    printf("BRK Called!\n");
}

void CPU::INS_ORA_ABS_Y()
{
    printf("BRK Called!\n");
}

void CPU::INS_NOP_IMP_0x1a()
{
    printf("BRK Called!\n");
}

void CPU::INS_SLO_ABS_Y()
{
    printf("BRK Called!\n");
}

void CPU::INS_NOP_ABS_X_0x1c()
{
    printf("BRK Called!\n");
}

void CPU::INS_ORA_ABS_X()
{
    printf("BRK Called!\n");
}

void CPU::INS_ASL_ABS_X()
{
    printf("BRK Called!\n");
}

void CPU::INS_SLO_ABS_X()
{
    printf("BRK Called!\n");
}

void CPU::INS_JSR_ABS()
{
    printf("JSR Called!\n");
}

















void CPU::Init( Memory memory )
{
    this->memory = memory;
}

void CPU::Reset()
{
    this->PC = RESET_VECTOR;
    this->SP = 0xff;
    this->C = this->Z = this->I = this->D = this->B = this->V = this->N = 0;
    this->A = this->X = this->Y = 0;
    //memory.Initialise();
}

void CPU::DisplayState()
{

    printf("A  X  Y  NV-BDIZC SP: PC:\n");
    printf("%02x %02x %02x %u%u-%u%u%u%u%u %02x  %04x\n", this->A, this->X, this->Y, this->N, this->V, this->B, this->D, this->I, this->Z, this->C, this->SP, this->PC );

}

void CPU::RunTestOpcode( Byte opcode ){
    (*opcode_table[opcode])();
}