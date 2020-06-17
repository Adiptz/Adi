#include <stdio.h>
#include <string.h>

int IsRotate( char *str1, char *str2)
{
		int rotate = 0;
		char *copy_str2 = NULL;
		char *copy_str1 = NULL;
		int i = 0;
		int stop = 5;
		int x = 0;
		
		copy_str2 = str2;
		copy_str1 = str1;

	while (x < 5)
	{
		copy_str2 = strchr(copy_str2, *(copy_str1 + x));
				
		if (NULL == copy_str2)
		{
			return 0;
		}
		
		while (*(copy_str1 + x + (i % 5)) == *(copy_str2 + (i % 5)) && (i < 5))
		{
			++i;
			rotate = 1;
		}
		
		if (*(copy_str1 + x + (i % 5)) != *(copy_str2 + (i % 5)))
		{
			rotate = 0;
			++x;
		}
		
		++x;
	}
	
	


	return rotate;
}

int main()
{
	char *str1 = "HELLO";
	char *str2 = "OHELL";
	
	printf("%d\n", IsRotate(str1,str2));
	
	return 4;
	
}
