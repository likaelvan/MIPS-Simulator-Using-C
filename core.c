/*********************************************************
 *                                                       *
 *  CS 21 Midterm Project                                *
 *                                                       *
 *  C simulator for MIPS                                 *
 *                                                       *
 *********************************************************/

#include "mips.h"

void init_mem(char *mem_name);
void init_register(void);
void view_reg(uint32_t inst);

int main(int argc, char *argv[])
{
  uint32_t inst;
  uint32_t bp,mp;
  int n = 0, m = 0;
  int i;
  char in;

  /* Initialization */
  init_mem(argv[1]);
  init_register();

  /* Running a program */
  while (1) {
    printf("Request: ");
    scanf(" %c", &in);

    switch (in) {
    case 's': // process a single instruction
      inst = fetch();
      process(inst);
      view_reg(inst);
      updatePC();
      break;
    case 'm': // process mutiple instructions
      printf("Number of instructions: ");
      scanf(" %d", &m);
      for (i = 0; i < m - 1; i++) {
        inst = fetch();
        process(inst);
        updatePC();
      }
      inst = fetch();
      process(inst);
      view_reg(inst);
      updatePC();
      break;
    case 'b': // process until the breakpoint is reached
      printf("Breakpoint address: ");
      scanf(" %x", &bp);
      while (PC != bp) {
        inst = fetch();
        process(inst);
        updatePC();
      }
      inst = fetch();
      process(inst);
      view_reg(inst);
      updatePC();
      break;
    case 'v': //memory view
      printf("Memory address: ");
      scanf(" %x",&mp);
      printf("%08x : %08x\n", mp,read_word(mp));
      break;
    case 'q': // quit
      exit(0);
      break;
    default:
      printf("Wrong input!\n");
      while (getchar() != '\n');
      break;
    }
  }
  return 0;
}

void init_mem(char *mem_name)
{
  FILE *fp;
  int i;
	uint32_t temp;

  mem = (unsigned char *) calloc(MEM_SIZE, sizeof(unsigned char));
  assert(mem != NULL);

  fp = fopen(mem_name, "r");
  for (i = 0; i < MEM_SIZE; i = i + 4) {
    if (fscanf(fp, "%x", &temp) <= 0)
      break;
		mem[i] = (unsigned char) temp;
		mem[i + 1] = (unsigned char) (temp >> 8);
		mem[i + 2] = (unsigned char) (temp >> 16);
		mem[i + 3] = (unsigned char) (temp >> 24);
	}
  fclose(fp);
}

void init_register(void)
{
  int i;
  for (i = 0; i < 32; i++)
    R[i] = 0;

  SP = MEM_SIZE + MEM_OFFSET - 4;
  PC = MEM_OFFSET + 4;
  EXE_PC = PC - 4;

  branch = 0;
  jump = 0;
}

void view_reg(uint32_t inst)
{
  int i;

  printf("\nInst: 0x%08X\n", inst);
  printf("Executed PC: 0x%08X\t Next PC: 0x%08X\n", EXE_PC, PC);
  printf("Registers\n");
  for (i = 0; i < 32; i++) {
    printf("[%2d]0x%08X ", i, R[i]);
    if (i % 4 == 3)
      printf("\n");
  }

  printf("\n===============================================\n");
  printf("\n");
}
