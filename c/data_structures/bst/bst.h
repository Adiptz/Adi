#ifndef __OL712_BST_H
#define __OL712_BST_H

#include <stddef.h> /* size_t */

typedef struct bst bst_t;
typedef struct bst_node *bst_iter_t; 

void PrintTreeByLevels(bst_t *bst);

/*
 * Create new binary search tree
 * Param @cmp_func - user comparison function. returns 0 if <iter_data> and 
 *					 <new_data> are equal, positive if <iter_data> is larger 
 *					 or negative if its smaller.
 * Param @param - user param for <is_before> function
 * Return: pointer to new binary search tree
 * Errors: if memory allocation failed, return NULL
 */
bst_t *BSTCreate(int (*cmp_func)(void *iter_data, void *new_data, void *param), 
				 void *param);

/*
 * Destroy binary search tree 
 * Param @bst - pointer to binary search tree  
 * Return : --
 * Errors : --
 */
void BSTDestroy(bst_t *bst);

/*
 * Insert new element to tree
 * Param @bst - pointer to binary search tree  
 * Param @data - pointer to data to insert
 * Return : pointer to new leaf
 * Errors : if memory allocation failed, return NULL
 */
bst_iter_t BSTInsert(bst_t *bst, void *data); 

/*
 * Removes iter from tree
 * Param @iter_to_remove - iter to remove
 * Return : --
 */
void BSTRemove(bst_iter_t iter_to_remove);

/*
 * Count how many nodes in given binary search tree
 * Param  @bst - binary search tree  
 * Return : size of bst
 * Errors : --
 */
size_t BSTSize(const bst_t *bst); 

/*
 * Check if tree is empty
 * Param  @bst - binary search tree
 * Return : 1 if bst is empty, 0 otherwise
 * Errors : --
 */
int BSTIsEmpty(const bst_t *bst); 

/*
 * Perform <action_func> for each element in <bst>, stops if action returns
 *        non-zero.
 * Param @bst - pointer to binary search tree 
 * Param @param - user param for <action_func>
 * Param @action_func - function to perform.
 * Note : <action_func> should not alter <iter_data>, doing so might alter
 *		  the structural logic of the bst.
		  <action_func> return 0 on success, non-zero otherwise
 * Return : 0 for success, action's last return value otherwise
 * Errors : --
 */
int BSTForEach(void *param, bst_iter_t from, bst_iter_t to, 
			   int (*action_func)(void *iter_data, void *param));

/*
 * Find <data> in binary tree <bst> 
 * Param  @bst - binary search tree to search
 * Param  @data - data to find
 * Return : iter to found iter
 * Errors : if <data> was not found, return NULL
 */
bst_iter_t BSTFind(bst_t *bst, void *data_to_find);   

/*
 * Get data of iter
 * Param @iter - pointer to iter to get data from
 * Return : pointer to data of iter
 * Errors : --
 */
void *BSTGetData(bst_iter_t iter);

/*
 * get iter to next larger value
 * Param @Iter - current iter
 * Return : iter to next larger value
 * Errors : if no next iter, return END
 */
bst_iter_t BSTNext(bst_iter_t iter);

/*
 * get iter to prev smaller value
 * Param @Iter - current iter
 * Return : iter to prev smaller value
 * Errors : if iter is BEGIN, behaviour is undefined 
 */
bst_iter_t BSTPrev(bst_iter_t iter);

/*
 * get End iter
 * Param  @bst - pointer to bst
 * Return : iter to invalid iter END
 * Errors : --
 */
bst_iter_t BSTEnd(const bst_t *bst);

/*
 * get iter to smallest value
 * Param  @bst - pointer to bst
 * Return : iter to smallest value
 * Errors : If <bst> is empty, returns END
 */
bst_iter_t BSTBegin(const bst_t *bst);

/*
 *  Compares two iterators
 * Param  @iter1 pointer to the first iter
 * Param  @iter2 pointer to the second iter
 * Return : 1 if iterators are same , 0 otherwise
 * Errors : --
 */
int BSTIsSameIter(bst_iter_t iter1, bst_iter_t iter2);


bst_iter_t BSTGetRoot(bst_t *bst);

#endif /*__OL712_BST_H*/
