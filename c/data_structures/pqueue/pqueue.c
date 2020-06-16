/***********************
 * Author   : Adi      *
 * Reviewer : Giveret  *
 * Status   : Approved *
 ***********************/

#include <stdlib.h> /* malloc, free*/
#include <assert.h> /* assert */

#include "sorted_list.h" /* delegation fot Sortedlist Funcs */
#include "pqueue.h"

typedef struct param param_t;
#define UNUSED(x) (void)(x)

static int IsBeforeAdp(void *data1, void *data2, const void *param);

/**************************** -- PQUEUE DESIGN -- *****************************/
struct param
{
	cmp_priority cmp;
	void *param;
};

struct pqueue
{
	sorted_list_t *sorted_list;
	param_t param;
};

/******************************* -- CREATE -- *********************************/
pqueue_t *PQueueCreate(cmp_priority is_lower_priority, const void *param)
{
	
	pqueue_t *new_pqueue = (pqueue_t *)malloc(sizeof(pqueue_t));
	if(NULL == new_pqueue)
	{
		return NULL;
	}
	
	assert(NULL != is_lower_priority);

	/*initialized new_pqueue members */
	new_pqueue->param.cmp = is_lower_priority;
	new_pqueue->param.param = (void *)param;
	new_pqueue->sorted_list = SortedListCreate(IsBeforeAdp, &new_pqueue->param);
	if(NULL == new_pqueue->sorted_list)
	{
		free(new_pqueue); new_pqueue = NULL;
		return NULL;
	}
	
	return new_pqueue;
}

/****************************** -- DESTROY -- *********************************/
void PQueueDestroy(pqueue_t *pqueue)
{
	assert(NULL != pqueue);
	SortedListDestroy(pqueue->sorted_list); pqueue->sorted_list = NULL;
	free(pqueue); pqueue = NULL;
}

/****************************** -- ENQUEUE -- *********************************/
int PQueueEnqueue(pqueue_t *pqueue, const void *data)
{
	sorted_list_iter_t insert = {NULL};

	assert(NULL != pqueue);
	
	insert = SortedListInsert(pqueue->sorted_list, data);
		
	return (SortedListIsSameIter(SortedListEnd(pqueue->sorted_list), insert));
}

/****************************** -- DEQUEUE -- *********************************/
void PQueueDequeue(pqueue_t *pqueue)
{
	assert(NULL != pqueue);
	
	SortedListPopFront(pqueue->sorted_list);
}

/******************************** -- PEEK -- **********************************/
void *PQueuePeek(const pqueue_t *pqueue)
{
	assert(NULL != pqueue);
		
	return SortedListGetData(SortedListBegin(pqueue->sorted_list));
}

/******************************** -- SIZE -- **********************************/
size_t PQueueSize(const pqueue_t *pqueue)
{
	assert(NULL != pqueue);
	
	return SortedListSize(pqueue->sorted_list);
}

/****************************** -- IS EMPTY -- ********************************/
int PQueueIsEmpty(const pqueue_t *pqueue)
{
	assert(NULL != pqueue);

	return SortedListIsEmpty(pqueue->sorted_list);
}

/******************************** -- ERASE -- *********************************/
void *PQueueErase(pqueue_t *pqueue, is_match func, void *data, void *param)
{
	sorted_list_iter_t iter = {NULL};
	void *req_data = NULL;

	assert(NULL != pqueue);
	assert(NULL != func);
	assert(NULL != data);

	iter = SortedListFindIf(SortedListBegin(pqueue->sorted_list),
						    SortedListEnd(pqueue->sorted_list),
							func,
							data,
							param);
	
	if(SortedListIsSameIter(iter, SortedListEnd(pqueue->sorted_list)))
	{
		return NULL;
	}
				
	req_data = SortedListGetData(iter);
	
	SortedListRemove(iter);
								
	return req_data;
}

/******************************* -- CLEAR -- **********************************/
void PQueueClear(pqueue_t *pqueue)
{
	assert(NULL != pqueue);

	while (0 == PQueueIsEmpty(pqueue))
	{
		PQueueDequeue(pqueue);
	}
}

/*/****************************** prioroty func *******************************/ 
static int IsBeforeAdp(void *data1, void *data2, const void *pqueue)
{
	assert(NULL != pqueue);
	
	return 0 < (((param_t *)pqueue)->cmp
								   (data1, data2, ((param_t *)pqueue)->param));
}	

