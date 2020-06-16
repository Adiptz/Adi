#ifndef __OL71_STACK_H
#define __OL71_STACK_H

#include <stddef.h>

typedef struct stack stack_t;

enum {
	  STACK_SUCCESS,
	  STACK_OVERFLOW_ERROR,
	  STACK_UNDERFLOW_ERROR
	 };

/*
 * Create a Stack
 * Param max_num_of_elements: maximal number of elements which can be
 * 							  pushed into the stack.
 * Param size_of_element	: size of each element
 * Returns: A pointer pointing to the created stack 
 * Errors: Returns NULL if stack creation failed.
 */
stack_t *StackCreate(size_t max_num_of_elements, size_t size_of_element);

/*
 * Destroys the stack
 * Param stack: pointer to a stack.
 * Errors: None
 */ 
void StackDestroy(stack_t *stack);

/*
 * Pushes element to the top of the stack.
 * Param stack		: pointer to stack
 * Param element	: const pointer to element value
 * Returns: STACK_SUCCESS if the push was successfull. Non-zero otherwise.
 * Errors: 	STACK_OVERFLOW_ERROR if the stack is in its maximum capacity,
 *			stack remains unchanged.
 * 		   	If stack points to an unreadable address, behavior is undefined.
 */
int StackPush(stack_t *stack, const void *element);

/*
 * Removes top element in stack and returns it.
 * Param stack: pointer to a stack
 * Returns: STACK_SUCCESS if the pop was successfull. Non-zero otherwise.
 * Errors:  returns STACK_UNDERFLOW_ERROR if stack is empty. Stack remains
 *		    unchanged.
 * 			If stack points to an unreadable address, behavior is undefined.
 */
int StackPop(stack_t *stack);

/*
 * Get the address of the value in the top element of the stack.
 * Param stack: pointer to a stack
 * Returns: A pointer to the value of the top element.
 * Errors: If stack points to unreadable address, behavior is undefined.
 */
void *StackPeek(const stack_t *stack);
/*
 * Checks if stack is empty.
 * Param: pointer to stack
 * Returns: 1 if stack is empty. 0 otherwise.
 * Errors: If stack points to unreadable address, behavior is undefined.
 */
int StackIsEmpty(const stack_t *stack);

/*
 * Checks the stack size.
 * Param stack: pointer to a stack
 * Returns: number of elements in the stack.
 * Errors: If stack points to unreadable address, behavior is undefined.
 */
size_t StackSize(const stack_t *stack);

#endif /* __OL71_STACK_H */
