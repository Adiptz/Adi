#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "ws2_str.h"

int Check7(int num);


int IsPalindrome(const char *str)
{	
	const char *start = str;
	const char *end = str;
	
	assert(NULL != str);
	
	end += (strlen(str)-1); /*take end to the end of the string str*/

	while ((start < end)&&(tolower(*start) == tolower(*end)))
	{	
			++start;
			--end;
	}
	
	return (0 == *start - *end);
}


/* help function for SevenBoom */
int IsContaining7(int num) 
{    
    while (num != 0)
    {
        if ( 7 == (num % 10))
        {
        	return 0; 		/* There is 7 */
        }     
           
        num /= 10;
    }
    
    return 1; 		/* There is no 7 */
}

void SevenBoom(int from, int to)
{
	
    while (from <= to)
    {
        if (0 == (abs(from) % 7) || 0 == (IsContaining7(abs(from))))
        {
        	printf("BOOM!\n");
        }
        
        else
        {
        	printf("%d\n", from);
        }
        
        ++from;
    }
}


void SwapPtrInt(int **left, int **right)
{	
	int *tmp = 0;
	
	assert(NULL != right);
	assert(NULL != left);
	
	tmp = *left;
	*left = *right;
	*right = tmp;
}	

void MoveLeft(char *str)  /* help function for RmSpaces - shift string left */
{
	while (*str != '\0')
	{
		*str = *(str+1);
		++str;
	}
}

void RmSpaces(char *str)
{
	char *str_original = str;
	
	assert (NULL != str);
	
	/* remove all double space/TAB */ 
	while (*str != 0)   
	{
		if (32 == *str || 9 == *str)
		{
			if (32 == *(str+1) || 9 == *(str+1))  
			{
				MoveLeft(str);	
				--str; 										
			}	
		}
		
		++str;	
	}	
	
	/*remove space/TAB from the end*/
	if (32 == *(str-1) || 9 == *(str-1))  
	{
		*(str-1) = '\0';
	}
	
	str = str_original;
	
	/*remove space/TAB from the start*/
	if (32 == *str || 9 == *str)   
	{
		MoveLeft(str);
	}
}



/* help function to Addition of big numbers */
void ReverseStr(char *str)
{
	char *base = str;
	int tmp = 0;
	
	str += (strlen(str) - 1);
	
	while (base < str)
	{
		tmp = *str;
		*str = *base;
		*base = tmp;
		--str;
		++base;
	}
}

/* Add Big Numbers */
char *Addition(char *res, const char *num1, const char *num2)
{
	char *base = res;
	char carry = 0;
	char sum = 0;
	size_t len1 = strlen(num1);
	size_t len2 = strlen(num2);	

	assert(NULL != res);
	assert(NULL != num1);
	assert(NULL != num2);
	
	num1 += (len1-1);   /*point to the ends of string*/
	num2 += (len2-1);
	
	
	while ( len1 > 0 && len2 > 0 )  /* run times = lenght of the short string */
	{
		sum = *num1 + *num2 + carry - 48;
		
		if (sum >= 58)
		{ 
			*res = sum -10;
			carry = 1;
		}
		
		else
		{
			*res = sum;
			carry = 0;
		}
		
		--num1;
		--num2;
		++res;
		--len1;
		--len2;
	}	
	
	while (len1 > 0)   /* if num1 was longer */
	{
		sum = *num1 + carry;
		
		if (sum >= 58)
		{ 
			*res = sum -10;
			carry = 1;
		}
		else
		{
			*res = sum;
			carry = 0;
		}
		
		--len1;
		--num1;
		++res;
	}
	
	
	while (len2 > 0)   /* if num2 was longer */
	{
		sum = *num2 + carry;
		
		if (sum >= 58)
		{ 
			*res = sum -10;
			carry = 1;
		}
		else
		{
			*res = sum;
			carry = 0; 
		}
		
		--len2;
		--num2;
		++res;
	}
	/* if there is still carry */
	if (1 == carry)
	{
		*res = '1';
		*(res+1) = '\0';
	}

	ReverseStr(base);
	
	return base;

}

