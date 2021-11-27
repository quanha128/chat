// M32R assembler (V0.01)
// 名前 (Name)：Ha Minh Quan　学籍番号 (ID)：10191002

#include <stdio.h>

// Register name and register number 
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7
#define R8 8
#define R9 9
#define R10 10
#define R11 11
#define R12 12
#define R13 13
#define R14 14
#define R15 15

// Instruction macro-functions for code generation
#define ADD(d,s)		code_rr(0x00A0,d,s,"ADD")
#define ADD3(d,s,imm16)	code_rri(0x80A0,d,s,imm16,"ADD3")
#define ADDI(d,imm8)	code_rr(0x4000,d,(imm8)&0xff,"ADDI")

#define AND(d,s)        code_rr(0x00C0,d,s,"AND")
#define AND3(d,s,imm16) code_rri(0x80C0,d,s,imm16,"AND3")

#define BC(label)		code_bc(0x7C00,label,"BC")
#define BC24(label)		code_bc24(0xFC00,label,"BC24")
#define BEQ(s1,s2,label) code_beq(0xB000,s1,s2,label,"BEQ")

#define BEQZ(s,label) code_beq(0xB080,0,s,label,"BEQZ")
#define BGEZ(s,label) code_beq(0xB0B0,0,s,label,"BGEZ")
#define BGTZ(s,label) code_beq(0xB0D0,0,s,label,"BGTZ")

#define BL(label)		code_bc(0x7E00,label,"BL")

#define BL24(label)     code_bc24(0xFE00,label,"BL24")
#define BLEZ(s,label) code_beq(0xB0C0,0,s,label,"BLEZ")
#define BLTZ(s,label) code_beq(0xB0A0,0,s,label,"BLTZ")
#define BNC(label)      code_bc(0x7D00,label,"BNC")
#define BNC24(label)      code_bc24(0xFD00,label,"BNC24")
#define BNE(s1,s2,label) code_beq(0xB010,s1,s2,label,"BNE")
#define BNEZ(s,label) code_beq(0xB090,0,s,label,"BNEZ")

#define BRA(label)		code_bc(0x7F00,label,"BRA")

#define BRA24(label)      code_bc24(0xFF00,label,"BRA24")

#define CMP(d,s)		code_rr(0x0040,d,s,"CMP")

#define CMPI(s,imm16)   code_rri(0x8040,0,s,imm16,"CMPI")
#define CMPU(d,s)       code_rr(0x0050,d,s,"CMPU")
#define CMPUI(s,imm16)  code_rri(0x8050,0,s,imm16,"CMPUI")
#define DIV(d,s)        code_rri(0x9000,d,s,0,"DIV")
#define DIVU(d,s)       code_rri(0x9010,d,s,0,"DIVU")
#define JL(s)           code_rr(0x1EC0,0,s,"JL")

#define JMP(s)			code_rr(0x1FC0,0,s,"JMP")
#define LD(d,s)			code_rr(0x20C0,d,s,"LD")

#define LD_INC(d,s)     code_rr(0x20E0,d,s,"LD_INC")

#define LDR(d,s,disp16)	code_rri(0xA0C0,d,s,disp16,"LDR")
#define LD24(d,imm24)	code_ld24(0xE000,d,imm24,"LD24")
#define LDB(d,s)		code_rr(0x2080,d,s,"LDB")

#define LDBR(d,s,disp16) code_rri(0xA080,d,s,disp16,"LDBR")
#define LDH(d,s)         code_rr(0x20A0,d,s,"LDH")
#define LDHR(d,s,disp16) code_rri(0xA0A0,d,s,disp16,"LDHR")

#define LDI(d,imm8)		code_rr(0x6000,d,(imm8)&0xff,"LDI")
#define LDI16(d,imm16)	code_rri(0x90F0,d,0,imm16,"LDI16")

#define LDUB(d,s)       code_rr(0x2090,d,s,"LDUB")
#define LDUBR(d,s,disp16) code_rri(0xA090,d,s,disp16,"LDUBR")
#define LDUH(d,s)       code_rr(0x20B0,d,s,"LDUH")
#define LDUHR(d,s,disp16) code_rri(0xA0B0,d,s,disp16,"LDUHR")

#define MUL(d,s)	 	code_rr(0x1060,d,s,"MUL")
#define MV(d,s)			code_rr(0x1080,d,s,"MV")

#define NEG(d,s)        code_rr(0x0030,d,s,"NEG")

#define NOP()			code_rr(0x7000,0,0,"NOP")

#define NOT(d,s)        code_rr(0x00B0,d,s,"NOT")
#define OR(d,s)         code_rr(0x00E0,d,s,"OR")
#define OR3(d,s,imm16)  code_rri(0x80E0,d,s,imm16,"OR3")
#define REM(d,s)        code_rri(0x9020,d,s,0,"REM")
#define REMU(d,s)       code_rri(0x9030,d,s,0,"REMU")
#define SETH(d,imm16)   code_rri(0xD0C0,d,0,imm16,"SETH")

#define SLL(d,s)	 	code_rr(0x1040,d,s,"SLL")
#define SLL3(d,s,imm16)	code_rri(0x90C0,d,s,imm16,"SLL3")
#define SLLI(d,imm5)	code_rr(0x5040,d,(imm5)&0x1f,"SLLI")

#define SRA(d,s)        code_rr(0x1020,d,s,"SRA")
#define SRA3(d,s,imm16) code_rri(0x90A0,d,s,imm16,"SRA3")
#define SRAI(d,imm5)    code_rr(0x5020,d,(imm5)&0x1f,"SRAI")
#define SRL(d,s)        code_rr(0x1000,d,s,"SRL")
#define SRL3(d,s,imm16) code_rri(0x9080,d,s,imm16,"SRL3")
#define SRLI(d,imm5)    code_rr(0x5000,d,(imm5)&0x1f,"SRLI")

#define ST(s1,s2)		code_rr(0x2040,s1,s2,"ST")

#define ST_INC(d,s)     code_rr(0x2060,d,s,"ST_INC")
#define ST_DEC(d,s)     code_rr(0x2070,d,s,"ST_DEC")

#define STR(s1,s2,disp16) code_rri(0xA040,s1,s2,disp16,"STR")
#define STB(s1,s2)		code_rr(0x2000,s1,s2,"STB")

#define STBR(d,s,disp16) code_rri(0xA000,d,s,disp16,"STBR")
#define STH(d,s)        code_rr(0x2020,d,s,"STH")
#define STHR(d,s,disp16) code_rri(0xA020,d,s,disp16,"STHR")
#define SUB(d,s)        code_rr(0x0020,d,s,"SUB")
#define XOR(d,s)        code_rr(0x00D0,d,s,"XOR")
#define XOR3(d,s,imm16) code_rri(0x80D0,d,s,imm16,"XOR3")

int addr; // Memory address to place generated code and data
int pass; // Pass number of the assmbly process

// Pseudo-inctruction functions
#define org(x)          ( addr = x )
#define aligncode()     ( ( addr%4 == 2 ) ? code_rr(0x7000,0,0,"NOP") : 0 )
#define aligndata()     ( ( addr%4 != 0 ) ? addr = (addr&0xfffffffc)+4 : 0 )
#define trap(n)         code_rr(0x10F0,0,n,"trap")

int string(char *s)
{
    char *p;

    for( p = s; *p != 0; addr++, p++ )
        if( pass > 0 )
            printf("%04x %02x // Byte data\n", addr, *p);
    if( pass > 0 )
        printf("%04x 00 // Byte data\n", addr);
    addr++;
    return 0;
}

// Code generator for the format of "*-*-" (Register-register)
int code_rr(int opcode, int m, int n, char *iname)
{
    if( pass > 0 )
        printf("%04x %04x // %s\n", addr, opcode|(m<<8)|n, iname);
    addr += 2;
    return 0;
}

// Code generator for the format of "*-*- imm16" (Register-register and 16-bit constant)
int code_rri(int opcode, int m, int n, int imm16, char *iname)
{
    if( pass > 0 )
        printf("%04x %04x%04x // %s\n", addr, opcode|(m<<8)|n, imm16&0xffff, iname);
    addr += 4;
    return 0;
}

// Code generator for the format of "**--" (Instruction format of BC)
int code_bc(int opcode, int label, char *iname)
{
    int pcdisp8;

    pcdisp8 = ((label&0xfffffffc)-(addr&0xfffffffc))>>2;
    if( pass > 0 )
        printf("%04x %04x // %s\n", addr, opcode|(pcdisp8&0xff), iname);
    addr += 2;
    return 0;
}

// Code generator for the format of "**-- pcdisp24" (Instruction format of BC24)
int code_bc24(int opcode, int label, char *iname)
{
    int pcdisp24;

    pcdisp24 = ((label&0xfffffffc)-(addr&0xfffffffc))>>2;
    if( pass > 0 )
        printf("%04x %04x%04x // %s\n", addr, opcode|((pcdisp24>>16)&0xff), pcdisp24&0xffff, iname);
    addr += 4;
    return 0;
}

// Code generator for the format of "*-*- pcdisp16" (Instruction format of BEQ)
int code_beq(int opcode, int m, int n, int label, char *iname)
{
    int pcdisp16;

    pcdisp16 = ((label&0xfffffffc)-(addr&0xfffffffc))>>2;
    if( pass > 0 )
        printf("%04x %04x%04x // %s\n", addr, opcode|(m<<8)|n, pcdisp16&0xffff, iname);
    addr += 4;
    return 0;
}

// Code generator for the format of "*--- imm24" (Instruction format of LD24)
int code_ld24(int opcode, int m, int imm24, char *iname)
{
    if( pass > 0 )
        printf("%04x %04x%04x // %s\n", addr, opcode|(m<<8)|((imm24>>16)&0xff), imm24&0xffff, iname);
    addr += 4;
    return 0;
}

// Main function of the M32R assmbler
int main()
{
    int L0, L1, L2, L3, L4, L5, L6;

// Process the assembler code two times
    for( pass = 0; pass < 2; pass++ ) {

// Sample code: Generate all instructions
    org(0);
trap(1);
    LDI(R0,0);      // R0 = 0
    LDI(R6,6);      // R6 = 6
    LDI(R7,7);      // R7 = 7
    LDI(R8,-8);     // R8 = -8
    LDI(R9,-9);     // R9 = -9
    ADD(R1,R6);
    ADD3(R2,R7,-123);
    ADDI(R3,-5);
    AND(R4,R11);
    AND3(R5,R12,0xf800);
    CMP(R1,R1);     // C = 0
    BC(L0);
    BC24(L0);
    BEQ(R6,R7,L0);
    BEQZ(R8,L0);
    BGEZ(R9,L0);
    BGTZ(R0,L0);
    BL(L0);
    aligncode();
L0 = addr;
    BL24(L1);
    aligncode();
L1 = addr;
    BLEZ(R6,L2);
    BLTZ(R7,L2);
    CMP(R6,R7);     // C = 1
    BNC(L2);
    BNC24(L2);
    aligncode();
L2 = addr;
    BNE(R9,R9,L3);
    BNEZ(R0,L3);
    BRA(L3);
    NOP();
    NOP();
    aligncode();
L3 = addr;
    BRA24(L4);
    NOP();
    NOP();
    aligncode();
L4 = addr;
    CMP(R6,R7);
    CMPI(R0,-3);
    CMPU(R1,R2);
    CMPUI(R3,0xcdef);
    DIV(R3,R8);
    DIVU(R5,R9);
    LDI16(R0,L5);
    JL(R0);
    aligncode();
L5 = addr;
    LDI16(R1,L6);
    JMP(R1);
    aligncode();
L6 = addr;
    LDI16(R3,4);
    LD(R1,R3);
    LD_INC(R2,R3);
    LDR(R1,R3,4);
    LD24(R1,0);
    LDB(R1,R3);
    LDBR(R1,R3,-5);
    LDH(R1,R3);
    LDHR(R1,R3,-12);
    LDUB(R1,R3);
    LDUBR(R1,R3,7);
    LDUH(R1,R3);
    LDUHR(R1,R3,6);
    MUL(R11,R10);
    MV(R3,R2);
    NEG(R5,R4);
    NOP();
    NOT(R3,R2);
    OR(R12,R11);
    OR3(R13,R12,0x0110);
    REM(R10,R6);
    REMU(R5,R7);
    SETH(R0,0x1234);
    SLL(R1,R2);
    SLL3(R3,R4,20);
    SLLI(R6,21);
    SRA(R5,R1);
    SRA3(R3,R8,18);
    SRAI(R1,19);
    SRL(R2,R6);
    SRL3(R0,R7,30);
    SRLI(R6,21);
    LDI(R2,0);
    LDI16(R3,2048);
    ST(R0,R3);
    ST_INC(R6,R3);
    ST_DEC(R7,R3);
    STR(R8,R4,8);
    STB(R6,R3);
    STBR(R7,R3,64);
    STH(R8,R3);
    STHR(R9,R3,-16);
    SUB(R3,R2);
    XOR(R1,R5);
    XOR3(R4,R0,0x1f1f);
trap(0);

    }
    return 0;
}
