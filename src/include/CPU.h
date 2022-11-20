#pragma once

#ifndef CPU_H
#define CPU_H

#include "Common.h"
#include "Clock.h"
#include "Memory.h"

class CPU
{
private:
    Memory memory;

    // Opcode static Functions
    
    static void INS_BRK_IMPL_0x00();         // = 0x00,
    static void INS_ORA_X_IND_0x01();        // = 0x01,
    static void INS_JAM_0X02_0x02();         // = 0x02,
    static void INS_SLO_X_IND_0x03();        // = 0x03,
    static void INS_NOP_ZPG_0x04();          // = 0x04,
    static void INS_ORA_ZPG_0x05();          // = 0x05,
    static void INS_ASL_ZPG_0x06();          // = 0x06,
    static void INS_SLO_ZPG_0x07();          // = 0x07,
    static void INS_PHP_IMPL_0x08();         // = 0x08,
    static void INS_ORA_IMM_0x09();          // = 0x09,
    static void INS_ASL_IMP_0x0a();          // = 0x0a,
    static void INS_ANC_IMM_0x0b ();         // = 0x0b,
    static void INS_NOP_ABS_0x0c();          // = 0x0c,
    static void INS_ORA_ABS_0x0d();          // = 0x0d,
    static void INS_ASL_ABS_0x0e();          // = 0x0e,
    static void INS_SLO_ABS_0x0f();          // = 0x0f,
    static void INS_BPL_REL_0x10();          // = 0x10,
    static void INS_ORA_IND_Y_0x11();        // = 0x11,
    static void INS_JAM_0x12();              // = 0x12,
    static void INS_SLO_IND_Y_0x13();        // = 0x13,
    static void INS_NOP_ZPG_X_0x14();        // = 0x14,
    static void INS_ORA_ZPG_X_0x15();        // = 0x15,
    static void INS_ASL_ZPG_X_0x16();        // = 0x16,
    static void INS_SLO_ZPG_X_0x17();        // = 0x17,
    static void INS_CLC_IMPL_0x18();         // = 0x18,
    static void INS_ORA_ABS_Y_0x19();        // = 0x19,
    static void INS_NOP_IMP_0x1a();          // = 0x1a,
    static void INS_SLO_ABS_Y_0x1b();        // = 0x1b,
    static void INS_NOP_ABS_X_0x1c();        // = 0x1c,
    static void INS_ORA_ABS_X_0x1d();        // = 0x1d,
    static void INS_ASL_ABS_X_0x1e();        // = 0x1e,
    static void INS_SLO_ABS_X_0x1f();        // = 0x1f,
    static void INS_JSR_ABS_0x20();          // = 0x20,
    static void INS_AND_X_IND_0x21();        // = 0x21,
    static void INS_JAM_0x22_0x22();         // = 0x22,
    static void INS_RLA_X_IND_0x23();        // = 0x23,
    static void INS_BIT_ZPG_0x24();          // = 0x24,
    static void INS_AND_ZPG_0x25();          // = 0x25,
    static void INS_ROL_ZPG_0x26();          // = 0x26,
    static void INS_RLA_ZPG_0x27();          // = 0x27,
    static void INS_PLP_IMP_0x28();          // = 0x28,
    static void INS_AND_IMM_0x29();          // = 0x29,
    static void INS_ROL_A_0x2a();            // = 0x2a,
    static void INS_ANC_IMM_0x2b();          // = 0x2b,
    static void INS_BIT_ABS_0x2c();          // = 0x2c,
    static void INS_AND_ABS_0x2d();          // = 0x2d,
    static void INS_ROL_ABS_0x2e();          // = 0x2e,
    static void INS_RLA_ABS_0x2f();          // = 0x2f
    static void INS_BMI_REL_0x30();          // = 0x30
    static void INS_AND_IND_Y_0x31();        // = 0x31
    static void INS_JAM_0x32();              // = 0x32
    static void INS_RLA_IND_Y_0x33();        // = 0x33
    static void INS_NOP_ZPG_X_0x34();        // = 0x34
    static void INS_AND_ZPG_X_0x35();        // = 0x35
    static void INS_ROL_ZPG_X_0x36();        // = 0x36
    static void INS_RLA_ZPG_X_0x37();        // = 0x37
    static void INS_SEC_IMP_0x38();          // = 0x38
    static void INS_AND_ABS_Y_0x39();        // = 0x39
    static void INS_NOP_IMP_0x3a();          // = 0x3a
    static void INS_RLA_ABS_Y_0x3b();        // = 0x3b
    static void INS_NOP_ABS_X_0x3c();        // = 0x3c
    static void INS_AND_ABS_X_0x3d();        // = 0x3d
    static void INS_ROL_ABS_X_0x3e();        // = 0x3e
    static void INS_RLA_ABS_X_0x3f();        // = 0x3f

    void (*opcode_table[64])() = {
        INS_BRK_IMPL,                   // 0x00
        INS_ORA_X_IND,                  // 0x01
        INS_JAM_0X02,                   // 0x02
        INS_SLO_X_IND,                  // 0x03
        INS_NOP_ZPG,                    // 0x04
        INS_ORA_ZPG,                    // 0x05
        INS_ASL_ZPG,                    // 0x06
        INS_SLO_ZPG,                    // 0x07
        INS_PHP_IMPL,                   // 0x08
        INS_ORA_IMM,                    // 0x09
        INS_ASL_IMP,                    // 0x0a
        INS_ANC_IMM_0x0b,               // 0x0b
        INS_NOP_ABS,                    // 0x0c
        INS_ORA_ABS,                    // 0x0d
        INS_ASL_ABS,                    // 0x0e
        INS_SLO_ABS,                    // 0x0f
        INS_BPL_REL,                    // 0x10
        INS_ORA_IND_Y,                  // 0x11
        INS_JAM_0x12,                   // 0x12
        INS_SLO_IND_Y,                  // 0x13
        INS_NOP_ZPG_X_0x14,             // 0x14
        INS_ORA_ZPG_X,                  // 0x15
        INS_ASL_ZPG_X,                  // 0x16
        INS_SLO_ZPG_X,                  // 0x17
        INS_CLC_IMPL,                   // 0x18
        INS_ORA_ABS_Y,                  // 0x19
        INS_NOP_IMP_0x1a,               // 0x1a
        INS_SLO_ABS_Y,                  // 0x1b
        INS_NOP_ABS_X_0x1c,             // 0x1c
        INS_ORA_ABS_X,                  // 0x1d
        INS_ASL_ABS_X,                  // 0x1e
        INS_SLO_ABS_X,                  // 0x1f
        INS_JSR_ABS,                    // 0x20
        INS_AND_X_IND,                  // 0x21
        INS_JAM_0x22,                   // 0x22
        INS_RLA_X_IND,                  // 0x23
        INS_BIT_ZPG,                    // 0x24
        INS_AND_ZPG,                    // 0x25
        INS_ROL_ZPG,                    // 0x26
        INS_RLA_ZPG,                    // 0x27
        INS_PLP_IMP,                    // 0x28
        INS_AND_IMM,                    // 0x29
        INS_ROL_A,                      // 0x2a
        INS_ANC_IMM,                    // 0x2b
        INS_BIT_ABS,                    // 0x2c
        INS_AND_ABS,                    // 0x2d
        INS_ROL_ABS,                    // 0x2e
        INS_RLA_ABS,                    // 0x2f
        INS_BMI_REL,                    // 0x30
        INS_AND_IND_Y,                  // 0x31
        INS_JAM_0x32,                   // 0x32
        INS_RLA_IND_Y,                  // 0x33
        INS_NOP_ZPG_X,                  // 0x34
        INS_AND_ZPG_X,                  // 0x35
        INS_ROL_ZPG_X,                  // 0x36
        INS_RLA_ZPG_X,                  // 0x37
        INS_SEC_IMP,                    // 0x38
        INS_AND_ABS_Y,                  // 0x39
        INS_NOP_IMP,                    // 0x3a
        INS_RLA_ABS_Y,                  // 0x3b
        INS_NOP_ABS_X_0x3c,             // 0x3c
        INS_AND_ABS_X,                  // 0x3d
        INS_ROL_ABS_X,                  // 0x3e
        INS_RLA_ABS_X                   // 0x3f
    };

public:

    // Registers are public
    Word PC;        // Program Counter
    Byte SP;        // Stack Pointer

    Byte A, X, Y;   //Registers

    /**
     * N = negative flag (1 when result is negative)
     * V = overflow flag (1 on signed overflow)
     * # = unused (always 1) <------ this is not handled in this implementation (yet)!
     * B = break flag (1 when interupt was caused by a BRK)
     * D = decimal flag (1 when CPU in BCD mode)
     * I = IRQ flag (when 1, no interupts will occur (exceptions are IRQs forced by BRK and NMIs))
     * Z = zero flag (1 when all bits of a result are 0)
     * C = carry flag (1 on unsigned overflow)
     */


    Byte C : 1;     // Status Flag
    Byte Z : 1;     // Status Flag
    Byte I : 1;     // Status Flag
    Byte D : 1;     // Status Flag
    Byte B : 1;     // Status Flag
    Byte V : 1;     // Status Flag
    Byte N : 1;     // Status Flag

    CPU();
    ~CPU();
    void Reset();
    void Init ( Memory memory );
    void DisplayState();
    void RunTestOpcode( Byte opcode );

};

#endif