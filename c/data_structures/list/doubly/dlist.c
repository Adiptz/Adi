
#include <stdlib.h> /* sizeof, malloc, free */
#include <assert.h> /* assert */
#include "dlist.h"

typedef struct dlist_node dlist_node_t;

/********************** -- LIST AND NODE STRUCTURES -- ************************/
struct dlist_node
{
	void *data;
	dlist_node_t *prev;
	dlist_node_t *next;
};

struct dlist 
{
	dlist_node_t *start;
	dlist_node_t *end;
};
/******************************************************************************/


/********************** -- CREATE NODE  help function -- **********************/
static dlist_iter_t CreateNode(void *data,
						       dlist_iter_t next,
							   dlist_iter_t prev)
{
	dlist_iter_t node = (dlist_iter_t)malloc(sizeof(struct dlist_node));
	if(NULL == node)
	{
		return NULL;
	}
	
	/*inatilization  members*/
	node->data = data;
	node->prev = prev;
	node->next = next;
	
	return node;
}

/**************************** -- CREATE LIST -- *******************************/
dlist_t *DListCreate(void)
{
	dlist_t *list = (dlist_t *)malloc(sizeof(struct dlist));
	if(NULL == list)
	{
		return NULL;
	}
	
	/*inatilization  members*/
	list->start = CreateNode(NULL, NULL, NULL);
	if(NULL == list->start)
	{
		free(list); list = NULL;
		return NULL;
	}

	list->end = CreateNode(NULL, NULL, list->start);
	if(NULL == list->end)
	{
		free(list); list = NULL;
		free(list->start); list->start = NULL;
		return NULL;
	}
	
	/* start points to end */
	list->start->next = list->end;

	return list;
}

/******************************* -- DESTROY -- ********************************/
void DListDestroy(dlist_t *list)
{
	dlist_iter_t current_node = NULL;
	dlist_iter_t end_node = NULL;
	
	assert(NULL != list);

	end_node =  DListEnd(list);
	current_node = DListBegin(list); 
	
	/* free all middles nodes */
	for(
		;(0 == DListIsSameIter(current_node, end_node))
		;current_node = DListRemove(current_node))
		{ /*empty body*/ }
		

	/*free start and end nodes*/
	free(list->start); list->start = NULL;
	free(list->end); list->end = NULL;
	free(list); list = NULL;
}

/******************************* -- IS EMPTY -- *******************************/
int DListIsEmpty(const dlist_t *list)
{
	assert(NULL != list);
	
	return (DListIsSameIter(DListBegin(list), DListEnd(list)));
}

/******************************* -- INSERT -- *********************************/
dlist_iter_t DListInsert(dlist_t *list, dlist_iter_t iter, void *data)
{
	dlist_iter_t new_node = NULL;
	
	assert(NULL != list);
	assert(NULL != iter);
	
	/* creat new node with given data */
	new_node =  CreateNode(data, iter, iter->prev);
	if(NULL == new_node)
	{
		return list->end;
	}
	
	/* set prev node to point to new_node */
	iter->prev->next = new_node;
		
	/* set iter to point back to new_node */
	iter->prev = new_node;
	
	return new_node;
}

/******************************* -- REMOVE -- *********************************/
dlist_iter_t DListRemove(dlist_iter_t iter_to_remove)
{
	dlist_iter_t after_remove = NULL;

	assert(NULL != iter_to_remove);
	
	after_remove = iter_to_remove->next;
	
	after_remove->prev = iter_to_remove->prev;
	iter_to_remove->prev->next = after_remove;
	
	free(iter_to_remove); iter_to_remove = NULL;
	
	return after_remove;
}

/******************************** -- SIZE -- **********************************/
size_t DListSize(const dlist_t *list)
{
	size_t size = 0;
	dlist_iter_t runner = NULL;
	
	assert(NULL != list);
	
	runner = DListBegin(list);
	
	while(runner != DListEnd(list))
	{
		++size;
		runner = DListNext(runner);
	}
	
	return size;
}

/****************************** -- FOR EACH -- ********************************/
int DListForEach(dlist_iter_t from, dlist_iter_t to, action_func func, 
				 											  	void *param)
{
	int ret_value = 0; 
	
	assert(NULL != from);
	assert(NULL != to);
	assert(NULL != func);
	
	while((0 == DListIsSameIter(from,to)) && 0 == ret_value)
	{
		ret_value = func(DListIterGetData(from), param);
		from = DListNext(from);
	}
	
	return ret_value;
}

/******************************** -- FIND -- **********************************/
dlist_iter_t DListFind(dlist_iter_t from, dlist_iter_t to,
					   cmp_func cmp, const void *data)
{
	assert(NULL != from);
	assert(NULL != to);
	assert(NULL != cmp);
	
	while((0 == DListIsSameIter(from,to)) && 0 != cmp(DListIterGetData(from), data))
	{
		from = DListNext(from);	
	}
	
	return from;
}

/***************************** -- PUSH FRONT -- *******************************/
dlist_iter_t DListPushFront(dlist_t *list, const void *data)
{
	dlist_iter_t push_node = NULL; 
	
	assert(NULL != list);
	
	push_node = DListInsert(list, DListBegin(list), (void *)data);
	
	return push_node;
}

/***************************** -- POP FRONT -- *******************************/
void *DListPopFront(dlist_t *list)
{
	void *data_tmp = NULL;
	
	assert(NULL != list);
	
	data_tmp = DListIterGetData(DListBegin(list));
	
	DListRemove(DListBegin(list));
	 	
	return data_tmp; 
}

/***************************** -- PUSH BACK -- ********************************/
dlist_iter_t DListPushBack(dlist_t *list, const void *data)
{
	dlist_iter_t push_node = NULL; 
	
	assert(NULL != list);
	
	push_node = DListInsert(list, DListEnd(list), (void *)data);
	
	return push_node;
}

/****************************** -- POP BACK -- ********************************/
void *DListPopBack(dlist_t *list)
{
	void *data_tmp = NULL;
	
	assert(NULL != list);
		
	data_tmp = DListIterGetData(DListBack(DListEnd(list)));
	
	DListRemove(DListBack(DListEnd(list)));
	 	
	return data_tmp; 
}



/******************************************************************************
 *																		 	  *
 *								ITER FUNCTIONS 								  *
 *																		      *
 ******************************************************************************/
 
 
/******************************* -- NEXT -- ***********************************/
dlist_iter_t DListNext(dlist_iter_t iter)
{
	assert(NULL != iter);
	
	return (iter->next);
}

/******************************* -- BACK -- ***********************************/
dlist_iter_t DListBack(dlist_iter_t iter)
{
	assert(NULL != iter);
	
	return (iter->prev);
}

/****************************** -- GET DATA -- ********************************/
void *DListIterGetData(dlist_iter_t iter)
{	
	assert(NULL != iter);
	
	return (iter->data);	
}

/******************************* -- BEGIN -- **********************************/
dlist_iter_t DListBegin(const dlist_t *list)
{
	assert(NULL != list);
	
	return (list->start->next);
}

/******************************** -- END -- ***********************************/
dlist_iter_t DListEnd(const dlist_t *list)
{
	assert(NULL != list);
	
	return (list->end);
}

/****************************** -- IS SAME -- *********************************/
int DListIsSameIter(const dlist_iter_t iter1, const dlist_iter_t iter2)
{
	assert(NULL != iter1);
	assert(NULL != iter2);
	
	return (iter1 == iter2);
}

/******************************* -- SPLICE -- *********************************/
dlist_iter_t DListSplice(dlist_iter_t iter_dest, dlist_iter_t iter_src_start, 
						                         dlist_iter_t iter_src_end)
{
	dlist_iter_t original_src_end_prev = NULL;

	assert(NULL != iter_dest);
	assert(NULL != iter_src_start);
	assert(NULL != iter_src_end);
	assert( NULL != DListBack(iter_dest)); /* check dest isn't dummy start */
	
	original_src_end_prev = iter_src_end->prev;
	
	/* remove nodes from src list */
	DListBack(iter_src_start)->next = iter_src_end;
	iter_src_end->prev = DListBack(iter_src_start);
	
	/* adding nodes to dest list */
	DListBack(iter_dest)->next = iter_src_start;
	iter_src_start->prev = DListBack(iter_dest);
	original_src_end_prev->next = iter_dest;
	iter_dest->prev = original_src_end_prev;
	
	return iter_dest;
}

