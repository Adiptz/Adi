
#include <assert.h> /* assert */
#include <stdlib.h> /* malloc, free */
#include <limits.h> /* CHAR_BIT, UCHAR_MAX */
#include <string.h> /* memcpy */


#include "trie.h"

enum {SUCCESS, FAIL};
enum {LEFT, RIGHT};
enum {NOT_EXIST, EXIST};

static void *FreeAndNULL(void *pointer_to_free);
static int IsChildAvailable(trie_node_t *node, int direction);
static int IsChildExist(trie_node_t *node, int direction);
static void TurnOnBit(unsigned char *new_host_id, size_t index, 
					  unsigned char mask);
static void TrieUpdateNotAvailabilityOfNodes(trie_node_t *node);
static int HasParent(trie_node_t *node);
static int IsChildrenNotAvailable(trie_node_t *node);
static int TrieHasTwoChildren(trie_node_t *node);
static int TrieIsChildrenNotAvailable(trie_node_t *node);
static int TrieIsLeaf(trie_node_t *node);
static int TrieGetChildDirection(const trie_node_t *child);

/***************************** -- CREATE NODE -- ******************************/
trie_node_t *TrieCreateNode(trie_node_t *parent)
{
	trie_node_t *new_node = (trie_node_t *)malloc(sizeof(trie_node_t));
	if (NULL == new_node)
	{
		return NULL;
	}
	
	new_node->parent = parent;
	new_node->child[LEFT] = NULL;
	new_node->child[RIGHT] = NULL;
	new_node->is_available = AVAILABLE;
	
	return new_node;
}

/****************************** -- DESTROY -- *********************************/
void TrieDestroy(trie_node_t *node)
{	
	if (NULL == node)
	{
		return;
	}
	
	TrieDestroy(node->child[RIGHT]);
	TrieDestroy(node->child[LEFT]);
	
	node = FreeAndNULL(node);
}

static void *FreeAndNULL(void *pointer_to_free)
{
	free(pointer_to_free);
	return NULL;
}


/*********************  -- UPDATE AVAILABILITY OF NODES ***********************/
void TrieUpdateAvailabilityOfNodes(trie_node_t *node)
{
	trie_node_t *runner = NULL;
	
	assert(NULL != node);
	
	runner = node;
	
	while (HasParent(runner))
	{
		runner = runner->parent;
		runner->is_available = AVAILABLE;
	}	
}

/******************************** -- GO TO PATH -- ********************************/
trie_node_t *TrieGetPathLeaf(const trie_node_t *root, size_t host_id_bytes, 
							  const unsigned char *path)
{
	size_t i, j = 0;
	trie_node_t *runner = NULL;
	
	assert(NULL != root);
	assert(NULL != path);
	assert(0 < host_id_bytes);
	
	runner = (trie_node_t *)root;
	
	for (i = 0; i < host_id_bytes; ++i)
	{
		unsigned char mask = 0x80;
		
		for (j = 0; j < CHAR_BIT; ++j, mask >>= 1)
		{
			unsigned char direction = (0 != (mask & path[i]));
					
			runner = runner->child[direction];
		}
	}
	
	return runner;
}

/******************************************************************************/
/************************ Trie Information about Paths ************************/
/******************************************************************************/

/*************************** TrieIsHostIDAvailable ****************************/
int TrieIsHostIDAvailable(const trie_node_t *root, size_t host_id_bytes, 
						  const unsigned char *host_id)
{	
	assert(NULL != root);
	assert(NULL != host_id);
	assert(0 < host_id_bytes);
	
	if (TrieIsPathExist(root, host_id_bytes, host_id))
	{
		return NOT_AVAILABLE;
	}
	
	return AVAILABLE;
}

/******************************* TrieIsPathExist ******************************/
int TrieIsPathExist(const trie_node_t *root, size_t host_id_bytes, 
					const unsigned char *path)
{
	size_t i, j = 0;
	trie_node_t *runner = NULL;
	
	assert(NULL != root);
	assert(NULL != path);
	assert(0 < host_id_bytes);
	
	runner = (trie_node_t *)root;
	
	for (i = 0; i < host_id_bytes; ++i)
	{
		unsigned char mask = 0x80;
		
		for (j = 0; j < CHAR_BIT && runner->is_available; ++j, mask >>= 1)
		{
			unsigned char direction = (0 != (mask & path[i]));
			
			if (NULL == runner->child[direction])
			{
				return NOT_EXIST;
			}
			
			runner = runner->child[direction];
		}
	}
	
	return EXIST;
}

/************************ TrieUpdateNextAvailableHostID ***********************/
int TrieUpdateNextAvailableHostID(const trie_node_t *root, size_t host_id_bytes, 	
						  		  unsigned char *new_host_id)
{
	size_t i, j = 0;
	trie_node_t *runner = NULL;
	int direction = 0;
	
	assert(NULL != root);
	assert(NULL != new_host_id);
	assert(0 < host_id_bytes);
	
	runner = (trie_node_t *)root;
	
	for (i = 0; i < host_id_bytes; ++i)
	{
		unsigned char mask = 0x80;
		
		for (  j = 0
			 ; (j < CHAR_BIT) && (runner->is_available)
			 ; ++j, runner = runner->child[direction])
		{
			if (IsChildAvailable(runner, LEFT))
			{
				mask >>= 1;
				direction = LEFT;
			}
			else if (!IsChildExist(runner, LEFT))
			{
				return SUCCESS;
			}
			else if (IsChildAvailable(runner, RIGHT))
			{
				TurnOnBit(new_host_id, i, mask);
				mask >>= 1;
				direction = RIGHT;
			}
			else if (!IsChildExist(runner, RIGHT))
			{
				TurnOnBit(new_host_id, i, mask);
				return SUCCESS;
			}
		}
	}
	
	return FAIL; /*trie is full, there is no ip to allocate*/
}

/*IsChildAvailable*/
static int IsChildAvailable(trie_node_t *node, int direction)
{
	assert(NULL != node);
	
	return ((IsChildExist(node, direction)) &&
			(node->child[direction]->is_available));
}

/*IsChildExist*/
static int IsChildExist(trie_node_t *node, int direction)
{
	assert(NULL != node);
	
	return (NULL != node->child[direction]);
}

/*TurnOnBit*/
static void TurnOnBit(unsigned char *new_host_id, size_t index, 
					  unsigned char mask)
{
	assert(NULL != new_host_id);
	
	new_host_id[index] |= mask;
}

/***************************** TrieAllocReqHostID *****************************/
int TrieAllocReqHostID(trie_node_t *root, const unsigned char *path, 
							  size_t host_id_bytes)
{
	size_t i, j = 0;
	trie_node_t *runner = NULL;
		
	assert(NULL != root);
	assert(NULL != path);
	assert(0 < host_id_bytes);
	
	runner = root;

	for (i = 0; i < host_id_bytes; ++i)
	{
		unsigned char mask = 0x80;
		
		for (j = 0; j < CHAR_BIT; ++j, mask >>= 1)
		{
			unsigned char direction = (0 != (mask & path[i]));
			
			if (NULL == runner->child[direction])
			{
				runner->child[direction] = TrieCreateNode(runner);
				if (NULL == runner->child[direction])
				{
					TrieFreeNewPath(runner);
					return FAIL;
				}
			}
			
			runner = runner->child[direction];
		}		
	}
	
	runner->is_available = NOT_AVAILABLE;
		
	TrieUpdateNotAvailabilityOfNodes(runner);
		
	return SUCCESS;
}

/*TrieUpdateNotAvailabilityOfNodes*/
static void TrieUpdateNotAvailabilityOfNodes(trie_node_t *node)
{
	trie_node_t *runner = NULL;
	
	assert(NULL != node);
	
	runner = node;
	
	while ((!runner->is_available) && (HasParent(runner)))
	{
		runner = runner->parent;
		
		if (IsChildrenNotAvailable(runner))
		{
			runner->is_available = NOT_AVAILABLE;
		}
	}	
}

/*HasParent*/
static int HasParent(trie_node_t *node)
{
	assert(NULL != node);
	
	return (NULL != node->parent);
}

/*IsChildrenNotAvailable*/
static int IsChildrenNotAvailable(trie_node_t *node)
{
	assert(NULL != node);
	
	return (TrieHasTwoChildren(node)) && (TrieIsChildrenNotAvailable(node));
}

/*TrieHasTwoChildren*/
static int TrieHasTwoChildren(trie_node_t *node)
{
	assert(NULL != node);
	
	return ((NULL != node->child[LEFT]) && (NULL != node->child[RIGHT]));
}

/*TrieIsChildrenNotAvailable*/
static int TrieIsChildrenNotAvailable(trie_node_t *node)
{
	assert(NULL != node);
	
	return ((!node->child[LEFT]->is_available) && 
			(!node->child[RIGHT]->is_available));
}

/******************************* TrieFreeNewPath ******************************/
trie_node_t *TrieFreeNewPath(trie_node_t *node)
{
	trie_node_t *runner = NULL;
	trie_node_t *parent = NULL;
	
	assert(NULL != node);
	
	runner = node;
	
	while ((TrieIsLeaf(runner)) && (HasParent(runner)))
	{
		
		int direction = TrieGetChildDirection(runner);
		parent = runner->parent;
		runner = FreeAndNULL(runner);
		runner = parent;
		runner->child[direction] = NULL;
	}
	
	return runner;
}

/*TrieIsLeaf*/
static int TrieIsLeaf(trie_node_t *node)
{
	assert(NULL != node);
	
	return ((NULL == node->child[LEFT]) && (NULL == node->child[RIGHT]));
}

/*TrieGetChildDirection*/
static int TrieGetChildDirection(const trie_node_t *child)
{
	assert(NULL != child);
	
	if (child->parent->child[LEFT] == child)
	{
		return LEFT;
	}
	
	return RIGHT;
}

