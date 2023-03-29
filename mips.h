/*********************************************************
 *                                                       *
 *  CS 21 Midterm Project                                *
 *                                                       *
 *  C simulator for MIPS                                 *
 *                                                       *
 *********************************************************/

#ifndef ISS_H
#define ISS_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// Registers
uint32_t R[32];
uint32_t PC;
uint32_t HI;
uint32_t LO;

#define Z0 R[0]
#define AT R[1]
#define SP R[29]
#define RA R[31]

#define MEM_SIZE  0x4000000 // 64 MB
#define DATA_SEGMENT 0x1000000 // 16 MB
#define MEM_OFFSET 0x400000  // Start of TEXT segment in MIPS (MARS)
uint8_t *mem;

// BRANCH should be set to 1 whenever branch occurs
int branch;
// JUMP should be set to 1 whenever jump occurs
int jump;
//instruction address for EXE stage (PC - 4)
uint32_t EXE_PC;

uint32_t fetch(void);
void process(uint32_t inst);
void updatePC(void);

uint32_t extract32(uint32_t data, int end, int start);
uint32_t extract32_(uint32_t data, int pos);
uint32_t sign_extend(uint32_t a, int length);

/* Shorthand for extracting bits in inst. */
#define INST(x, y) extract32(inst, x, y)
#define INST_(x) extract32_(inst, x)

#define MSB(x) extract32_(x, 31)

// Sign extension
#define zeroExtend32(x) (x)
#define signExtend32(x, n) (((((x) >> ((n)-1)) & 0x1) != 0) ? (~((unsigned int)0) << (n)) | (x) : (x))

/* Memory access functions. */
uint32_t read_word(uint32_t addr);
uint32_t read_halfword(uint32_t addr);
uint32_t read_byte(uint32_t addr);

void write_word(uint32_t addr, uint32_t value);
void write_halfword(uint32_t addr, uint32_t value);
void write_byte(uint32_t addr, uint32_t value);

#endif
