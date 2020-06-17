#include <assert.h> /* assert */
#include <stdlib.h> /* malloc, free */

#include "heap.h"
#include "vector.h"

#define SIZE 100

typedef int (*cmp_priority_t)(const void *data1, const void *data2, void *param);
typedef int (*is_match_t)(const void *heap_data, const void *user_data);

enum direction {LEFT, RIGHT};
enum sift_direction {SIFT_UP, SIFT_DOWN};
enum sifting {LEFT_DOWN, RIGHT_DOWN, UP, NO_SIFT};

struct heap 
{
	cmp_priority_t cmp_priority;
	void *param;
	vector_t *vector;
};

/* sifting */
static void Sifting(heap_t *heap, size_t index_to_remove);								
static int GetSiftDirection(heap_t *heap, size_t index);
static void DoSift(heap_t *heap, size_t index, int sift_direction);

/* data */
static void *GetData(vector_t *vector, size_t index);
static void SwapData(vector_t *vector, size_t index1, size_t index2);
static size_t FindIndexWithData(heap_t *heap,
			                    is_match_t is_match,
			                    void *user_data);
/* relative */			                    
static size_t GetParentIndex(size_t index);
static int HasParent(size_t index);
static size_t GetChildIndex(size_t index, int direction);
static int HasChild(heap_t *heap, size_t index, int direction);                 
static int GetMaxChildDirection(heap_t *heap,
								size_t left_child,
								size_t right_child);


/******************************* -- CREATE -- *********************************/
heap_t *HeapCreate(cmp_priority_t cmp_priority, void *param)
{
	vector_t *new_vector = NULL;
	
	heap_t *new_heap = (heap_t *)malloc(sizeof(heap_t)); 
	if (NULL == new_heap)
	{
		return NULL;
	} 
	
	new_vector = VectorCreate(1, sizeof(void *));
	if(NULL == new_vector)
	{
		free(new_heap); new_heap = NULL; 
		return NULL;
	}
	
	new_heap->cmp_priority = cmp_priority;
	new_heap->param = param;
	new_heap->vector = new_vector;
	
	return new_heap;	
}				

/******************************* -- DESTROY -- ********************************/
void HeapDestroy(heap_t *heap)
{
	assert(NULL != heap);
	
	VectorDestroy(heap->vector);
	free(heap);	heap = NULL;	
}

/********************************* -- PUSH -- *********************************/
int HeapPush(heap_t *heap, const void *data)
{
	int status = 0;
	size_t last_index = 0;

	assert(NULL != heap);

	/* at first push only - for not allocate space till not use */
	if (HeapIsEmpty(heap))
	{
		status = VectorReserve(heap->vector, SIZE);
		if (VECTOR_ALLOCATION_FAILED == status)
		{
			return HEAP_ALLOC_FAIL;
		}
	}
	
	status = VectorPushBack(heap->vector, &data);
	if (VECTOR_ALLOCATION_FAILED == status)
	{
		return HEAP_ALLOC_FAIL;
	}
	
	last_index = HeapSize(heap) - 1;
	
	DoSift(heap, last_index, SIFT_UP);
	
	return HEAP_SUCCESS;	
}

/********************************* -- POP -- **********************************/
void HeapPop(heap_t *heap)
{
	size_t first_index = 0;
	size_t last_index = 0;
	
	assert(NULL != heap);
	
	last_index = HeapSize(heap) - 1 ;

	SwapData(heap->vector, first_index,last_index);
	
	VectorPopBack(heap->vector);
	
	if (!HeapIsEmpty(heap))
	{
		DoSift(heap, first_index, SIFT_DOWN);	
	}
}

/******************************** -- PEEK -- **********************************/
void *HeapPeek(const heap_t *heap)
{
	void **top_priority = NULL;
	
	assert(NULL != heap);
	
	top_priority = VectorGetItemAddress(heap->vector, 0); 
	
	return *top_priority;
}

/******************************** -- SIZE -- **********************************/
size_t HeapSize(const heap_t *heap)
{
	assert(NULL != heap);
	
	return VectorSize(heap->vector);
}

/******************************* -- IS EMPTY -- *******************************/
int HeapIsEmpty(const heap_t *heap)
{
	assert(NULL != heap);
	
	return (VectorIsEmpty(heap->vector));
}
		
/******************************* -- REMOVE -- *********************************/
void *HeapRemove(heap_t *heap, is_match_t is_match, void *data_to_remove)
{
	void *data_to_return = NULL;
	size_t last_index = 0;
	size_t index_to_remove = 0;
	
	assert(NULL != heap);
	assert(NULL != data_to_remove);
	
	last_index = HeapSize(heap) - 1;
	index_to_remove = FindIndexWithData(heap, is_match, data_to_remove);
	
	
	if (HeapSize(heap) == index_to_remove) /* data not found */
	{
		return NULL;
	}
	
	data_to_return = GetData(heap->vector, index_to_remove);
	
	if (index_to_remove == last_index) /* sift not needed */
	{
		VectorPopBack(heap->vector);
	}
	else	
	{
		/* move data to last index and remove it */
		SwapData(heap->vector, index_to_remove, last_index);
		
		VectorPopBack(heap->vector);
		
		Sifting(heap, index_to_remove);	
	}
	
	return data_to_return;
}


/*******************************************************************************
 *******************************************************************************
 **																			  **
 ** 				 		PRIVATE PRIVATE PRIVATE							  **
 **																			  **
 *******************************************************************************
 ******************************************************************************/

static void *GetData(vector_t *vector, size_t index)
{	
	assert(NULL != vector);
	
	return *(void **)VectorGetItemAddress(vector, index);
}

static size_t GetChildIndex(size_t index, int direction)
{
	return 2 * index + 1 + direction;
}

static size_t GetParentIndex(size_t index)
{
	return ((index - 1) / 2); 
}

static int GetMaxChildDirection(heap_t *heap,
								size_t left_child,
								size_t right_child)
{
	void *left_data = GetData(heap->vector, left_child);
	void *right_data = GetData(heap->vector, right_child);
	
	int cmp_result = heap->cmp_priority(left_data, right_data, heap->param);
	
	return ((0 < cmp_result) ? RIGHT : LEFT);
}

static void DoSift(heap_t *heap, size_t index, int sift_direction)
{
	int sift_status = 0;
	size_t child_index = 0;
	size_t parent_index = 0;

	for (sift_status = GetSiftDirection(heap, index)
		; NO_SIFT != sift_status
		; sift_status = GetSiftDirection(heap, index))
	{
		int direction = sift_status;
		
		if (SIFT_UP == sift_direction) /* index should be sif with his parent */
		{
			parent_index = GetParentIndex(index);
			SwapData(heap->vector, index, parent_index);
			index = parent_index;
		}		
		else   /* index should be sif with his child */
		{
			child_index = GetChildIndex(index, direction);
			SwapData(heap->vector, index, child_index);
			index = child_index;
		}
	}
}

static void SwapData(vector_t *vector, size_t index1, size_t index2)
{
	void **data1 = VectorGetItemAddress(vector, index1);
	void **data2 = VectorGetItemAddress(vector, index2);
	void *tmp = NULL;
	
	assert(NULL != data1);
	assert(NULL != data2);
	
	tmp = *data1;
	*data1 = *data2;
	*data2 = tmp;
}

static int HasChild(heap_t *heap, size_t index, int direction)
{
	size_t child_index = 0;
	size_t heap_size = 0;
	
	assert(NULL != heap);
	
	heap_size = HeapSize(heap);
	child_index = GetChildIndex(index, direction);
	
	return (child_index < heap_size);
}

static int HasParent(size_t index)
{
	return (0 != index);
	
}

static int GetSiftDirection(heap_t *heap, size_t index)
{
	size_t parent_index = 0;
	size_t left_child_index = 0;
	size_t right_child_index = 0;
	void *index_data = NULL;

	assert(NULL != heap);
	
	parent_index = GetParentIndex(index);
	left_child_index = GetChildIndex(index, LEFT);
	right_child_index = GetChildIndex(index, RIGHT);
	index_data = GetData(heap->vector, index);
	
	if (HasParent(index) && 0 < heap->cmp_priority
			                        (GetData(heap->vector, parent_index),
							         GetData(heap->vector, index),
							         heap->param))
	{
		return UP;
	}
	else
	{
		if (HasChild(heap, index, LEFT)) /* have left child */
		{
			if (HasChild(heap, index, RIGHT)) /* also have right child */
			{
				int direction = GetMaxChildDirection(heap,
											         left_child_index,
											         right_child_index);
				
				void *max_child_data = 
				GetData(heap->vector, GetChildIndex(index, direction));
				
				int cmp_result = heap->cmp_priority(index_data,
													max_child_data,
													heap->param);
													
				return ((0 < cmp_result) ? direction : NO_SIFT);
			}
			else /* have only left child */
			{
				void *left_child_data = GetData(heap->vector, left_child_index);
				int cmp_result = heap->cmp_priority(index_data,
									  	 	  	    left_child_data,
									  	 	  	    heap->param);
				
				return ((0 < cmp_result) ? LEFT_DOWN : NO_SIFT);		  	 	  	    
			}											   		
		}
	}
		
	return NO_SIFT;
}

static size_t FindIndexWithData(heap_t *heap,
			                    is_match_t is_match,
			                    void *user_data)
{
	int is_match_result = 0;
	size_t i = 0;
	size_t heap_size = HeapSize(heap);
	
	assert(NULL != heap);
	
	for (i = 0
		; 0 == is_match_result && i < heap_size
		; ++i)
	{
		void *heap_data = GetData(heap->vector, i);
		is_match_result = is_match(heap_data, user_data);	
	}
	
	/* in case data found i increased one too many */
	if (is_match_result == 1)
	{
		i -= 1; 
	}
	
	return i;
}			                    

static void Sifting(heap_t *heap, size_t index_to_remove)
{
	int sift_direction = 0;

	assert(NULL != heap);

	sift_direction = GetSiftDirection(heap, index_to_remove);
	
	if (LEFT_DOWN == sift_direction || RIGHT_DOWN == sift_direction)
	{
		DoSift(heap, index_to_remove, SIFT_DOWN);
	}
	else if (UP == sift_direction)
	{
		DoSift(heap, index_to_remove, SIFT_UP);
	}
}		               	                    
