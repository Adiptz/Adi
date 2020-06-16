/*************************
 *   Author   : Adi      *
 *************************/

/******************************************/
#include <stdio.h>	/* printf */
#include <stddef.h> /* size_t */
#include <assert.h> /* assert */
#include "mem.h"

#define WORD 8
/******************************************/

/********************* My Implamentation of memcpy *************************/
void *Memcpy(void *dest, const void *src, size_t n)
{		
	void *dest_original = NULL;

	assert(NULL != dest);
	assert(NULL != src);
	
	dest_original = dest;
	
	while (n > 0)
	{
	
		/* if address devide by 8 and (n > 8) *
		 * we want to copy src to dest        */
		if ((0 == ((size_t)dest % WORD)) && (n > WORD))
		{
			*(size_t*)dest = *(size_t*)src;
			n -= WORD;
			/* move dest and src for next address */ 
			src = (size_t *)src + 1;
			dest = (size_t *)dest + 1;
		}
		/* else we want to copy byte by byte */
		else 
		{
			*(char *)dest = *(char *)src;
			--n;
			/* move dest and src for next byte */ 
			src = (char *)src + 1;
			dest = (char *)dest + 1;
		}
	}
	
	assert(0 == n);
	
	return dest_original;
}	
/***************************************************************************/
 
/********************* My Implamentation of memset *************************/		
void *Memset(void *s, int c, size_t n)
{
	char *current_s = NULL;
	long word = 0;
	char rightest_byte = (char)c;

	assert(NULL != s);

	word = CreateWord(rightest_byte);
	
	while (n > WORD)
	{
		if ((0 == ((size_t)current_s % WORD)) && (n > WORD))
		{
			/* copy word by word */
			*current_s = word;
			current_s += WORD;
		}
		else 
		{
			/* copy byte by byte */
			*current_s = rightest_byte;
			--n;
			++current_s;
		}
	}
	
	assert(0 == n);
	
	return s;
}		

/****************       Service Function       *******************
 * filling 8 bytes with the pattern of givven single byte */	
long CreateWord(char single_byte)
{
	int counter = WORD;
	long eight_bytes = 0;
	
	while(counter--)
	{
		eight_bytes <<= WORD;
		eight_bytes |= single_byte;	
	}
	
	return eight_bytes;
}

/*****************************************************************************/

/********************* My Implementation Of memove ***************************/

void *Memmove(void *dest, const void *src, size_t n)
{			
	char *curr_dest = 0;
	char *curr_src = 0;
	
	assert(NULL != dest);
	assert(NULL != src);
	
	curr_dest = (char *)dest;
	curr_src = (char *)src;
	
	/* check if there is a over lap :                    *
	 * happens when srcs address goes over dests address */
	if(curr_src + n > curr_dest)
	{
		
		while(n--)
		{
			/* copy byte by byte */
			*(curr_dest + n) = *(curr_src + n);
		}
	}
	else
	{
		dest = Memcpy(dest, src, n);	
	}
	
	return dest;
}
/******************************************************************************/

