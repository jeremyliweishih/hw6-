#include "instruction_set.h"



void cond_move (int A, int B, int C, int *registers)
{
	if (registers[C] != 0)
	{
		registers[A] = registers[B];
	}
}

void seg_load  (int A, int B, int C, int *registers, Segmem_T memory)
{
	registers[A] = Segmem_at(memory, registers[B], registers[C]);
}

void seg_store (int A, int B, int C, int *registers, Segmem_T memory)
{
	Segmem_update(memory, registers[A], registers[B], registers[C]);
}

void add       (int A, int B, int C, int *registers)
{
	registers[A] = (registers[B] + registers[C]) % (int)pow(2,32);
}

void mult      (int A, int B, int C, int *registers)
{
	registers[A] = (registers[B] * registers[C]) % (int)pow(2,32);
}

void divide    (int A, int B, int C, int *registers)
{
	registers[A] = registers[B] / registers[C];
}

void nand      (int A, int B, int C, int *registers)
{
	registers[A] = ~(registers[B] & registers[C]);
}

bool halt()
{
	return true;
}

void map_seg (int B, int C, int *registers, 
                        Segmem_T memory, int *ismapped)
{
	int k = 0;
	int index = -1;
	int length = sizeof(ismapped)/sizeof(int); // size of pointer or array?
	for (; k < length; k++)
	{
		if (ismapped[k] == 0)
		{
			index = k;
		}
	}
	if (k == -1)
	{
		Segmem_new_seg(registers[C], memory);
		int i = 0;
		for (; i < registers[C]; i++)
		{
			Segmem_update(memory, memory->length -1, i, 0);
		}
	}
	else 
	{
		
	}
}

void unmap_seg (int C, int *registers, int *ismapped)
{
	
}

void output(int C, int *registers)
{
	printf("%d /n", registers[C]);
}

void intput(int C, int *registers)
{
	registers[C] = getchar();
}

void load_program(int B, int C, int *registers, Segmem_T memory)
{
	
}

void load_value(int value, int A, int *registers)
{
	registers[A] = value;
}
