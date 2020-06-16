#ifndef __OL71_PQUEUE_H
#define __OL71_PQUEUE_H

#include <stddef.h> /* size_t */

typedef struct pqueue pqueue_t;

enum {PQUEUE_SUCCESS, PQUEUE_FAILED};

/* return less than 0 if data1 priority is grater that data 2
   return grater than 0 if data1 is lesser priority than data2 
   return 0 if priority is equal */
typedef int (*cmp_priority)(void *data1, void *data2, const void *param);

/* return 1 if q_data and user_data match, 0 otherwise */
typedef int (*is_match)(void *q_data, const void *user_data, void *param);

/*
 * Create new pqueue
 * Param is_lower_priority : function that serves as a key for the priority
 * Param param : is_lower_priority parameter
 * Return: pointer to new pqueue
 * Errors: if memory allocation failed, return NULL
 */
pqueue_t *PQueueCreate(cmp_priority is_lower_priority, const void *param);


/*
 * Destroy pqueue
 * Param pqueue : pointer to pqueue
 * Return: none
 * Errors: none
 */
void PQueueDestroy(pqueue_t *pqueue);

/*
 * Add new member to pqueue according to priority
 * Param pqueue : pointer to pqueue
 * Param data : pointer to data 
 * Return: return PQUEUE_SUCCESS for success, PQUEUE_FAILED otherwise
 * Errors: if memory allocation failed, return PQUEUE_FAILED
 */
int PQueueEnqueue(pqueue_t *pqueue, const void *data);

/*
 * Remove member from top priority
 * Param pqueue : pointer to pqueue
 * Return: none
 * Errors: if queue is empty, behaviour is undefined
 */
void PQueueDequeue(pqueue_t *pqueue);

/*
 * Return pointer to data from top priority
 * Param pqueue : pointer to pqueue
 * Return: void pointer to data
 * Errors: if pqueue is empty, behavior is undefined
 */
void *PQueuePeek(const pqueue_t *pqueue);

/*
 * Returns amount of elements in pqueue
 * Param pqueue : pointer to pqueue
 * Return: size of pqueue, if pqueue is empty, return 0; 
 * Errors: none
 */
size_t PQueueSize(const pqueue_t *pqueue);

/*
 * Check if pqueue is empty 
 * Param pqueue : pointer to pqueue
 * Return: 1 if empty, 0 otherwise
 * Errors: none
 */
int PQueueIsEmpty(const pqueue_t *pqueue);

/*
 * Erase iter from pqueue
 * Param pqueue : pointer to pqueue
 * Param func : is_match function to compare <data>
 * Param data : data to compare
 * Return: pointer to data of erased iter
 * Errors: if <data> was not found in queue, return NULL    
 */
void *PQueueErase(pqueue_t *pqueue, is_match func, void *data, void *param);

/*
 * Clear all elements from pq
 * Param  pqueue : pointer to pqueue
 * Return: none
 * Errors: none        
 */
void PQueueClear(pqueue_t *pqueue);

#endif /* __OL71_PQUEUE_H */


