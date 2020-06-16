#include <assert.h> /* assert */ 
#include "dlist.h"


void IsEmpty_test()
{
	dlist_t *test = DListCreate();
	int i = 5;
	
	assert(1 == DListIsEmpty(test));
	
	DListInsert(test, DListEnd(test), &i);
	
	assert(0 == DListIsEmpty(test));
	
	DListDestroy(test);
}

void Insert_test()
{
	dlist_t *test = DListCreate();
	int i = 5;
	int j = 9;
	
	/* insert i */
	DListInsert(test, DListEnd(test), &i);
	assert(5 == (*(int *)DListIterGetData(DListBack(DListEnd(test))))); 
	
	/* insert j */
	DListInsert(test, DListBegin(test), &j);
	assert(9 == (*(int *)DListIterGetData(DListBegin(test))));
	
	DListDestroy(test);
}

void Remove_test()
{
	dlist_t *test = DListCreate();
	
	int i = 5;
	
	assert(1 == DListIsEmpty(test));
	
	DListInsert(test, DListEnd(test), &i);
	
	assert(0 == DListIsEmpty(test));
	
	DListRemove(DListBegin(test));
	
	assert(1 == DListIsEmpty(test));
		
	DListDestroy(test);
}

void Size_test()
{
	dlist_t *test = DListCreate();
	int i = 5;
	int j = 9;
	
	assert(0 == DListSize(test));
	/* insert i */
	DListInsert(test, DListEnd(test), &i);
	assert(1 == DListSize(test));
	
	/* insert j */
	DListInsert(test, DListEnd(test), &j);
	assert(2 == DListSize(test));
	
	DListDestroy(test);
}

/* help function for ForEach testing */
int AddIntFunc(void *data, void *param_data)
{
	*(int *)data += *(int *)param_data;
	
	return 0;
}

void ForEach_test()
{
	dlist_t *test = DListCreate();
	int i = 5;
	int j = 9;
	int k = 3;
	void *param = &k;

	
	/* insert i */
	dlist_iter_t from = DListInsert(test, DListEnd(test), &i);
	
	/* insert j */
	dlist_iter_t to = DListInsert(test, DListEnd(test), &j);
	
	DListForEach(from, to, AddIntFunc, param);
				
	assert(8 == (*(int *)DListIterGetData(DListBegin(test)))); 
	 											  	
	DListDestroy(test);
}

int CmpIntFunc(void *data, const void *param)
{
	return !(*(int *)data == *(int *)param);
}

void Find_test()
{
	dlist_t *test = DListCreate();
	dlist_iter_t data2_found = NULL;
	
	int i = 5;
	int j = 9;
	int k = 3;
	
	int data1 = 6;
	int data2 = 9;
	 
	/* insert i,j,k to DLL */
	DListInsert(test, DListEnd(test), &i);
	data2_found = DListInsert(test, DListEnd(test), &j);
	DListInsert(test, DListEnd(test), &k);
	
	assert(DListIsSameIter
		  (DListEnd(test),
		  (DListFind(DListBegin(test), DListEnd(test), CmpIntFunc, &data1))));
		   
	assert(DListIsSameIter
		  (data2_found,
		  (DListFind(DListBegin(test), DListEnd(test), CmpIntFunc, &data2))));
		  
	DListDestroy(test);
}

void PushFront_test()
{
	dlist_t *test = DListCreate();
	
	int i = 5;
	int j = 9;
	int k = 3;	 
	
	DListInsert(test, DListEnd(test), &i);
	DListInsert(test, DListEnd(test), &j);
		
	DListPushFront(test, &k);
	
	assert(3 == *(int *)(DListIterGetData(DListBegin(test))));

	DListDestroy(test);
}

void PopFront_test()
{
	dlist_t *test = DListCreate();
	int i = 5;
	int j = 9;
	 
	DListInsert(test, DListEnd(test), &i);
	DListInsert(test, DListEnd(test), &j);
	
	assert(5 == *(int *)DListIterGetData(DListBegin(test))); 
	
	assert(5 == *(int *)DListPopFront(test));

	assert(9 == *(int *)DListIterGetData(DListBegin(test))); 
	
	DListDestroy(test);
}

void PushBack_test()
{
	dlist_t *test = DListCreate();

	int i = 5;
	int j = 9;
	int k = 3;	 
	
	DListInsert(test, DListEnd(test), &i);
	DListInsert(test, DListEnd(test), &j);
		
	DListPushBack(test, &k);
	
	assert(3 == *(int *)DListIterGetData(DListBack(DListEnd(test)))); 

	DListDestroy(test);
}

void PopBack_test()
{
	dlist_t *test = DListCreate();

	int i = 5;
	int j = 9;
	int k = 3;	
	
	DListInsert(test, DListEnd(test), &i);
	DListInsert(test, DListEnd(test), &j);
	DListInsert(test, DListEnd(test), &k);
	
	assert(3 == *(int *)DListPopBack(test));

	DListDestroy(test);
}

void Next_test()
{
	dlist_t *test = DListCreate();
	dlist_iter_t current = NULL;
	
	int i = 5;
	int j = 9;
	int k = 3;	
	
	current = DListInsert(test, DListEnd(test), &i);
	DListInsert(test, DListEnd(test), &j);
	DListInsert(test, DListEnd(test), &k);
	
	assert(9 == *(int *)DListIterGetData(DListNext(current)));
	
	DListDestroy(test);
}

void Back_test()
{
	dlist_t *test = DListCreate();
	dlist_iter_t current = NULL;

	int i = 5;
	int j = 9;
	int k = 3;	
	
	DListInsert(test, DListEnd(test), &i);
	current = DListInsert(test, DListEnd(test), &j);
	DListInsert(test, DListEnd(test), &k);
	
	assert(i == *(int *)DListIterGetData(DListBack(current)));
	
	DListDestroy(test);
}

void Splice_test()
{
	dlist_iter_t dest = NULL;
	dlist_iter_t src_start = NULL;
	dlist_iter_t src_end = NULL;
	
	dlist_t *list1 = DListCreate();
	dlist_t *list2 = DListCreate();
	
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5, n6 = 6;
	
	/*fill list1 with 1-2-3 */
	dest = DListInsert(list1, DListEnd(list1), &n1);
	DListInsert(list1, DListEnd(list1), &n2);
	DListInsert(list1, DListEnd(list1), &n3);
	assert(3 == DListSize(list1));
	
	/*fill list2 with 4-5-6 */
	src_start = DListInsert(list2, DListEnd(list2), &n4);
	DListInsert(list2, DListEnd(list2), &n5);
	DListInsert(list2, DListEnd(list2), &n6);
	assert(3 == DListSize(list2));
	
	src_end = DListEnd(list2);
	
	DListSplice(dest, src_start, src_end);
	
	assert(6 == DListSize(list1));
	assert(1 == DListIsEmpty(list2));
	
	assert(n4 == *(int *)DListIterGetData(DListBegin(list1)));
	DListPopFront(list1);
	assert(n5 == *(int *)DListIterGetData(DListBegin(list1)));
	DListPopFront(list1);
	assert(n6 == *(int *)DListIterGetData(DListBegin(list1)));
	DListPopFront(list1);
	assert(n1 == *(int *)DListIterGetData(DListBegin(list1)));
	
	DListDestroy(list1);
	DListDestroy(list2);

}


int main()
{
	IsEmpty_test();
	Insert_test();
	Remove_test();
	Size_test();
	ForEach_test();
	Find_test();
	PushFront_test();
	PopFront_test();
	PushBack_test();
	PopBack_test();
	Splice_test();
	
	Next_test();
	Back_test();

	return 0;
}
