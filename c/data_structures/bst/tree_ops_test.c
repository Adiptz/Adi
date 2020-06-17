#include "tree_ops.h"

#define UNUSED(x) (void)(x) 

/*********************** -- forward decleration -- *********************/
static void PrintLevels_test();
static void Mirror_test();
int CmpInts(void *iter_data, void *new_data, void *param);
/***************************** -- main -- ******************************/
int main()
{
/*	PrintLevels_test();*/
	
	Mirror_test();
	
	return 0;
}

/****************************** -- tests -- ****************************/
int CmpInts(void *iter_data, void *new_data, void *param)
{
	UNUSED(param);
	return (*(int *)iter_data - *(int *)new_data);
}

static void PrintLevels_test()
{
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;

	bst_t *test = BSTCreate(CmpInts, NULL);
	
	bst_iter_t first = NULL;
	bst_iter_t second = NULL;
	bst_iter_t third = NULL;
	bst_iter_t fourth = NULL;
	bst_iter_t fifth = NULL;
	
	assert(NULL != test);
	
	UNUSED(first);
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


static void Mirror_test()
{
    int ints[] = {6, 3, 8, 1, 9, 7, 2, 5, 4, 0};
	size_t i = 0, ints_count = sizeof(ints) / sizeof(ints[0]);

    bst_t *bst = BSTCreate(CmpInts, NULL);
	
	for (i = 0; i < ints_count; ++i)
	{
		BSTInsert(bst, &ints[i]);	
	}
	
    puts("\nBEFORE MIRROR");
	PrintTree(bst);

    MirrorTree(bst);

    puts("BEFORE MIRROR");
	PrintTree(bst);
	
	BSTDestroy(bst);
}
