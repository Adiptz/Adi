/****************************************
 * Title  : Variable Sized Allocator    *
 * Author : Adi Peretz                  *
 ****************************************/
#include <stdio.h> /* perror */
#include <stdlib.h> /* abs */
#include <assert.h> /* assert */

#include "vsa.h"

#define DEADBEEF 0xDEADBEEFl
#define WORD_SIZE (sizeof(size_t))

typedef struct manager
{
	void *end_of_memory;		
}manager_t;

struct vsa
{
	long block_size;
	
 	#ifndef NDEBUG
	long magic_number;
	#endif	
};


/*************************** -- HELP FUNCTIONS -- *****************************/

/* Add pedding to request number of bytes to alloc from user

   input : @bytes_to_alloc - number of bytes needs to allocate
   output :  number of bytes to alocate after calculate alignment */
static size_t CalcSizeOfBlockImp(size_t bytes_to_alloc)
{
	size_t remainder = bytes_to_alloc % WORD_SIZE;
	
	if (0 != remainder)
	{	
		bytes_to_alloc += (WORD_SIZE - remainder);
	}
	
	return bytes_to_alloc;
}


/* Making Defragmentation between free block 

   input : @head - begginging of metadata of block
		   @end_of_memory - end of all vsa_pool
   output : size of DefragImprmented block */
static long DefragImp(vsa_t *head, void *end_of_memory) 
{
	long size = 0;
	long counter = 0;
	vsa_t *runner = NULL;
	
	assert(NULL != head);
	
	
	for (runner = head
		; (void *)runner < end_of_memory && (0 < runner->block_size)
		; runner = (vsa_t *)((char *)runner + 
				                     runner->block_size + sizeof(vsa_t)))
	{
		++counter;
		size += runner->block_size;
	}
	
	if (0 != size)
	{
		head->block_size = size + ((counter - 1) * sizeof(vsa_t));
	}
	
	
	return head->block_size;	
}


/* Create new metadata for next block if needed 
   and there is enough space for it 
   
   input : @current_size - block size that return from DefragImp
   	       @original_block_size - prev size of block before allocate again 
   	       @bytes_to_alloc - bytes needed to aloc
		   @vsa - points to beggining of metadata in current block
   output : none */
static void CreateNewMetaDataImp(long current_size,
	                   			 size_t bytes_to_alloc,
					   			 long original_block_size,
					   			 vsa_t *vsa)
{
	if (current_size > (long)bytes_to_alloc)
	{	
		long remain_space = original_block_size - bytes_to_alloc;
		
		if (remain_space > (long)(sizeof(vsa_t)))
		{
			vsa = (vsa_t *)((char *)vsa + bytes_to_alloc + sizeof(vsa_t));
			vsa->block_size = original_block_size -
                              bytes_to_alloc - sizeof(vsa_t);
			
			#ifndef NDEBUG
			vsa->magic_number = DEADBEEF;
			#endif
		}
		else
		{
			 vsa->block_size -= remain_space;
		}
	}
}

/******************************* -- INIT -- ***********************************/
vsa_t *VSAInit(void *memory, size_t memory_size)
{	
	vsa_t *vsa = NULL;
	
	/* shrink size if not aligned */										
	memory_size -= memory_size % WORD_SIZE; 

	assert(NULL != memory);
	
	if (0 != (size_t)memory % WORD_SIZE)
	{
		return NULL;
	}
	
	/* initialized managment */
	((manager_t *)memory)->end_of_memory = (char *)memory + memory_size;
	
	/* initialized vsa */
	vsa = (vsa_t *)((char *)memory + sizeof(manager_t));
	vsa->block_size = memory_size - sizeof(vsa_t) - sizeof(manager_t);
		
	#ifndef NDEBUG
	vsa->magic_number = DEADBEEF;
	#endif
		
	return memory;
}


/******************************* -- ALLOC -- **********************************/
void *VSAAlloc(vsa_t *vsa_pool, size_t bytes_to_alloc)
{
	long found_size = 0;
	long original_block_size = 0;
	void *end = NULL;
	vsa_t *runner = NULL;
	void *return_block = NULL;
	
	assert(NULL != vsa_pool);
	
	/* aligned request bytes_to_alloc */
	bytes_to_alloc = CalcSizeOfBlockImp(bytes_to_alloc);	
	

	for (end = ((manager_t *)vsa_pool)->end_of_memory, 
	     runner = (vsa_t *)((char *)vsa_pool + sizeof(manager_t))
	    ;((void *)runner < end)
	    ;runner = (vsa_t *)((char *)runner + abs(found_size) + sizeof(vsa_t)))
	{
		found_size = DefragImp(runner, end);	
		
		if (found_size >= (long)bytes_to_alloc)
		{
			break;
		}	
	}
	
	if ((void *)runner == end)
	{
		return NULL;
	}
	
	/* update metadata of current block */				
	original_block_size = runner->block_size;
	runner->block_size = -bytes_to_alloc;

	return_block = (char *)runner + sizeof(vsa_t); 
	
	CreateNewMetaDataImp(found_size, bytes_to_alloc, original_block_size, runner);
	
	return return_block;
}

/******************************* -- FREE -- ***********************************/
void VSAFree(void *address_to_free)
{
	vsa_t *free_block = NULL;
	
	assert (NULL != address_to_free);
	
	free_block = (vsa_t *)((char *)address_to_free - sizeof(vsa_t));

	#ifndef NDEBUG
	if(free_block->magic_number != DEADBEEF)
	{
		perror("Error: Not Your VSA");
		abort();
	}
	#endif

	free_block->block_size *= -1; /* TODO help function -- change status */
}

/*************************** -- LARGEST CHUNK -- ******************************/
size_t VSALargestChunk(vsa_t *vsa_pool)
{
	long biggest_size = 0;
	long possible_chunk = 0;
	void *end = NULL;
	vsa_t *runner = NULL;
	
	for ( end = ((manager_t*)vsa_pool)->end_of_memory,
	      runner = (vsa_t *)((char *)vsa_pool + sizeof(manager_t))
		; (void *)runner < end
	    ; runner = (vsa_t *)((char *)runner + abs(possible_chunk)
	    				                          + sizeof(vsa_t))
		)
	{
	 	possible_chunk = DefragImp(runner, end);
		
		if (biggest_size < possible_chunk)
		{
			biggest_size = possible_chunk;
		}	
	}
	
	return biggest_size;
}
