#include <seq.h>
#include <stdlib.h>
#include "segmem.h"
#include <math.h>
#include <stdbool.h>

/* Instruction Set Functions for UM */
extern void cond_move (int A, int B, int C, int *registers);
extern void add       (int A, int B, int C, int *registers);
extern void mult      (int A, int B, int C, int *registers);
extern void divide    (int A, int B, int C, int *registers);
extern void nand      (int A, int B, int C, int *registers);

extern void seg_load  (int A, int B, int C, int *registers, Segmem_T memory);
extern void seg_store (int A, int B, int C, int *registers, Segmem_T memory);

extern bool halt();

extern void map_seg (int B, int C, int *registers, 
                        Segmem_T memory, int *ismapped);

extern void unmap_seg (int C, int *registers, int *ismapped);

extern void output(int C, int *registers);
extern void intput(int C, int *registers);

extern void load_program(int B, int C, int *registers, Segmem_T memory);
extern void load_value(int value, int A, int *registers);

