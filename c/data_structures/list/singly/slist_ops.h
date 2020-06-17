/**** -- Includes -- ****/
#include <assert.h> /* assert */
#include <stdlib.h> /* free */

#include "slist.h"

/******************************************************************************/

/* Loop */
int HasLoop(const slist_node_t *head);
void BreakLoop(const slist_node_t *head, slist_node_t *loop_position);

/********************** -- FIND AND BREAK LOOP **********************
 *	input  : node to head of list									*
 *  output : 0 if there was loop and it broked						*
 *			 1 if there's no loop                                   *  
 ********************************************************************/
int FindAndBreakLoop(const slist_node_t *head);


/* Intersection */
slist_node_t *FindIntersection(const slist_node_t *node1,
							   const slist_node_t *node2);

													   
/*************** -- FIND AND REMOVE INTERSECTION -- *****************
 *	Find intersection between two lists                             *
 *  list1 will stay as it was, list2 will get shorter 				*
 *																	*
 *	input  : node1 to head of list1									*
 *           node2 to head of lists									*
 *  output : 0 if there was intersection and it broked				*
 *			 1 if there's no intersection                           *  
 ********************************************************************/
int FindAndRemoveIntersction(slist_node_t *node1, slist_node_t *node2);


/* Flip */
slist_node_t *FlipListIterative(slist_node_t *head);
slist_node_t *FlipListRecursive(slist_node_t *head);
