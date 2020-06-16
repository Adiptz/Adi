#include <assert.h> /* assert */
#include <stdlib.h> /* malloc, free */
#include "circ_buff.h"

struct buffer
{
	size_t tail;
	size_t head;
	size_t capacity;
	char buf[1];
};

/******************************** -- CREATE -- ********************************/
circ_buff_t *CircBuffCreate(size_t init_capacity)
{	
	circ_buff_t *buffer = NULL;
	size_t capacity = init_capacity;
	
	assert (0!= init_capacity);
	
	/* use the appending byte created by cheat buf[1] */
	if (init_capacity >= 8)
	{
		capacity = init_capacity - 8;
	}
	
	buffer = (circ_buff_t *)malloc(sizeof(circ_buff_t) + capacity);	
	
	if(NULL == buffer)
	{
		return NULL;
	}
	
	buffer->capacity = init_capacity;
	buffer->tail = 0;
	buffer->head = 0;
	 
	return buffer;	
}

/******************************** -- DESTROY -- *******************************/
void CircBuffDestroy(circ_buff_t *circ_buff)   /* O(1) */
{
	assert (NULL != circ_buff);
	
	free(circ_buff); circ_buff = NULL;
}

/******************************** -- WRITE -- *********************************/
size_t CircBuffWrite(circ_buff_t *circ_buff, const void *src, size_t count)
{
	size_t i = 0; /* i represent written bytes */

	assert(NULL != circ_buff);
	assert(NULL != src);

	/* Writing to circ_buff from src count bytes -
	   as long as there's enough free space            */
	while(i < count && 0 != CircBuffFreeSpace(circ_buff))
	{
		size_t tmp_head = circ_buff->head % circ_buff->capacity;

		circ_buff->buf[tmp_head] = *((char *)src + i);

    	++circ_buff->head;
    	
    	++i;
	}

	return i;
}

/******************************** -- READ -- **********************************/
 
size_t CircBuffRead(circ_buff_t *circ_buff, void *dest, size_t count)
{
	size_t i = 0; /* i represent read bytes */

	assert(NULL != circ_buff);
	assert(NULL != dest);

	/* Read from circ_buff to dest count bytes -  
	   as long as the buffer is not empty    	  */
	while(i < count && 1 != CircBuffIsEmpty(circ_buff))
	{
		size_t tmp_tail = circ_buff->tail % circ_buff->capacity;
	
		*((char *)dest + i) = circ_buff->buf[tmp_tail] ;

    	++circ_buff->tail;
    	
    	++i;
	}

	return i;
}	
	
/******************************* -- IS EMPTY -- *******************************/
int CircBuffIsEmpty(const circ_buff_t *circ_buff) /* O(1) */
{
	assert(NULL != circ_buff);
	
	return (circ_buff->head == circ_buff->tail); 
}

/******************************* -- CAPACITY -- *******************************/
size_t CircBuffCapacity(const circ_buff_t *circ_buff)   /* O(1) */
{
	assert(NULL != circ_buff);
	
	return (circ_buff->capacity);
}

/********************************* -- FREE -- **********************************/
size_t CircBuffFreeSpace(const circ_buff_t *circ_buff)   /* O(1) */
{
	assert(NULL != circ_buff);
	
	return (circ_buff->capacity - (circ_buff->head - circ_buff->tail));
}	

