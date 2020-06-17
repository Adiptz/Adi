/* Adi Peretz -- OL712 -- 05/10/2019 */


#include <assert.h> /* assert */
#include <string.h> /*strlen */
#include <stdio.h> /* printf */

static void RotateLetters(char *str);
static void SwapFirstLetters(char *str);

static void PrintPrem(char *str)			
{
	size_t i = 0;
	size_t str_length = strlen(str);       
	size_t num_of_prem = str_length * (str_length - 1);
	
	for (i = 0; i < num_of_prem; ++i)	
	{
		if (0 == i % (str_length - 1))
		{
			SwapFirstLetters(str);			
		}
		else
		{
			RotateLetters(str + 1);
		}
		
		printf("%s\n", str);
	}
}

static void SwapFirstLetters(char *str)
{
	char tmp = '0';
	
	assert(NULL != str);
	
	tmp = *str;
	*str = *(str + 1);
	*(str + 1) = tmp;
}

static void RotateLetters(char *str)
{
	size_t str_length = strlen(str);  
	size_t i = 0;
	char first_letter = *str;
	
	for (i = 0; i < str_length - 1; ++i)
	{
		*(str + i) = *(str + i + 1);		
	}
	
	*(str + i) = first_letter;
}

int main()
{
	char str[] = "eat";
	char str1[] = "abcd";
	
	PrintPrem(str);
	puts("");
	PrintPrem(str1);
	
	return 0;
}

