
#define UNUSED(x) (void)(x) 

#include <stdlib.h> /* malloc, free*/
#include <assert.h> /* assert */

#include "bst.h"

#include "queue.h"
/**************************** -- HELP FUNCTIONS -- ****************************/
/******************* -- creation ***************************/
static bst_iter_t CreateLeaf(void *data, bst_iter_t parent);

/******************* -- directions ************************/
static int IsLeftChild(bst_iter_t iter);
static int IsRightChild(bst_iter_t iter);
static int CanGoLeft(bst_iter_t iter);
static int CanGoRight(bst_iter_t iter);
static bst_iter_t GoLeft(bst_iter_t iter);
static bst_iter_t GoRight(bst_iter_t iter);
static bst_iter_t GoToParent(bst_iter_t iter);

/******************* -- bonds -- **************************/
static int HasTwoChildren(bst_iter_t iter);
static int HasOneChildren(bst_iter_t iter);
static int HasLeftChild(bst_iter_t iter);
static int HasRightChild(bst_iter_t iter);
static int IsRoot(bst_iter_t iter);

/************* -- remove and place nodes -- ***************/
static bst_iter_t RemoveLeaf(bst_iter_t leaf_to_remove);
static void RemoveNodeWithOneChild(bst_iter_t iter_to_remove);
static void RemoveNodeWithTwoChildren(bst_iter_t iter_to_remove);
static void *FreeAndNULL(void *memory_to_free);

static bst_iter_t FindWhereToPlaceNewLeaf(const bst_t *bst, 
				                          bst_iter_t runner,
				                          int *cmp, 
				                          void *data,
				                          void *param);
				                          
static void InsertNewLeaf(bst_iter_t parent_of_new_leaf,
						  bst_iter_t leaf_to_insert,
					      int *direction);
/******************************************************************************/
					     

/******************************* -- STRUCTS -- ********************************/
struct bst_node
{
	void *data;
	bst_iter_t parent;
	bst_iter_t left_child;
	bst_iter_t right_child;
};

struct bst
{
	void *param;
	int (*cmp_func)(void *, void *, void *);
	bst_iter_t dummy;
};
/******************************************************************************/


/******************************* -- CREATE -- *********************************/
bst_t *BSTCreate(int (*cmp_func)(void *iter_data, void *new_data, void *param), 
				 void *param)
{
	bst_t *bst = NULL;
	
	assert(NULL != cmp_func);
	
	bst = (bst_t *)malloc(sizeof(struct bst_node));
	if (NULL == bst)
	{
		return NULL;
	}
	
	bst->dummy = CreateLeaf(NULL, NULL); 
	if (NULL == bst->dummy)
	{
		bst = FreeAndNULL(bst);
		return NULL;
	}
	
	bst->param = param;
	bst->cmp_func = cmp_func;
	bst->dummy->left_child = bst->dummy; /* dummy points to himself */ 
	
	return bst;
}

/******************************* -- DESTROY -- ********************************/
void BSTDestroy(bst_t *bst)
{
	bst_iter_t runner = NULL;
	
	runner = bst->dummy->left_child;
	
	while (!BSTIsSameIter(runner, bst->dummy))
	{
		if (CanGoLeft(runner))
		{
			runner = GoLeft(runner);
		}
		else if (CanGoRight(runner))
		{
			runner = GoRight(runner);
		}
		else
		{
			bst_iter_t iter_to_remove = runner;
			runner = runner->parent;
			
			if (IsRightChild(iter_to_remove))
			{
				runner->right_child = NULL;
			}
			else
			{
				runner->left_child = NULL;
			}
			
			iter_to_remove = FreeAndNULL(iter_to_remove);
		}
	}
	
	bst->dummy = FreeAndNULL(bst->dummy);
	bst = FreeAndNULL(bst);
}
	
/******************************* -- INSERT -- *********************************/
bst_iter_t BSTInsert(bst_t *bst, void *data)
{
	bst_iter_t new_leaf = NULL;
	bst_iter_t runner = NULL;
	int find_direction = 0;
	void *param = NULL;
	
	assert(NULL != bst);
	
	runner = bst->dummy->left_child;
	param = bst->param;

	new_leaf = CreateLeaf(data, NULL);
	if (NULL == new_leaf)
	{
		return BSTEnd(bst);
	}	
	
	runner = FindWhereToPlaceNewLeaf(bst, runner, &find_direction, data, param);
	
	InsertNewLeaf(runner, new_leaf, &find_direction);
		
	return new_leaf;
}	

/******************************* -- REMOVE -- *********************************/
void BSTRemove(bst_iter_t iter_to_remove)
{
	assert(NULL != iter_to_remove);
		
	if (HasTwoChildren(iter_to_remove)) 
	{
		RemoveNodeWithTwoChildren(iter_to_remove);
	}
	else if (HasOneChildren(iter_to_remove))
	{
		RemoveNodeWithOneChild(iter_to_remove);
	}	
	else 
	{
		iter_to_remove = RemoveLeaf(iter_to_remove);
	}

	iter_to_remove = FreeAndNULL(iter_to_remove);
}

/******************************** -- SIZE -- **********************************/
size_t BSTSize(const bst_t *bst)
{
	size_t counter = 0;
	bst_iter_t runner = NULL;
	
	assert(NULL != bst);
	
	for ( runner = BSTBegin(bst)
		; !BSTIsSameIter(runner, bst->dummy)
		; runner = BSTNext(runner))
	{
		++counter;
	}
	
	return counter;
}

/******************************* -- IS EMPTY -- *******************************/
int BSTIsEmpty(const bst_t *bst)
{
	assert(NULL != bst);
	
	return (BSTIsSameIter(bst->dummy, bst->dummy->left_child));
}

/******************************* -- FOR EACH -- *******************************/
int BSTForEach(void *param,
			   bst_iter_t from,
			   bst_iter_t to, 
			   int (*action_func)(void *iter_data, void *param))
{
	int action_func_status = 0;
	bst_iter_t runner = NULL;
	
	assert(NULL != from);
	assert(NULL != to);
		
	for ( runner = from
		; !BSTIsSameIter(runner, to) && 0 == action_func_status
		; runner = BSTNext(runner))
	{
		action_func_status = action_func(BSTGetData(runner), param);		
	}
	
	return action_func_status;
}

/******************************** -- FIND -- **********************************/
bst_iter_t BSTFind(bst_t *bst, void *data_to_find)
{
	bst_iter_t runner = NULL;
	int cmp = 1;
	
	assert(NULL != bst);
	assert(NULL != data_to_find);
	
	runner = bst->dummy->left_child;
	
	while (NULL != runner && !BSTIsSameIter(runner, BSTEnd(bst)))
	{
		cmp = bst->cmp_func(BSTGetData(runner), data_to_find, NULL);
		
		if (0 < cmp)
		{
			runner = GoLeft(runner);
		}
		
		else if (0 > cmp)
		{
			runner = GoRight(runner);
		}
		else
		{
			break;
		}
	}
	
	if (0 != cmp) 
	{
		return NULL;
	}
	
	return runner;
}

/****************************** -- GET DATA -- ********************************/
void *BSTGetData(bst_iter_t iter)
{
	assert(NULL != iter);
	
	return iter->data;
}

/******************************** -- NEXT -- **********************************/
bst_iter_t BSTNext(bst_iter_t iter)
{
	assert(NULL != iter);
	
	if (!HasRightChild(iter))
	{
			while (IsRightChild(iter))
			{
				iter = GoToParent(iter);
			}
			
			iter = GoToParent(iter);						
	}
	else
	{		 
		iter = GoRight(iter);
		
		while(CanGoLeft(iter))
		{
			iter = GoLeft(iter);
		}
	}
	
	return iter;
}

/******************************** -- PREV -- **********************************/
bst_iter_t BSTPrev(bst_iter_t iter)
{
	assert(NULL != iter);
	
	if (!HasLeftChild(iter))
	{
		while (IsLeftChild(iter))
		{
			iter = GoToParent(iter);
		}

		iter = GoToParent(iter);						
	}
	else
	{		
		iter = GoLeft(iter);
		
		while(CanGoRight(iter))
		{
			iter = GoRight(iter);
		}
	}
	
	return iter;
}

/********************************* -- END -- **********************************/
bst_iter_t BSTEnd(const bst_t *bst)
{
	assert(NULL != bst);
	
	return bst->dummy;
}

/******************************** -- BEGIN -- *********************************/
bst_iter_t BSTBegin(const bst_t *bst)
{
	bst_iter_t runner = NULL;
	
	assert(NULL != bst);
	
	runner = bst->dummy->left_child; 
	
	if (!BSTIsEmpty(bst))
	{
		while(CanGoLeft(runner))
		{
			runner = GoLeft(runner);
		}
	}
	
	return runner;
}

/******************************* -- IS SAME -- ********************************/
int BSTIsSameIter(bst_iter_t iter1, bst_iter_t iter2)
{	
	return (iter1 == iter2);
}

/******************************************************************************/


/**************************** -- HELP FUNCTIONS -- ****************************/
/******************* -- creation ****************************/
static bst_iter_t CreateLeaf(void *data, bst_iter_t parent)
{
	bst_iter_t new_leaf = NULL;
	
	new_leaf = (bst_iter_t)malloc(sizeof(struct bst_node));
	if (NULL == new_leaf)
	{
		return NULL;
	}
	
	new_leaf->data = data;
	new_leaf->parent = parent;
	new_leaf->left_child = NULL;
	new_leaf->right_child = NULL;
 
	return new_leaf;
}

/******************* -- directions ****************************/
static int IsLeftChild(bst_iter_t iter)
{
	assert(NULL != iter);
	return (BSTIsSameIter(iter, iter->parent->left_child));
}

static int IsRightChild(bst_iter_t iter)
{
	assert(NULL != iter);
	return !(IsLeftChild(iter));
}

static int CanGoLeft(bst_iter_t iter)
{
	assert(NULL != iter);
	return (NULL != iter->left_child);
}

static int CanGoRight(bst_iter_t iter)
{
	assert(NULL != iter);
	return (NULL != iter->right_child);
}

static bst_iter_t GoLeft(bst_iter_t iter)
{
	assert(NULL != iter);
	return (iter->left_child);
}

static bst_iter_t GoRight(bst_iter_t iter)
{
	assert(NULL != iter);
	return (iter->right_child);
}

static bst_iter_t GoToParent(bst_iter_t iter)
{
	assert(NULL != iter);
	return (iter->parent);
}

/******************* -- bonds -- ****************************/
static int HasTwoChildren(bst_iter_t iter)
{
	assert(NULL != iter);
	return (NULL != iter->left_child && NULL != iter->right_child);
}

static int HasOneChildren(bst_iter_t iter)
{
	assert(NULL != iter);
	
	return ((NULL != iter->right_child && NULL == iter->left_child) ||
			(NULL != iter->left_child && NULL == iter->right_child));
}

static int HasLeftChild(bst_iter_t iter)
{
	assert(NULL != iter);
	return (NULL != iter->left_child);
}

static int HasRightChild(bst_iter_t iter)
{
	assert(NULL != iter);
	return (NULL != iter->right_child);
}

static int IsRoot(bst_iter_t iter)
{
	assert(NULL != iter);	
	return (NULL == iter->parent->parent);
}

/********************** -- remove and place nodes -- ***********************/
static bst_iter_t RemoveLeaf(bst_iter_t leaf_to_remove)
{
	assert(NULL != leaf_to_remove);
		
	if (IsRightChild(leaf_to_remove))
	{
		leaf_to_remove->parent->right_child = NULL;		
	}
	else
	{
		if (IsRoot(leaf_to_remove))
		{
			leaf_to_remove->parent->left_child = leaf_to_remove->parent;
		}
		else
		{
			leaf_to_remove->parent->left_child = NULL;
		}
	}
	
	return leaf_to_remove;
}

static void RemoveNodeWithOneChild(bst_iter_t iter_to_remove)
{
	assert(NULL != iter_to_remove);
	
	if (IsRightChild(iter_to_remove))
	{
		if (HasLeftChild(iter_to_remove))
		{
		   iter_to_remove->parent->right_child = iter_to_remove->left_child;
		   iter_to_remove->left_child->parent = iter_to_remove->parent;	
		}
		else
		{
		  iter_to_remove->parent->right_child = iter_to_remove->right_child;
		  iter_to_remove->right_child->parent = iter_to_remove->parent;
		}
	}
	else
	{
		if (HasLeftChild(iter_to_remove))
		{
			iter_to_remove->parent->left_child = iter_to_remove->left_child;
			iter_to_remove->left_child->parent = iter_to_remove->parent;
		}
		else
		{
		   iter_to_remove->parent->left_child = iter_to_remove->right_child;
		   iter_to_remove->right_child->parent = iter_to_remove->parent;
		}
	}
}

static void RemoveNodeWithTwoChildren(bst_iter_t iter_to_remove)
{
	assert(NULL != iter_to_remove);
		
	if (IsRightChild(iter_to_remove))
	{
		bst_iter_t next_of_iter_to_remove = BSTNext(iter_to_remove);
		
		iter_to_remove->parent->right_child = iter_to_remove->right_child;
		iter_to_remove->right_child->parent = iter_to_remove->parent;
	
		next_of_iter_to_remove->left_child = iter_to_remove->left_child;
		next_of_iter_to_remove->left_child->parent = next_of_iter_to_remove;
	}
	else
	{
	   bst_iter_t prev_of_iter_to_remove = BSTPrev(iter_to_remove);
		
	   iter_to_remove->parent->left_child = iter_to_remove->left_child;
	   iter_to_remove->left_child->parent = iter_to_remove->parent;
	
	   prev_of_iter_to_remove->right_child = iter_to_remove->right_child;
	   prev_of_iter_to_remove->right_child->parent = prev_of_iter_to_remove;		
	}
}

static bst_iter_t FindWhereToPlaceNewLeaf(const bst_t *bst, 
				                          bst_iter_t runner,
				                          int *cmp, 
				                          void *data,
				                          void *param)
{
	assert(NULL != bst);
	assert(NULL != runner);
	assert(NULL != cmp);

	while (!(BSTIsSameIter(runner,bst->dummy)))
	{
		*cmp = bst-> cmp_func(BSTGetData(runner), data, param);
		
		if (0 < *cmp && CanGoLeft(runner))
		{
			runner = GoLeft(runner);
		}
		else if(0 > *cmp && CanGoRight(runner))
		{
			runner = GoRight(runner);
		}
		else
		{
			break;
		}	
	}
	
	return runner;
}

static void InsertNewLeaf(bst_iter_t parent_of_new_leaf,
						  bst_iter_t leaf_to_insert,
					      int *direction)
{
	if (0 > *direction)
	{
		parent_of_new_leaf->right_child = leaf_to_insert;
	}
	else
	{
		parent_of_new_leaf->left_child = leaf_to_insert;
	}

	leaf_to_insert->parent = parent_of_new_leaf;	
}

static void *FreeAndNULL(void *memory_to_free)
{	
	free(memory_to_free);
	memory_to_free = NULL;
	
	return NULL;
}

bst_iter_t BSTGetRoot(bst_t *bst)
{
	return bst->dummy->left_child;
}
/******************************************************************************/

/*void PrintTreeByLevels(bst_t *bst)*/
/*{*/
/*	queue_t *queue = NULL;*/
/*	*/
/*	assert(NULL != bst);*/
/*	*/
/*	queue = QueueCreate();*/
/*	if (NULL == queue)*/
/*	{*/
/*		return;*/
/*	}*/
/*	*/
/*	QueueEnqueue(queue, bst->dummy->left_child);*/
/*	*/
/*	while (!QueueIsEmpty(queue))*/
/*	{*/
/*		bst_iter_t node = (bst_iter_t)QueuePeek(queue);*/
/*		printf("%d\n", *(int *)BSTGetData(node));*/
/*			*/
/*		if (NULL != node->left_child)*/
/*		{*/
/*			QueueEnqueue(queue, node->left_child);*/
/*		}	*/
/*		*/
/*		if (NULL != node->right_child)*/
/*		{*/
/*			QueueEnqueue(queue, node->right_child);*/
/*		}*/
/*		*/
/*		QueueDequeue(queue);*/
/*	}*/
/*	*/
/*	QueueDestroy(queue);*/
/*}*/


