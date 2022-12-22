#ifndef SIC_INS_H
#define SIC_INS_H
#include "main.c"
void ADD() {
    reg_A += get_value(operand,indexed);
}

void AND() {
    reg_A &= get_value(operand,indexed);
}

void COMP() {
    int t = get_value(operand,indexed);
    if (reg_A > t)
        reg_SW = '>';
    else if (reg_A < t)
        reg_SW = '<';
    else
        reg_SW = '=';
}

void DIV() {
    reg_A /= get_value(operand,indexed);
}

void J() {
    reg_PC = operand;
    curr_add = (reg_PC - start_add) * 2;
}

void JEQ() {
    if(reg_SW == '=')
        J();
}

void JGT() {
    if(reg_SW == '>')
        J();
}

void JLT() {
    if(reg_SW == '<')
        J();
}

void JSUB() {
    reg_L = reg_PC;
    J();
}

void LDA() {
    reg_A = get_value(operand,indexed);
}

void LDCH() {
    int t = get_byte(operand,indexed);
    reg_A &= 0x111100;
    reg_A+=t;
}

void LDL() {
    reg_L = get_value(operand,indexed);
}

void LDX() {
    reg_X = get_value(operand,indexed);
}

void MUL() {
    reg_A *= get_value(operand,indexed);
}

void OR() {
    reg_A |= get_value(operand,indexed);
}

void RD() {
    char t;
    t = fgetc(in);
    reg_A = 0x0000000;
    if(t==EOF) t &= 0x000000;
    reg_A += t;    
}

void RSUB() {
    reg_PC = reg_L;
    if(reg_PC == 0x000000)
        reg_PC = prog_len + start_add;
    else
        curr_add = (reg_PC - start_add) * 2;
}

void STA() {
    put_value(reg_A,operand,indexed);
}

void STCH() {
    put_byte(reg_A,operand,indexed);
}

void STL() {
    put_value(reg_L,operand,indexed);
}

void STSW() {
    put_value(reg_SW,operand,indexed);
}

void STX() {
    put_value(reg_X,operand,indexed);
}

void SUB() {
    reg_A -= get_value(operand,indexed);
}

void TD() {
    if(in) reg_SW = '<';
    else reg_SW = '='; 
}

void TIX() {
    reg_X += 1;
    int temp = get_value(operand,indexed);
    if(reg_X>temp)
        reg_SW = '>';
    else if(reg_X<temp)
        reg_SW = '<';
    else
        reg_SW = '=';
}

void WD() {
    char text[3];
    int x;
    sprintf(text,"%02x",reg_A);
    sscanf(text,"%x",&x);
    fprintf(out,"%c",x);
    printf("%c",x);
}

void run(int op) {
    switch (op)
    {
    case oADD:
        ADD();break;
    case oAND:
        AND();break;
    case oCOMP:
        COMP();break;
    case oDIV:
        DIV();break;
    case oJ:
        J();break;
    case oJEQ:
        JEQ();break;
    case oJGT:
        JGT();break;
    case oJLT:
        JLT();break;
    case oJSUB:
        JSUB();break;
    case oLDA:
        LDA();break;
    case oLDCH:
        LDCH();break;
    case oLDL:
        LDL();break;
    case oLDX:
        LDX();break;
    case oMUL:
        MUL();break;
    case oOR:
        OR();break;
    case oRD:
        RD();break;
    case oRSUB:
        RSUB();break;
    case oSTA:
        STA();break;
    case oSTCH:
        STCH();break;
    case oSTL:
        STL();break;
    case oSTSW:
        STSW();break;
    case oSTX:
        STX();break;
    case oSUB:
        SUB();break;
    case oTD:
        TD();break;
    case oTIX:
        TIX();break;
    case oWD:
        WD();break;
   default:
        break;
    }   
}

#endif