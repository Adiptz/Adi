#include <stdio.h>
#include "stack.h"



/************************ -- MAIN -- ******************************/
int main()
{
	int i= 5;
	int x = 8;
	stack_t *adi = StackCreate(4,sizeof(int));
	
	/* peek for empty string */
	puts("PEEK FOR EMPTY STACK:");
	printf("%p\n\n", StackPeek(adi));
	
	/* check if stack is empty*/
	puts("IS STACK EMPTY ?");
	printf("YES - 1 : %d\n\n", StackIsEmpty(adi));
	
	/* print stack size */
	puts("ELEMENTS IN STACK:");
	printf("expect 0 : %lu\n\n", StackSize(adi));
	
	/* push and print 5 to first element */
	puts("PUSH 5 --> ELEMENTS 1  :");
	StackPush(adi, &i);
	printf("expected 5 : %d\n\n", *(int *)StackPeek(adi));
	
	/* print stack size */
	puts("ELEMENTS IN STACK:");
	printf("expect 1 : %lu\n\n", StackSize(adi));
	
	/* check if stack is empty*/
	puts("IS STACK EMPTY ?");
	printf("NO - 0 : %d\n\n", StackIsEmpty(adi));
	
	/* push and print 8 to first element */
	puts("PUSH 8 --> ELEMENTS 2  :");
	StackPush(adi, &x);
	printf("expected 8 : %d\n\n", *(int *)StackPeek(adi));
	
	/* print stack size */
	puts("ELEMENTS IN STACK:");
	printf("expect 2 : %lu\n\n", StackSize(adi));
	
	/* get top address and print value stored inside */
	puts("ADDRESS OF TOP ELEMENTS:");
	printf("%p\n\n", StackPeek(adi));
	puts("VALUE OF TOP ELEMENTS:");
	printf("expected 8 : %d\n\n", *(int *)StackPeek(adi));
	
	/* take out top element */
	puts("~pop out top element (8)~");
	StackPop(adi);
	
	/* print top element */
	puts("VALUE OF NEW TOP ELEMENT:");
	printf("expected 5 : %d\n\n", *(int *)StackPeek(adi));
	puts("ADDRESS OF TOP ELEMENTS:");
	printf("%p\n\n", StackPeek(adi));
	
	/* check if stack is empty*/
	puts("IS STACK EMPTY ?");
	printf("NO - 0 : %d\n", StackIsEmpty(adi));
	
	StackDestroy(adi);


	return 0;
}
