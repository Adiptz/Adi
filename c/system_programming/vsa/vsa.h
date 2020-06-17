/****************************************
 * Title  : Variable Sized Allocator    *
 * Author : Daya Dotan                  *
 * Group  : OL71                        *
 * Date   : 01/09/2019                  *
 ****************************************/

#ifndef __OL71_VSA_H
#define __OL71_VSA_H

#include <stddef.h> /* size_t */

typedef struct vsa vsa_t;

/*
 * Initialize variable size allocator
 * @memory : allocated memory to be used as variable sized allocator
 * @memory_size : size of memory in bytes
 * Return: pointer to variable size allocator
 * Errors: if @memory is not aligned, retuen NULL
 * Note: in DEBUG version, @memory_size must be greater than 4 * WORD
 * 		 in RELEASE version, @memory_size must be greater than 3 * WORD
 */
vsa_t *VSAInit(void *memory, size_t memory_size);

/*
 * Allocate memory block in variable size allocator
 * @ vsa_pool : variable sized allocator
 * @ bytes_to_alloc : num of bytes to allocate
 * Return: pointer to allocated memory
 * Errors: if bytes_to_alloc is larger than largest free chunk in vsa, 
 *		   returns NULL
 */
void *VSAAlloc(vsa_t *vsa_pool, size_t bytes_to_alloc);

/*
 * Free block starting in <adress_to_free> from variable size allocator
 * @address_to_free : allocated memory block that returns from Alloc
 * Return: none
 * Errors: if @address_to_free wasn't returned from Alloc, 
 * 		   behaviour is undefined
 */
void VSAFree(void *address_to_free);

/*
 * Find the largest continuous chunk of free memory
 * @vas_pool : vsa to count
 * Return: Size in bytes of the largest continuous chunk of free memory
 * Errors: none
 */
size_t VSALargestChunk(vsa_t *vsa_pool);

#endif /* __OL71_VSA_H */
