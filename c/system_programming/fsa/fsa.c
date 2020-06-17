/**********************
 * Author   :  Adi    *
 **********************/

#include <assert.h> /* assert */
#include "fsa.h"

#define WORD_SIZE sizeof(size_t) 

/**************************** -- fsa gesign -- ********************************/
struct fsa
{
	size_t next_free_index;
};

typedef struct metadata 
{
	size_t index;
}metadata_t;



/************************* -- HELP FUNCTIONS -- *******************************/


/* input : block_size that requested
 * output : the actual size needed includes metadata */
static size_t CalcSizeOfBlock(size_t block_size)
{
	/* in case block_size bigger than max alignment and need pedding */
	if (0 != block_size % WORD_SIZE && block_size > WORD_SIZE)
	{
		block_size += (sizeof(metadata_t) + 
					  (WORD_SIZE - (block_size % WORD_SIZE)));
	}
	else
	{
		block_size = sizeof(metadata_t) + WORD_SIZE;
	}
	
	return block_size;
}

/* input : pointer to fsa, pointer to set 
 * output : pointer set to next free blocks' metadata */
static void *PointToNextFreeBlock(void *pointer_to_set, fsa_t *fsa)
{
	assert(NULL != fsa);
	
	/* jump for free block and go back to beggining of metadata */
	pointer_to_set =((char *)fsa + fsa->next_free_index) - sizeof(metadata_t); 
	
	return pointer_to_set;
}

/* input : pointer to fsa, pointer to metadata
   output : swapping between values holds by the two pointers */
static void SwapValues(fsa_t *fsa_ptr, metadata_t *index_ptr)
{
	size_t tmp_value = 0; 
	
	assert(NULL != fsa_ptr);
	assert(NULL != index_ptr);
	
	tmp_value = fsa_ptr->next_free_index; 
	fsa_ptr->next_free_index = index_ptr->index;	
	index_ptr->index = tmp_value; 
}

/* input : pointer to block from user
   output : metadata of given block */
static size_t GetMetadata(void *block)
{
	size_t metadata = 0;

	assert(NULL != block);	
		
	/*take pointer back --> read data --> get pointer back to original place */
	block = (char *)block - sizeof(metadata_t);
	metadata = ((metadata_t *)block)->index;
	block = (char *)block + sizeof(metadata_t);
	
	return metadata;
}



/******************************* -- INIT -- ***********************************/
fsa_t *FSAInit(void *memory, size_t memory_size, size_t block_size)
{
	size_t i = 0;
	size_t blocks_to_create = 0;
	char *runner = NULL;
	fsa_t *fsa = NULL;
	
	assert(NULL != memory);
	
	block_size = CalcSizeOfBlock(block_size); /* add pedding to size if need */

	if (memory_size < block_size + sizeof(fsa_t))
	{
		return NULL;
	}
	
	fsa = (fsa_t *)memory;	
	
	blocks_to_create = (memory_size - sizeof(fsa_t)) / block_size;
		
	fsa->next_free_index = sizeof(fsa_t) + sizeof(metadata_t);
		
	runner = memory;
	
	/* put the next free adress (offset from fsa)
	   at the beggining of each block */	
	for (i = 1, runner += sizeof(fsa_t)
		; i < (blocks_to_create)
		; ++i, runner += block_size)
	{
		((metadata_t *)runner)->index = fsa->next_free_index + (block_size * i);
	}

	((metadata_t *)runner)->index = 0;
	
	return (fsa_t *)memory;
}

/******************************* -- ALLOC -- **********************************/
void *FSAAlloc(fsa_t *fsa)
{
	void *tmp_pointer = NULL;
	
	assert(NULL != fsa);
	
	if (0 == fsa->next_free_index)
	{
		return NULL;
	}
	
	/* point to next free adress and swap it with the value fsa holds*/ 
	tmp_pointer = PointToNextFreeBlock(tmp_pointer, fsa);
	SwapValues(fsa, (metadata_t*)tmp_pointer);
	
	return (char *)fsa + (*(size_t *)tmp_pointer);
}

/******************************* -- FREE -- ***********************************/
void FSAFree(void *block_to_free)
{
	void *fsa = NULL;
	size_t distance_from_beggining = 0;
	
	if(NULL == block_to_free)
	{
		/*empty body*/
	}
	else
	{
		/* find and point to beggining of fsa */
		distance_from_beggining = GetMetadata(block_to_free);
		fsa = (char *)(block_to_free) - distance_from_beggining;
		
		/* point to metadata of block_to_free */
		block_to_free = (char *)block_to_free - sizeof(metadata_t);
	
		SwapValues(fsa, block_to_free);
	}
}

/*************************** -- COUNT FREE -- *********************************/
size_t FSACountFree(const fsa_t *fsa)
{
	size_t counter = 0;
	size_t next_index = 0;
	
	next_index = fsa->next_free_index;
	
	while(0 != next_index)
	{
		++counter;
		next_index = GetMetadata((char *)fsa + next_index);
	}
	
	return counter;
}

/************************** -- SUGGEST SIZE -- ********************************/
size_t FSASuggestSize(size_t num_of_blocks, size_t block_size)
{
	size_t suggest_size = 0; 
	
	block_size = CalcSizeOfBlock(block_size);
	suggest_size = (block_size * num_of_blocks) + sizeof(fsa_t);
	
	return suggest_size;	
}
