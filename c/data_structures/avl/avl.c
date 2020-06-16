/*************************
 *  Author   :  Adi      *
 *  Reviewer :  Hila     *
 *  Status   :  Sent     *
 *************************/

#include <assert.h> /* assert */
#include <stdlib.h> /* malloc */

#include "avl.h"

#define MAX_CHILDREN 2

enum ret_status {SUCCESS, FAIL};
enum direction {LEFT, RIGHT};

typedef int (*action_func)(void *tree_data, void *param);

typedef int (*cmp_func)(const void *tree_data,
						const void *new_data,
						void *param);

typedef struct avl_node avl_node_t;

struct avl_node
{
	void *data;
	size_t height;
	avl_node_t *child[MAX_CHILDREN];
};

struct avl
{
	void *param;
	avl_node_t *root;
	int (*cmp_func)(const void *tree_data, const void *new_data, void *param);
};

/********** -- HELP FUNCS -- **********/
static void InitAVL(avl_t *avl, void *param, avl_node_t *root, cmp_func cmp);
static avl_node_t *CreateNode(const void *data);
static void *DestroyNode(avl_node_t *node);
static int HasChild(avl_node_t *node, int direction);
static int HasTwoChildren(avl_node_t *node);
static void *GetData(avl_node_t *node);
static avl_node_t *GetRoot(const avl_t *tree);  				      
static avl_node_t *GetNext(avl_node_t *node);
static size_t GetHeight(avl_node_t *node);
static size_t GetHighest(size_t left_height, size_t right_height);
static void UpdateHeight(avl_node_t *node);
static avl_node_t *Rotate(avl_node_t *pivot, int direction);
static avl_node_t *Balance(avl_node_t *node);

/* recursive */
static void RECDestroy(avl_node_t *node);

static size_t RECCount(avl_node_t *node);

static int RECForEach(avl_node_t *node,
					  action_func operation,
					  void *param);						    			

static avl_node_t *RECRemove(avl_node_t *node,
							 const void *data,
							 cmp_func cmp,
							 void *param);

static avl_node_t *RecInsert(avl_node_t *current_node,
   				      avl_node_t *node_to_insert,
   				      cmp_func cmp,
   				      void *param);

static avl_node_t *RECFind(avl_node_t *node,
						   const void *data_to_find,
						   cmp_func cmp,
						   void *param);


/*******************************************************************************
 *									IMPLEMENT FUNCS    						   *
 ******************************************************************************/

/********************************* -- CREATE -- *******************************/
avl_t *AVLCreate(void *param, cmp_func cmp)
{
	avl_t *new_avl = (avl_t *)malloc(sizeof(struct avl));
	if (NULL == new_avl)
	{
		return NULL;
	}
	
	InitAVL(new_avl, param, NULL, cmp);

	return new_avl;
}


/********************************* -- DESTROY -- ******************************/
void AVLDestroy(avl_t *avl)
{
    assert(avl);
    RECDestroy(avl->root);

    free(avl); avl = NULL;
}

static void RECDestroy(avl_node_t *node)
{
    if (NULL == node)
    {
        return; 
    }

    RECDestroy(node->child[RIGHT]);
    RECDestroy(node->child[LEFT]);
	
	node->data = NULL;
    free(node); node = NULL;
}


/********************************* -- INSERT -- *******************************/
int AVLInsert(avl_t *avl, const void *data_to_insert)
{
	avl_node_t *node_to_insert = NULL;
	
	assert(NULL != avl);
		
	node_to_insert = CreateNode(data_to_insert);
	if (NULL == node_to_insert)
	{
		return FAIL; 
	}
	
	avl->root =	RecInsert(GetRoot(avl),
						  node_to_insert,
						  avl->cmp_func,
						  avl->param);
	
	return SUCCESS;
}

static avl_node_t *RecInsert(avl_node_t *current_node,
   				      avl_node_t *node_to_insert,
   				      cmp_func cmp,
   				      void *param)
{
	assert(NULL != node_to_insert);
	assert(NULL != cmp);
	
	if (NULL == current_node)
    {   
        return node_to_insert;
    }
    else
    {
		int direction = 0;
		int cmp_result = 0;
		
		cmp_result = cmp(current_node->data, node_to_insert->data, param);
		direction = (0 < cmp_result); /* 0 left, 1 right*/ 
		
	    current_node->child[direction] = 
									   RecInsert(current_node->child[direction],
												 node_to_insert, cmp, param);
	
		UpdateHeight(current_node);	
	
		return Balance(current_node);
	}
}


/********************************* -- REMOVE -- *******************************/
void AVLRemove(avl_t *avl, const void *data_to_remove)
{
	assert(NULL != avl);
	
	if (AVLIsEmpty(avl))
	{
		return;	
	}
	
	avl->root = RECRemove(GetRoot(avl),
						  data_to_remove,
						  avl->cmp_func,
						  avl->param);
}

static avl_node_t *RECRemove(avl_node_t *node,
							 const void *data,
							 cmp_func cmp,
							 void *param)
{
	int cmp_result = 0;

	assert(NULL != node);
	assert(NULL != data);
	
	cmp_result = cmp(data, node->data, param);

	if (0 != cmp_result)
	{
		int direction = (cmp_result < 0);  
		node->child[direction] = RECRemove(node->child[direction], data, cmp, param);
		
		return Balance(node);
	}
	else
	{
		if (HasTwoChildren(node))
		{
			/* overwrite current_node->data with next_node->data */
			avl_node_t *next_node = GetNext(node->child[RIGHT]);
			node->data = next_node->data;
			
			node->child[RIGHT] = RECRemove(node->child[RIGHT], next_node->data,
										   cmp, param);
			return node;
		}
		else
		{
			int direction = (HasChild(node, RIGHT)); 
			avl_node_t *child = node->child[direction];
			
			node = DestroyNode(node);
			
			return child; 
		}
	}
}


/********************************** -- FIND -- ********************************/
void *AVLFind(const avl_t *avl, const void *data_to_find)
{
	avl_node_t *node_with_data_to_find = NULL;
	
	assert(NULL != avl);
	assert(NULL != data_to_find);
	
	node_with_data_to_find = RECFind(GetRoot(avl),
							         data_to_find,
							         avl->cmp_func,
							         avl->param);
		
	return GetData(node_with_data_to_find);
}

static avl_node_t *RECFind(avl_node_t *node,
						   const void *data_to_find,
				           cmp_func cmp,
					  	   void *param)
{
	int cmp_result = 0;
	
	if(NULL == node)
	{
		return NULL;		
	}
	
	cmp_result = cmp(GetData(node), data_to_find, param);
	
	if (0 != cmp_result)
	{
		int direction = (0 < cmp_result);
		
		node = RECFind(node->child[direction],
					   data_to_find,
				 	   cmp,
					   param);
	}

	return node;
}


/********************************* -- COUNT -- ********************************/
size_t AVLCount(const avl_t *avl)
{
	assert(NULL != avl);
	
	return RECCount(GetRoot(avl));
}

static size_t RECCount(avl_node_t *node)
{	
	if (NULL == node)
	{
		return 0;
	}
	
	return RECCount(node->child[LEFT]) + RECCount(node->child[RIGHT]) + 1;
}

/********************************* -- HEIGHT -- *******************************/
size_t AVLHeight(const avl_t *avl)
{	
	assert(NULL != avl);
	
	return avl->root->height;
}

/******************************** -- IS EMPTY -- ******************************/
int AVLIsEmpty(const avl_t *avl)
{
	assert(NULL != avl);
	
	return (NULL == avl->root);
}

/******************************** -- FOR EACH -- ******************************/
int AVLForEach(void *param, avl_t *avl, int (*action_func)(void *tree_data,
														   void *param))
{
    assert(NULL != avl);
    assert(NULL != action_func);
    
    if(AVLIsEmpty(avl))
    {
		return FAIL;
	}
	
   	return RECForEach(GetRoot(avl), action_func, param);
}

static int RECForEach(avl_node_t *node, action_func operation, void *param)
{
    int status = 0;

    if (NULL == node)
    {
        return 0;
    }
	
	if (HasChild(node, LEFT))
	{
    	status = RECForEach(node->child[LEFT], operation, param);
    }
    
    if (0 != status)
    {
        return status;
    }

    status = operation(node->data, param);

    if (0 != status)
    {
        return status;
    }

	if (HasChild(node, RIGHT))
	{
    	status = RECForEach(node->child[RIGHT], operation, param);
	}

    return status;
}

/*************************** -- HELP FUNCTIONS -- *****************************/
static void InitAVL(avl_t *avl, void *param, avl_node_t *root, cmp_func cmp)
{
	assert(NULL != avl);
	assert(NULL != cmp);
	
	avl->root = root;
	avl->param = param;
	avl->cmp_func = cmp;
}

static avl_node_t *CreateNode(const void *data)
{
	avl_node_t *new_node = NULL;
	
	assert(NULL != data);
	
	new_node = (avl_node_t *)malloc(sizeof(avl_node_t));
	if (NULL == new_node)
	{
		return NULL;
	}
	
	new_node->data = (void *)data;
	new_node->height = 1;
	new_node->child[LEFT] = NULL;
	new_node->child[RIGHT] = NULL;
	
	return new_node;
}

static void *DestroyNode(avl_node_t *node)
{
	node->data = NULL;
	free(node);
	return NULL;
}

static int HasChild(avl_node_t *node, int direction)
{
	return (NULL != node->child[direction]);
}

static int HasTwoChildren(avl_node_t *node)
{
	return (NULL != node->child[RIGHT] && NULL != node->child[LEFT]);
}

/******* geters *******/
static void *GetData(avl_node_t *node)
{
	if (NULL == node)
	{
		return NULL;
	}
	
	return node->data;
}

static avl_node_t *GetRoot(const avl_t *tree)
{
	return tree->root;
}

static avl_node_t *GetNext(avl_node_t *node)
{
	if (NULL == node->child[LEFT])
	{
		return node;
	}
	
	return (GetNext(node->child[LEFT]));
}

/********************* heigth / balance / rotate ***************************/
static size_t GetHeight(avl_node_t *node)
{
	if (NULL == node)
	{
		return 0;
	}
	
	return node->height;
}

static size_t GetHighest(size_t left_height, size_t right_height)
{
	return (left_height > right_height ? left_height : right_height);
}

static void UpdateHeight(avl_node_t *node)
{
	size_t height_of_bigger_subtree = 0;
	
	assert(NULL != node); 
	
	height_of_bigger_subtree = GetHighest(GetHeight(node->child[LEFT]), 
						                 GetHeight(node->child[RIGHT]));
	
	node->height = height_of_bigger_subtree + 1;
}

static avl_node_t *Balance(avl_node_t *node)
{
	long balance_factor = 0;
	
	assert(NULL != node);
	
	balance_factor = GetHeight(node->child[LEFT]) -
		                                          GetHeight(node->child[RIGHT]); 
	
	if (1 < balance_factor)
	{
		node = Rotate(node, RIGHT);
	}
	else if (-1 > balance_factor)
	{
		node = Rotate(node, LEFT);
	}
	
	UpdateHeight(node);

	return node;
}

static avl_node_t *Rotate(avl_node_t *node, int direction)
{
	avl_node_t *pivot = NULL;
	avl_node_t *child_of_pivot = NULL; 
	
	assert(NULL != node);
		
	pivot = node->child[!direction];
	
	if (HasChild(pivot, direction)) /* in case of inner rotation needed */
	{
		pivot = Rotate(pivot, !direction);
	}
	
	/* rotate between origin node, pivot and its child */
	child_of_pivot = pivot->child[direction];
	pivot->child[direction] = node;
	node->child[!direction] = child_of_pivot;
	
	UpdateHeight(node);
	UpdateHeight(pivot);
	
	return pivot;
}
