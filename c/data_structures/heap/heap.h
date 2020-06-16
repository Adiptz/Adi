/*********************************
 * Title       : Heap            *
 * Author      : Daya            *
 * Group       : OL712           *
 * Version     : 1.2             *
 * Last update : 03.10.2019      *
 *********************************/
#ifndef __ILRD_HEAP_H
#define __ILRD_HEAP_H

#include <stddef.h> /* size_t */

enum heap_status {HEAP_SUCCESS, HEAP_ALLOC_FAIL};

typedef struct heap heap_t;

/*
 * Create new heap
 * Param @capacity : initial capacity
 * Param @cmp_priority : function that serves as a key for the priority
 					return less than 0 if data1 priority is greater than data2
 					return greater than 0 if data1 priority is lesser than data2
 					return 0 if priority is equal 
 * Param @param : cmp_priority parameter
 * Return: pointer to new heap
 * Errors: if memory allocation failed, return NULL
 */
heap_t *HeapCreate(int (*cmp_priority)(const void *data1,
				   		const void *data2, void *param), void *param);

/*
 * Destroy heap
 * Param @heap : pointer to heap
 * Return: none
 * Errors: none
 */
void HeapDestroy(heap_t *heap);

/*
 * Add new member to heap according to priority
 * Param @heap : pointer to heap
 * Param @data : pointer to data
 * Return: return 0 for success, non-zero otherwise
 * Errors: if memory allocation failed, returns HEAP_ALLOC_FAIL.
 */
int HeapPush(heap_t *heap, const void *data);

/*
 * Remove member from top priority
 * Param @heap : pointer to heap
 * Return: none
 */
void HeapPop(heap_t *heap);

/*
 * Return pointer to data from top priority
 * Param @heap : pointer to heap
 * Return: void pointer to data
 * Errors: if heap is empty, behaviour is undefined
 */
void *HeapPeek(const heap_t *heap);

/*
 * Return amount of elements in heap
 * Param @heap : pointer to heap
 * Return: size of heap. if heap is empty, return 0
 * Errors: none
 */
size_t HeapSize(const heap_t *heap);

/*
 * Check if heap is empty
 * Param @heap : pointer to heap
 * Return: 1 if empty, 0 otherwise
 * Errors: none
 */
int HeapIsEmpty(const heap_t *heap);

/*
 * Remove data from heap
 * Param @heap : pointer to heap
 * Param @is_match : is_match function to match <data>
					 return 1 if <heap_data> matches <user_data>, 0 if not 
 * Param @data : data to compare
 * Return: pointer to removed <data>
 * Errors: if <data> was not found in heap or allocation failed return NULL
 */
void *HeapRemove(heap_t *heap, int (*is_match)(const void *heap_data,
			   	 const void *user_data), void *data);

#endif /* __ILRD_HASH_TABLE_H */
