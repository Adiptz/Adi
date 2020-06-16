#ifndef __ILRD_AVL_H
#define __ILRD_AVL_H

#include <stddef.h> /* size_t */

typedef struct avl avl_t;

/*
 * Create new AVL tree.
 * Param: @cmp_func - user comparison function. Returns 0 if <tree_data> and 
 *					  <new_data> are equal, positive if <tree_data> is after 
 *					  or negative if it's before.
 * Param: @param - user Param: for <cmp_func> function.
 * Return: pointer to new AVL tree.
 * Errors: if memory allocation failed, return NULL.
 */
avl_t *AVLCreate(void *param, int (*cmp_func)(const void *tree_data,
								 			  const void *new_data,
								 			  void *param));

/* 
 * POST-ORDER.
 * Destroy AVL tree.
 * Param: @avl - pointer to AVL tree.
 */
void AVLDestroy(avl_t *avl);

/*
 * Insert new element to tree.
 * Param: @avl - pointer to AVL tree. 
 * Param: @data_to_insert - pointer to data to insert.
 * Return: 0 on success.
 * Errors: if memory allocation failed, return 1.
 */
int AVLInsert(avl_t *avl, const void *data_to_insert); 

/*
 * Removes iter from tree.
 * Param: @avl - pointer to AVL tree
	      @data_to_remove: data to remove.
 * Errors: if data not found, do nothing.
 */
void AVLRemove(avl_t *avl, const void *data_to_remove);

/* 
 * PRE-ORDER.
 * Count how many nodes in given AVL tree.
 * Param:  @avl - AVL tree.
 * Return: number of nodes of avl.
 */
size_t AVLCount(const avl_t *avl); 

/*
 * Check height of AVL tree.
 * Param:  @avl - pointer to AVL tree.
 * Return: height of avl.
 */
size_t AVLHeight(const avl_t *avl); 

/*
 * Check if tree is empty.
 * Param:  @avl - AVL tree.
 * Return: 1 if avl is empty, 0 otherwise.
 */
int AVLIsEmpty(const avl_t *avl); 

/*
 * IN-ORDER.
 * Perform <action_func> for each element in <avl>,
 * stops if action returns non-zero.
 * Param: @avl - pointer to AVL tree.
 * Param: @param - user Param: for <action_func>.
 * Param: @action_func - function to perform.
 * Note: <action_func> should not alter <tree_data>, doing so might alter
 *		 the structural logic of the avl. <action_func> return 0 on success,
 		 non-zero otherwise.
 * Return: 0 for success, action's last return value otherwise.
 */
int AVLForEach(void *param, avl_t *avl, int (*action_func)(void *tree_data,
														   void *param));

/*
 * Find <data> in binary tree <avl>.
 * Param:  @avl - pointer to AVL tree to search.
 * Param:  @data - data to find.
 * Return: pointer to found data.
 * Errors: if <data> was not found, return NULL.
 */
void *AVLFind(const avl_t *avl, const void *data_to_find);

#endif /* __ILRD_AVL_H */

