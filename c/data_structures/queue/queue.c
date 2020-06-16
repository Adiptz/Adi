/**********************
 * Author : Adi       *
 * Reviewer : Shieber *
 * Status : Sent      *
 **********************/
 
#include <assert.h> /* assert */
#include <stdlib.h> /* malloc, free */

#include "../slist/slist.c" /* SListCreateNode, SListInsert, SListRemove */

#include "queue.h"


/**************************** -- QUEUE DESIGN -- ******************************/
struct queue
{
	slist_node_t *head; 
	slist_node_t *dummy_end; 
 	size_t size; 
};


/******************************* -- CREATE -- *********************************/
queue_t *QueueCreate(void)
{
	/* create manage list */
	queue_t *ptr_queue = (queue_t *)malloc(sizeof(queue_t));
	
	if(NULL == ptr_queue)
	{
		return NULL;
	}
	
	/* queue struct initalization */
	ptr_queue->dummy_end = /*TODO try return NULL*/
	SListCreateNode(NULL ,NULL); 
	ptr_queue->head = ptr_queue->dummy_end;
	ptr_queue->size = 0;
	
	return ptr_queue;
}

/****************************** -- DESTROY -- *********************************/
void QueueDestroy(queue_t *queue)
{
	assert(NULL != queue);
		
	SListFreeAll(queue->head);
	free(queue);	
}

/****************************** -- ENQUEUE -- *********************************/
int QueueEnqueue(queue_t *queue, const void *data)
{
	/*create new node with givven data*/
	slist_node_t *new = SListCreateNode((void *)data, queue->dummy_end);
	if(NULL == new)
	{
		return FAIL;
	}
	
	assert(NULL != queue);
	
	new = SListInsert(queue->dummy_end, new);
	
	queue->dummy_end = new->next_node;
	
	++queue->size;
	
	return SUCCESS;
}

/****************************** -- DEQUEUE -- *********************************/
int QueueDequeue(queue_t *queue)
{
	slist_node_t *removed = SListRemove(queue->head);
	
	assert(NULL != queue);
	
	if(QueueIsEmpty(queue))
	{
		return FAIL;
	}
	
	
	free(removed);
	
	--queue->size;
	
	return SUCCESS;
}

/******************************** -- SIZE -- **********************************/
size_t QueueSize(const queue_t *queue)
{
	assert(NULL != queue);
		
	return queue->size;	
}

/****************************** -- IS EMPTY -- ********************************/
int QueueIsEmpty(const queue_t *queue)
{
	assert(NULL != queue);
	
	return (0 == QueueSize(queue));
}

/******************************** -- PEEK -- **********************************/
void *QueuePeek(const queue_t *queue)
{
	assert(NULL != queue);
	
	return (queue->head->data);
}

/******************************* -- APPEND -- *********************************/
queue_t *QueueAppend(queue_t *dest, queue_t *src)
{
	slist_node_t *new_src_dummy = NULL;
	
	assert(dest != src);
	assert(NULL != src);
	assert(NULL != dest);
	
	/*end of dest pointing to src*/
	dest->dummy_end->next_node = src->head;
	
	new_src_dummy = SListRemove(dest->dummy_end);
	
	/*dest->dummy_end is src->dummy_end*/
	dest->dummy_end = src->dummy_end;
	
	/*src list is empty */
	src->head = new_src_dummy;
	
	dest->size += src->size;
	src->size = 0;
	
	return dest;
}
	
