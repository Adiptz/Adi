#include <stdlib.h> /* free */
#include <assert.h> /* assert */
#include <stdio.h>
#include "slist.h"

void CreateFree_test()
{
	int n1 = 1;
	slist_node_t *test = SListCreateNode(&n1, NULL);
	
	assert(1 == *(int *)test->data);
	assert(NULL == test->next_node);
	
	SListFreeAll(test);
}

void Insert_test()
{
	int n1 = 1, n2 = 2, n3 = 3;
	slist_node_t *node2 = SListCreateNode(&n2, NULL);
	slist_node_t *node1 = SListCreateNode(&n1, node2);
	slist_node_t *to_insert = SListCreateNode(&n3, NULL);
	
	/* insert to_insert before node2 
	   test holds address of to_insert*/
	slist_node_t *test = SListInsert(node2, to_insert);

	/* order expected : node1 | test | node2  */
	assert(*(int *)test->data == 3);
	assert(*(int *)test->next_node->data == 2);
	SListFreeAll(node1);
}


void InsertAfter_test()
{
	int n1 = 1, n2 = 2, n3 = 3;
	slist_node_t *node2 = SListCreateNode(&n2, NULL);
	slist_node_t *node1 = SListCreateNode(&n1, node2);
	slist_node_t *to_insert = SListCreateNode(&n3, NULL);
	
	SListInsertAfter(node1, to_insert);

	assert(*(int *)node1->next_node->data == 3);
	
	SListFreeAll(node1);
}


void Remove_test()
{
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;

	/* Creation of linked list */
	slist_node_t *node5 = SListCreateNode(&n5, NULL);
	slist_node_t *node4 = SListCreateNode(&n4, node5);
	slist_node_t *node3 = SListCreateNode(&n3, node4);
	slist_node_t *node2 = SListCreateNode(&n2, node3);
	slist_node_t *node1 = SListCreateNode(&n1, node2);
	
	slist_node_t *remove = SListRemove(node2);
	assert(node3 == remove);
	assert(3 == *(int *)node1->next_node->data);
	
	SListFreeAll(node1);
	free(node3); 
}


void Remove_After_test()
{
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;

	/* Creation of linked list */
	slist_node_t *node5 = SListCreateNode(&n5, NULL);
	slist_node_t *node4 = SListCreateNode(&n4, node5);
	slist_node_t *node3 = SListCreateNode(&n3, node4);
	slist_node_t *node2 = SListCreateNode(&n2, node3);
	slist_node_t *node1 = SListCreateNode(&n1, node2);
	
	/* regular remove */
	slist_node_t *test = SListRemoveAfter(node2);
	assert(node3 == test);
	assert(3 == *(int *)test->data);
	
	/* remove 1 before last */
	test = SListRemoveAfter(node4);
	assert(node4->next_node == NULL);
	
	/* remove last */
	test = SListRemoveAfter(node5);
	assert(NULL == test);
	
	SListFreeAll(node1);
	free(node3);
	free(node5);
}

void Counter_test()
{
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;

	/* Creation of linked list */
	slist_node_t *node5 = SListCreateNode(&n5, NULL);
	slist_node_t *node4 = SListCreateNode(&n4, node5);
	slist_node_t *node3 = SListCreateNode(&n3, node4);
	slist_node_t *node2 = SListCreateNode(&n2, node3);
	slist_node_t *node1 = SListCreateNode(&n1, node2);
	
	assert(5 == SListCount(node1));
	assert(4 == SListCount(node2));
	assert(3 == SListCount(node3));
	assert(2 == SListCount(node4));
	assert(1 == SListCount(node5));
	assert(0 == SListCount(NULL));
	
	SListFreeAll(node1);
}

int CmpFunc(void *node_data, const void *param_data)
{
	return !(*(int *)node_data == *(int *)param_data);
}

void Find_test()
{
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;

	slist_node_t *node5 = SListCreateNode(&n5, NULL);
	slist_node_t *node4 = SListCreateNode(&n4, node5);
	slist_node_t *node3 = SListCreateNode(&n3, node4);
	slist_node_t *node2 = SListCreateNode(&n2, node3);
	slist_node_t *node1 = SListCreateNode(&n1, node2);
	
	assert(node4 == SListFind(node1, CmpFunc, &n4));
	assert(node3 == SListFind(node1, CmpFunc, &n3));
	assert(node2 == SListFind(node1, CmpFunc, &n2));
	assert(node1 == SListFind(node1, CmpFunc, &n1));

	SListFreeAll(node1);
}

void Flip_test()
{
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;

	/* Creation of linked list */
	slist_node_t *node5 = SListCreateNode(&n5, NULL);
	slist_node_t *node4 = SListCreateNode(&n4, node5);
	slist_node_t *node3 = SListCreateNode(&n3, node4);
	slist_node_t *node2 = SListCreateNode(&n2, node3);
	slist_node_t *node1 = SListCreateNode(&n1, node2);
	
	SListFlip(node1);
	
	assert(node1->next_node == NULL);
	assert(node2->next_node == node1);
	assert(node3->next_node == node2);
	assert(node4->next_node == node3);
	assert(node5->next_node == node4);
	
	SListFreeAll(node5);
}

void Loop_test()
{	
	int num = 1;

	slist_node_t *head_int3 = SListCreateNode(&num, NULL);
	slist_node_t *head_int2 = SListCreateNode(&num, head_int3);
	slist_node_t *head_int1 = SListCreateNode(&num, head_int2);

	head_int3->next_node = head_int1;

	assert(1 == SListHasLoop(head_int1));
	
	head_int3->next_node = NULL;

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
	
	assert(node2 == SListFindIntersection(node1, node4));
	
	SListFreeAll(node4);
	free(node1);
}



int main()
{
	CreateFree_test();
	InsertAfter_test();
	Insert_test();
	Remove_test();
	Remove_After_test();
	Counter_test();
	Find_test();
	Flip_test();
	Loop_test();
	FindIntersection_test();
	
	return 0;
}
