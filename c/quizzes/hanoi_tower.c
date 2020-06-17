#include <assert.h> /* assert */
#include <stdio.h> /* printf */
#include <stdlib.h> /* size_t */

#include "stack.h"


/************************* -- forward declerations -- *************************/
void HanoiTowerPseudo(size_t num_of_disks, char src, char tmp, char dest);

void HanoiTowerStack(size_t size,
				     stack_t *stack_src,
				     stack_t *stack_tmp,
				     stack_t *stack_dest);
void MoveDisk(stack_t *stack_src, stack_t *stack_dest);

/* tests */			
void pseudo_code_test();
void HanoiTowers_test();




/********************************* -- main -- *********************************/
int main()
{
	puts("Test 1");
	pseudo_code_test();
	
	puts("");
		
	puts("Test 2");
	HanoiTowers_test();
	
	puts("");
	
	return 0;
}


/*** pseudo - code ***/
void HanoiTowerPseudo(size_t num_of_disks, char src, char tmp, char dest)
{
	if (1 == num_of_disks)
	{
		printf("move disk #1 : %c --> %c\n", src, dest);
		return;
	}
	
	HanoiTowerPseudo(num_of_disks - 1, src, dest, tmp);
	printf("move disk #%lu : %c --> %c\n", num_of_disks, src, dest);

	HanoiTowerPseudo(num_of_disks - 1, tmp, src, dest);
}

/********************* -- implementation with stack -- ************************/

/* Move disk from one stack to another 						*
 * input : @stack_src - pointer to stack move disk from it  *
 * 		   @stack_dest - pointer to stack move disk to it	*
 * output : none                                            */
void MoveDisk(stack_t *stack_src, stack_t *stack_dest)
{
	assert(NULL != stack_src);
	assert(NULL != stack_dest);
	
	StackPush(stack_dest, StackPeek(stack_src));
	StackPop(stack_src);
}

void HanoiTowerStack(size_t size,
				stack_t *stack_src,
				stack_t *stack_tmp,
				stack_t *stack_dest)
{
	assert(NULL != stack_src);
	assert(NULL != stack_tmp);
	assert(NULL != stack_dest);
	
	if (1 == size)
	{
		MoveDisk(stack_src, stack_dest);
		return;
	}
	
	HanoiTowerStack(size - 1, stack_src, stack_dest, stack_tmp);
	
	MoveDisk(stack_src, stack_dest);
	
	HanoiTowerStack(size - 1, stack_tmp, stack_src, stack_dest);
}


/********************************* -- tests -- ********************************/
void pseudo_code_test()
{
	size_t num_of_disks = 3;
	
	HanoiTowerPseudo(num_of_disks, 'O', 'T', 'D');
}

void HanoiTowers_test()
{
	stack_t*src = NULL;	
	stack_t*dst = NULL;	
	stack_t*tmp = NULL;	
	int arr[]= {6, 5, 4, 3, 2, 1};
	size_t num_of_elements = sizeof(arr)/ sizeof(*arr);
	size_t i = 0;

	src = StackCreate(sizeof(int) * num_of_elements, sizeof(int));
	dst = StackCreate(sizeof(int) * num_of_elements, sizeof(int));
	tmp = StackCreate(sizeof(int) * num_of_elements, sizeof(int));

	for (i = 0; i < num_of_elements; ++i)
	{
		StackPush(src, &arr[i]);
	}

	HanoiTowerStack(num_of_elements, src, tmp, dst);

	while(!StackIsEmpty(dst))
	{
		printf("%d ", *(int*)StackPeek(dst));
		StackPop(dst);
	}

	StackDestroy(src);
	StackDestroy(dst);
	StackDestroy(tmp);
}
