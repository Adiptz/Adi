#include <stdio.h> /* printf */
#include <assert.h> /* assert */

#include "slist.h"
#include "queue.h"
#include "bst.h"

void PrintTreeByLevels(bst_t *bst);
void RecMirrorTree(bst_iter_t node);
void PrintTree(bst_t *bst);
