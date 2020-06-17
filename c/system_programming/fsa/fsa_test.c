#include <assert.h> /* assert */
#include <stdlib.h> /* malloc, free, sizeof */
#include <stdio.h> /* printf */

#include "fsa.h"




void FSAInit_test()
{
	fsa_t *fsa = NULL;
	char *runner = NULL;
	size_t  i = 0;
	void *test = (void *)malloc(96); /* 40 bytes */

	fsa = FSAInit(test, 96, 5);
	runner = (char *)fsa;
	
	puts("INIT TEST");
	printf("index: %lu\n", *((size_t *)runner));
	
	runner += 8;
	
	for(i = 0; i < 5; ++i)
	{
		printf("index: %lu\n", *((size_t *)runner));
		runner += 16;
	}
	puts("");
	free(test);
}

void Alloc_test()
{
	fsa_t *fsa = NULL;
	size_t block_size = 16;
	void *first_alloc = NULL;
	void *second_alloc = NULL;
	void *check = NULL;
	void *test = (void *)malloc(96); /* 40 bytes */
	fsa = FSAInit(test, 96, 5);

	puts("ALLOC TEST");
	check = fsa;
	printf("Original           16 : %lu\n", *(size_t*)check);
	
	first_alloc = FSAAlloc(fsa);
	printf("After 1'st Alloc   32 : %lu\n\n", *(size_t*)check);

	assert((size_t)fsa + block_size == (size_t)first_alloc);
	
	check = (char *)check + 8;
	printf("Check that prev first free is metadata of first store block 16 : %lu\n", 				*(size_t*)check);				
					
	second_alloc = FSAAlloc(fsa);
	assert((size_t)fsa + (2*block_size) == (size_t)second_alloc);
	
	check = fsa;
	FSAFree(first_alloc);
	
	printf("Next Free 16 : %lu\n", *(size_t*)check);
	
	FSAAlloc(fsa);
	printf("Next Free 48 : %lu\n", *(size_t*)check);
	
	puts("");
	free(test);
}

void Free_test()
{
	fsa_t *fsa = NULL;
	void *check = NULL;
	void *first_alloc = NULL;
	void *test = (void *)malloc(96); /* 40 bytes */
	
	fsa = FSAInit(test, 96, 5);

	puts("FREE TEST");
	check = fsa;
	
	/* 2 alloc than free the first */
	first_alloc = FSAAlloc(fsa);	
	FSAAlloc(fsa);
	FSAFree(first_alloc);
	
	printf("Next Free 16 : %lu\n", *(size_t*)check);
	FSAAlloc(fsa);
	printf("Next Free 48 : %lu\n", *(size_t*)check);
	
	puts("");
	free(test);
}

void CountFree_test()
{
	fsa_t *fsa = NULL;
	void *test = (void *)malloc(88);

	fsa = FSAInit(test, 88, 5);

	puts("COUNT FREE TEST");
	printf("size: %lu\n" ,FSACountFree(fsa));

	FSAAlloc(fsa);
	printf("size: %lu\n" ,FSACountFree(fsa));

	FSAAlloc(fsa);
	printf("size: %lu\n" ,FSACountFree(fsa));



	free(test);
}

void SuggestSize_test()
{
	assert(56 == FSASuggestSize(3, 4));
	assert(136 == FSASuggestSize(4, 17));
	assert(88 == FSASuggestSize(5, 5));
}



int main()
{
	FSAInit_test();
	Alloc_test();
	Free_test();
	CountFree_test();
	SuggestSize_test();
	return 0;
}
