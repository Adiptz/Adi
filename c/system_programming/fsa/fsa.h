/******************************************
* Title	: Fixed Sized Allocator
* Author: Ran Shieber
* Group	: OL71
* Date	: 28/08/2019
*******************************************/
#ifndef __OL71_FSA_H
#define __OL71_FSA_H

#include <stddef.h> /* size_t */

typedef struct fsa fsa_t;

/*
 * Initialize new fixed size allocator
 * @memory : allocated memory to be used as fixed sized allocator
 * @memory_size : size of mem in bytes
 * @block_size  : size of fixed block in bytes
 * Return: pointer to fixed sized allocator
 * Errors: if @memory_size is too small for 1 block of size @block_size, 
 *         return NULL
 *   	   if @block_size is 0, behavior is undefined
 *		   if @memory is not aligned, behavior is undefined
 */
fsa_t *FSAInit(void *memory, size_t memory_size, size_t block_size);

/*
 * Allocate memory block in fixed size allocator
 * @fsa : fixed sized allocator
 * Return: pointer to allocated memory
 * Errors: if fsa is full, return NULL
 */
void *FSAAlloc(fsa_t *fsa);

/*
 * Free memory block in fixed size allocator
 * @block_to_free : allocated memory block
 * Return: none
 * Errors: same as free() in <stdlib.h>
 */
void FSAFree(void *block_to_free);

/*
 * Count number of free blocks in fixed size allocator
 * @fsa  : fixed sized allocator
 * Return: number of free blocks in fsa
 * Errors: none
 */
size_t FSACountFree(const fsa_t *fsa);

/*
 * Calculate required size of memory allocation per user input
 * @num_of_blocks: amount of elements required 
 * @block_size: fixed size of data element
 * Return: number of bytes needed for an fsa of @num_of_blocks of size 
    @block_size, assuming first address is word-aligned.
 * Errors: none
 */
size_t FSASuggestSize(size_t num_of_blocks, size_t block_size);

#endif /* __OL71_FSA_H */
