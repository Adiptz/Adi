#ifndef __OL71_SORTLIST_H
#define __OL71_SORTLIST_H

#include <stddef.h> /* size_t */

#include "dlist.h" /* dlist_iter_t */

typedef struct sorted_list sorted_list_t;

typedef struct
{
    dlist_iter_t diter;
} sorted_list_iter_t;

/*return 1 if data1 is before data2 or 0 if data1 is after data2*/
typedef int (*is_before)(void *data1, void *data2, const void *param);

/*return 1 if match found, 0 otherwise */
typedef int (*sorted_list_is_match)(void *data1, const void *data2, void *param);

/*return 0 for success, non-zero otherwise*/
typedef int (*sorted_list_action_func)(void *data, void *param);

/****************
 * FUNCTIONS    *
 ****************/

/*
 * Create new sorted linked list
 * Param is_before func : function that serves as a key for the sort comparison
 * Param param : is_before function parameter
 * Return : pointer to new sorted list
 * Errors : if memory allocation fails, return NULL
 */
sorted_list_t *SortedListCreate(is_before func, const void *param);

/*
 * Destroy sorted linked list
 * Param sorted linked list: pointer to list
 * Return : --
 * Errors : if list pointer is not valid, behaviour is undefined
 */
void SortedListDestroy(sorted_list_t *list);

/*
 * Insert new element with <data> in the correct position within the sorted list
 * Param sorted linked list: pointer to list
 * Param data : pointer to data of new element
 * Return : iter to new element
 * Errors : if memory allocation failed, return END
 */
sorted_list_iter_t SortedListInsert(sorted_list_t *list, const void *data);

/*
 * Remove element from sorted linked list
 * Param sorted_list_iter_t iter_to_remove: pointer to element to remove
 * Return : iter to next element
 * Errors : if iter is not valid, behaviour is undefined
 */
sorted_list_iter_t SortedListRemove(sorted_list_iter_t iter_to_remove);

/*
 * Remove first element of the list
 * Param list : pointer to list
 * Return : pointer to data of popped element
 * Errors: if the list is empty, behaviour is undefined
 */
void *SortedListPopFront(sorted_list_t *list);

/*
 * Remove last element of the list.
 * Param list: pointer to the list.
 * Return : pointer to data of popped element
 * Errors : if the list is empty, behaviour is undefined
 */
void *SortedListPopBack(sorted_list_t *list);

/*
 * Check if sorted linked list is empty
 * Param list :  pointer to list
 * Return: 1 if empty and 0 otherwise
 * Errors : --
 */
int SortedListIsEmpty(const sorted_list_t *list);

/*
 * Size of list
 * Param list : pointer to list
 * Return : number of elements in list
 * Errors : --
 */
size_t SortedListSize(const sorted_list_t *list);

/*
 * Perform a function for every element in the sorted list
 * Param from : iterator to start operation from
 * Param to : iterator to stop operation at (not included in comparison)
 * Param param : pointer to additional parameters
 * Param func : pointer to action function
 * Return : last return status. stop operation if func_action return non-zero
 * Errors : if list or function pointers are not valid, behaviour is undefined
 *          if action_func changes sorted data, list behaviour is undefined
 */
int SortedListForEach(sorted_list_iter_t from, sorted_list_iter_t to,
                      sorted_list_action_func func, void *param);

/*
 * Find element with matching data
 * Param from : iterator to start search from
 * Param to : iterator to stop search at (not included in comparison)
 * Param data : pointer to data to compare
 * Return : iter to first matching element found, iter to to if no match found
 * Errors : if list pointer or one or both iters is not valid,
 *            behaviour is undefined
 */
sorted_list_iter_t SortedListFind(const sorted_list_t *list,
                                  sorted_list_iter_t from,
                                  sorted_list_iter_t to, const void *param);

/*
 * Merge two sorted lists
 * Param list_dest : list to be merged into
 * Param list_src : list to be merged
 *                    (after merging, list_src will be empty but still valid)
 * Return : pointer to merged list_dest
 * Errors : if one or both list pointers are not valid, behaviour is undefined
 *          if list_src and list_dest are sorted differently,
 *            behaviour is undefined
 */
sorted_list_t *SortedListMerge(sorted_list_t *list_dest,
                               sorted_list_t *list_src);

/*
 * Find element with matching data
 * Param from : iterator to start search from
 * Param to : iterator to stop search at (not included in comparison)
 * Param data : pointer to data to compare
 * Param cmp : pointer to compare function
 * Return : iter to first matching element found, iter to to if no match found
 * Errors : if function pointer or one or both iters is not valid,
 *             behaviour is undefined
 */
sorted_list_iter_t SortedListFindIf(sorted_list_iter_t from,
                                    sorted_list_iter_t to,
                                    sorted_list_is_match func, 
                                    const void *data, void *param);

/*
 * Returns iterator to the first element of the sorted list
 * Param : pointer to list
 * Return: Iterator to the first element in the list
 * Errors: if the list is empty, return END
 */
sorted_list_iter_t SortedListBegin(const sorted_list_t *list);

/*
 * Returns iterator to the end of the sorted list
 * Param list : pointer to list
 * Return : Invalid iterator representing end of list
 * Errors : --
 */
sorted_list_iter_t SortedListEnd(const sorted_list_t *list);

/*
 * Returns iterator to the next element
 * Param iter :iterator to the current element in sorted list.
 * Return : Iterator to the next element.
 * Errors : if iter is last element, return END
 */
sorted_list_iter_t SortedListNext(sorted_list_iter_t iter);

/*
 * Returns iterator to the previous element.
 * Param iter : iterator to the current element in sorted list
 * Return : iterator to the previous element
 * Errors : if iter is first element, behaviour is undefined
 */
sorted_list_iter_t SortedListPrev(sorted_list_iter_t iter);

/*
 * get data pointer pointed to by iterator.
 * Param iterator: iterator
 * Return : pointer to data in element pointed by iterator
 * Errors : --
 */
void *SortedListGetData(sorted_list_iter_t iter);

/*
 * Compares two iterators of sorted lists
 * Param iter1, iter2 - sorted lists iterators
 * Return : 1 if equal, 0 otherwise.
 * Errors : --
 */
int SortedListIsSameIter(const sorted_list_iter_t iter1,
                         const sorted_list_iter_t iter2);

#endif /*__OL71_SORTLIST_H*/









