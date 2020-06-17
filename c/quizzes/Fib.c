#include <stdio.h>

int Fib(int n)
{
	int a = 0;
	int b = 1;
	int tmp = 0;
	int i = 0;
	
	for(i = 0; i < n; ++i)
	{
		tmp = a + b;
		a = b;
		b = tmp;	
	}
	
	return b;
}


int main ()
{
	int test1 = 0;
	int test2 = 5;
	int test3 = 52;
	
	printf("%d\n", Fib(test1));
	printf("%d\n", Fib(test2));
	printf("%d\n", Fib(test3));
	
	return 0;

}
