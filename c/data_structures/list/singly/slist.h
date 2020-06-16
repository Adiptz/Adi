#ifndef __OL71_SLIST_H
#define __OL71_SLIST_H


#include <stddef.h> /* size_t */

typedef struct node slist_node_t;
typedef int (*cmp_func)(void *node_data, const void *param_data);
typedef int (*func_action)(void *data, void *param);

struct node
{
    void *data;
    slist_node_t *next_node;
};


/*
 * Create node
 * Param void *data : pointer to data to store in node
 * Param next : address for the next node
 * Return : pointer to the created node
 * Errors : returns NULL if memory allocation failed.
 */
slist_node_t *SListCreateNode(void *data, slist_node_t *next);


/*
 * Free node and all subsequent nodes
 * Param : pointer to the first node in linked list
 * Return : amount of nodes freed
 * Errors: if node has loop, behaviour is undefind
 */
void SListFreeAll(slist_node_t *head);


/*
 * Insert node to linked-list before a given node
 * Param current_node : node to insert before
 * Param new_node : node to insert
 * Return: pointer to new_node
 * Errors: none
 */
slist_node_t *SListInsert(slist_node_t *current_node, slist_node_t *new_node);


/*
 * Insert node to linked-list after a given node
 * Param current_node : node to insert after
 * Param new_node : node to insert
 * Return :  pointer to current_node
 * Errors : none
 */
slist_node_t *SListInsertAfter(slist_node_t *current_node, slist_node_t *new_node);


/*
 * Find first node that store a given data
 * param head : pointer to node look from
 * param cmp_func : pointer to compare func
 * param data : data needs to be find in list.
 * Return : address of first node with matching <data>, NULL if none was found. 
 * Return cmp_func : 0 for success, else for fail.
 * Errors : if node has loop, behaviour is undefind
 */
slist_node_t *SListFind(slist_node_t *head, cmp_func cmp, const void *data);


/*
 * Remove links from node 
 * param head : pointer to node to remove - can't be the last node.
 * Return : pointer to the removed node
 * Errors : if head is the last node, behaviour is undifined
 */
slist_node_t *SListRemove(slist_node_t *head);


/*
 * Remove links from and to node after a given node
 *  param head : pointer to node pointing to node to remove 
 * Return : pointer to the removed node
 *			if node has no node after it - return NULL
 * Errors : none
 */
slist_node_t *SListRemoveAfter(slist_node_t *head);


/*
 * Count how many nodes in linked-list
 * Param : pointer to node 
 * Return : numbers of nodes including starting node
 * Errors : if node has loop, behaviour is undefind
 */
size_t SListCount(const slist_node_t *head);


/*
 * Perform action for each node in the linked-list
 * param head :  pointer to node
 * Param func : pointer to action function
 * Param param : param passing to action func. NULL if there's no param. 
 * Return : 0 for success, else for fail.
 * Return action_func : 0 for success, else for fail.
 * Errors : if node has loop, behaviour is undefined
 */
int SListForEach(slist_node_t *head, func_action func, void *param);


/*
 * Changes the direction of the linked-list
 * param head : pointer to node
 * Return : pointer to the new first node
 * Errors : if node has loop, behavior is undefined
 */
slist_node_t *SListFlip(slist_node_t *head);


/*
 * Check if linked list contains a loop
 * param head : pointer to node
 * Return : 1 if there’s loop, else 0 
 * Errors : none
 */
int SListHasLoop(const slist_node_t *head);


/* 
 * Find intersection of two lists
 * Param node1 : pointer to node
 * Param node2 : pointer to node
 * Return : pointer to the firsrt intersaction node, NULL if no intersection found
 * Errors : if node has loop, behavior is undefined
 */
slist_node_t *SListFindIntersection(const slist_node_t *node1,
									const slist_node_t *node2);


#endif /* __OL71_SLIST_H */

