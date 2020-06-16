#include <stdio.h>
#include <assert.h>
#include "vector.h"
/******************************************************************************/
struct vector
{
	void *base;
	void *current;
	size_t capacity;
	size_t size_of_element;
};
/******************* -- TEST -- ******************/
int main()
{
	int first = 1;
	int second = 8;
	
	
	/* create vector */
	vector_t *vector_test = VectorCreate(2,4);
	assert(NULL != vector_test);
	if (2 != VectorCapacity(vector_test))
	{
		puts("Capacity Error !"); 	
	}
	
	if(0 != VectorSize(vector_test))
	{
		puts("Size Error");
	}
	
	if(1 != VectorIsEmpty(vector_test))
	{
		puts("Error Is Empty");
	}
	
	/* push 1st element*/
	puts("\nPUSH ELEMENT 1");
	VectorPushBack(vector_test, &first);
	if(vector_test->base != VectorGetItemAddress(vector_test, 0))
	{
		puts("Error on address you pushed value to");
	}
	
	if(1 != *(int *)vector_test->base)
	{
		puts("Error Pushing Value");
	}
	
	if(2 != VectorCapacity(vector_test))
	{
		puts("Capacity Error !"); 	
	}
	
	if(1 != VectorSize(vector_test))
	{
		puts("Size Error");
	}
	
	if(0 != VectorIsEmpty(vector_test))
	{
		puts("Error Is Empty");
	}

	/* push 2nd element - full capacity */
	puts("\nPUSH ELEMENT 2 - FULL CAPACITY");
	VectorPushBack(vector_test, &second);
	if((char *)vector_test->base + 4 != VectorGetItemAddress(vector_test, 1))
	{
		puts("Error on GetItemAddress - after push!");
	}
	
	if(8 != *(int *)VectorGetItemAddress(vector_test, 1))
	{
		puts("Error Pushing Value");
	}
	
	if(2 != VectorCapacity(vector_test))
	{
		puts("Capacity Error !"); 	
	}
	
	if(2 != VectorSize(vector_test))
	{
		puts("Size Error");
	}
	
	if(0 != VectorIsEmpty(vector_test))
	{
		puts("Error Is Empty");
	}
	
	
	puts("\nPOP ELEMENT 2");
	VectorPopBack(vector_test);
	
	
	if(2 != VectorCapacity(vector_test))
	{
		puts("Error when size is 1/4 of capacity");
	}
	
	if(1 != VectorSize(vector_test))
	{
		puts("Size Error");
	}
	
	puts("\nVector RESERVE + 5");
	VectorReserve(vector_test, 5);
	if(7 != VectorCapacity(vector_test))
	{
		puts("Capacity Error after Reserve !"); 
	}
	
	puts("\nPOP ELEMENT 1");
	VectorPopBack(vector_test);

	if(3 != VectorCapacity(vector_test))
	{
		puts("Error when size is 1/4 of capacity");
	}
	
	if(0 != VectorSize(vector_test))
	{
		puts("Size Error");
	}
	
	if(1 !=  VectorIsEmpty(vector_test))
	{
		puts("Error Is Empty");
	}
	
	VectorDestroy(vector_test);

	return 0;
}
