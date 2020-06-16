#ifndef __OL71_DLIST_H
#define __OL71_DLIST_H

#include <stddef.h> /* size_t */

typedef struct dlist dlist_t;

typedef struct dlist_node *dlist_iter_t;

typedef int (*cmp_func)(void *data, const void *param);
typedef int (*action_func)(void *data, void *param);

/****************
 * FUNCTIONS	*
 ****************/

/*
 * Create new doubly linked list
 * Param : none
 * Return : pointer to new dlist
 * Errors : return NULL if allocation fails
 */
dlist_t *DListCreate(void);

/*
 * Destroy doubly linked list
 * Param list : pointer to list
 * Return : none
 * Errors : --
 */
void DListDestroy(dlist_t *list);

/*
 * Check if doubly linked list is empty
 * Param  list :  pointer to list
 * Return: 1 if empty and 0 otherwise
 * Errors: --
 */
int DListIsEmpty(const dlist_t *list);

/*
 * Insert new element with <data> before <iter>
 * Param list : pointer to list 
 * Param iter : iterator in list
 * param data : pointer to data of new element
 * Return : iter to new element
 * Errors : if memory allocation failed, return end iterator
 */
dlist_iter_t DListInsert(dlist_t *list, dlist_iter_t iter, void *data);

/*
 * Remove element from list
 * Param list : pointer to list 
 * Param iter_to_remove: iterator of element to remove 
 * Return: iter to next
 * Errors: --
 */
dlist_iter_t DListRemove(dlist_iter_t iter_to_remove);

/*
 * Size of list
 * Param list : pointer to list
 * Return : number of elements in list
 * Errors : --
 */
size_t DListSize(const dlist_t *list);

/*
 * Perform a function for every element in the Dlist
 * Param from : iterator to start operation from
 * Param to : iterator to stop operation at (last action done on previous iter)
 * Param param : pointer to additional parameters
 * Param func : pointer to action function
 * Return : last return status. stop operation if func_action return non-zero
 */
int DListForEach(dlist_iter_t from, dlist_iter_t to, action_func func, 
				 void *param);

/*
 * Find element with matching data
 * Param from : iterator to start search from
 * Param to : iterator to stop search at (last comparison done on previous iter)
 * Param cmp : pointer to compare func, return 0 if equal, non-zero otherwise
 * Param data : pointer to data to compare
 * Return : pointer to first matching element found 
 * Errors : if no match was found, return <to>
 */
dlist_iter_t DListFind(dlist_iter_t from, dlist_iter_t to, cmp_func cmp,
					   const void *data);

/*
 * Insert data to the beginning of the list.
 * Param list: pointer to the list.
 * Param data: pointer to the data to add.
 * Return: on success return iter to new element, else return iter to end
 * Errors: if memory allocation fails, return iter to end
 */
dlist_iter_t DListPushFront(dlist_t *list, const void *data);

/*
 * Remove first element of the list.
 * Param list : pointer to the list.
 * Return : popped element's data.
 * Errors: if list is empty, behaviour is undefined.
 */
void *DListPopFront(dlist_t *list);

/*
 * Insert data to the end of the list.
 * Param list: pointer to the list.
 * Param data: pointer to the data to add.
 * Return: on success return iter to new element, else return iter to end
 * Errors: if memory allocation fails, return iter to end
 */
dlist_iter_t DListPushBack(dlist_t *list, const void *data);

/*
 * Remove last element of the list.
 * Param list: pointer to the list.
 * Return : popped element's data.
 * Errors: if list is empty, behaviour is undefined.
 */
void *DListPopBack(dlist_t *list);

/*
 * Iterator to the next element.
 * Param iterator: iterator to the current element.
 * Return: Iterator to the next element.
 * Errors: Undefined behavior if iter points to an end iterator.
 */
dlist_iter_t DListNext(dlist_iter_t iter);

/*
 * Iterator to the previous element.
 * Param iter: iterator to the current element.
 * Return: iterator to the previous element.
 * Errors: Undefined behavior if iter points to a begin iterator.
 */
dlist_iter_t DListBack(dlist_iter_t iter);

/*
 * get data pointer pointed to by iterator.
 * Param iterator: iterator
 * Return : pointer to data in element pointed by iterator 
 * Errors : --
 */
void *DListIterGetData(dlist_iter_t iter);

/*
 * Iterator to the first element in the list.
 * Param dlist: pointer to list
 * Return: Iterator to the first element in the list.
 * Errors: if list is empty return end
 */
dlist_iter_t DListBegin(const dlist_t *dlist);

/*
 * Iterator to the end of the dlist.
 * Param alist: pointer to list
 * Return: Invalid iterator representing end of list
 * Errors: --
 */
dlist_iter_t DListEnd(const dlist_t *dlist);

/*
 * Compares two dlist iterators.
 * Param iter1, iter2 - dlist iterators
 * Return: 1 if equal, 0 otherwise.
 * Errors: --
 */
int DListIsSameIter(const dlist_iter_t iter1, const dlist_iter_t iter2);

/*
 * Insert part of list before iter_dest 
 * Param iter_dest: pointer to the list for adding.
 * Param iter_src_start: pointer to beginning of source
 * Param iter_src_end: pointer to end of source (not included) - must be after
					   iter_src_start.
 * Return: pointer to iter_dest
 * Errors: if iter_src_end is before iter_src_start, behaviour is undefined
 */
dlist_iter_t DListSplice(dlist_iter_t iter_dest, dlist_iter_t iter_src_start, 
						                         dlist_iter_t iter_src_end);

#endif /* __OL71_DLIST_H */

