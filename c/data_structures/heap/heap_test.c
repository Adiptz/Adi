#include <assert.h> /* assert */

#include "heap.h"

#define UNUSED(x) ((void)x)

int CmpPriority(const void *data1, const void *data2, void *param)
{
	UNUSED(param);
	
	return (*( int*)data2 - *(int *)data1);	
}

int IsMatch(const void *heap_data, const void *user_data)
{
	return (*(int *)heap_data == *(int *)user_data);
}

heap_t *CreateHeap(void)
{
	heap_t *heap = HeapCreate(CmpPriority, NULL);
	int int_arr[] = {100, 80, 90, 70, 75, 60, 50, 10, 5, 72, 74, 40, 30, 20};
	size_t i = 0;
	static size_t arr_size = 14;
	
	for (i = 0; i < arr_size; ++i)
	{
		assert(0 == HeapPush(heap, &int_arr[i]));	
	}
	
	return heap;
}

static void Create_Destroy_test()
{
	heap_t *new_heap = HeapCreate(CmpPriority, NULL);
	assert(NULL != new_heap);
	
	
	HeapDestroy(new_heap);	
}


static void Push_Pop_test()
{
	heap_t *heap = HeapCreate(CmpPriority, NULL);
	
	int data5 = 5, data10 = 10, data3 = 3;	
	
	HeapPush(heap, &data5);
	assert(1 == HeapSize(heap));
	assert(data5 == *(int *)HeapPeek(heap));
		
	HeapPush(heap, &data10);
	assert(2 == HeapSize(heap));
	assert(data10 ==  *(int *)HeapPeek(heap));
		
	HeapPush(heap, &data3);
	assert(3 == HeapSize(heap));
	assert(data10 == *(int *)HeapPeek(heap));
	
	HeapPop(heap);
	assert(data5 == *(int *)HeapPeek(heap));
		
	HeapPop(heap);
	assert(data3 == *(int *)HeapPeek(heap));
	
	HeapPop(heap);
	assert(0 == HeapSize(heap));
	assert(1 == HeapIsEmpty(heap));
	
	HeapDestroy(heap);
}

static void Remove_test()
{
	heap_t *heap = HeapCreate(CmpPriority, NULL);
	
	int data5 = 5, data10 = 10, data3 = 3, not_find = 4;	
	
	
	HeapPush(heap, &data5);
	assert(1 == HeapSize(heap));
	assert(data5 == *(int *)HeapPeek(heap));
		
	HeapPush(heap, &data10);
	assert(2 == HeapSize(heap));
	assert(data10 == *(int *)HeapPeek(heap));
		
	HeapPush(heap, &data3);
	assert(3 == HeapSize(heap));
	assert(data10 == *(int *)HeapPeek(heap));

	assert(data10 == *(int *)HeapRemove(heap, IsMatch, &data10)); 
	assert(2 == HeapSize(heap));
		
	/* remove not exict data */
	assert(NULL == 	HeapRemove(heap, IsMatch, &not_find));
	assert(data5 == *(int *)HeapPeek(heap));
	assert(2 == HeapSize(heap));

	assert(data5 == *(int *)HeapRemove(heap, IsMatch, &data5)); 
	assert(data3 == *(int *)HeapPeek(heap));
	
	HeapDestroy(heap);
}


static void Flow1()
{
	size_t i = 0;
	
	heap_t *heap = CreateHeap();
	
	assert(14 == HeapSize(heap));
	assert(0 == HeapIsEmpty(heap));
}

static void HeapSort()
{	
	heap_t *heap = HeapCreate(CmpPriority, NULL);
	int int_arr[] = {86, 45, 52, 97, 60, 24, 38, 12, 7, 76};
	size_t arr_length = 10; 
	size_t i = 0;
	
	for (i = 0; i < arr_length; ++i)
	{
		assert(0 == HeapPush(heap, &int_arr[i]));
		assert(i + 1 == HeapSize(heap));
	}	
	
	for (i = 0; i < arr_length; ++i)
	{
		void *max_value = HeapPeek(heap);
		int_arr[i] = *(int *)max_value;
		HeapPop(heap);
	}
	
	for (i = 0; i < arr_length; ++i)
	{
		printf("%d\n", int_arr[i]);	
	}
}

int main()
{
	Create_Destroy_test();
	Push_Pop_test();
	Remove_test();
	HeapSort();
	
	return 0;
}
