/*********************************************************
 *                                                       *
 *  CS 21 Midterm Project                                *
 *                                                       *
 *  C simulator for MIPS                                 *
 *                                                       *
 *********************************************************/


#include "mips.h"

/* syscall */
void syscall();

/* R-type instructions */
void add(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd);
void addu(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd);
void sub(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd);
void subu(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd);
void mult(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd);
void div_r(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd);
void and(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd);
void or(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd);
void nor(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd);
void xor(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd);
void mfhi(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd);
void mflo(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd);
void slt(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd);
void sltu(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd);
void sll(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd, uint32_t shamt);
void srl(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd, uint32_t shamt);
void jr(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd);

/* I-type instructions */
void addi(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm);
void addiu(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm);
void ori(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm);
void lui(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm);
void slti(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm);
void sltiu(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm);
void beq(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm);
void bne(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm);
void sw(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm);
void lw(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm);

/* J-type instructions */
void j(uint32_t inst, uint32_t addr);
void jal(uint32_t inst, uint32_t addr);

void process(uint32_t inst)
{
   uint32_t op = INST(31,26);
   uint32_t rs = INST(25,21);
   uint32_t rt = INST(20,16);
   uint32_t rd = INST(15,11);
   uint32_t shamt = INST(10,6);
   uint32_t funct = INST(5,0);
   uint32_t imm = INST(15,0);
   uint32_t addr = INST(25,0);
   switch(op) {
       //r-type
       case 0b000000:
           switch(funct){
                case 0b100000:
                    add(inst, rs, rt, rd);
                    break;
                case 0b100010:
                    sub(inst, rs, rt, rd);
                    break;
                case 0b100011:
                    subu(inst, rs, rt, rd);
                    break;
                case 0b100001:
                    addu(inst, rs, rt, rd);
                    break;
                case 0b011000:
                    mult(inst, rs, rt, rd);
                    break;
                case 0b011010:
                    div_r(inst, rs, rt, rd);
                    break;
                case 0b100100:
                    and(inst, rs, rt, rd);
                    break;
                case 0b100101:
                    or(inst, rs, rt, rd);
                    break;
                case 0b100111:
                    nor(inst, rs, rt, rd);
                    break;
                case 0b100110:
                    xor(inst, rs, rt, rd);
                    break;
                case 0b010000:
                    mfhi(inst, rs, rt, rd);
                    break;
                case 0b010010:
                    mflo(inst, rs, rt, rd);
                    break;
                case 0b101010:
                    slt(inst, rs, rt, rd);
                    break;
                case 0b101001:
                    sltu(inst, rs, rt, rd);
                    break;
                case 0b000000:
                    sll(inst, rs, rt, rd, shamt);
                    break;
                case 0b000010:
                    srl(inst, rs, rt, rd, shamt);
                    break;
                case 0b001000:
                    jr(inst, rs, rt, rd);
                    break;
                case 0b001100:
                    syscall();
                    break;
                default:
                    break;
            }
            break;
       case 0b001000:
           addi(inst, rs, rt, imm);
           break;
       case 0b001001:
           addiu(inst, rs, rt, imm);
           break;
       case 0b001111:
           lui(inst, rs, rt, imm);
           break;
       case 0b001101:
           ori(inst, rs, rt, imm);
           break;
       case 0b001010:
            slti(inst, rs, rt, imm);
            break;
       case 0b001011:
            sltiu(inst, rs, rt, imm);
            break;
       case 0b000100:
            beq(inst, rs, rt, imm);
            break;
       case 0b000101:
            bne(inst, rs, rt, imm);
            break;
       case 0b101011:
            sw(inst, rs, rt, imm);
            break;
       case 0b100011:
            lw(inst, rs, rt, imm);
            break;
       case 0b000010:
            j(inst, addr);
            break;
       case 0b000011:
            jal(inst, addr);
            break;
       default:
            break;
   }
}


//r-type
void add(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd)
{
    R[rd] = (int)R[rs] + (int)R[rt];
}
void addu(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd)
{
    R[rd] = R[rs] + R[rt];
}
void sub(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd)
{
    R[rd] = (int)R[rs] - (int)R[rt];
}
void subu(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd)
{
    R[rd] = R[rs] - R[rt];
}
void mult(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd)
{
    int64_t prod;
    int64_t new_rs = (extract32_(R[rs], 31))? (0xFFFFFFFF00000000 | (int64_t)R[rs]) : (int64_t)R[rs];
    int64_t new_rt = (extract32_(R[rt], 31))? (0xFFFFFFFF00000000 | (int64_t)R[rt]) : (int64_t)R[rt];
    prod = new_rs * new_rt;
    HI = (int)(prod >> 32);
    LO =  (int)prod ;
}
void div_r(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd)
{
    HI = (int)R[rs] % (int)R[rt];
    LO = (int)R[rs] / (int)R[rt];
}
void and(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd)
{
    R[rd] = R[rs] & R[rt];
}
void or(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd)
{
    R[rd] = R[rs] | R[rt];
}
void nor(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd)
{
    or(inst, rs, rt, rd);
    R[rd] = ~ R[rd];
}
void xor(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd)
{
    R[rd] = R[rs] ^ R[rt];
}
void mfhi(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd)
{
    R[rd] = HI;
}
void mflo(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd)
{
    R[rd] = LO;
}
void slt(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd)
{
    R[rd] = (((int)R[rs] < (int)R[rt]) ? 1 : 0);
}
void sltu(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd)
{
    R[rd] = ((R[rs] < R[rt]) ? 1 : 0);
}
void sll(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd, uint32_t shamt)
{
    R[rd] = R[rt] << shamt;
}
void srl(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd, uint32_t shamt)
{
     R[rd] = R[rt] >> shamt;
}
void jr(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t rd)
{
    PC = R[rs];
}

//i-type
void addi(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm)
{
    imm = sign_extend(imm, 16);
    R[rt] = (int)R[rs] + (int)imm;
}
void addiu(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm)
{
    imm = sign_extend(imm, 16);
    R[rt] = R[rs] + imm;
}
void lui(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm)
{
    R[rt] = (imm << 16);
}
void ori(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm)
{
    R[rt] = R[rs] | imm;
}
void slti(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm)
{
    imm = sign_extend(imm, 16);
    R[rt] = (((int)R[rs] < (int)imm)? 1 : 0 );
}
void sltiu(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm)
{
    imm = sign_extend(imm, 16);
    R[rt] = ((R[rs] < imm)? 1 : 0 );
}
void beq(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm)
{
    imm = sign_extend(imm, 16);
    if(R[rs]==R[rt])
    {
        PC= PC + (imm *4) ;
        branch = 1;
    }
}
void bne(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm)
{
    imm = sign_extend(imm, 16);
    if(R[rs]!=R[rt])
    {
        PC= PC + (imm *4) ;
        branch = 1;
    }
}
void sw(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm)
{
    imm = sign_extend(imm, 16);
    write_word(R[rs]+imm, R[rt]);
}
void lw(uint32_t inst, uint32_t rs, uint32_t rt, uint32_t imm)
{
    imm = sign_extend(imm, 16);
    R[rt] = read_word(R[rs]+imm);
}

//j-type
void j(uint32_t inst, uint32_t addr)
{
    PC = (addr << 2);
    jump = 1;
}
void jal(uint32_t inst, uint32_t addr)
{
    R[31] = PC;
    PC = (addr << 2);
    jump = 1;
}

void syscall()
{
    switch(R[2]) {
        case 0x00000001:
            printf("%d", (int)R[4]);
            break;
        case 0x00000005:
            scanf("%d", &R[2]);
            break;
        case 0x0000000a:
            exit(0);
            break;
        default:
            break;
    }
}
