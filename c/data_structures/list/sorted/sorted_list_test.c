#include "../dlist/dlist.h" /* dlist_iter_t */
#include "sorted_list.h"
#include <assert.h>



#define UNUSED(x) (void)(x)

int IsBeforeInt(void *data1, void *data2, const void *param)
{
	int n1 = 0;
	int n2 = *(int *)data2;
	UNUSED(param);
	
	if(data1 == NULL)
	{
		return 0;
	}

	n1 = *(int *)data1;
	n2 = *(int *)data2;

	if(n1 <= n2)
	{
		return 1;
	}
	
	return 0;
}

/* help function for ForEach testing */
int AddInt(void *data, void *param_data)
{
	*(int *)data += *(int *)param_data;
	
	return 0;
}


int CmpInt(void *data, const void *param, void *param1)
{
	return (*(int *)data == *(int *)param);
}

/******************************** -- TESTS -- *********************************/
void CreateDestroy_test()
{
	sorted_list_t *test = SortedListCreate(IsBeforeInt, NULL);
	/*sorted_list_iter_t begin = SortedListBegin(test);
	sorted_list_iter_t end = SortedListEnd(test);*/
	
	assert(SortedListIsEmpty(test));
	assert(SortedListBegin(test).diter == SortedListEnd(test).diter);
	
	SortedListDestroy(test);
}

void Insert_test()
{
	sorted_list_t *test = SortedListCreate(IsBeforeInt, NULL);
	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	
	sorted_list_iter_t begin = {NULL};
	sorted_list_iter_t iter1 = {NULL};
	
	SortedListInsert(test, &n2);
	SortedListInsert(test, &n3);
	iter1 = SortedListInsert(test, &n1);

	begin = SortedListBegin(test);	
	assert(iter1.diter == begin.diter);

	SortedListDestroy(test);
}

void NextPrev_test()
{
	sorted_list_iter_t begin = {NULL};
	sorted_list_iter_t next = {NULL};
	sorted_list_iter_t prev = {NULL};
	

	sorted_list_iter_t iter2 = {NULL};

	sorted_list_t *test = SortedListCreate(IsBeforeInt, NULL);
	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	
	
	 SortedListInsert(test, &n1);
	iter2 = SortedListInsert(test, &n2);
	SortedListInsert(test, &n3);

	begin = SortedListBegin(test);
	next = SortedListNext(begin);
	assert(iter2.diter == next.diter);
	
	prev = SortedListPrev(next);
	assert(begin.diter == prev.diter);
		
	SortedListDestroy(test);	
}

void GetData_test()
{
	sorted_list_iter_t iter1 = {NULL};
	
	sorted_list_t *test = SortedListCreate(IsBeforeInt, NULL);
	int n1 = 1;
	
	iter1 = SortedListInsert(test, &n1);
	assert(*(int *)SortedListGetData(iter1) == n1);
	
	SortedListDestroy(test);	
}


void Size_IsEmpty_test()
{
	sorted_list_t *test = SortedListCreate(IsBeforeInt, NULL);
	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	
	/* empty list */
	assert(0 == SortedListSize(test));
	assert(SortedListIsEmpty(test));
	
	/* insert iters */
	SortedListInsert(test, &n1);
	assert(1 == SortedListSize(test));
	assert(0 == SortedListIsEmpty(test));
	
	SortedListInsert(test, &n2);
	SortedListInsert(test, &n3);
	assert(3 == SortedListSize(test));
	
	/* remove all iters*/
	SortedListRemove(SortedListBegin(test));
	SortedListRemove(SortedListBegin(test));
	SortedListRemove(SortedListBegin(test));
	assert(SortedListIsEmpty(test));
	
	SortedListDestroy(test);
}

void PopFrontBack_test()
{
	sorted_list_t *test = SortedListCreate(IsBeforeInt, NULL);
	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	

	sorted_list_iter_t iter1 = {NULL};
	sorted_list_iter_t iter2 = {NULL};
	
	iter2 = SortedListInsert(test, &n2);
	SortedListInsert(test, &n3);
	iter1 = SortedListInsert(test, &n1);

		
	assert(iter1.diter == SortedListBegin(test).diter);

	SortedListPopFront(test);
	assert(iter2.diter == SortedListBegin(test).diter);
			
	assert(3 == *(int *)SortedListPopBack(test));
	
	SortedListDestroy(test);
}

void ForEach_test()
{
	sorted_list_t *test = SortedListCreate(IsBeforeInt, NULL);
	sorted_list_iter_t begin = {NULL};
	sorted_list_iter_t end = {NULL};
	
	
	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	void *param = &n3;
	
	assert(NULL != test);
	
	SortedListInsert(test, &n2);
	SortedListInsert(test, &n3);
	SortedListInsert(test, &n1);

	end = SortedListEnd(test);
	begin = SortedListBegin(test);
	
	assert(*(int *)SortedListGetData(begin) == n1);  
	assert(0 == SortedListForEach(begin, end, AddInt, param));
	assert(*(int *)SortedListGetData(begin) == 4);
	assert(*(int *)SortedListGetData(SortedListPrev(end)) == 6); 					
	  											  	
	SortedListDestroy(test);
}

void Find_test()
{
	/* Test setup */
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, fail = 5;
		sorted_list_t *test = SortedListCreate(IsBeforeInt, NULL);
		sorted_list_iter_t begin = {NULL};
		sorted_list_iter_t end = {NULL};
		sorted_list_iter_t iter = {NULL};
	
		SortedListInsert(test, &n4);	
		SortedListInsert(test, &n2);
		SortedListInsert(test, &n3);
		SortedListInsert(test, &n1);

	/* SortedListFind test start */
	begin = SortedListBegin(test);
	end = SortedListEnd(test);

	iter = SortedListFind(test, begin, SortedListPrev(end), &n1);
	assert(n1 == *(int *)SortedListGetData(iter));

	iter = SortedListFind(test, begin, end, &n3);
	assert(n3 == *(int *)SortedListGetData(iter));
	
	iter = SortedListFind(test, begin, SortedListPrev(end), &fail);
	assert(n4 == *(int *)SortedListGetData(iter));
	SortedListDestroy(test);
}





void FindIf_test()
{
	sorted_list_t *test = SortedListCreate(IsBeforeInt, NULL);
	sorted_list_iter_t end = {NULL};
	
	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	const void *data = &n3;
	
	assert(NULL != test);
	
	SortedListInsert(test, &n1);
	SortedListInsert(test, &n2);
	SortedListInsert(test, &n3);
	
	end = SortedListEnd(test);

	assert(SortedListIsSameIter(SortedListPrev(end),
	SortedListFindIf(SortedListBegin(test), SortedListEnd(test), CmpInt, data, NULL)));
	
	SortedListDestroy(test);
}

void IsSame_test()
{
	sorted_list_t *test = SortedListCreate(IsBeforeInt, NULL);
	int n1 = 1;
	int n2 = 2;

	sorted_list_iter_t begin = {NULL};
	sorted_list_iter_t iter1 = {NULL};
	sorted_list_iter_t iter2 = {NULL};

	iter1 = SortedListInsert(test, &n1);
	iter2 = SortedListInsert(test, &n2);

	begin = SortedListBegin(test);	
	assert(1 == SortedListIsSameIter(begin, iter1));
	
	begin = SortedListNext(begin);
	assert(1 == SortedListIsSameIter(begin, iter2));
	
	SortedListDestroy(test);
}

static sorted_list_t *FourElement_list()
{
	int param = 0;
	static int data1 = -1, data2 = 5, data3 = 9, data4 = 10; 

	sorted_list_t *list = SortedListCreate(IsBeforeInt, &param);
	assert(NULL != list);
	
	SortedListInsert(list, &data1);
	SortedListInsert(list, &data2);
	SortedListInsert(list, &data3);
	SortedListInsert(list, &data4);
	
	assert(0 == SortedListIsEmpty(list));
	assert(4 == SortedListSize(list));
	
	return list;
}

/**************************    Create 5 elem list  ****************************/
static sorted_list_t *FiveElement_list()
{
	int param = 0;
	static int data1 = 8, data2 = 4, data3 = 6, data4 = 0, data5 = 2; 

	sorted_list_t *list = SortedListCreate(IsBeforeInt, &param);
	assert(NULL != list);
	
	SortedListInsert(list, &data1);
	SortedListInsert(list, &data2);
	SortedListInsert(list, &data3);
	SortedListInsert(list, &data4);
	SortedListInsert(list, &data5);
	
	assert(0 == SortedListIsEmpty(list));
	assert(5 == SortedListSize(list));
	
	return list;
}

void Merge_test()
{
	sorted_list_t *five_elem_list = FiveElement_list(); /*dest*/
	sorted_list_t *four_elem_list = FourElement_list(); /*src*/
	
	assert(five_elem_list == SortedListMerge(five_elem_list, four_elem_list));
	
	assert(1 == SortedListIsEmpty(four_elem_list));
	assert(0 == SortedListSize(four_elem_list));
	
	assert(0 == SortedListIsEmpty(five_elem_list));
	assert(9 == SortedListSize(five_elem_list));

	assert(-1 == *(int *)SortedListPopFront(five_elem_list));
	assert(0 == *(int *)SortedListPopFront(five_elem_list));
	assert(2 == *(int *)SortedListPopFront(five_elem_list));
	assert(4 == *(int *)SortedListPopFront(five_elem_list));
	assert(5 == *(int *)SortedListPopFront(five_elem_list));
	assert(6 == *(int *)SortedListPopFront(five_elem_list));
	assert(8 == *(int *)SortedListPopFront(five_elem_list));
	assert(9 == *(int *)SortedListPopFront(five_elem_list));
	assert(10 == *(int *)SortedListPopFront(five_elem_list));
						
	SortedListDestroy(five_elem_list); five_elem_list = NULL;
	SortedListDestroy(four_elem_list); four_elem_list = NULL;
}

int main()
{
	CreateDestroy_test();
	Insert_test();
	NextPrev_test();
	Size_IsEmpty_test();
	PopFrontBack_test();
	GetData_test();
	IsSame_test();
	ForEach_test();
	Find_test();
	Merge_test();
	
	return 0;
}
