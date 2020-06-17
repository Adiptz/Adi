#include <stdio.h>
#include <stdlib.h> /* malloc */

#define RED   "\033[1;31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

extern int etext, edata, end;

int global_init = 1;
int global_zero = 0;
int global_uninit;

int foo(int arg1, int arg2)
{
	printf("argument1     : %p\n", (void *)&arg1);
	printf("argument2     : %p\n", (void *)&arg2);
}


int main()
{
	/*variables for foo()*/
	int a = 1;
	int b = 2;
	int foo();

	/* locals STACK */	
	volatile int local1 = 1;
	int local2 = 1;
	int local3 = 3;
	int uninit_local;
	int init_to_zero = 0;	

	/*BSS */	
	static int static_zero = 0;
	static int static_uninit;
	
	/* should go to DATA SEGMENT */
	static int static_init = 1;
	
	/* HEAP */
	void *first_malloc = malloc(88);
	void *second_malloc = malloc(96);
	
	/* DATA SEGMENT r.o area */
	const char *str_literal = "fuck literals";
	
	/* arrays */
	int arr[30]; /* local should be on stack */
	static int static_arr[30] ; /* should be on data */
	
	
	
	
	
	printf(RED "STACK\n" RESET);
	printf(CYN "local variables only\nvariables cannot be resized\nvery fast access\n"RESET);
	printf(YEL "First Frame\n" RESET);
	printf("init_to_zero  : %p\n", &init_to_zero);
	printf("uninit        : %p\n", &uninit_local);
	printf("local3        : %p\n", &local3);
	printf("local2        : %p\n", &local2);
	printf("local1        : %p\n", &local1);
	printf("local arr[]   : %p\n", &arr);
	
	printf(YEL "Second Frame\n" RESET);
	foo(a,b );
		
	printf(RED "\nHEAP\n" RESET);
	printf(CYN"dynamic aloocation\nvariables can be resized using realloc()\n"RESET);
	printf("second malloc : %p\n", second_malloc);
	printf("first malloc  : %p\n", first_malloc);
	printf(MAG "begin of heap : %p\n", &end);
	
	printf(RED "\nBSS\n" RESET);
	printf(CYN"globals / statics variables\ncontains uninitalized variables / initalized with zero\n"RESET);
	/*uninitilaized data or initilazied to zero*/
	printf("global_uninit : %p\n", &global_uninit);
	printf("static_zero   : %p\n", &static_zero);
	printf("static_uninit : %p\n", &static_uninit);
	printf("global_zero   : %p\n", &global_zero);
	printf(MAG "begin of bss  : %p\n", &edata);

	printf(RED"\nDATA SEGMENT\n"RESET);
	printf(CYN"globals / statics variables\ncontains initialized variables\n" RESET);
	printf("static_init   : %p\n", &static_init);
	printf("static arr[]  : %p\n", &static_arr);
	printf(YEL "read-only :\n" RESET);
	printf("str_literal   : %p\n", str_literal);
	printf(MAG"begin of data : %p\n", &etext);
	
	printf(RED"\nCODE SEGMENT\n"RESET);
	printf("foo()         : %p\n", foo);
	printf("main()        : %p\n", main);
	
	return 0;
}
