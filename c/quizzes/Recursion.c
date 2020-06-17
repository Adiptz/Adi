#include <stdio.h>

#include <string.h>

int FibRecursion(int n)
{
	if (n <= 1)
	{
		return n;
	}
	
	return (FibRecursion(n - 2) + FibRecursion(n - 1));
}

size_t StrlenRec(const char *str)
{
	if('\0' == *str)
	{
		return 0;
	}

	return (StrlenRec(str + 1) + 1);	
}

int StrcmpRec(const char *str1, const char *str2)
{
	if ('\0' == *str1 || *str1 != *str2 )
	{
		return (*str1 - *str2);
	}	

	return StrcmpRec(str1 + 1, str2 + 1) ;
}

char *StrcpyRec(char *dest, const char *src)
{
	if ('\0' != *src)
	{
		*dest = *src;
		StrcpyRec(dest + 1, src + 1);
	}
	
	*dest = *src;
	return dest;
}

char *StrcatRec(char *dest, const char *src)
{
	char *original_dest = dest;
	
	*(dest + strlen(dest)) = *src;	

	if ('\0' != *src)
	{
		StrcatRec(dest + strlen(dest) , src +1);
		return original_dest;
	}
	
	return original_dest;
}



int main()
{
	
	char cat[50] = "18";
	const char *cat1 = "abc";
	
	char cpy[50] = "";
	const char *cpy1 = "strcpy";
	
	const char *str1_test = "bbc";
	const char *str2_test = "cbc";
	const char *str2 = "abcdef";
	
	char *strcat = StrcatRec(cat, cat1);
	char *strcpy = StrcpyRec(cpy, cpy1);
	
	printf("%s\n", strcat);
	printf("%s\n", strcpy);
	
	
	return 0;
}
