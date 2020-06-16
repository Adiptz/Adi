#include <assert.h> /*assert*/
#include <string.h> /*memcpy*/
#include <stdlib.h> /*malloc, realloc, free*/
#include "vector.h" /*vector function*/

const int CAPACITY_SIZE_TO_DECREASE = 4; /*if new size is quarter of capacity*/
const int DECREASE_CAPACITY = 2; /*decrease capacity by half*/

/************************************
*	ex : data structures vector		*
*	author: Daya					*
*	reviewer: Maya 					*
*	revision : 1					*
*	status : A						*
*************************************/

struct vector
{
	void *base;
	void *current;
	size_t capacity;
	size_t size;
	size_t size_of_element;
};

/*****************************		Create		*******************************/
vector_t *VectorCreate(size_t init_capacity, size_t size_of_element)
{
	vector_t *vector = 0;
	
	assert(0 != init_capacity); /*UB*/
	assert(0 != size_of_element); /*UB*/
	
	/*allocation for struct*/
	vector = (vector_t *)malloc(sizeof(vector_t));
	if (NULL == vector)
	{
		return NULL;
	}
	
	/*allocation for vector*/
	vector->base = (void *)malloc(init_capacity * size_of_element);
	if (NULL == vector->base)
	{
		free(vector); vector = NULL;
		return NULL;
	}
	
	/*init struct*/
	vector->current = vector->base;
	vector->capacity = init_capacity;
	vector->size = 0;
	vector->size_of_element = size_of_element;
	
	return vector;
}

/*****************************		Destroy		*******************************/
void VectorDestroy(vector_t *vector)
{
	assert(NULL != vector);
	
	free(vector->base); vector->base = NULL;
	free(vector); vector = NULL;
}

/**************************		GetItemAddress		***************************/
void *VectorGetItemAddress(const vector_t *vector, size_t element_index)
{
	size_t index = 0;
	
	assert(NULL != vector); /*UB*/
	assert(element_index < vector->size); /*UB*/
	
	index = element_index * vector->size_of_element;
	
	return (char*)vector->base + index;;
}

/***************************		PushBack		***************************/
int VectorPushBack(vector_t *vector, const void *element_value)
{
	int realloc_success = 0;
	
	assert(NULL != vector); /*UB*/
	assert(NULL != element_value); /*UB*/
	
	if (vector->size == vector->capacity)
	{
		realloc_success = VectorReserve(vector, vector->capacity);
		if (realloc_success == VECTOR_ALLOCATION_FAILED) /*realloc faild*/
		{
			return VECTOR_ALLOCATION_FAILED;
		}
	}
		
	memcpy(vector->current, element_value, vector->size_of_element);
	vector->current = (char*)vector->current + vector->size_of_element;	
	++vector->size;
	
	return VECTOR_SUCCESS;
}



/*****************************		PopBack		*******************************/
int VectorPopBack(vector_t *vector)
{	
	assert(NULL != vector); /*UB*/
	assert(1 != VectorIsEmpty(vector)); /*UB*/
		
	vector->current = (char*)vector->current - vector->size_of_element;
	--vector->size;
	
	/*if new size is quarter of capacity decrease capacity by half*/
	if (vector->size <= (vector->capacity / CAPACITY_SIZE_TO_DECREASE))
	{
		void *new_base = 0;
	
		/*new memory place for vector*/
		new_base = (void *)realloc(vector->base, 
					(vector->capacity / DECREASE_CAPACITY) * 
					vector->size_of_element);
		if (NULL == new_base)
		{
			return VECTOR_ALLOCATION_FAILED;
		}
		
		/*updating struct after new allocation*/
		vector->base = new_base;
		vector->current = (char *)vector->base + 
						  (vector->size * vector->size_of_element);
		vector->capacity /= DECREASE_CAPACITY;	
	}
	
	return VECTOR_SUCCESS;
}

/*****************************		Size		*******************************/
size_t VectorSize(const vector_t *vector)
{	
	assert(NULL != vector); /*UB*/
	
	return vector->size;
}

/*****************************		IsEmpty		*******************************/
int VectorIsEmpty(const vector_t *vector)
{
	assert(NULL != vector); /*UB*/
	
	return (0 == vector->size);
}

/***************************		Capacity		***************************/
size_t VectorCapacity(const vector_t *vector)
{
	assert(NULL != vector); /*UB*/
	
	return vector->capacity;
}

/***************************		Reserve		*******************************/
int VectorReserve(vector_t *vector, size_t size)
{	
	void *new_base = 0;
	
	assert(NULL != vector); /*UB*/
	
	/*new memory place for vector*/
	new_base = (void *)realloc(vector->base, 
				(vector->capacity + size) * vector->size_of_element);
	if (NULL == new_base)
	{
		return VECTOR_ALLOCATION_FAILED;
	}
	
	/*updating struct after new allocation*/
	vector->base = new_base;	
	vector->current = (char *)vector->base + 
					  (vector->size * vector->size_of_element);
	vector->capacity += size;
	
	return VECTOR_SUCCESS;
}
