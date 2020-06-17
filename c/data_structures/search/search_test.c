#include <stdio.h>
#include <assert.h>

#include "search.h"

#define START_RED printf("\033[1;31m");
#define END_RED printf("\033[0m");
#define TRUE 1
#define FALSE 0

#define PRINT_ERROR START_RED printf("ERROR in %s.\n", func_name); END_RED

#define PREVENT_WARNINGS_FROM_UNUSED_FUNCS_FROM_TESTS_TEMPLATE \
{\
	int a = 1;\
	expect_int(1,1,"hi");\
	expect_size_t(1lu,1lu,"hi");\
	expect_NULL(NULL,"hi");\
	expect_Not_NULL(&a, "hi");\
}

/*************************************************************************
								 										 *
				      GENERAL TEST FUNCTIONS							 *
																		 *
*************************************************************************/
void expect_int(int result, int expected_result, char *func_name)
{
	if (result != expected_result)
	{
		PRINT_ERROR
		printf("Expected: \t%d\nActual: \t%d\n", expected_result, result);
	}	
}

void expect_size_t(size_t result, size_t expected_result, char *func_name)
{
	if (result != expected_result)
	{
		PRINT_ERROR
		printf("Expected: \t%lu\nActual: \t%lu\n", expected_result, result);
	}	
}

void expect_NULL(void *pointer, char *func_name)
{
	if (pointer != NULL)
	{
		PRINT_ERROR
		printf("pointer isn't NULL.\n");
	}	
}

void expect_Not_NULL(void *pointer, char *func_name)
{
	if (pointer == NULL)
	{
		PRINT_ERROR
		printf("pointer isn't NULL.\n");
	}	
}

int IntCmp(const void *data1, const void *data2)
{
	assert (NULL != data1);
	assert (NULL != data2);
	
	return *(int *)data1 - *(int *)data2;
}

/*************************************************************************
								 										 *
				      FORWARD DECLARATIONS								 *
																		 *
*************************************************************************/

void BSearchIterative_test_simple_even();
void BSearchIterative_test_simple_odd();
void BSearchIterative_test_simple_even_not_found();

void BSearchRecursive_test_simple_even();
void BSearchRecursive_test_simple_odd();
void BSearchRecursive_test_simple_even_not_found();

void JumpSearch_test_simple_even();
void JumpSearch_test_simple_odd();
void JumpSearch_test_simple_odd_not_found();

void SingleElement_test();

void SingleValue_test();

int main()
{
	PREVENT_WARNINGS_FROM_UNUSED_FUNCS_FROM_TESTS_TEMPLATE
	
	BSearchIterative_test_simple_even();
	
	BSearchIterative_test_simple_odd();
	
	BSearchIterative_test_simple_even_not_found();	
	
	BSearchRecursive_test_simple_even();

	BSearchRecursive_test_simple_odd();

	BSearchRecursive_test_simple_even_not_found();	
	
	JumpSearch_test_simple_even();
	
	JumpSearch_test_simple_odd();

	JumpSearch_test_simple_odd_not_found();
	
	SingleElement_test();
	
	SingleValue_test();
/*	*/
	return 0;
}

void SingleValue_test()
{
	int arr[] = {7,7,7,7,7,7,7,7,7,7,7,7,7,7};
	
	int key1 = 5;
	int key2 = 7;
	int key3 = 678;
	
	size_t elm_size = sizeof(arr[0]);	
	size_t nitems = sizeof(arr)/sizeof(arr[0]);
	
	int *jump_result = NULL;
	int *recursive_result = NULL;
	int *iterative_result = NULL;
	
	jump_result = JSearch(&key1, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(jump_result, "SingleValue_test_jump_1");
	
	jump_result = JSearch(&key2, arr, nitems, elm_size, IntCmp);
	
	expect_int(*jump_result, key2, "SingleValue_test_jump_2");
	
	jump_result = JSearch(&key3, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(jump_result, "SingleValue_test_jump_3");
	
	recursive_result = BSearchRecursive(&key1, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(recursive_result, "SingleValue_test_BSearchRecursive_1");
	
	recursive_result = BSearchRecursive(&key2, arr, nitems, elm_size, IntCmp);
	
	expect_int(*recursive_result, key2, "SingleValue_test_BSearchRecursive_2");
	
	recursive_result = BSearchRecursive(&key3, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(recursive_result, "SingleValue_BSearchRecursive_jump_3");
	
	iterative_result = BSearchIterative(&key1, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(iterative_result, "SingleValue_test_BSearchIterative_1");
	
	iterative_result = BSearchIterative(&key2, arr, nitems, elm_size, IntCmp);
	
	expect_int(*iterative_result, key2, "SingleValue_test_BSearchIterative_2");
	
	iterative_result = BSearchIterative(&key3, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(iterative_result, "SingleValue_test_BSearchIterative_3");		
}

void SingleElement_test()
{
	int arr[] = {7};
	
	int key1 = 5;
	int key2 = 7;
	int key3 = 678;
	
	size_t elm_size = sizeof(arr[0]);	
	size_t nitems = sizeof(arr)/sizeof(arr[0]);
	
	int *jump_result = NULL;
	int *recursive_result = NULL;
	int *iterative_result = NULL;
	
	jump_result = JSearch(&key1, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(jump_result, "SingleElement_test_jump_1");
	
	jump_result = JSearch(&key2, arr, nitems, elm_size, IntCmp);
	
	expect_int(*jump_result, key2, "SingleElement_test_jump_2");
	
	jump_result = JSearch(&key3, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(jump_result, "SingleElement_test_jump_3");
	
	recursive_result = BSearchRecursive(&key1, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(recursive_result, "SingleElement_test_BSearchRecursive_1");
	
	recursive_result = BSearchRecursive(&key2, arr, nitems, elm_size, IntCmp);
	
	expect_int(*recursive_result, key2, "SingleElement_test_BSearchRecursive_2");
	
	recursive_result = BSearchRecursive(&key3, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(recursive_result, "SingleElement_BSearchRecursive_jump_3");
	
	iterative_result = BSearchIterative(&key1, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(iterative_result, "SingleElement_test_BSearchIterative_1");
	
	iterative_result = BSearchIterative(&key2, arr, nitems, elm_size, IntCmp);
	
	expect_int(*iterative_result, key2, "SingleElement_test_BSearchIterative_2");
	
	iterative_result = BSearchIterative(&key3, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(iterative_result, "SingleElement_test_BSearchIterative_3");		
}

void JumpSearch_test_simple_odd()
{
	int arr[] = {2,4,8,10,12,14,16,18,60};
	
	int key = 12;
	size_t i = 0;

	size_t elm_size = sizeof(arr[0]);	
	size_t nitems = sizeof(arr)/sizeof(arr[0]);
	
	int *result = JSearch(&key, arr, nitems, elm_size, IntCmp);
	
	expect_int(*result, key, "JumpSearch_test_simple_odd1");
	
	for (i = 0; i < nitems; ++i)
	{
		key = arr[i];
		result = JSearch(&key, arr, nitems, elm_size, IntCmp);
		expect_int(*result, key, "JumpSearch_test_simple_odd");
	}
	
	key = 0;
	
	result = JSearch(&key, arr, nitems, elm_size, IntCmp);
	expect_NULL(result, "JumpSearch_test_simple_odd0");	
	
	key = 99;
	
	result = JSearch(&key, arr, nitems, elm_size, IntCmp);
	expect_NULL(result,"JumpSearch_test_simple_odd99");	
}
void JumpSearch_test_simple_odd_not_found()
{
	int arr[] = {2,4,8,10,12,14,16,18,60};
	
	int key = 11;

	size_t elm_size = sizeof(arr[0]);	
	size_t nitems = sizeof(arr)/sizeof(arr[0]);
	
	int *result = JSearch(&key, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(result, "JumpSearch_test_simple_odd_not_found11");
		
	key = 0;
	result = JSearch(&key, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(result, "JumpSearch_test_simple_odd_not_found0");
	
	key = 70;
	result = JSearch(&key, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(result, "JumpSearch_test_simple_odd_not_found70");
}

void JumpSearch_test_simple_even()
{
	int arr[] = {2,4,8,10,12,14};
	
	int key = 12;

	size_t elm_size = sizeof(arr[0]);	
	size_t nitems = sizeof(arr)/sizeof(arr[0]);
	
	int *result = JSearch(&key, arr, nitems, elm_size, IntCmp);
	
	expect_int(*result, key, "JumpSearch_test_simple_even");	
}

void BSearchRecursive_test_simple_even_not_found()
{
	int arr[] = {2,4,8,10,12,14};
	
	int key = 11;

	size_t elm_size = sizeof(arr[0]);	
	size_t nitems = sizeof(arr)/sizeof(arr[0]);
	
	int *result = BSearchRecursive(&key, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(result, "BSearchRecursive_test_simple_even_not_found");
	
	key = 0;
	result = BSearchRecursive(&key, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(result, "BSearchRecursive_test_simple_even_not_found0");
	
	key = 70;
	result = BSearchRecursive(&key, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(result, "BSearchRecursive_test_simple_even_not_found0");		
}

void BSearchRecursive_test_simple_odd()
{
	int arr[] = {2,4,8,10,12,14,16,18,60};
	
	int key = 12;

	size_t elm_size = sizeof(arr[0]);	
	size_t nitems = sizeof(arr)/sizeof(arr[0]);
	
	int *result = BSearchRecursive(&key, arr, nitems, elm_size, IntCmp);
	
	expect_int(*result, key, "BSearchRecursive_test1");
}


void BSearchRecursive_test_simple_even()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	
	int key = 2;

	size_t elm_size = sizeof(arr[0]);	
	size_t nitems = sizeof(arr)/sizeof(arr[0]);
	
	int *result = BSearchRecursive(&key, arr, nitems, elm_size, IntCmp);
	
	expect_int(*result, key, "BSearchRecursive_test1");
}
void BSearchIterative_test_simple_even_not_found()
{
	int arr[] = {2,4,8,10,12,14};
	
	int key = 13;

	size_t elm_size = sizeof(arr[0]);	
	size_t nitems = sizeof(arr)/sizeof(arr[0]);
	
	int *result = BSearchIterative(&key, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(result, "BSearchIterative_test_simple_even_not_found13");
	
	key = 0;
	result = BSearchIterative(&key, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(result, "BSearchIterative_test_simple_even_not_found0");
	
	key = 70;
	result = BSearchIterative(&key, arr, nitems, elm_size, IntCmp);
	
	expect_NULL(result, "BSearchIterative_test_simple_even_not_found0");	
}

void BSearchIterative_test_simple_odd()
{
	int arr[] = {2,4,8,10,12,14,16,18,60};
	
	int key = 12;
	size_t i = 0;

	size_t elm_size = sizeof(arr[0]);	
	size_t nitems = sizeof(arr)/sizeof(arr[0]);
	
	int *result = BSearchIterative(&key, arr, nitems, elm_size, IntCmp);
	
	expect_int(*result, key, "BSearchIterative_test1");
	
	for (i = 0; i < nitems; ++i)
	{
		key = arr[i];
		result = BSearchIterative(&key, arr, nitems, elm_size, IntCmp);
		expect_int(*result, key, "BSearchIterative_test1");
	}
}

void BSearchIterative_test_simple_even()
{
	int arr[] = {2,4,8,10,12,14};
	
	int key = 12;

	size_t elm_size = sizeof(arr[0]);	
	size_t nitems = sizeof(arr)/sizeof(arr[0]);
	
	int *result = BSearchIterative(&key, arr, nitems, elm_size, IntCmp);
	
	expect_int(*result, key, "BSearchIterative_test1");
}
