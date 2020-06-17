/*******************
 * Author : Adi    *
 * Review : Vova   *
 * Group  : fs712  *
 * Date   : 11/04  *
 *******************/
 
#include <stdio.h> /* printf */
#include <assert.h> /* assert */
#include <string.h> /* strlen */

void PrintPermutation(char *str);
void RotateString(char *str);
void RecPrintPermutation(char *original_str, char *str_to_rotate, size_t str_length);

int main()
{	
	char eat[] = "eat";
	char helo[] = "helo";
	
	PrintPermutation(eat);
	puts("");
	PrintPermutation(helo);

	return 0;
}
void PrintPermutation(char *str)
{
	size_t str_length = 0;
	
	assert(NULL != str);
	
	str_length = strlen(str);
	
	RecPrintPermutation(str, str, str_length);
}

void RecPrintPermutation(char *original_str, char *str_to_rotate, size_t str_length)
{
	size_t i = 0;
	
	if (1 == str_length)
	{
		printf("%s\n", original_str);
		return;
	}
		
	for (i = 0; i < str_length; ++i)
	{
		RotateString(str_to_rotate);
		RecPrintPermutation(original_str, str_to_rotate + 1, str_length - 1);
	}
}

void RotateString(char *str)
{
	size_t i = 0;
	size_t length = 0;
	char tmp = '\0';
	
	assert(NULL != str);
	
	length = strlen(str);
	
	tmp = str[i];
	
	for (i = 0; i < (length - 1) ; ++i)
	{
		str[i] = str[i + 1];
	}
	
	str[i] = tmp;
}
