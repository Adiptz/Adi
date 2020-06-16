#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include "str.h"
 

/*******************************
 *		Author : Adi	       *
 *******************************
 
 
 
 ******************************
 *          Strlen            *
 *  Input : *p to string      *
 *  Output: length of string  *
 ******************************/

size_t Strlen(const char *p)
{	
	size_t length = 0;
	
	assert(NULL != p);
	
	while (*p != '\0')
	{
	 ++p;
     ++length;
	}

	return length;
}

/********************************
 *           Strcmp             *				
 * Input  : 2 strings	        *
 * Output :  a > b =  1	        *
 *           a < b = -1         *
 *           a = b =  0         *						    
 ********************************/
 
int Strcmp(const char *a, const char *b)
{
	assert(NULL != a);
	assert(NULL != b);
	
	while (*a != '\0' && *a == *b)
	{
		++a;
		++b;
	}
	
	return (*a - *b);
}

/*********************************
 *           Strcpy              *				
 * Input  : 2 pointers	         *
 * Output : copy source string   *
 *         to destination string *    					    
 *********************************/
 
char *Strcpy(char *dest, char *src)
{
	char *dest_original = dest;
	
	assert(NULL != dest);
	assert(NULL != src);
	
	while (*src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
	} 
 	
 	*dest = '\0'; /* compare *dest to '\0' */
 	
 	return dest_original;
}
 
 /*********************************
  *           Strncpy             *				
  * Input  : 2 pointers + n       *
  * Output : copy n character     *
  *          of source string     *
  *         to destination string *    					    
  *********************************/
  
char *Strncpy(char *dest, const char *src, size_t n)
{	
	char *dest_original = dest;
	size_t i = 0;
	size_t length = strlen(dest);
	
	assert(NULL != dest);
	assert(NULL != src);
			
	for(i = 0; i < n; ++i)
	{
		*dest = *src;
		++dest;
		++src;	
	} 
	/* indexes left to fill with '\0' */
	i = length - n ; 
	
	while (i--) 
	{
		*(dest) = '\0';
		++dest;
	}
  	
	return dest_original;
}
  
 /*******************************
  *       Strcasecmp            *				
  *   Input  : 2 strings        *
  *   Output : a > b =  1	    *
  *            a < b = -1       *
  *            a = b =  0       *
  *   lowercase = upper case    *
  *   abc = ABC                 *						    
  *******************************/
  
int Strcasecmp(const char *string1, const char *string2)
{
	assert(NULL != string1);
	assert(NULL != string2);	
	
  	while (*string1 != '\0' &&  tolower(*string1) == tolower(*string2 ))
  	{  
  		++string1;
  		++string2;
  	}
  	
  	return (*string1 - *string2);
}
 
 

/**********************************
 *           Strchr               *				
 * Input  : pointer to str	      *
 *          and char              *
 * Output : pointer to where the  *
 *		char is in the string     *    					    
 **********************************/
 
char *Strchr(const char *str, int c)
{
	size_t i = 0;
	
	assert(NULL != str);
	
	for (i = 0; i < strlen(str); ++i)
	{
		if (*str != c)
		{
			++str;
		}
		
		else
		{
		return (char *)str;
		}
	}  
 	
 	return NULL;
}
 
 
 /*********************************
 *           Strdup               *				
 * Input  : pointer to str	      *
 * Output : pointer to where	  *
 *			is the duplication    *
 *			other location        *    					    
 **********************************/
 
char *Strdup(const char *str1)
{ 
	char *duplicate = (char*)malloc((sizeof(char))*(Strlen(str1) + 1));
	
	assert(NULL != str1);	
	
	Strcpy(duplicate, (char*)str1);
 	
 	return duplicate;
}
 
 
 
/**********************************
 *           Strcat               *
 * Input  : 2 strings             *
 * Output : adding str2 to the    *
 * end of str 1                   *      
 **********************************/
 
char *Strcat(char *dest, const char *src)
{
	char *start = dest;

	assert(NULL != dest);
	assert(NULL != src);
	
	dest = dest + Strlen(dest);

	Strcpy(dest, (char *)src);

	return start;
}

 /**************************************
 *           Strncat                    *
 * Input  : 2 strings & number of      *
 * elements to copy           *
 * Output : dest+number elemnts of src *      
 ***************************************/
 
char *Strncat(char *dest, const char *src, size_t n)
{
	char *start = dest;
	
	assert(NULL != dest);
	assert(NULL != src);

	dest = dest + Strlen(dest);

	Strncpy(dest, src, n);

	return start;
}
 
