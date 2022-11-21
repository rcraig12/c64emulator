#include "CPU.h"

CPU::CPU()
{
}

CPU::~CPU()
{
}

// CPU Opcode Section

void CPU::INS_BRK_IMPL_0x00()
{
    printf("opcode called!\n");
}

void CPU::INS_ORA_X_IND_0x01()
{
    printf("opcode called!\n");
}

void CPU::INS_JAM_0X02_0x02()
{
    printf("opcode called!\n");
}

void CPU::INS_SLO_X_IND_0x03()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_ZPG_0x04()
{
    printf("opcode called!\n");
}

void CPU::INS_ORA_ZPG_0x05()
{
    printf("opcode called!\n");
}

void CPU::INS_ASL_ZPG_0x06()
{
    printf("opcode called!\n");
}

void CPU::INS_SLO_ZPG_0x07()
{
    printf("opcode called!\n");
}

void CPU::INS_PHP_IMPL_0x08()
{
    printf("opcode called!\n");
}

void CPU::INS_ORA_IMM_0x09()
{
    printf("opcode called!\n");
}

void CPU::INS_ASL_IMP_0x0a()
{
    printf("opcode called!\n");
}

void CPU::INS_ANC_IMM_0x0b ()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_ABS_0x0c()
{
    printf("opcode called!\n");
}

void CPU::INS_ORA_ABS_0x0d()
{
    printf("opcode called!\n");
}

void CPU::INS_ASL_ABS_0x0e()
{
    printf("opcode called!\n");
}

void CPU::INS_SLO_ABS_0x0f()
{
    printf("opcode called!\n");
}

void CPU::INS_BPL_REL_0x10()
{
    printf("opcode called!\n");
}

void CPU::INS_ORA_IND_Y_0x11()
{
    printf("opcode called!\n");
}

void CPU::INS_JAM_0x12()
{
    printf("opcode called!\n");
}

void CPU::INS_SLO_IND_Y_0x13()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_ZPG_X_0x14()
{
    printf("opcode called!\n");
}

void CPU::INS_ORA_ZPG_X_0x15()
{
    printf("opcode called!\n");
}

void CPU::INS_ASL_ZPG_X_0x16()
{
    printf("opcode called!\n");
}

void CPU::INS_SLO_ZPG_X_0x17()
{
    printf("opcode called!\n");
}

void CPU::INS_CLC_IMPL_0x18()
{
    printf("opcode called!\n");
}

void CPU::INS_ORA_ABS_Y_0x19()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_IMP_0x1a()
{
    printf("opcode called!\n");
}

void CPU::INS_SLO_ABS_Y_0x1b()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_ABS_X_0x1c()
{
    printf("opcode called!\n");
}

void CPU::INS_ORA_ABS_X_0x1d()
{
    printf("opcode called!\n");
}

void CPU::INS_ASL_ABS_X_0x1e()
{
    printf("opcode called!\n");
}

void CPU::INS_SLO_ABS_X_0x1f()
{
    printf("opcode called!\n");
}

void CPU::INS_JSR_ABS_0x20()
{
    printf("opcode called!\n");
}

void CPU::INS_AND_X_IND_0x21()
{
    printf("opcode called!\n");
}

void CPU::INS_JAM_0x22_0x22()
{
    printf("opcode called!\n");
}

void CPU::INS_RLA_X_IND_0x23()
{
    printf("opcode called!\n");
}

void CPU::INS_BIT_ZPG_0x24()
{
    printf("opcode called!\n");
}

void CPU::INS_AND_ZPG_0x25()
{
    printf("opcode called!\n");
}

void CPU::INS_ROL_ZPG_0x26()
{
    printf("opcode called!\n");
}

void CPU::INS_RLA_ZPG_0x27()
{
    printf("opcode called!\n");
}

void CPU::INS_PLP_IMP_0x28()
{
    printf("opcode called!\n");
}

void CPU::INS_AND_IMM_0x29()
{
    printf("opcode called!\n");
}

void CPU::INS_ROL_A_0x2a()
{
    printf("opcode called!\n");
}

void CPU::INS_ANC_IMM_0x2b()
{
    printf("opcode called!\n");
}

void CPU::INS_BIT_ABS_0x2c()
{
    printf("opcode called!\n");
}

void CPU::INS_AND_ABS_0x2d()
{
    printf("opcode called!\n");
}

void CPU::INS_ROL_ABS_0x2e()
{
    printf("opcode called!\n");
}

void CPU::INS_RLA_ABS_0x2f()
{
    printf("opcode called!\n");
}

void CPU::INS_BMI_REL_0x30()
{
    printf("opcode called!\n");
}

void CPU::INS_AND_IND_Y_0x31()
{
    printf("opcode called!\n");
}

void CPU::INS_JAM_0x32()
{
    printf("opcode called!\n");
}

void CPU::INS_RLA_IND_Y_0x33()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_ZPG_X_0x34()
{
    printf("opcode called!\n");
}

void CPU::INS_AND_ZPG_X_0x35()
{
    printf("opcode called!\n");
}

void CPU::INS_ROL_ZPG_X_0x36()
{
    printf("opcode called!\n");
}

void CPU::INS_RLA_ZPG_X_0x37()
{
    printf("opcode called!\n");
}

void CPU::INS_SEC_IMP_0x38()
{
    printf("opcode called!\n");
}

void CPU::INS_AND_ABS_Y_0x39()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_IMP_0x3a()
{
    printf("opcode called!\n");
}

void CPU::INS_RLA_ABS_Y_0x3b()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_ABS_X_0x3c()
{
    printf("opcode called!\n");
}

void CPU::INS_AND_ABS_X_0x3d()
{
    printf("opcode called!\n");
}

void CPU::INS_ROL_ABS_X_0x3e()
{
    printf("opcode called!\n");
}

void CPU::INS_RLA_ABS_X_0x3f()
{
    printf("opcode called!\n");
}

void CPU::INS_RTI_IMP_0x40()
{
    printf("opcode called!\n");
}

void CPU::INS_EOR_X_IND_0x41()
{
    printf("opcode called!\n");
}

void CPU::INS_JAM_0x42()
{
    printf("opcode called!\n");
}

void CPU::INS_SRE_X_IND_0x43()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_ZPG_X_0x44()
{
    printf("opcode called!\n");
}

void CPU::INS_EOR_ZPG_0x45()
{
    printf("opcode called!\n");
}

void CPU::INS_LSR_ZPG_0x46()
{
    printf("opcode called!\n");
}

void CPU::INS_SRE_ZPG_0x47()
{
    printf("opcode called!\n");
}

void CPU::INS_PHA_IMP_0x48()
{
    printf("opcode called!\n");
}

void CPU::INS_EOR_IMP_0x49()
{
    printf("opcode called!\n");
}

void CPU::INS_LSR_A_0x4a()
{
    printf("opcode called!\n");
}

void CPU::INS_ALR_IMP_0x4b()
{
    printf("opcode called!\n");
}

void CPU::INS_JMP_ABS_0x4c()
{
    printf("opcode called!\n");
}

void CPU::INS_EOR_ABS_0x4d()
{
    printf("opcode called!\n");
}

void CPU::INS_LSR_ABS_0x4e()
{
    printf("opcode called!\n");
}

void CPU::INS_SRE_ABS_0x4f()
{
    printf("opcode called!\n");
}

void CPU::INS_BVC_REL_0x50()
{
    printf("opcode called!\n");
}

void CPU::INS_EOR_IND_Y_0x51()
{
    printf("opcode called!\n");
}

void CPU::INS_JAM_0x52()
{
    printf("opcode called!\n");
}

void CPU::INS_SRE_IND_Y_0x53()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_ZPG_X_0x54()
{
    printf("opcode called!\n");
}

void CPU::INS_EOR_ZPG_X_0x55()
{
    printf("opcode called!\n");
}

void CPU::INS_LSR_ZPG_X_0x56()
{
    printf("opcode called!\n");
}

void CPU::INS_SRE_ZPG_X_0x57()
{
    printf("opcode called!\n");
}

void CPU::INS_CLI_IMP_0x58()
{
    printf("opcode called!\n");
}

void CPU::INS_EOR_ABS_Y_0x59()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_IMP_0x5a()
{
    printf("opcode called!\n");
}

void CPU::INS_SRE_ABS_Y_0x5b()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_ABS_X_0x5c()
{
    printf("opcode called!\n");
}

void CPU::INS_EOR_ABS_X_0x5d()
{
    printf("opcode called!\n");
}

void CPU::INS_LSR_ABS_X_0x5e()
{
    printf("opcode called!\n");
}

void CPU::INS_SRE_ABS_X_0x5f()
{
    printf("opcode called!\n");
}

void CPU::INS_RTS_IMP_0x60()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_ADC_X_IND_0x61()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_JAM_0x62()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_RRA_X_IND_0x63()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_NOP_ZPG_0x64()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_ADC_ZPG_0x65()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_ROR_ZPG_0x66()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_RRA_ZPG_0x67()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_PLA_IMP_0x68()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_ADC_IMM_0x69()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_ROR_A_0x6a()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_ARR_IMM_0x6b()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_JMP_IND_0x6c()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_ADC_ABS_0x6d()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_ROR_ABS_0x6e()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_RRA_ABS_0x6f()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_BVS_REL_0x70()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_ADC_IND_Y_0x71()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_JAM_0x72()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_RRA_IND_Y_0x73()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_NOP_ZPG_X_0x74()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_ADC_ZPG_X_0x75()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_ROR_ZPG_X_0x76()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_RRA_ZPG_X_0x77()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_SEA_IMP_0x78()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_ADC_ABS_Y_0x79()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_NOP_IMP_0x7a()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_RRA_ABS_Y_0x7b()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_NOP_ABS_X_0x7c()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_ADC_ABS_X_0x7d()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_ROR_ABS_X_0x7e()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_RRA_ABS_X_0x7f()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_NOP_IMM_0x80()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_STA_X_IND_0x81()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_NOP_IMM_0x82()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_SAX_X_IND_0x83()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_STY_ZPG_0x84()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_STA_ZPG_0x85()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_STX_ZPG_0x86()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_SAX_ZPG_0x87()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_DEY_IMP_0x88()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_NOP_IMM_0x89()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_TXA_IMP_0x8a()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_ANE_IMM_0x8b()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_STY_ABS_0x8c()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_STA_ABS_0x8d()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_STX_ABS_0x8e()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_SAX_ABS_0x8f()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_BCC_REL_0x90()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_STA_IND_Y_0x91()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_JAM_0x92()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_SHA_IND_Y_0x93()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_STY_ZPG_X_0x94()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_STA_ZPG_X_0x95()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_STX_ZPG_Y_0x96()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_SAX_ZPG_Y_0x97()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_TYA_IMP_0x98()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_STA_ABS_Y_0x99()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_TXS_IMP_0x9a()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_TAS_ABS_Y_0x9b()
{
    printf("OPCODE CALLED!\n");
}

void CPU::INS_SHY_ABS_X_0x9c()
{
    printf("opcode called!\n");
}

void CPU::INS_STA_ABS_X_0x9d()
{
    printf("opcode called!\n");
}

void CPU::INS_SHX_ABS_Y_0x9e()
{
    printf("opcode called!\n");
}

void CPU::INS_SHA_ABS_Y_0x9f()
{
    printf("opcode called!\n");
}

void CPU::INS_LDY_IMM_0xa0()
{
    printf("opcode called!\n");
}

void CPU::INS_LDA_X_IND_0xa1()
{
    printf("opcode called!\n");
}

void CPU::INS_LDX_IMM_0xa2()
{
    printf("opcode called!\n");
}

void CPU::INS_LAX_X_IND_0xa3()
{
    printf("opcode called!\n");
}

void CPU::INS_LDY_ZPG_0xa4()
{
    printf("opcode called!\n");
}

void CPU::INS_LDA_ZPG_0xa5()
{
    printf("opcode called!\n");
}

void CPU::INS_LDX_ZPG_0xa6()
{
    printf("opcode called!\n");
}

void CPU::INS_LAX_ZPG_0xa7()
{
    printf("opcode called!\n");
}

void CPU::INS_TAY_IMP_0xa8()
{
    printf("opcode called!\n");
}

void CPU::INS_LDA_IMM_0xa9()
{
    printf("opcode called!\n");
}

void CPU::INS_TAX_IMP_0xaa()
{
    printf("opcode called!\n");
}

void CPU::INS_LXA_IMM_0xab()
{
    printf("opcode called!\n");
}

void CPU::INS_LDY_ABS_0xac()
{
    printf("opcode called!\n");
}

void CPU::INS_LDA_ABS_0xad()
{
    printf("opcode called!\n");
}

void CPU::INS_LDX_ABS_0xae()
{
    printf("opcode called!\n");
}

void CPU::INS_LAX_ABS_0xaf()
{
    printf("opcode called!\n");
}

void CPU::INS_BCS_REL_0xb0()
{
    printf("opcode called!\n");
}

void CPU::INS_LDA_IND_Y_0xb1()
{
    printf("opcode called!\n");
}

void CPU::INS_JAM_0xb2()
{
    printf("opcode called!\n");
}

void CPU::INS_LAX_IND_Y_0xb3()
{
    printf("opcode called!\n");
}

void CPU::INS_LDY_ZPG_X_0xb4()
{
    printf("opcode called!\n");
}

void CPU::INS_LDA_ZPG_X_0xb5()
{
    printf("opcode called!\n");
}

void CPU::INS_LDX_ZPG_Y_0xb6()
{
    printf("opcode called!\n");
}

void CPU::INS_LAX_ZPG_Y_0xb7()
{
    printf("opcode called!\n");
}

void CPU::INS_CLV_IMP_0xb8()
{
    printf("opcode called!\n");
}

void CPU::INS_LDA_ABS_Y_0xb9()
{
    printf("opcode called!\n");
}

void CPU::INS_TSX_IMP_0xba()
{
    printf("opcode called!\n");
}

void CPU::INS_LAS_ABS_Y_0xbb()
{
    printf("opcode called!\n");
}

void CPU::INS_LDY_ABS_X_0xbc()
{
    printf("opcode called!\n");
}

void CPU::INS_LDA_ABS_X_0xbd()
{
    printf("opcode called!\n");
}

void CPU::INS_LDX_ABS_Y_0xbe()
{
    printf("opcode called!\n");
}

void CPU::INS_LAX_ABS_Y_0xbf()
{
    printf("opcode called!\n");
}

void CPU::INS_CPY_IMM_0xc0()
{
    printf("opcode called!\n");
}

void CPU::INS_CMP_X_IND_0xc1()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_IMM_0xc2()
{
    printf("opcode called!\n");
}

void CPU::INS_DCP_X_IND_0xc3()
{
    printf("opcode called!\n");
}

void CPU::INS_CPY_ZPG_0xc4()
{
    printf("opcode called!\n");
}

void CPU::INS_CMP_ZPG_0xc5()
{
    printf("opcode called!\n");
}

void CPU::INS_DEC_ZPG_0xc6()
{
    printf("opcode called!\n");
}

void CPU::INS_DCP_ZPG_0xc7()
{
    printf("opcode called!\n");
}

void CPU::INS_INY_IMP_0xc8()
{
    printf("opcode called!\n");
}

void CPU::INS_CMP_IMM_0xc9()
{
    printf("opcode called!\n");
}

void CPU::INS_DEX_IMP_0xca()
{
    printf("opcode called!\n");
}

void CPU::INS_SBX_IMP_0xcb()
{
    printf("opcode called!\n");
}

void CPU::INS_CPY_ABS_0xcc()
{
    printf("opcode called!\n");
}

void CPU::INS_CMP_ABS_0xcd()
{
    printf("opcode called!\n");
}

void CPU::INS_DEC_ABS_0xce()
{
    printf("opcode called!\n");
}

void CPU::INS_DCP_ABS_0xcf()
{
    printf("opcode called!\n");
}

void CPU::INS_BNE_REL_0xd0()
{
    printf("opcode called!\n");
}

void CPU::INS_CMP_IND_Y_0xd1()
{
    printf("opcode called!\n");
}

void CPU::INS_JAM_0xd2()
{
    printf("opcode called!\n");
}

void CPU::INS_DCP_IND_Y_0xd3()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_ZPG_X_0xd4()
{
    printf("opcode called!\n");
}

void CPU::INS_CMP_ZPG_X_0xd5()
{
    printf("opcode called!\n");
}

void CPU::INS_DEC_ZPG_X_0xd6()
{
    printf("opcode called!\n");
}

void CPU::INS_DCP_ZPG_X_0xd7()
{
    printf("opcode called!\n");
}

void CPU::INS_CLD_IMP_0xd8()
{
    printf("opcode called!\n");
}

void CPU::INS_CMP_ABS_Y_0xd9()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_IMP_0xda()
{
    printf("opcode called!\n");
}

void CPU::INS_DCP_ABS_Y_0xdb()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_ABS_X_0xdc()
{
    printf("opcode called!\n");
}

void CPU::INS_CMP_ABS_X_0xdd()
{
    printf("opcode called!\n");
}

void CPU::INS_DEC_ABS_X_0xde()
{
    printf("opcode called!\n");
}

void CPU::INS_DCP_ABS_X_0xdf()
{
    printf("opcode called!\n");
}

void CPU::INS_CPX_IMM_0xe0()
{
    printf("opcode called!\n");
}

void CPU::INS_SBC_X_IND_0xe1()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_IMM_0xe2()
{
    printf("opcode called!\n");
}

void CPU::INS_ISC_X_IND_0xe3()
{
    printf("opcode called!\n");
}

void CPU::INS_CPX_ZPG_0xe4()
{
    printf("opcode called!\n");
}

void CPU::INS_SBC_ZPG_0xe5()
{
    printf("opcode called!\n");
}

void CPU::INS_INC_ZPG_0xe6()
{
    printf("opcode called!\n");
}

void CPU::INS_ISC_ZPG_0xe7()
{
    printf("opcode called!\n");
}

void CPU::INS_INX_IMP_0xe8()
{
    printf("opcode called!\n");
}

void CPU::INS_SBC_IMM_0xe9()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_IMP_0xea()
{
    printf("opcode called!\n");
}

void CPU::INS_USBC_IMM_0xeb()
{
    printf("opcode called!\n");
}

void CPU::INS_CPX_ABS_0xec()
{
    printf("opcode called!\n");
}

void CPU::INS_SBC_ABS_0xed()
{
    printf("opcode called!\n");
}

void CPU::INS_INC_ABS_0xee()
{
    printf("opcode called!\n");
}

void CPU::INS_ISC_ABS_0xef()
{
    printf("opcode called!\n");
}

void CPU::INS_BEQ_REL_0xf0()
{
    printf("opcode called!\n");
}

void CPU::INS_SBC_IND_Y_0xf1()
{
    printf("opcode called!\n");
}

void CPU::INS_JAM_0xf2()
{
    printf("opcode called!\n");
}

void CPU::INS_ISC_IND_Y_0xf3()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_ZPG_X_0xf4()
{
    printf("opcode called!\n");
}

void CPU::INS_SBC_ZPG_X_0xf5()
{
    printf("opcode called!\n");
}

void CPU::INS_INC_ZPG_X_0xf6()
{
    printf("opcode called!\n");
}

void CPU::INS_ISC_ZPG_X_0xf7()
{
    printf("opcode called!\n");
}

void CPU::INS_SED_IMP_0xf8()
{
    printf("opcode called!\n");
}

void CPU::INS_SBC_ABS_Y_0xf9()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_IMP_0xfa()
{
    printf("opcode called!\n");
}

void CPU::INS_ISC_ABS_Y_0xfb()
{
    printf("opcode called!\n");
}

void CPU::INS_NOP_ABS_X_0xfc()
{
    printf("opcode called!\n");
}

void CPU::INS_SBC_ABS_X_0xfd()
{
    printf("opcode called!\n");
}

void CPU::INS_INC_ABS_X_0xfe()
{
    printf("opcode called!\n");
}

void CPU::INS_ISC_ABS_X_0xff()
{
    printf("opcode called!\n");
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