#ifndef __OL71_BIT_ARRAY_64_H
#define __OL71_BIT_ARRAY_64_H

#include <stddef.h> /*size_t*/
typedef size_t bitarray_t; 

/********************************
 * INFORMATION FUNCTIONS        *
 ********************************/
/* 
 * Check if bit_index is on (1) in a given bit_array
 * Param bit_array: the bit array
 * Param bit_index: the bit to check.
 * The bit_index value must be 0 <= bit_index < 64
 * Returns: if specific bit is set return 1, else return 0
 * Errors: if bit_index is not valid, behavior is undefined
 */
int BitArrIsBitSet(bitarray_t bit_array, size_t bit_index);

/* 
 * Counts on bits in a bit array
 * Param bit_array: the bit array
 * Returns: number of on bits
 * Errors: none
 */
size_t BitArrCountOnBits(bitarray_t bit_array);

/*
 * Counts off (0) bits in bit array
 * Param bit_array: the bit array
 * Returns: number of off bits
 * Errors: none
*/
size_t BitArrCountOffBits(bitarray_t bit_array);

/*
 * Creates string representation of bit_array
 * Param bit_array: the bit array
 * Param char *str: destination string from user (must be large enough to
 * receive string representation of bit_array)
 * Returns: functions return a pointer to the destination string str
 * Errors: if str not large enough or NULL, behavior is undefined
 */
char *BitArrBitToStr(bitarray_t bit_array, char *str);

/************************
 * OPERATION FUNCTIONS    *
 ************************/

/*
 * sets <bit_index> bit in bit_array to 1
 * Param bit_array: the bit array
 * Param bit_index: index of bit to set on (1)
 * bit_index must be 0 <= bit_index < 64
 * Returns: modified bit_array
 * Errors: if bit index is not 0 <= bit_index < 64, behavior is undefined
 */
bitarray_t BitArrSetBitOn(bitarray_t bit_array, size_t bit_index);

/*
 * sets <bit_index> bit in bit_array to 0
 * Param bit_array: the bit array
 * Param bit_index: index of bit to set off (0)
 * bit_index must be in 0 <= bit_index < 64
 * Returns bit_array
 * Error: if index out of range, behavior is undefined
 */
bitarray_t BitArrSetBitOff(bitarray_t bit_array, size_t bit_index);

/*
 * set <bit_index> bit in <bit_array> to <value> (1 or 0)
 * param bit_array: the bit array
 * param bit_index: index of bit to change 
 * (must be in range 0 <= bit_index < 64)
 * param value: value to change to, must be boolean
 * Returns: modified bit_array
 * Errors: if bit_index is out of range, behavior is undefined
 * if value is not boolean, behavior is undefined
 */
bitarray_t BitArrSetBit(bitarray_t bit_array, size_t bit_index, int value);

/*
 * flips value of a specific bit in the bit array. 
 * param bit_array: the bit array
 * param bit_index: index of bit to flip (must be in range 0 <= bit_index < 64)
 * returns: the modified bit array
 * errors: if bit_index is not in range, behavior is undefined 
 */ 
bitarray_t BitArrFlipBit(bitarray_t bit_array, size_t bit_index);

/* 
 * flips the values of all the  bits in the bit array. 
 * Param bit_array: the bit array
 * Returns: the array with flipped bits.
 * Errors: none
 */
bitarray_t BitArrFlipAllBits(bitarray_t bit_array);

/*
 * sets all bits on
 * Param bit_array: the bit array
 * Returns: the array with all bits set on
 * Errors: none
 */
bitarray_t BitArrSetAllBitsOn(bitarray_t bit_array);

/* 
 * sets all bits off
 * Param bit_array: the bit array
 * Returns: the array with all bits off
 * Errors: none
 */
bitarray_t BitArrSetAllBitsOff(bitarray_t bit_array); 

/* 
 * swap value of two specific bits 
 * param bit_array: the bit array
 * param bit_index1: index of first bit (must be in range 0 <= bit_index < 64)
 * param bit_index2: index of second bit (must be in range 0 <= bit_index < 64)
 * return: the modified bit array
 * error: if bit indexes are identical or not in range, behavior is undefined.
*/
bitarray_t BitArrSwapBits(bitarray_t bit_array, size_t bit_index1, size_t bit_index2);

/* 
 * rotate bit_array right <rotate_by> times 
 * Param bit_array: the bit array
 * Param rotate_by: number to rotate by
 * Returns: rotated bit_array
 * Errors: none 
 */
bitarray_t BitArrRotateBitsRight(bitarray_t bit_array, size_t rotate_by);

/*
 * rotate bit_array left <rotate_by> times 
 * Param bit_array: the bit array
 * Param rotate_by: number to rotate by
 * Returns: rotated bit_array
 * Errors: none
 */
bitarray_t BitArrRotateBitsLeft(bitarray_t bit_array, size_t rotate_by);

/*
 * reverses the order of the bits
 * Param bit_array: the bit array
 * Returns: mirrored bit_array (end to start)
 * Errors: none
 */
bitarray_t BitArrBitMirror(bitarray_t bit_array);

#endif /* __OL71_BIT_ARRAY_64_H */


