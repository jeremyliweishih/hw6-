#include "assert.h"
#include "mem.h"
#include "seq.h"
#include "segmem.h"
#include "stdio.h"
#include "stdlib.h"

#define T Segmem_T

struct T { /* represents a 2D array of cells each of size 'size' */
        Seq_T memory;
        int length;
};

T Segmem_new(int num_words)
{
        T segmem = malloc(sizeof(*segmem));        
        segmem->memory = Seq_new(1);
        segmem->length = 0;
        int *segment =  malloc(num_words * sizeof(int));
        Seq_addhi(segmem->memory, segment);
        return segmem;
}

T  Segmem_new_seg(int num_words, T segmem)
{
        int *segment = malloc(num_words * sizeof(int));
       // printf("%p \n", (void *)segment);
        Seq_addhi(segmem->memory, segment);
        segmem->length += 1;
        return segmem;
}

int Segmem_at(T segmem, int index, int offset)
{
        int *segment = (int *)Seq_get(segmem->memory, index);
        int value = segment[offset];
        return value;
}
void Segmem_update(T segmem, int index, int offset, int value)
{
        int *segment = (int *)Seq_get(segmem->memory, index);
        segment[offset] = value;
}

void  Segmem_free(T segmem)
{       
        int i;
        for(i = 0; i < segmem->length; i++)
        {
                int *array = (int *)Seq_get(segmem->memory, i);
                //printf("%p\n", (void *)(array));

                free(array);
        }
        Seq_free(&(segmem->memory));
}








