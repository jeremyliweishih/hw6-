#include <stdio.h>
#include <stdbool.h>
#include "bitpack.h"
#include "except.h"
#include "assert.h"
#include "instruction_set.h"
#include "seq.h"
#include "segmen.h"

/* reads instructions from file and places into segment 0*/
extern void readfile(FILE *fp, Segmen_T memory);

/* initialzes initial state*/
extern void init();

/*executes word instruction*/
extern void execute(int word, int *registers, Segmen_T memory);
