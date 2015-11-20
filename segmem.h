#ifndef SEGMEM_INCLUDED
#define SEGMEM_INCLUDED

#define T Segmem_T
typedef struct T *T;

/*
	creates and returns a segmen_T
*/
extern T 	Segmem_new(int num_words);

/*
	adds a new segment with specified number of words
*/
extern T  Segmem_new_seg(int num_words, T segmem);

/*
	free segmem
*/
extern void  Segmem_free(T segmem);

/*
	returns value at segment ID
*/
extern int Segmem_at(T segmem, int index, int offset);

/*
	changes value at segment ID
*/
extern void Segmem_update(T segmem, int index, int offset, int value);


#undef T
#endif
