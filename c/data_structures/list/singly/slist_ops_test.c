#include "slist_ops.h"

/* Loop */
void HasLoop_test();
void BreakLoop_test();
void FindAndBreakLoop_test();

/* Intersection */
void FindIntersection_test();
void FindAndRemoveIntersection_test();
void FindAndRemoveIntersection_test2();

/* Flip */
void FlipListIterative_test();
void FlipListRecursive_test();

/******************************* -- Main -- ***********************************/
int main()
{
	HasLoop_test();
	BreakLoop_test();
	FindAndBreakLoop_test();
	
	FindIntersection_test();
	FindAndRemoveIntersection_test();
	FindAndRemoveIntersection_test2();
	
	FlipListIterative_test();
	FlipListRecursive_test();
	
	return 0;
}


/******************** -- TESTS -- *******************/
void HasLoop_test()
{	
	int num = 1;

	slist_node_t *head_int3 = SListCreateNode(&num, NULL);
	slist_node_t *head_int2 = SListCreateNode(&num, head_int3);
	slist_node_t *head_int1 = SListCreateNode(&num, head_int2);

	head_int3->next_node = head_int1;

	assert(1 == HasLoop(head_int1));
	
	head_int3->next_node = NULL;
	
	assert(0 == HasLoop(head_int1));
	
	SListFreeAll(head_int1);
}

void BreakLoop_test()
{
	int num = 1;

	slist_node_t *head_int3 = SListCreateNode(&num, NULL);
	slist_node_t *head_int2 = SListCreateNode(&num, head_int3);
	slist_node_t *head_int1 = SListCreateNode(&num, head_int2);

	head_int3->next_node = head_int1;

	assert(1 == HasLoop(head_int1));
	
	BreakLoop(head_int1, head_int1);
	
	assert(0 == HasLoop(head_int1));
	
	SListFreeAll(head_int1);

}

void FindAndBreakLoop_test()
{
	int num = 1;

	slist_node_t *head_int3 = SListCreateNode(&num, NULL);
	slist_node_t *head_int2 = SListCreateNode(&num, head_int3);
	slist_node_t *head_int1 = SListCreateNode(&num, head_int2);

	head_int3->next_node = head_int1;

	assert(1 == HasLoop(head_int1));
	
	FindAndBreakLoop(head_int1);
	
	assert(NULL == head_int3->next_node);
	assert(0 == HasLoop(head_int1));
	
	SListFreeAll(head_int1);
}

void FindIntersection_test()
{
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;
	
	slist_node_t *node5 = SListCreateNode(&n5, NULL);
	slist_node_t *node4 = SListCreateNode(&n4, node5);
	
	slist_node_t *node3 = SListCreateNode(&n3, NULL);
	slist_node_t *node2 = SListCreateNode(&n2, node3);
	slist_node_t *node1 = SListCreateNode(&n1, node2);
	
	node5->next_node = node2; 
	
	assert(node2 == FindIntersection(node1, node4));
	
	SListFreeAll(node4);
	free(node1);
}

void FindAndRemoveIntersection_test()
{
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;
	
	slist_node_t *node5 = SListCreateNode(&n5, NULL);
	slist_node_t *node4 = SListCreateNode(&n4, node5);
	
	slist_node_t *node3 = SListCreateNode(&n3, NULL);
	slist_node_t *node2 = SListCreateNode(&n2, node3);
	slist_node_t *node1 = SListCreateNode(&n1, node2);
	
	node5->next_node = node2; 
	
	assert(node2 == FindIntersection(node1, node4));
	
	assert(0 == FindAndRemoveIntersction(node1, node4));
	
	assert(NULL == FindIntersection(node1, node4));
	
	assert(NULL == node5->next_node);	
	
	SListFreeAll(node4);
	SListFreeAll(node1);
}

void FindAndRemoveIntersection_test2()
{
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;
	
	slist_node_t *node5 = SListCreateNode(&n5, NULL);
	slist_node_t *node4 = SListCreateNode(&n4, node5);
	
	slist_node_t *node3 = SListCreateNode(&n3, NULL);
	slist_node_t *node2 = SListCreateNode(&n2, node3);
	slist_node_t *node1 = SListCreateNode(&n1, node2);
	
	node5->next_node = node2; 
	
	assert(node2 == FindIntersection(node1, node4));
	
	FindAndRemoveIntersction(node4, node1);
	
	assert(NULL == FindIntersection(node1, node4));
	assert(1 == FindAndRemoveIntersction(node4, node1));
	
	assert(NULL == node1->next_node);	
	
	SListFreeAll(node4);
	SListFreeAll(node1);
}

void FlipListIterative_test()
{
	int n1 = 1;
	
	slist_node_t *node4 = SListCreateNode(&n1, NULL);
	slist_node_t *node3 = SListCreateNode(&n1, node4);
	slist_node_t *node2 = SListCreateNode(&n1, node3);
	slist_node_t *node1 = SListCreateNode(&n1, node2);
	
	assert(node4 == FlipListIterative(node1));
	assert(node3 == node4->next_node);
	assert(node2 == node3->next_node);
	assert(node1 == node2->next_node);
	assert(NULL == node1->next_node);
	
	SListFreeAll(node4);
}

void FlipListRecursive_test()
{
	int n1 = 1;
	
	slist_node_t *node4 = SListCreateNode(&n1, NULL);
	slist_node_t *node3 = SListCreateNode(&n1, node4);
	slist_node_t *node2 = SListCreateNode(&n1, node3);
	slist_node_t *node1 = SListCreateNode(&n1, node2);
	
	assert(node4 == FlipListRecursive(node1));
	assert(node3 == node4->next_node);
	assert(node2 == node3->next_node);
	assert(node1 == node2->next_node);
	assert(NULL == node1->next_node);
	
	SListFreeAll(node4);
}
