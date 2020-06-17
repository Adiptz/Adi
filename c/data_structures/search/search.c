
#include <assert.h> /* assert */
#include <math.h> /* sqrt */

#include "search.h"


void *BSearchIterative(const void *key, const void *base,
					   size_t number_of_elements,
					   size_t element_size,
					   int (*cmp)(const void *, const void *))
{
	void *left = NULL;
	void *right = NULL;
	
	assert(NULL != key);
	assert(NULL != base);
	
	left = (void *)base;
	right = (char *)base + (number_of_elements - 1) * element_size;
	
	while (left <= right)
	{
		void *middle = (char *)left +
					   ((number_of_elements -1) / 2) * element_size;
		int cmp_result = cmp(middle, key);
		
		if (0 == cmp_result)
		{
			return middle;
		}
		
		if (0 > cmp_result)
		{
			left = (char *)middle + element_size;
		}
		else
		{
			right = (char *)middle - element_size;
		}
		
		number_of_elements /= 2;
	}
	
	return NULL;

}


void *BSearchRecursive(const void *key, const void *base,
					   size_t number_of_elements,
					   size_t element_size,
					   int (*cmp)(const void *, const void *))
{
	void *middle = (char *)base + (number_of_elements / 2 * element_size);
	int cmp_result = cmp(middle, key);
	size_t left_side_size = 0;
	
	if (0 == cmp_result) /* key found */
	{
		return middle;
	}
	
	if (1 >= number_of_elements) /* key not found */
	{
		return NULL;
	}
	
	left_side_size = ((char *)middle - (char *)base) / element_size;
	
	if (0 > cmp_result) /* needs to search on right side */
	{
		void *new_base = (char *)middle + element_size;
		size_t right_side_size = number_of_elements - left_side_size - 1;
		
		return BSearchRecursive(key, new_base,
							    right_side_size,
								element_size, cmp);
	}
	else  /* needs to search on left side */
	{
		return BSearchRecursive(key, base, left_side_size, element_size, cmp);	
	}
}


void *LinearSearch(const void *key, void *from, void *to, size_t element_size,
				   int (*cmp)(const void *, const void *))
{
	void *runner = NULL;
	
	for ( runner = from
		; runner < to
		; runner = (char *)runner + element_size)
	{
		int cmp_result = cmp(runner, key);
		
		if (0 == cmp_result)
		{
			return runner;
		}
		
		if (0 < cmp_result) /* optimization */
		{
			return NULL;
		}
	}
	
	return NULL;
}
				   

void *JSearch(const void *key, const void *base,
		      size_t number_of_elements,
		      size_t element_size,
		      int (*cmp)(const void *, const void *))
{
	void *jumper = (void *)base;
	void *follower = (void *)base;
	void *end = (char *)base + (number_of_elements * element_size);	
	size_t jump_range = sqrt(number_of_elements);
	
	for ( jumper = follower
		; jumper < end
		; jumper = (char *)jumper + (jump_range * element_size))
	{
		int cmp_result = cmp(jumper, key);
		
		if (0 == cmp_result)
		{
			return jumper;
		}	
		else if (0 > cmp_result)
		{
			follower = jumper;
		}
		else
		{
			return LinearSearch(key, follower, jumper, element_size, cmp);
		}
	}
	
	return LinearSearch(key, follower, end, element_size, cmp);	
}

