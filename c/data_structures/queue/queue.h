#ifndef __OL71_QUEUE_H
#define __OL71_QUEUE_H

#include <stddef.h> /* size_t */

typedef struct queue queue_t;

enum {SUCCESS, FAIL};

/*
 * Create new Queue
 * Return: pointer to new queue
 * Errors: if memory allocation failed, return NULL
 */
queue_t *QueueCreate(void);


/*
 * Destroy Queue
 * Param queue : pointer to queue
 * Return: --
 * Errors: if pointer is NULL, behaviour is undefined 
 */
void QueueDestroy(queue_t *queue);


/*
 * Add new member to end of queue
 * Param queue : pointer to queue
 * Param data : pointer to data 
 * Return: return 0 for success, none-zero otherwise
 * Errors: if memory allocation failed, return 1
 */
int QueueEnqueue(queue_t *queue, const void *data);

/*
 * Remove member from head of queue
 * Param  queue : pointer to queue
 * Return: return 0 for success, none-zero otherwise
 * Errors: if pointer is NULL, behaviour is undefined 
 */
int QueueDequeue(queue_t *queue);

/*
 * Return pointer to data in head of queue
 * Param queue : pointer to queue
 * Return: void pointer to data 
 * Errors: 
 */
void *QueuePeek(const queue_t *queue);

/*
 * Returns amount of elements in queue
 * Param queue : pointer to queue
 * Return: size of queue
 * Errors: if queue is empty, return 0; 
 */
size_t QueueSize(const queue_t *queue);

/*
 * Check if queue is empty 
 * Param queue : pointer to queue
 * Return: 1 if empty, 0 otherwise
 * Errors: is pointer is NULL, behaviour is undefined 
 */
int QueueIsEmpty(const queue_t *queue);

/*
 * Concatenate src to end of dest
 * Param  queue : pointer to queue dest 
 * Param  queue : pointer to queue src  
 * Param condition: If dest and src are the same queue, behaviour is undefined 
 * Return: pointer to new queue
 * Errors: if one of the pointers is NULL, behaviour is undefined
 *        
 */
queue_t *QueueAppend(queue_t *dest, queue_t *src);

#endif /* __OL71_QUEUE_H */


