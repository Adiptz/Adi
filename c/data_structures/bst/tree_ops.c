#include "tree_ops.h"

#define SPACE 6

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

/************************ -- print tree by levels -- **************************/
void PrintTreeByLevels(bst_t *bst)
{
	queue_t *queue = NULL;
	
	assert(NULL != bst);
	
	queue = QueueCreate();
	if (NULL == queue)
	{
		return;
	}
	
	QueueEnqueue(queue, BSTGetRoot(bst));
	
	while (!QueueIsEmpty(queue))
	{
		bst_iter_t node = (bst_iter_t)QueuePeek(queue);
		printf("%d\n", *(int *)BSTGetData(node));
			
		if (NULL != node->left_child)
		{
			QueueEnqueue(queue, node->left_child);
		}	
		
		if (NULL != node->right_child)
		{
			QueueEnqueue(queue, node->right_child);
		}
		
		QueueDequeue(queue);
	}
	
	QueueDestroy(queue);
}


/**************************** -- mirror tree -- *******************************/
void MirrorTree(bst_t *tree)
{
	RecMirrorTree(BSTGetRoot(tree));
}

void RecMirrorTree(bst_iter_t node)
{
	bst_iter_t tmp = NULL;
	
	if (NULL == node)
	{
		return;
	}
	
	tmp = node->left_child;
	node->left_child = node->right_child;
	node->right_child = tmp;
	
	RecMirrorTree(node->left_child);
	RecMirrorTree(node->right_child);
}


static void print2DUtil(bst_iter_t node, int space)
{
	int i = 0;
	if (node == NULL) return;
		  
	space += SPACE;
	print2DUtil(node->right_child, space);
	puts("");

	for (i = SPACE; i < space; i++)
		printf(" ");

	printf("%d\n", *(int *)node->data);
	print2DUtil(node->left_child, space);
}

void PrintTree(bst_t *bst)
{
   print2DUtil(BSTGetRoot(bst), 0);
}







