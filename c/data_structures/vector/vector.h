#ifndef __OL71_VECTOR_H
#define __OL71_VECTOR_H

#include <stddef.h> /* size_t */

typedef struct vector vector_t;

enum {
    VECTOR_SUCCESS,
    VECTOR_ALLOCATION_FAILED
};

/* 
 * Create a Vector
 * Param init_capacity: initial capacity of vector
 * Param size_of_element: size of element 
 * Return : A pointer to the created vector 
 * Errors: Returns NULL if vector creation failed
 */
vector_t *VectorCreate(size_t init_capacity, size_t size_of_element);

/* 
 * Destroy the Vector
 * Param vector: pointer to vector 
 * Return: None
 * Errors: None
 */
void VectorDestroy(vector_t *vector);

/* 
 * Get the address of the value in a given element of the vector
 * Param vector: pointer to vector
 * Param element_index: index of element in array
 * Return : A pointer to the value of the element in the given index
 * Errors: if element_index is lager than size, behaviour is undefined
 */
void *VectorGetItemAddress(const vector_t *vector, size_t element_index);

/* 
 * Push element to the back of the vector
 * Param vector: pointer to vector 
 * Param element_value: const pointer to element value
 * Return : VECTOR_SUCCESS, non-zero otherwise.
 * Errors: if memory allocation failed - return VECTOR_ALLOCATION_FAILED
 */
int VectorPushBack(vector_t *vector, const void *element_value);

/* 
 * Remove last element
 * if new size is quarter of capacity decrease capacity by half
 * Param vector: pointer to vector 
 * Return : VECTOR_SUCCESS, non-zero otherwise
 * Errors : If vector points to unreadable address or if vector is empty,
 *			behavior is undefined.
 *			If allocation failed - return VECTOR_ALLOCATION_FAILED
 * 			
 */
int VectorPopBack(vector_t *vector);

/* 
 * Check the vector size
 * Param vector: pointer to vector 
 * Return : number of elements in the vector
 * Errors: If vector points to unreadable address, behavior is undefined
 */
size_t VectorSize(const vector_t *vector);

/* 
 * Check if vector is empty
 * Param vector: pointer to vector 
 * Return : 1 if vector is empty. 0 otherwise
 * Errors: If vector points to unreadable address, behavior is undefined
 */
int VectorIsEmpty(const vector_t *vector);

/* 
 * Get the vector capacity
 * Param vector: pointer to vector 
 * Return : current capacity of vector 
 * Errors: none
 */
size_t VectorCapacity(const vector_t *vector);

/* 
 * Request additional memory for vector
 * Param vector: pointer to vector
 * Param size: number of elements to increase capacity by
 * Return : 0 if success, 1 if allocation failed
 * Errors: if memory allocation failed - return VECTOR_ALLOCATION_FAILED
 */
int VectorReserve(vector_t *vector, size_t size);

#endif /* __OL71_VECTOR */
