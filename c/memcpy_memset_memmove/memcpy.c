#include "memcpy.h"

#define WORD sizeof(void *)

void *Memcpy(void *dest, const void *src, size_t bytes)
{	
	size_t words_to_cpy = bytes / WORD;
	size_t bytes_to_cpy = bytes % WORD;
	void *original_dest = NULL;
	size_t i = 0;
	
	assert(NULL != dest);
	assert(NULL != src);
	
	original_dest = dest;
	
	/*copy word by word */
	for (i = 0; i < words_to_cpy; ++i)
	{
		*(size_t *)dest = *(size_t *)src;
		dest = ((size_t *)dest) + 1;
		src = ((size_t *)src) + 1;
	}
	
	/*copy byte by byte */
	for (i = 0; i < bytes_to_cpy; ++i)
	{
		*(char *)dest = *(char *)src;
		dest = ((char *)dest) + 1;
		src = ((char *)src) + 1;
	}
	
	return original_dest;
}



