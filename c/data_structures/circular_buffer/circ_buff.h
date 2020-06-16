#ifndef __OL71_BUFFER_H
#define __OL71_BUFFER_H

#include <stddef.h> /* size_t */

typedef struct buffer circ_buff_t;

/*
 * Create a buffer.
 * Param init_capacity: capacity of the new buffer to create.
 * Return: pointer to the created buffer.
 * Errors: if buffer creation is failed returns NULL.
 *         Behavior is undefined if initialization capacity is 0.
 */
circ_buff_t *CircBuffCreate(size_t init_capacity);

/*
 * Destroy the buffer.
 * Param circ_buff: pointer to the buffer.
 */
void CircBuffDestroy(circ_buff_t *circ_buff);

/*
 * Write to the buffer.
 * Param circ_buff: pointer to the buffer to write.
 * Param src: pointer to the source to read.
 * Param count: number of bytes to write. If count is 0,
 *              function does nothing and 0 returned.
 * Return: on success, the number of bytes written is returned. 
 *         It is not an error if this number is smaller than the
 *         number of bytes requested. This may happen for example because
 *         the  buffer is full.
 * Errors: behavior is undefined if count is more than source capacity.
 */
size_t CircBuffWrite(circ_buff_t *circ_buff, const void *src, size_t count);

/*
 * Read from the buffer.
 * Param circ_buff: pointer to the buffer to read.
 * Param dest: pointer to the destination to write.
 * Param count: number of bytes to read. If count is 0,
 *              function does nothing and 0 returned.
 * Return: on success, the number of bytes read is returned.
 *         It is not an error if this number is smaller than the
 *         number of bytes requested. This may  happen  for example because
 *         fewer bytes are actually available right now.
 * Errors: behavior is undefined if destination has not enough memory to write.
 */
size_t CircBuffRead(circ_buff_t *circ_buff, void *dest, size_t count);

/*
 * Check if buffer is empty.
 * Param circ_buff: pointer to the buffer.
 * Return: if buffer is empty 1, else 0.
 * Errors: behavior is undefined if buffer points to unreadable address.
 */
int CircBuffIsEmpty(const circ_buff_t *circ_buff);

/*
 * Get buffer maximum capacity.
 * Param circ_buff: pointer to the buffer.
 * Return: maximum capacity of the buffer.
 * Errors: behavior is undefined if buffer points to unreadable address.
 */
size_t CircBuffCapacity(const circ_buff_t *circ_buff);

/*
 * Get current size of free space of the buffer.
 * Param circ_buff: pointer to the buffer.
 * Return: size of current free space of the buffer.
 * Errors: behavior is undefined if buffer points to unreadable address.
 */
size_t CircBuffFreeSpace(const circ_buff_t *circ_buff);

#endif /* __OL71_BUFFER_H */

