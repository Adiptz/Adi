
#include <stdio.h> /* printf */
#include <string.h> /* memcpy*/
#include <stdlib.h> /* malloc, free, size_t */
#include <assert.h> /* assert */

#include "stack.h"

struct stack
{
	void *base;
	void *current;
	void *end;
	size_t size_of_element;
};

/************************ -- CREATE -- ****************************/
stack_t *StackCreate(size_t max_num_of_elements, size_t size_of_element)
{
	stack_t *ptr_stack = (stack_t *)malloc(sizeof(stack_t));
	
	if(NULL == ptr_stack) /* check if malloc failed */
	{
		return NULL;
	}
	
 /* find place to the stack the user 
    wants and store his address in stack.base */
	ptr_stack->base = malloc(max_num_of_elements * size_of_element);
	if(NULL == ptr_stack->base) 
	{
		free(ptr_stack); ptr_stack = NULL;
		return NULL;
	}
	
	ptr_stack->current = ptr_stack->base;
	ptr_stack->end = (char *)ptr_stack->base + (max_num_of_elements * size_of_element);
	ptr_stack->size_of_element =  size_of_element;
	
	return ptr_stack;
}

/************************ -- DESTROY -- *****************************/
void StackDestroy(stack_t *stack)
{
	assert(NULL != stack);
	
	free(stack->base); stack->base =  NULL;
	free(stack); stack = NULL;
}

/************************* -- PUSH -- ******************************/
int StackPush(stack_t *stack, const void *element)
{
	assert(NULL != stack);
	assert(NULL != element);
	
	if(stack->current == stack->end)
	{
		return STACK_OVERFLOW_ERROR;
	}
	
	/* copy element into stack->current.
	   copy size_of_elements bytes      */
	memcpy(stack->current, element, stack->size_of_element);
	
	stack->current = (char *)stack->current + stack->size_of_element;
	
	return STACK_SUCCESS;
}

/************************* -- POP -- *******************************/
int StackPop(stack_t *stack)
{
	assert(NULL != stack);
	
	if(StackIsEmpty(stack))
	{
		return STACK_UNDERFLOW_ERROR;
	}
	
	stack->current = (char *)stack->current - stack->size_of_element;
	
	return STACK_SUCCESS;
}

/************************* -- PEEK -- *****************************/
void *StackPeek(const stack_t *stack)
{
	assert(NULL != stack);
	
	if(StackIsEmpty(stack))
	{
		return NULL;
	}
	
	return (char *)stack->current - stack->size_of_element;
}

/************************ -- IS EMPTY -- ***************************/
int StackIsEmpty(const stack_t *stack)
{
	assert(NULL != stack);
	
	return (stack->current == stack->base);
}

/************************** -- SIZE -- *****************************/
size_t StackSize(const stack_t *stack)
{
	assert(NULL != stack);
	
	return (((char *)stack->current - (char *)stack->base) / stack->size_of_element);
}

