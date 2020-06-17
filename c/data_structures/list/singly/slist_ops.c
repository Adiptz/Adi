#include "slist_ops.h"


/******************************************************************************
 *   						  		LOOP 									  *
 ******************************************************************************/
int FindAndBreakLoop(const slist_node_t *head)
{
	slist_node_t *slow = NULL;
	slist_node_t *fast = NULL;
	
	assert(NULL != head);
	
	slow = (slist_node_t *)head;
	fast = (slist_node_t *)head;
	
	while (NULL != fast->next_node && NULL != fast->next_node->next_node)
	{
		slow = slow->next_node;
		fast = fast->next_node->next_node;
		
		if (slow == fast)
		{
			BreakLoop(head, slow);
			return 0;
		}
	}
	
	return 1;
}
/******************** -- HAS LOOP -- *******************/
int HasLoop(const slist_node_t *head)
{
	slist_node_t *slow = (slist_node_t *)head;
	slist_node_t *fast = (slist_node_t *)head;
	
	assert(NULL != head);
	
	while (NULL != fast->next_node && NULL != fast->next_node->next_node)
	{
		slow = slow->next_node;
		fast = fast->next_node->next_node;
		
		if (slow == fast)
		{
			return 1;
		}
	}
	
	return 0;
}

/******************** -- BREAK LOOP -- *******************/
void BreakLoop(const slist_node_t *head, slist_node_t *loop_position)
{
	slist_node_t *runner = NULL;
	
	assert(NULL != head);
	assert(NULL != loop_position);
	
	/* find meeting point */
	for ( runner = loop_position
		; runner != head
		; runner = runner->next_node,
		  head = head->next_node)
	{}
	
	/* find last node of list */
	for (; runner->next_node != head
		 ; runner = runner->next_node)
	{}
	
	/* break the loop */
	runner->next_node = NULL;
}


/******************************************************************************
 *   						  	Intersection  								  *
 ******************************************************************************/
 slist_node_t *FindIntersection(const slist_node_t *node1,
							    const slist_node_t *node2)
{
	/* promotion - lists become at the same size */
	while (SListCount(node1) > SListCount(node2))
	{
		node1 = node1->next_node;
	}
	
	while (SListCount(node2) > SListCount(node1))
	{
		node2 = node2->next_node;
	}
	
	if (node1 == node2) /* two nodes from the same list */
	{
		return NULL;
	}
	
	while (NULL != node1 && node1 != node2)
	{
		node1 = node1->next_node;
		node2 = node2->next_node; 
	}
	 
	return (slist_node_t *)node1;
}


int FindAndRemoveIntersction(slist_node_t *node1, slist_node_t *node2)
{
	slist_node_t *intersection_node = NULL;
	
	assert(NULL != node1);
	assert(NULL != node2);
	
	/* promotion - lists become at the same size */
	while (SListCount(node1) > SListCount(node2))
	{
		node1 = node1->next_node;
	}
	
	while (SListCount(node2) > SListCount(node1))
	{
		node2 = node2->next_node;
	}
	
	if (node1 == node2) /* two nodes from the same list */
	{
		return 1; 
	}
	
	while (NULL != node1 && node1 != node2)
	{
		intersection_node = node2;
		node1 = node1->next_node;
		node2 = node2->next_node; 
	}
	
	if (node1 == NULL)
	{
		return 1;
	}
	
	intersection_node->next_node = NULL; /* break intersection */
	
	return 0;	
}

/******************************************************************************
 *   						  		 Flip 	 								  *
 ******************************************************************************/
slist_node_t *FlipListIterative(slist_node_t *head)
{
	slist_node_t *next_head = NULL;
	slist_node_t *next_next = NULL;
	
	assert(NULL != head);
	
	while(NULL != head)
	{
		next_head = head->next_node;
		
		head->next_node = next_next;
		
		next_next = head;
		head = next_head;
	}
	
	return next_next;
}

slist_node_t *FlipListRecursive(slist_node_t *head)
{
	slist_node_t *new_head = NULL;
	
	if (NULL == head->next_node)
	{
		return head;
	}
	
	new_head = FlipListRecursive(head->next_node);
	
	head->next_node->next_node = head;
	head->next_node = NULL;
	
	return new_head;
}


