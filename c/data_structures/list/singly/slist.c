/*************************
 * Author   :  Adi       *
 * Reviewer :  Daya      *
 * Status   :  Approved  *
 *************************/

#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */

#include "slist.h"

/******************************* -- CREATE -- *********************************/
slist_node_t *SListCreateNode(void *data, slist_node_t *next)
{
	slist_node_t *head = NULL;
	
	head = (slist_node_t *)malloc(sizeof(slist_node_t));
	if(NULL == head)
	{
		return NULL;
	}
	
	/*inatilization heads members*/
	head->data = data;
	head->next_node = next;
	
	return head;
}

/****************************** -- FREE ALL -- ********************************/
void SListFreeAll(slist_node_t *head)
{
	assert(NULL != head);
	
	while(head != NULL)
	{
		slist_node_t *tmp = head->next_node;
		free(head); head = NULL;
		head = tmp;
	}	
}

/******************************* -- INSERT -- *********************************/
slist_node_t *SListInsert(slist_node_t *current_node, slist_node_t *new_node)
{
	void *tmp_data = current_node->data;
	current_node = SListInsertAfter(current_node, new_node);
	
	assert(NULL != current_node);
	assert(NULL != new_node);
	
	current_node->data = new_node->data;
	
	new_node->data = tmp_data;
	
	return current_node;
}

/**************************** -- INSERT AFTER -- ******************************/
slist_node_t *SListInsertAfter(slist_node_t *current_node, slist_node_t *new_node)
{
	assert(NULL != current_node);
	assert(NULL != new_node);
	
	new_node->next_node = current_node->next_node;
	current_node->next_node = new_node;

	return current_node;
}

/******************************** -- FIND -- **********************************/
slist_node_t *SListFind(slist_node_t *head, cmp_func cmp, const void *data)
{
	slist_node_t *runner = NULL;
	
	assert(NULL != head);
	assert(NULL != data);
	
	runner = head;
	
	for( runner = head 
	    ;(NULL != runner) && (0 != cmp(runner->data, data))
	    ;runner = runner->next_node)
	{ /* empty body */ }
		
	return runner;
}

/******************************* -- REMOVE -- *********************************/
slist_node_t *SListRemove(slist_node_t *head)
{
	void *head_data = head->data;
	slist_node_t *after_head = head->next_node;
	
	/* turn head to be as the node after it */
	head->data = after_head->data;
	head->next_node = after_head->next_node;
	
	/* after_head node gets old data of head and detach from list*/
	after_head->data = head_data;
	after_head->next_node = NULL;
	
	return after_head;	
}

/**************************** -- REMOVE AFTER -- ******************************/
slist_node_t *SListRemoveAfter(slist_node_t *head)
{
	slist_node_t *after_head = head->next_node;
	
	if (NULL != after_head) /* if head is not the last node */
	{
		head->next_node = after_head->next_node;
		after_head->next_node = NULL;
	}
	
	return after_head;
}

/******************************* -- COUNT -- **********************************/
size_t SListCount(const slist_node_t *head)
{
	size_t counter = 0;
	
	while(NULL != head)
	{
		++counter;
		head = head->next_node;
	}

	return counter;
}

/***************************** -- FOR EACH -- *********************************/
int SListForEach(slist_node_t *head, func_action func, void *param)
{
	int ret_value = 0;
	
	while(NULL != head && 0 == ret_value)
	{
		ret_value = func(head->data, param);
		head = head->next_node;
	}

	return ret_value;
}

/******************************* -- FLIP -- **********************************/
slist_node_t *SListFlip(slist_node_t *head)
{
	slist_node_t *after_head = head->next_node;
	
	head->next_node = NULL; /* current node holds NULL - will turn to be last */
	
	while(NULL != after_head)
	{
			slist_node_t *tmp = after_head->next_node; 
			
			/* changing hold address at current node */
			after_head->next_node = head;
			
			/* passing to next node in list */
			head = after_head;
			after_head = tmp; 
	}
	
	return head;
}


/*slist_node_t *SListFlip(slist_node_t *head)*/
/*{*/
/*	slist_node_t *after_head = head->next_node;	*/
/*	*/
/*	if (NULL == after_head)*/
/*	{*/
/*		return head;*/
/*	}*/
/*	*/
/*	*/
/*	SListFlip(after_head);*/
/*	*/
/*	return head->next;*/
/*}*/


/******************************* -- LOOP -- ***********************************/
int SListHasLoop(const slist_node_t *head)
{
	slist_node_t *slow_move = (slist_node_t *)head;
	slist_node_t *fast_move = (slist_node_t *)head;
	
	while(NULL != fast_move && NULL != fast_move->next_node)
	{
		slow_move = slow_move->next_node;
		fast_move = fast_move->next_node->next_node;
		
		if(slow_move == fast_move)
		{
			return 1;
		}	
	}
	
	return 0;
}

/*************************** -- INTERSECTION -- *******************************/
slist_node_t *SListFindIntersection
		                  (const slist_node_t *node1, const slist_node_t *node2)
{
	/*O(n)*/
	size_t length1 = SListCount(node1); 
	size_t length2 = SListCount(node2);
	
	if(node1 == node2) /* if it's the same list */
	{
		return NULL;
	}
	
	/*if 2 lists are not the same length -
	  go ahead on the longer list till they're equal */
	while (length1 > length2)
	{
		node1 = node1->next_node; 
		--length1;
	}
	while (length2 > length1)
	{
		node2 = node2->next_node; 
		--length2;
	}
	
	while (NULL != node1 && node1 != node2)
	{
		node1 = node1->next_node;
		node2 = node2->next_node; 
	}
	 
	return (slist_node_t *)node1;


	/* O(n^2)
	slist_node_t *list1 = (slist_node_t *)node1;
	slist_node_t *list2 = (slist_node_t *)node2;
	slist_node_t *list2_original = list2;
	
	for(list1 = list1; NULL != list1; list1 = list1->next_node)
	{
		for(list2 = list2_original; NULL != list2; list2 = list2->next_node)
		{
			if(list1 == list2 && (list1 == node1 || list1 == node2))
			{
				return NULL;
			}
			else if(list1 == list2)
			{
				return list1;
			}
		}
	}

	return NULL;*/
}									

