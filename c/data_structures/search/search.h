/****************************************
 * Title  : search    					*
 * Author : Dandan Ogni                 *
 * Group  : OL712                       *
 * Date   : 07/10/2019               	*
 ****************************************/

#ifndef __ILRD_OL712_SEARCH_H
#define __ILRD_OL712_SEARCH_H

#include <stddef.h> /* size_t */

/*
 * Search in @base for @key using binary search iteratively.
 * @key: key to search.
 * @base: array to search in.
 * @nitems: number of elements in @base.
 * @elm_size: size of each element in base.
 * @cmp: compare function, return less than, equal, or more than 0 if first
 *		 argument should be before, is matching, or should be after the second.
 * return: found data, NULL if no data found.
 */
void *BSearchIterative(const void *key, const void *base, size_t nitems,
					   size_t elm_size, int (*cmp)(const void *, const void *));

/*
 * Search in @base for @key using binary search recursively.
 * @key: key to search.
 * @base: array to search in.
 * @nitems: number of elements in @base.
 * @elm_size: size of each element in base.
 * @cmp: compare function, return less than, equal, or more than 0 if first
 *		 argument should be before, is matching, or should be after the second.
 * return: found data, NULL if no data found.
 */
void *BSearchRecursive(const void *key, const void *base, size_t nitems,
					   size_t elm_size, int (*cmp)(const void *, const void *));

/*
 * Search in @base for @key using jump search.
 * @key: key to search.
 * @base: array to search in.
 * @nitems: number of elements in @base.
 * @elm_size: size of each element in base.
 * @cmp: compare function, return less than, equal, or more than 0 if first
 *		 argument should be before, is matching, or should be after the second.
 * return: found data, NULL if no data found.
 */
void *JSearch(const void *key, const void *base, size_t nitems, size_t elm_size,
			  int (*cmp)(const void *, const void *));

#endif /* __ILRD_OL712_SEARCH_H */
