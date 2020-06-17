#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h> /* assert */

#include "vsa.h"

#define Expect(x) {                                                \
    if (!(x))                                                    \
    {                                                            \
        fprintf(stderr, "Test failed in line %d\n", __LINE__);    \
        return 0;                                                \
    } } /* end of Expects(x) */

int CreateAndSize();
int Alloc();
int AllocFree();
int AllocFreeValue();

int main()
{
	CreateAndSize();
	Alloc();
	AllocFree();
	AllocFreeValue();
	printf("Great :)\n");
	
	return 0;
}

int CreateAndSize()
{
	int *memory = (int *)malloc(4*8);

	vsa_t *create = VSAInit(memory, (4*8));
	
	#ifndef NDEBUG
	assert((1 * 8) == VSALargestChunk(create));
	
	free(memory); memory = NULL;
	return 0;
	#endif
	
	Expect(2 * 8)

	free(memory); memory = NULL;
	return 0;
}


int Alloc()
{
	int *memory = (int *)malloc(8*8);
	int one = 1;
	int two = 2;
	int three = 3;
	int *ptr_one = NULL;
	int *ptr_two = NULL;
	int *ptr_three = NULL;
	int *ptr_four = NULL;
	vsa_t *memory_ptr = NULL;
	int debug_flag = 1;
	
	memory_ptr = VSAInit(memory, (8*8));
	
	#ifndef NDEBUG
	debug_flag = 0;
	#endif
	
	#ifndef NDEBUG
	assert(40 == VSALargestChunk(memory_ptr));
	#endif
	if (0 != debug_flag)
	{
		printf("%lu", VSALargestChunk(memory_ptr));
		Expect(48 == VSALargestChunk(memory_ptr))
	}
	
	ptr_one = VSAAlloc(memory_ptr, sizeof(int));
	*ptr_one = one;
	
	#ifndef NDEBUG
	assert(16 == VSALargestChunk(memory_ptr));
	#endif
	if (0 != debug_flag)
	{
		Expect(32 == VSALargestChunk(memory_ptr))
	}
	
	ptr_two = VSAAlloc(memory_ptr, sizeof(int));
	*ptr_two = two;
	if (0 != debug_flag)
	{
		Expect(16 == VSALargestChunk(memory_ptr))
	}
	
	#ifndef NDEBUG
	ptr_three = VSAAlloc(memory_ptr, sizeof(int));
	assert (NULL == ptr_three);
	
	assert(1 == *ptr_one);
	assert(2 == *ptr_two);

	free(memory); memory = NULL;
	return 0;
	#endif
	
	Expect(1 == *ptr_one)
	Expect(2 == *ptr_two)
	
	ptr_three = VSAAlloc(memory_ptr, sizeof(int));
	*ptr_three = three;
	
	Expect(3 == *ptr_three)

	ptr_four = VSAAlloc(memory_ptr, sizeof(int));
	
	Expect(NULL == ptr_four)
	
	free(memory); memory = NULL;
	return 0;
}


int AllocFree()
{
	int *memory = (int *)malloc(148);
	int one = 1;
	char two = 2;
	char string[] = "Hello";
	int four = 4;
	int *ptr_one = NULL;
	char *ptr_two = NULL;
	int *ptr_hello = NULL;
	int *ptr_four = NULL;
	int *ptr_five = NULL;
	vsa_t *memory_ptr = NULL;
	int debug_flag = 1;
	
	memory_ptr = VSAInit(memory, (148));
	
	#ifndef NDEBUG
	debug_flag = 0;
	#endif
		
	#ifndef NDEBUG
	assert(120 == VSALargestChunk(memory_ptr));
	#endif
	if (0 != debug_flag)
	{
		Expect(128 == VSALargestChunk(memory_ptr))
	}
	
	ptr_one = VSAAlloc(memory_ptr, sizeof(int));
	*ptr_one = one;
	#ifndef NDEBUG
	assert(96 == VSALargestChunk(memory_ptr));
	#endif
	if (0 != debug_flag)
	{
		Expect(112 == VSALargestChunk(memory_ptr))
	}
	
	ptr_two = VSAAlloc(memory_ptr, sizeof(char));
	*ptr_two = two;
	#ifndef NDEBUG
	assert(72 == VSALargestChunk(memory_ptr));
	#endif
	if (0 != debug_flag)
	{
		Expect(96 == VSALargestChunk(memory_ptr))
	}
	
	ptr_hello = VSAAlloc(memory_ptr, 10);
	strcpy((char *)ptr_hello, string);
	#ifndef NDEBUG
	assert(40 == VSALargestChunk(memory_ptr));
	#endif
	if (0 != debug_flag)
	{
		Expect(72 == VSALargestChunk(memory_ptr))
	}
	
	ptr_four = VSAAlloc(memory_ptr, sizeof(int));
	*ptr_four = four;
	
	#ifndef NDEBUG
	assert(16 == VSALargestChunk(memory_ptr));
	#endif
	if (0 != debug_flag)
	{
		Expect(56 == VSALargestChunk(memory_ptr))
	}
	
	ptr_five = VSAAlloc(memory_ptr, 17);
	if (0 != debug_flag)
	{
		Expect(24 == VSALargestChunk(memory_ptr))
	}
	
	#ifndef NDEBUG
	assert(NULL == ptr_five);
	#endif
	
	VSAFree(ptr_two);
	VSAFree(ptr_one);
	
	#ifndef NDEBUG
	assert(32 == VSALargestChunk(memory_ptr));
	#endif
	
	if (0 != debug_flag)
	{
		Expect(32 == VSALargestChunk(memory_ptr))
	}
	ptr_two = VSAAlloc(memory_ptr, sizeof(char));
	*ptr_two = two;
	
	#ifndef NDEBUG
	assert(16 == VSALargestChunk(memory_ptr));
	#endif
	if (0 != debug_flag)
	{
		Expect(16 == VSALargestChunk(memory_ptr))
	}
	free(memory); memory = NULL;
	return 0;
}

int AllocFreeValue()
{
	int *memory = (int *)malloc(148);
	int one = 1;
	char two = 2;
	char string[] = "Hello ^_^";
	char *str_cmp = "Hello ^_^";
	int four = 4;
	int *ptr_one = NULL;
	char *ptr_two = NULL;
	int *ptr_hello = NULL;
	int *ptr_four = NULL;
	int *ptr_five = NULL;
	vsa_t *memory_ptr = NULL;
	
	memory_ptr = VSAInit(memory, (148));

	ptr_one = VSAAlloc(memory_ptr, sizeof(int));
	*ptr_one = one;
	
	ptr_two = VSAAlloc(memory_ptr, sizeof(char));
	*ptr_two = two;
	
	ptr_hello = VSAAlloc(memory_ptr, 10);
	strcpy((char *)ptr_hello, string);
	
	ptr_four = VSAAlloc(memory_ptr, sizeof(int));
	*ptr_four = four;
	
	Expect(1 == *ptr_one)
	
	Expect(2 == *ptr_two)

	Expect(0 == strcmp(str_cmp, (char *)ptr_hello))
	
	
	VSAFree(ptr_two);
	VSAFree(ptr_one);
	
	ptr_two = VSAAlloc(memory_ptr, sizeof(char));
	*ptr_two = four;
	
	Expect(4 == *ptr_two)
	
	free(memory); memory = NULL;
	return 0;
}
