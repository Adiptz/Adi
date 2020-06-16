#include <stdio.h> /* printf */
#include <assert.h> /* assert */

#include "bst.h"


#include "queue.h"

#define UNUSED(x) (void)(x) 


int Cmp(void *iter_data, void *new_data, void *param)
{
	UNUSED(param);
	return (*(int *)iter_data - *(int *)new_data);
}

int PrintData(void *iter_data, void *param)
{
	UNUSED(param);
	printf("%d", *(int *)iter_data);
	
	return 0;
}

void CreateDestroy_test()
{
	bst_t *test = BSTCreate(Cmp, NULL);
	
	BSTDestroy(test);
}


void Remove_Begin_Iter_test()
{
	int n1 = 1, n2 = 2, n3 = 3;

	bst_t *test = BSTCreate(Cmp, NULL);
	
	bst_iter_t first = NULL;
	bst_iter_t second = NULL;
	bst_iter_t third = NULL;
	
	UNUSED(first);
	
	assert(NULL != test);
	
	first = BSTInsert(test, &n3);   
	second = BSTInsert(test, &n1);     
	third = BSTInsert(test, &n2);
	
	/* remove begin */
	BSTRemove(BSTBegin(test));
	assert(2 == *(int *)BSTGetData(BSTBegin(test)));
	
	BSTRemove(BSTBegin(test));
	assert(3 == *(int *)BSTGetData(BSTBegin(test)));

	BSTRemove(BSTBegin(test));
	assert (1 == BSTIsEmpty(test));
	
	BSTDestroy(test);
}

void Remove_Iter_With_Two_children_test()
{
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;

	bst_t *test = BSTCreate(Cmp, NULL);
	
	bst_iter_t first = NULL;
	bst_iter_t second = NULL;
	bst_iter_t third = NULL;
	bst_iter_t fourth = NULL;
	bst_iter_t fifth = NULL;
	
	assert(NULL != test);
	
	UNUSED(second);
	UNUSED(third);
	UNUSED(fourth);
	UNUSED(fifth);
				
	first = BSTInsert(test, &n2);   
	second = BSTInsert(test, &n1);     
	third = BSTInsert(test, &n4);
	fourth = BSTInsert(test, &n3);
	fifth = BSTInsert(test, &n5);
	
	BSTRemove(first);
	assert(1 == *(int *)BSTGetData(BSTBegin(test)));
	
	BSTRemove((BSTBegin(test)));
	assert(3 == *(int *)BSTGetData(BSTBegin(test)));
	
	BSTDestroy(test);
}


void Insert_test()
{
	int n1 = 1, n2 = 2, n3 = 3;

	bst_t *test = BSTCreate(Cmp, NULL);
	
	bst_iter_t first = NULL;
	bst_iter_t second = NULL;
	bst_iter_t third = NULL;
	
	assert(NULL != test);
	
	UNUSED(second);
	UNUSED(third);
	
	first = BSTInsert(test, &n2);   
	second = BSTInsert(test, &n1);     
	third = BSTInsert(test, &n3);
	
	assert(2 == *(int *)BSTGetData(first));
	assert(1 == *(int *)(BSTGetData(BSTBegin(test))));
	
	BSTDestroy(test);
}

void BeginEnd_test()
{
	int n0 = -2, n1 = 1, n2 = 2, n3 = 3; 

	bst_t *test = BSTCreate(Cmp, NULL);
	
	bst_iter_t first = NULL;
	bst_iter_t second = NULL;
	bst_iter_t third = NULL;
	bst_iter_t fourth = NULL;

	assert(NULL != test);
	assert(NULL == (BSTGetData(BSTEnd(test))));
	
	UNUSED(third);
	
	first = BSTInsert(test, &n2);	   
	assert(first == BSTBegin(test));
	
	second = BSTInsert(test, &n1); 	  
	third = BSTInsert(test, &n3);
	assert(second == BSTBegin(test));
	
	fourth = BSTInsert(test, &n0);
	assert(fourth == BSTBegin(test));
	
	assert(NULL == (BSTGetData(BSTEnd(test))));
	
	BSTDestroy(test);
}

void NextPrev_test()
{
	int n1 = 1, n2 = 2, n3 = 3;  

	bst_t *test = BSTCreate(Cmp, NULL);
	
	bst_iter_t first = NULL;
	bst_iter_t second = NULL;
	bst_iter_t third = NULL;
	
	assert(NULL != test);
	
	first = BSTInsert(test, &n2);	  
	second = BSTInsert(test, &n1);     
	third = BSTInsert(test, &n3);
	
	assert(first == BSTNext(second));
	assert(first == BSTPrev(third));
	
	/* check if next after max is dummy */
	assert(BSTIsSameIter(BSTNext(third),(BSTEnd(test))));
	
	/* check if prev to dummy its max */
	assert(BSTIsSameIter(third, BSTPrev(BSTEnd(test))));
	
	BSTDestroy(test);
}

void Size_test()
{
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;  

	bst_t *test = BSTCreate(Cmp, NULL);
	
	bst_iter_t first = NULL;
	bst_iter_t second = NULL;
	bst_iter_t third = NULL;
	bst_iter_t fourth = NULL;
	
	assert(NULL != test);
	
	UNUSED(n5);
	UNUSED(first);
	UNUSED(third);
	UNUSED(fourth);
	
	first = BSTInsert(test, &n2);   
	assert(1 == BSTSize(test)); 
	
	second = BSTInsert(test, &n1);     
	assert(2 == BSTSize(test));  
	
	third = BSTInsert(test, &n3);
	assert(3 == BSTSize(test));
	
	fourth = BSTInsert(test, &n4);
	assert(4 == BSTSize(test));
	
	BSTRemove(second);
	assert(3 == BSTSize(test));
	
	assert(NULL == BSTFind(test, &n1));
	
	BSTDestroy(test);
}

void Find_test()
{
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;  

	bst_t *test = BSTCreate(Cmp, NULL);
	
	bst_iter_t first = NULL;
	bst_iter_t second = NULL;
	bst_iter_t third = NULL;
	bst_iter_t fourth = NULL;
	
	assert(NULL != test);
	
	UNUSED(fourth);
	
	first = BSTInsert(test, &n2);   
	second = BSTInsert(test, &n1);     
	third = BSTInsert(test, &n3);
	fourth = BSTInsert(test, &n4);
	
	assert(1 == BSTIsSameIter(second, BSTFind(test, &n1)));
	assert(1 == BSTIsSameIter(first, BSTFind(test, &n2)));
	assert(1 == BSTIsSameIter(third, BSTFind(test, &n3)));
	assert(NULL == BSTFind(test, &n5));
	
	BSTDestroy(test);
}


void ForEach_test()
{
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4;  

	bst_t *test = BSTCreate(Cmp, NULL);
	
	bst_iter_t first = NULL;
	bst_iter_t second = NULL;
	bst_iter_t third = NULL;
	bst_iter_t fourth = NULL;		
	
	first = BSTInsert(test, &n2);	  
	second = BSTInsert(test, &n1);     
	third = BSTInsert(test, &n3);
	fourth = BSTInsert(test, &n4);
	
	assert(first == BSTNext(second));
	assert(third == BSTNext(first));
	
	UNUSED(fourth);
	
	assert(4 == BSTSize(test));	   
	assert(NULL != test);
	
	printf("123 : ");
	BSTForEach(NULL, BSTBegin(test), BSTPrev(BSTEnd(test)), PrintData);

	printf("\n1234 :");
	BSTForEach(NULL, BSTBegin(test), BSTEnd(test), PrintData);
	
	BSTDestroy(test);
}

void PrintLevels_test()
{
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;

	bst_t *test = BSTCreate(Cmp, NULL);
	
	bst_iter_t first = NULL;
	bst_iter_t second = NULL;
	bst_iter_t third = NULL;
	bst_iter_t fourth = NULL;
	bst_iter_t fifth = NULL;
	
	assert(NULL != test);
	
	UNUSED(second);
	UNUSED(third);
	UNUSED(fourth);
	UNUSED(fifth);
				
	first = BSTInsert(test, &n2);   
	second = BSTInsert(test, &n1);     
	third = BSTInsert(test, &n4);
	fourth = BSTInsert(test, &n3);
	fifth = BSTInsert(test, &n5);
	
	assert(5 == BSTSize(test));
	
	PrintTreeByLevels(test);
	
	BSTDestroy(test);
}

int main()
{
	CreateDestroy_test();
	Remove_Begin_Iter_test();
	Remove_Iter_With_Two_children_test();
	Insert_test();
	BeginEnd_test();
	NextPrev_test();
	Size_test();
	Find_test();
	ForEach_test();
	puts("");
	PrintLevels_test();
	printf("\nVOVA THE QUEEN\n");
	
	return 0;
}	

