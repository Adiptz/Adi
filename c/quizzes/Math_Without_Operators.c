#include <stdio.h>

unsigned int AddOne(unsigned int num)	/*A*/			
{
	unsigned int mask = 1;
	
	while(0 != (num & mask)) 
	{
		num ^= mask;
		mask <<= 1; 
	}
	
	num |= mask; 
	
	return num;
}

unsigned int Multiply(unsigned int num, unsigned int mult_by)
{
	unsigned int i = 1;
	unsigned int j = 0;
	unsigned int result = num;
	
	for(i = 1; i < mult_by; i = AddOne(i))
	{
		for (j = 0; j < num; j = AddOne(j))
		{
			result = AddOne(result);
		}
	}
	
	return result;	
}

unsigned int Pow(unsigned int num, unsigned int exp)
{
	unsigned int i = 0;
	unsigned int result = num;
	
	if (0 == exp)
	{
		return 1;
	}
	
	for (i = 1; i < exp; i = AddOne(i))
	{
		result = Multiply(result, num);
	}
	
	return result;
}

int main()
{
	printf("%u", AddOne(3));
	printf("%u", Multiply(3,2));
	printf("%u", Pow(3,2));
	printf("%u", Pow(3,0));

	return 0;
}
