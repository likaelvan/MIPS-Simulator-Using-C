/*********************************************************
 *                                                       *
 *  CS 21 Midterm Project                                *
 *                                                       *
 *  C simulator for MIPS                                 *
 *                                                       *
 *********************************************************/

#include "mips.h"

uint32_t read_word(uint32_t addr)
{
  uint32_t data;

  addr -= MEM_OFFSET;

  data = (uint32_t)mem[addr];
  data += (uint32_t)mem[addr + 1] << 8;
  data += (uint32_t)mem[addr + 2] << 16;
  data += (uint32_t)mem[addr + 3] << 24;

  return data;
}

uint32_t read_halfword(uint32_t addr)
{
  uint32_t data;

  addr -= MEM_OFFSET;

  data = (uint32_t)mem[addr];
  data += (uint32_t)mem[addr + 1] << 8;

  return data;
}

uint32_t read_byte(uint32_t addr)
{
  addr -= MEM_OFFSET;

  return (uint32_t)mem[addr];
}

void write_word(uint32_t addr, uint32_t value)
{
  addr -= MEM_OFFSET;

  mem[addr] = (unsigned char)value;
  mem[addr + 1] = (unsigned char)(value >> 8);
  mem[addr + 2] = (unsigned char)(value >> 16);
  mem[addr + 3] = (unsigned char)(value >> 24);
}

void write_halfword(uint32_t addr, uint32_t value)
{
  addr -= MEM_OFFSET;

  mem[addr] = (unsigned char)value;
  mem[addr + 1] = (unsigned char)(value >> 8);
}

void write_byte(uint32_t addr, uint32_t value)
{
  addr -= MEM_OFFSET;

  mem[addr] = (unsigned char)value;
}
