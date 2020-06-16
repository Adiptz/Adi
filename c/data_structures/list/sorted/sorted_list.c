/**************************
 *    Author  : Adi       *
 *    Reviwer : Daya      *
 *    Status  : Sent      *
 **************************/
 
/****************************** -- LIBARIES -- ********************************/
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */

#include "sorted_list.h" 
#include "dlist.h"  /*delegation fot DListFuncs */

/**************************** -- LIST STRUCTURE -- ****************************/
struct sorted_list
{
	dlist_t *dlist;
	is_before comperator;
	void *param;
};

typedef struct patch /*TODO : give informative name */
{
	void *user_data;
	void *user_param;
	sorted_list_is_match user_func;
}patch_t;

static int IsMatch_Adapt(void *data1, const void *patch);
static patch_t PatchInit(void *data, void *param, sorted_list_is_match func);

/************************ -- CREATE SORTED LIST -- ****************************/
sorted_list_t *SortedListCreate(is_before func, const void *param)
{	
	sorted_list_t *new_sorted_list = NULL;

	assert(NULL != func);

	new_sorted_list =(sorted_list_t *)malloc(sizeof(sorted_list_t));
	if(NULL == new_sorted_list)
	{
		return NULL;
	}
	
	/* initialized members in sorted-list struct */
	new_sorted_list->dlist = DListCreate();
	if(NULL == new_sorted_list->dlist)
	{
		free(new_sorted_list); new_sorted_list = NULL;
		return NULL;
	}
	
	new_sorted_list->comperator = func;
	new_sorted_list->param = (void *)param;
	
	return new_sorted_list;
}

/******************************* -- DESTROY -- ********************************/
void SortedListDestroy(sorted_list_t *list)
{
	assert(NULL != list);
	
	DListDestroy(list->dlist); list->dlist = NULL;
	free(list); list = NULL;
}

/******************************* -- INSERT -- ********************************/
sorted_list_iter_t SortedListInsert(sorted_list_t *list, const void *data)
{
	sorted_list_iter_t runner_iter = {NULL};
	sorted_list_iter_t end_iter = {NULL};
	
	assert(NULL != list);
	assert(NULL != data);
	
	for(  end_iter = SortedListEnd(list),
		  runner_iter = SortedListBegin(list)
		;
		  !SortedListIsSameIter(runner_iter, end_iter)
		  && list->comperator
		  (SortedListGetData(runner_iter), (void *)data, list->param) 
		;
		  runner_iter = SortedListNext(runner_iter)
		)
		{/* empty body*/}
	
	/* insert iter with given data to sorted-list*/
	runner_iter.diter =
					DListInsert(list->dlist, runner_iter.diter, (void *) data);
	
	return runner_iter;
}

/******************************* -- REMOVE -- *********************************/
sorted_list_iter_t SortedListRemove(sorted_list_iter_t iter_to_remove)
{
	assert(NULL != iter_to_remove.diter);
		
	iter_to_remove.diter = DListRemove(iter_to_remove.diter);	
	
	return iter_to_remove;
}

/***************************** -- POP FRONT -- ********************************/
void *SortedListPopFront(sorted_list_t *list)
{
	assert(NULL != list);
	assert(!SortedListIsEmpty(list));
	
	return DListPopFront(list->dlist);	
}

/****************************** -- POP BACK -- ********************************/
void *SortedListPopBack(sorted_list_t *list)
{
	assert(NULL != list);
	assert(!SortedListIsEmpty(list));

	return DListPopBack(list->dlist);
}

/******************************* -- IS EMPTY -- *******************************/
int SortedListIsEmpty(const sorted_list_t *list)
{
	assert(NULL != list);
	
	return DListIsEmpty(list->dlist);
}

/******************************** -- SIZE -- **********************************/
size_t SortedListSize(const sorted_list_t *list)
{
	assert(NULL != list);
	
	return DListSize(list->dlist);
}

/****************************** -- FOR EACH -- ********************************/
int SortedListForEach(sorted_list_iter_t from,
					  sorted_list_iter_t to,
                      sorted_list_action_func func,
                      void *param)
{
	assert(NULL != from.diter);
	assert(NULL != to.diter);
	assert(NULL != func);
	
	return DListForEach(from.diter, to.diter, func, param);
}
/******************************** -- FIND -- **********************************/
sorted_list_iter_t SortedListFind(const sorted_list_t *list,
                                  sorted_list_iter_t from,
                                  sorted_list_iter_t to,
                                  const void *param)
{
	sorted_list_iter_t run_iter = {0};
	sorted_list_iter_t prev = {0};

	assert(NULL != list);
	assert(NULL != from.diter);
	assert(NULL != to.diter);

	/* run as long as list->data is before given param */
	for ( run_iter = from
		; !SortedListIsSameIter(run_iter, to)
		   && (list->comperator
	          (SortedListGetData(run_iter), (void *)param, list->param))
		; run_iter = SortedListNext(run_iter)
		)
	{/* empty body */}

	prev = SortedListPrev(run_iter);

	/* check if data before iter is equal to params data */
	if (!SortedListIsSameIter(run_iter, from)
	  && (list->comperator((void *)param, SortedListGetData(prev), list->param)
	 == list->comperator(SortedListGetData(prev), (void *)param, list->param)))
	{
		run_iter = prev;
	}
	/* check if param isn't before prev_data, means isn't in list */
	else if (list->comperator
	   		((void *)param, SortedListGetData(run_iter), list->param))
	{
		run_iter = to;
	}

	return run_iter;
} 
	
	             
/******************************** -- MERGE -- *********************************/
sorted_list_t *SortedListMerge(sorted_list_t *list_dest,
                               sorted_list_t *list_src)
{
	sorted_list_iter_t to_src = {NULL};
	sorted_list_iter_t from_src = {NULL};
	sorted_list_iter_t curr_dest = {NULL};
	sorted_list_iter_t end_src = {NULL};
	sorted_list_iter_t end_dest = {NULL};
	
	assert(NULL != list_dest);
	assert(NULL != list_src);
	
	from_src = SortedListBegin(list_src);
	to_src = from_src;
	curr_dest = SortedListBegin(list_dest);
	end_src = SortedListEnd(list_src);
	end_dest =  SortedListEnd(list_dest);
	
	/* if there's nothing to merge  TODO */
	if(SortedListIsEmpty(list_src))
	{
		return list_dest;
	}
	
	/* as long as dest didnt reach to end */
	while(!SortedListIsSameIter(curr_dest, end_dest))
	{	
		/* get range of iters to insert from src to dest */
		while(1 == list_dest->comperator(SortedListGetData(to_src),
								         SortedListGetData(curr_dest),
								         list_dest->param))
		{
			to_src = SortedListNext(to_src);
		}
		
		if(!SortedListIsSameIter(to_src, from_src))
		{
			DListSplice(curr_dest.diter, from_src.diter, to_src.diter);
			from_src = to_src;	
		}
		
		curr_dest = SortedListNext(curr_dest);
	}
	
	/* merging src tail if dest reach to end */
	if(!SortedListIsSameIter(to_src, end_src))
	{
		DListSplice(curr_dest.diter, to_src.diter, end_src.diter);
	}
	
	return list_dest;
}

/******************************* -- FIND IF -- ********************************/
sorted_list_iter_t SortedListFindIf(sorted_list_iter_t from,
                                    sorted_list_iter_t to,
									sorted_list_is_match func,
                                    const void *data, void *param)
{
	patch_t patch_struct = {NULL};
	
	assert(NULL != from.diter);
	assert(NULL != to.diter);
	assert(NULL != func);
	
	patch_struct = PatchInit((void *)data, param, func);
	
	from.diter = DListFind(from.diter, to.diter, IsMatch_Adapt, &patch_struct);

	return from;
}

/******************************* -- BEGIN -- **********************************/
sorted_list_iter_t SortedListBegin(const sorted_list_t *list)
{
	sorted_list_iter_t begin = {NULL};
	
	assert(NULL != list);
	
	begin.diter = DListBegin(list->dlist);
	
	return begin;
}

/******************************** -- END -- ***********************************/
sorted_list_iter_t SortedListEnd(const sorted_list_t *list)
{
	sorted_list_iter_t end = {NULL};
		
	assert(NULL != list);

	end.diter = DListEnd(list->dlist);
	
	return end;
}

/******************************* -- NEXT -- ***********************************/
sorted_list_iter_t SortedListNext(sorted_list_iter_t iter)
{
	assert(NULL != iter.diter);	
	
	iter.diter = DListNext(iter.diter);
	
	return iter;
}

/******************************* -- PREV -- ***********************************/
sorted_list_iter_t SortedListPrev(sorted_list_iter_t iter)
{	
	assert(NULL != iter.diter);	
	
	iter.diter = DListBack(iter.diter);
	
	return iter;
}

/****************************** -- GET DATA -- ********************************/
void *SortedListGetData(sorted_list_iter_t iter)
{
	assert(NULL != iter.diter);
	
	return DListIterGetData(iter.diter);
}

/****************************** -- IS SAME -- *********************************/
int SortedListIsSameIter(const sorted_list_iter_t iter1,
                         const sorted_list_iter_t iter2)
{
	assert(NULL != iter1.diter);
	assert(NULL != iter2.diter);
	
	return DListIsSameIter(iter1.diter, iter2.diter);
}


int IsMatch_Adapt(void *data1, const void *patch)
{
	patch_t *patch_casted = {NULL};
	
	assert(NULL != patch);
	
	patch_casted = (patch_t *)patch;
	
	return !((patch_casted->user_func)(data1, patch_casted->user_data,
									   patch_casted->user_param));
	
}

static patch_t PatchInit(void *data, void *param, sorted_list_is_match func)
{
	patch_t new_patch = {NULL};
	
	assert(NULL != func);
	
	new_patch.user_data = data;
	new_patch.user_param = param;
	new_patch.user_func = func;
	
	return new_patch;
}
