#include <stdio.h>
#include <assert.h>

#include "avl.h"

#define UNUSED(x) (void)(x)

static int CmpInt(const void *data, const void *new_data, void *param)
{
	UNUSED(param);
	
	return (*(int *)data - *(int *)new_data);
}

int PrintInt(void *tree_data, void *param)
{
	UNUSED(param);
	printf("%d ", *(int *)tree_data);

	return 0;
}


static void Create_Destroy_Test()
{
	avl_t *tree = AVLCreate(NULL, CmpInt);
	assert(AVLIsEmpty(tree));
	AVLDestroy(tree);
}

static void Insert_By_Oreder_Test()
{
	avl_t *tree = AVLCreate(NULL, CmpInt);
	int insert1 = 1;
	int insert2 = 2;
	int insert3 = 3;
	
	assert(AVLIsEmpty(tree));
	
	AVLInsert(tree, &insert1);
	AVLInsert(tree, &insert2);
	AVLInsert(tree, &insert3);

	assert(3 == AVLCount(tree));
		
	AVLDestroy(tree);
}

static void Remove_Test()
{
	avl_t *tree = AVLCreate(NULL, CmpInt);
	int insert1 = 1;
	int insert2 = 2;
	int insert3 = 3;
	
	assert(AVLIsEmpty(tree));
	
	/* by order */
	AVLInsert(tree, &insert1);
	AVLInsert(tree, &insert2);
	AVLInsert(tree, &insert3);

	assert(3 == AVLCount(tree));
	
	AVLRemove(tree, &insert1);
	AVLRemove(tree, &insert2);
	AVLRemove(tree, &insert3);

	assert(AVLIsEmpty(tree));
	
	/* not by order */
	AVLInsert(tree, &insert2);
	AVLInsert(tree, &insert3);
	AVLInsert(tree, &insert1);

	assert(3 == AVLCount(tree));
	
	AVLRemove(tree, &insert2);
	AVLRemove(tree, &insert1);
	AVLRemove(tree, &insert3);
	
	AVLDestroy(tree);
}

static void Insert_Not_By_Order_Test()
{
	void *param = NULL;
    avl_t *tree = AVLCreate(param ,CmpInt);
    int arr_nums[] = {0,1,4,6,2,3,9,8,7,5};
    int arr_length = 10;
    int i = 0;
    
    assert(AVLIsEmpty(tree));
    
    for(i = 0 ; i < arr_length ; ++i)
    {       
        AVLInsert(tree, &arr_nums[i]);
    }
	
 	assert(!AVLIsEmpty(tree));
	
	for(i = 0 ; i < arr_length ; ++i)
    {
		AVLRemove(tree, &arr_nums[i]);
    }
        
    assert(AVLIsEmpty(tree));
    
    AVLDestroy(tree);
}

static void Find_Test()
{	
	void *param = NULL;
    avl_t *tree = AVLCreate(param ,CmpInt);
   	
   	int insert1 = 1, insert2 = 2, insert3 = 3, insert4 = 4, insert5 = 5;
	
	assert(AVLIsEmpty(tree));
	
	AVLInsert(tree, &insert1);
	AVLInsert(tree, &insert3);
	AVLInsert(tree, &insert2);
	AVLInsert(tree, &insert5);
	AVLInsert(tree, &insert4);
	
    assert(*(int *)AVLFind(tree, &insert5) == 5);

    AVLRemove(tree, &insert5);    
    assert(NULL == AVLFind(tree, &insert5));
    
    AVLDestroy(tree);
}

static void Count_Test()
{	
	void *param = NULL;
    avl_t *tree = AVLCreate(param ,CmpInt);
   	
   	int insert1 = 1, insert2 = 2, insert3 = 3, insert4 = 4, insert5 = 5;
	
	assert(AVLIsEmpty(tree));
	
	AVLInsert(tree, &insert1);
	assert(1 == AVLCount(tree));

	AVLInsert(tree, &insert3);
	assert(2 == AVLCount(tree));
	
	AVLInsert(tree, &insert2);
	assert(3 == AVLCount(tree));
	
	AVLInsert(tree, &insert5);
	assert(4 == AVLCount(tree));
	
	AVLInsert(tree, &insert4);
	assert(5 == AVLCount(tree));
	
    AVLRemove(tree, &insert5);
    assert(4 == AVLCount(tree));
    
    
    AVLDestroy(tree);
}

static void ForEach_Test()
{
	void *param = NULL;
    int arr_nums[] = {0, 1, 9, 5, 4, 3, 6, 7, 8, 2};
    int arr_length = 10;
    int i = 0;
    avl_t *tree = AVLCreate(param ,CmpInt);
    
    assert(AVLIsEmpty(tree));
    
    for(i = 0 ; i < arr_length ; ++i)
    {       
        AVLInsert(tree, &arr_nums[i]);
    }
    
    AVLForEach(param, tree, PrintInt); 
 
	puts("");   

	AVLDestroy(tree);
}

static void RemoveEmpty()
{
	avl_t *new_tree = AVLCreate(NULL, &CmpInt);
	int data = 4;
	
	assert(NULL != new_tree);
	
	AVLRemove(new_tree, &data);

	AVLDestroy(new_tree);
}

int main()
{
	printf("VOVA THE QUEEN\n");

	Create_Destroy_Test();
	Insert_By_Oreder_Test();
	Insert_Not_By_Order_Test();
	Remove_Test();
	Find_Test();
	Count_Test();
	ForEach_Test();
	RemoveEmpty();
	return 0;
}
