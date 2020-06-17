

#include <stdio.h>
#include <assert.h>

#include "pqueue.h"

#define UNUSED(x) (void)(x)

static int IsBefore(void *data1, void *data2, const void *param)
{
	UNUSED(param);
	
	return *(int *)data1 <= *(int *)data2;
}	

static int IsMatch(void *data1, const void *data2, void *param)
{
	UNUSED(param);

	return (*(int *)data1 == *(int *)data2);
}



void CreateDestroy_test()
{
	pqueue_t *test = PQueueCreate(IsBefore, NULL);
	
	assert(0 == PQueueSize(test));
	assert(1 == PQueueIsEmpty(test));
	
	PQueueDestroy(test);
}

void EnqueueDequeue_test()
{	
	pqueue_t *test = PQueueCreate(IsBefore, NULL);
	int n1 = 5;
	
	assert(0 == PQueueSize(test));
	
	PQueueEnqueue(test, &n1); 
	assert(n1 == *(int *)PQueuePeek(test));
	assert(1 == PQueueSize(test));
	assert(0 == PQueueIsEmpty(test));
	
	PQueueDequeue(test);
	assert(0 == PQueueSize(test));
	assert(1 == PQueueIsEmpty(test));
		
	PQueueDestroy(test);
}

void Peek_test()
{
	pqueue_t *test = PQueueCreate(IsBefore, NULL);
	int n1 = 1, n2 = 2, n3 = 3;
	
	PQueueEnqueue(test, &n2); 
	PQueueEnqueue(test, &n1); 
	PQueueEnqueue(test, &n3);
	
	assert(n1 == *(int *)PQueuePeek(test));
	
	PQueueDestroy(test); 
}

void Erase_test()
{
	pqueue_t *test = PQueueCreate(IsBefore, NULL);
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5, n6 = 9;
	
	assert(0 == PQueueSize(test));
	
	PQueueEnqueue(test, &n2); 
	PQueueEnqueue(test, &n1); 
	PQueueEnqueue(test, &n3);
	PQueueEnqueue(test, &n5); 
	PQueueEnqueue(test, &n4); 
	
	assert(5 == PQueueSize(test));
	
	assert(n3 == *(int *)PQueueErase(test, IsMatch, &n3, NULL));
	assert(NULL == PQueueErase(test, IsMatch, &n6, NULL));
	assert(n1 == *(int *)PQueuePeek(test));
	assert(4 == PQueueSize(test));
	
	PQueueDestroy(test); 
}

void Clear_test()
{
	pqueue_t *test = PQueueCreate(IsBefore, NULL);
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;
	
	assert(0 == PQueueSize(test));
	
	PQueueEnqueue(test, &n2); 
	PQueueEnqueue(test, &n1); 
	PQueueEnqueue(test, &n3);
	PQueueEnqueue(test, &n5); 
	PQueueEnqueue(test, &n4); 
	
	assert(5 == PQueueSize(test));
	
	PQueueClear(test);
	assert(0 == PQueueSize(test));
	
	PQueueDestroy(test); 
}

int main()
{
	CreateDestroy_test();
	EnqueueDequeue_test();
	Peek_test();
	Erase_test();
	Clear_test();
	
	puts("\n Test Done \n");

	return 0;
}
