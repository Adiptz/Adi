/****************************
 * Author: Dandan Ogni		*
 * Reviewer: 				*
 * Revision: 				*
 * Status: 					*
 ****************************/

/******************************************************************************/

/****************
 * HEADER FILES	*
 ****************/

#include <stdio.h> /* printf */
#include <assert.h> /* assert */
#include <math.h> /* log */

#include "avl.h" /* avl API */

/******************************************************************************/

/****************
 * TOGGLE ZONE	*
 ****************/

#define CHECK_IS_EMPTY
#define CHECK_COUNT
#define CHECK_INSERT
#define CHECK_REMOVE
#define CHECK_FIND
#define CHECK_FOR_EACH
#define CHECK_HEIGHT
/*#define CHECK_BALANCE*/

/************************
 * END OF TOGGLE ZONE	*
 ************************/

/******************************************************************************/

/************
 * MACRO	*
 ************/

#define Expect(x) \
{\
	if (!(x))\
	{\
		printf("Test failed at line %d\n", __LINE__);\
		return 0;\
	}\
} /* end of Expect */

#define ExpectMain(x, str) \
{\
	if (!(x))\
	{\
		printf("Test failed for %s\n", str);\
	}\
} /* end of ExpectMain */

#define UNUSED(x) ((void)(x))

/******************************************************************************/

/************************
 * FUNCTION DECLARATION	*
 ************************/

static int CheckIsEmpty();
static int CheckCount();
static int CheckFind();
static int CheckForEach();
static int CheckHeight();

static int CmpInt(const void *iter_data, const void *new_data, void *param);
static int CmpByParam(const void *iter_data, const void *new_data, void *param);

static int AddParamToData(void *data, void *param);
static int ReturnDataIfParamIsZeroElseSubParam(void *data, void *param);

/******************************************************************************/

/************************
 * FUNCTION DEFINITION	*
 ************************/

int main()
{
	ExpectMain(CheckIsEmpty(), "IsEmpty"); /*TODO A*/
	ExpectMain(CheckCount(), "Count"); 
	ExpectMain(CheckFind(), "Find"); 
	ExpectMain(CheckForEach(), "ForEach"); 
/*	ExpectMain(CheckHeight(), "Height");*/

	return 0;
}

static int CmpInt(const void *iter_data, const void *new_data, void *param)
{
	UNUSED(param);
	return (*(int *)iter_data - *(int *)new_data);
}

static int CmpByParam(const void *iter_data, const void *new_data, void *param)
{
	int *arr = param;
	const int *data = iter_data;
	const int *compared = new_data;

	return (arr[*data] - arr[*compared]);
}

static int AddParamToData(void *data, void *param)
{
	*(int *)data += *(int *)param;

	return 0;
}

static int ReturnDataIfParamIsZeroElseSubParam(void *data, void *param)
{
	if (0 == *(int *)param)
	{
		return *(int *)data;
	}
	else
	{
		--*(int *)param;

		return 0;
	}
}

#ifdef CHECK_BALANCE
static double log2(double num)
{
	return (log(num) / log(2));
}
#endif /* CHECK_BALANCE */

static int CheckIsEmpty()
{
	#ifdef CHECK_IS_EMPTY
	int arr1[] = {1, 5, 3, 2, 10, 8, 7, 4, 9, 6};
	avl_t *new_tree = AVLCreate(NULL, &CmpInt);
	size_t i = 0;

	Expect(NULL != new_tree);

	Expect(1 == AVLIsEmpty(new_tree));

	# ifdef CHECK_INSERT
	for (i = 0; i < 10; ++i)
	{
		Expect(0 == AVLInsert(new_tree, &(arr1[i])));
		Expect(0 == AVLIsEmpty(new_tree));
	}

	#  ifdef CHECK_REMOVE
	for (i = 0; i < 10; ++i)
	{
		Expect(0 == AVLIsEmpty(new_tree));
		AVLRemove(new_tree, &(arr1[i]));
	}

	Expect(1 == AVLIsEmpty(new_tree));
	#  endif /* CHECK_REMOVE */
	# endif /* CHECK_INSERT */

	AVLDestroy(new_tree);
	#endif /* CHECK_IS_EMPTY */

	return 1;
}

static int CheckCount()
{
	#ifdef CHECK_COUNT
	int arr1[] = {1, 5, 3, 2, 10, 8, 7, 4, 9, 6};
	avl_t *new_tree = AVLCreate(NULL, &CmpInt);
	size_t i = 0;

	Expect(NULL != new_tree);

	Expect(0 == AVLCount(new_tree));

	# ifdef CHECK_INSERT
	for (i = 0; i < 10; ++i)
	{
		Expect(i == AVLCount(new_tree));
		Expect(0 == AVLInsert(new_tree, &(arr1[i])));
	}

	#  ifdef CHECK_REMOVE
	for (i = 0; i < 10; ++i)
	{
		Expect((10 - i) == AVLCount(new_tree));
		AVLRemove(new_tree, &(arr1[i]));
	}

	Expect(0 == AVLCount(new_tree));
	#  endif /* CHECK_REMOVE */
	# endif /* CHECK_INSERT */

	AVLDestroy(new_tree);
	#endif /* CHECK_COUNT */

	return 1;
}

static int CheckFind()
{
	#ifdef CHECK_INSERT
	# ifdef CHECK_FIND
	int arr1[] = {1, 5, 3, 2, 10, 8, 7, 4, 9, 6};
	int param[] = {1, 2, 4, 5, 3, 9, 10, 8, 7, 6, 0, 11, 12, 13, 14, 15, 16};
	avl_t *new_tree = AVLCreate(param, &CmpByParam);
	int i = 0;

	Expect(NULL != new_tree);

	for (i = 0; i < 10; ++i)
	{
		Expect(0 == AVLInsert(new_tree, &(arr1[i])));
	}

	for (i = 1; i < 11; ++i)
	{
		Expect((int)i == *(int *)AVLFind(new_tree, &i));
	}

	Expect(NULL == AVLFind(new_tree, &i));

	#  ifdef CHECK_REMOVE
	{
		int to_remove = 8;
		AVLRemove(new_tree, &to_remove);
		Expect(NULL == AVLFind(new_tree, &to_remove));
	
		for (i = 1; i < 11; ++i)
		{
			if (8 == i)
			{
				++i;
			}
			Expect((int)i == *(int *)AVLFind(new_tree, &i));
		}
	}
	#  endif /* CHECK_REMOVE */

	AVLDestroy(new_tree);
	# endif /* CHECK_FIND */
	#endif /* CHECK_INSERT */

	return 1;
}

static int CheckForEach()
{
	#ifdef CHECK_INSERT
	# ifdef CHECK_FOR_EACH
	int arr1[] = {1, 5, 3, 2, 10, 8, 7, 4, 9, 6};
	avl_t *new_tree = AVLCreate(NULL, &CmpInt);
	int i = 0;

	Expect(NULL != new_tree);

	for (i = 0; i < 10; ++i)
	{
		Expect(0 == AVLInsert(new_tree, &(arr1[i])));
	}

	{
		int param = 20;
		Expect(0 == AVLForEach(&param, new_tree, &ReturnDataIfParamIsZeroElseSubParam));
		Expect(10 == param);

		param = 5;
		Expect(0 == AVLForEach(&param, new_tree, &ReturnDataIfParamIsZeroElseSubParam));
		Expect(0 == param);
	}

	{
		int param = 100;
		Expect(0 == AVLForEach(&param, new_tree, &AddParamToData));

		for (i = 101; i < 111; ++i)
		{
			Expect((int)i == *(int *)AVLFind(new_tree, &i));
		}

		for (i = 0; i < 100; ++i)
		{
			Expect(NULL == AVLFind(new_tree, &i));
		}
	}

	AVLDestroy(new_tree);
	# endif /* CHECK_FOR_EACH */
	#endif /* CHECK_INSERT */


	return 1;
}

static int CheckHeight()
{
	#ifdef CHECK_HEIGHT
	static int arr1[10000] = {0};
	avl_t *new_tree = AVLCreate(NULL, &CmpInt);
	size_t i = 0;
	size_t size = 0;

	Expect(NULL != new_tree);

	Expect(0 == AVLHeight(new_tree));

	for (i = 0; i < 1000; ++i)
	{
		arr1[i] = i;
	}

	# ifdef CHECK_INSERT
	for (i = 0; i < 1000; ++i)
	{
		size = i;
		#  ifdef CHECK_BALANCE
		Expect(log2(size + 1) <= AVLHeight(new_tree));
		Expect(1.45 * log2(size + 2) - 0.328 >=  AVLHeight(new_tree));
		#  endif /* CHECK_BALANCE */
		Expect(size >= AVLHeight(new_tree));
		Expect(0 == AVLInsert(new_tree, &(arr1[i])));
		Expect(1 <= AVLHeight(new_tree));
	}

	#  ifdef CHECK_REMOVE
	for (i = 0; i < 1000; ++i)
	{
		size = 1000 - i;
		#  ifdef CHECK_BALANCE
		Expect(log2(size + 1) <= AVLHeight(new_tree));
		Expect(1.45 * log2(size + 2) - 0.328 >=  AVLHeight(new_tree));
		#  endif /* CHECK_BALANCE */
		Expect(1 <= AVLHeight(new_tree));
		Expect(size >= AVLHeight(new_tree));
		AVLRemove(new_tree, &(arr1[i]));
	}

	Expect(0 == AVLHeight(new_tree));
	#  endif /* CHECK_REMOVE */
	# endif /* CHECK_INSERT */

	AVLDestroy(new_tree);
	#endif /* CHECK_HEIGHT */

	return 1;
}
