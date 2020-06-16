/**************************
 *   Author   : Adi       *
 *   Reviewer : Shieber   *
 *	 Status   : Sent      *
 **************************/

#include <assert.h> /* assert */
#include <limits.h> /* CHAR_BIT : in MACRO */
#include "bit_array.h"

#define BITTARRAY_T_BIT sizeof(bitarray_t)*CHAR_BIT

/**********************************************************************************
 *							 *************************							  *
 *							 * INFORMATION FUNCTIONS *							  *
 *							 *************************							  *
 **********************************************************************************/ 

/************************ -- IS BIT SET -- ***********************/
int BitArrIsBitSet(bitarray_t bit_array, size_t bit_index)
{
	bitarray_t mask = 1;
	
	mask <<= bit_index;
	
	return (mask&bit_array) >> bit_index;
}

/********************** -- COUNT ON BITS -- *********************/
size_t BitArrCountOnBits(bitarray_t bit_array)
{
	size_t i = 0;
	size_t counter = 0;
	bitarray_t mask = 1;
	
	for(i = 0; i < BITTARRAY_T_BIT; ++i)
	{
		if(0 != (mask & bit_array))
		{
			++counter;
		}
		
		mask <<= 1;
	}
	
	return counter;
}

/******************** -- COUNT OFF BITS -- ***********************/
size_t BitArrCountOffBits(bitarray_t bit_array)
{
	return (BITTARRAY_T_BIT - BitArrCountOnBits(bit_array));
}

/******************* -- BIT TO STR -- ****************************/
char *BitArrBitToStr(bitarray_t bit_array, char *str)
{
	bitarray_t mask = 1;
	size_t i = BITTARRAY_T_BIT;

	assert(NULL != str);
		
	str[i] = '\0';
	
	while(i--)
	{
		bitarray_t tmp = mask & bit_array;
		
		str[i] = 0 != tmp ? '1' : '0'; 
		
		mask <<= 1;
	}
	
	return str;
}

/**********************************************************************************
 *							 ************************* 							  *
 *							 *  OPERATION FUNCTIONS  *							  *
 *							 *************************							  *
 **********************************************************************************/

 
/********************* -- SET BIT ON -- ****************************/
bitarray_t BitArrSetBitOn(bitarray_t bit_array, size_t bit_index)
{
	bitarray_t mask = 1;
	
	mask <<= bit_index;
	
	return (bit_array | mask);
}
 
/********************** -- SET BIT OFF -- ***************************/
bitarray_t BitArrSetBitOff(bitarray_t bit_array, size_t bit_index)
{ 
 	bitarray_t mask = 1;
	
	mask <<= bit_index;
	
	return (bit_array & ~mask);
}
 

/********************** -- SET BIT BY VALUE -- **********************/

bitarray_t BitArrSetBit(bitarray_t bit_array, size_t bit_index, int value)
{
	bitarray_t mask = (bitarray_t)1 << bit_index;
	
	if(0 == value)
	{
		return (bit_array & ~mask); /* turn off the specific bit */
	}
	else
	{
		return (bit_array | mask); /* turn on the specific bit */
	}
}
 
/*********************** -- FLIP SINGLE BIT -- **********************/
bitarray_t BitArrFlipBit(bitarray_t bit_array, size_t bit_index)
{
	bitarray_t mask = (bitarray_t)1 << bit_index;
	
	return (bit_array ^ mask);
}

/********************** -- FLIP ALL BITS -- *************************/
bitarray_t BitArrFlipAllBits(bitarray_t bit_array)
{
	return ~bit_array;
}

/********************** -- SET ALL BITS ON -- ***********************/
bitarray_t BitArrSetAllBitsOn(bitarray_t bit_array)
{
	return(bit_array = 0xFFFFFFFFFFFFFFFFlu);
}

/*********************** -- SET ALL BITS OFF -- *********************/
bitarray_t BitArrSetAllBitsOff(bitarray_t bit_array)
{
	return(bit_array = 0);
}

/*********************** -- SWAP ALL BITS -- ************************/
bitarray_t BitArrSwapBits(bitarray_t bit_array, size_t bit_index1, size_t bit_index2)
{
	bitarray_t mask = 1; 
	
	/* place index1 at rightest bit_a
     * and index2 at rightest bit_b   */
	bitarray_t bit_a = ((bit_array >> bit_index1) & mask);
	bitarray_t bit_b = ((bit_array >> bit_index2) & mask);
	
	/* turning off index1 and index2 in original bit_array */
	bit_array = BitArrSetBitOff(bit_array,bit_index1);
	bit_array = BitArrSetBitOff(bit_array,bit_index2);
	
	/* place index1 where index2 was
     * and index2 where index 1 was */
	bit_array |= (bit_a << bit_index2); 
	bit_array |= (bit_b << bit_index1);
	
	return bit_array;
}

/*********************** -- ROTATE RIGHT -- **************************/
bitarray_t BitArrRotateBitsRight(bitarray_t bit_array, size_t rotate_by)
{
	bitarray_t mask = 1;
	size_t put_1 = 0x8000000000000000lu;
	
	while(rotate_by--)
	{	
		bitarray_t tmp = (bit_array & mask);
	
		bit_array >>= 1;
		
		if (0 != tmp)
		{
			bit_array |= put_1; 	
		}
	}
	
	return bit_array;
}

/************************* -- ROTATE LEFT -- **************************/
bitarray_t BitArrRotateBitsLeft(bitarray_t bit_array, size_t rotate_by)
{
	bitarray_t mask = 0x8000000000000000lu;
	size_t put_1 = 1;
	
	while(rotate_by--)
	{	
		bitarray_t tmp = (bit_array & mask);
	
		bit_array <<= 1;
		
		if (0 != tmp)
		{
			bit_array |= put_1; 	
		}
	}
	
	return bit_array;
}

/************************* -- BIT MIRROR -- **************************/
bitarray_t BitArrBitMirror(bitarray_t bit_array)
{
	bitarray_t mask = 1;
	bitarray_t mirror = 0;
	size_t i = 64;
	
 /* shift left mirror 
 	place rightest bit of givven number
	into mirror
	shift right given number  */ 
    while(i--)
    {
		mirror <<= 1;
		
		if(0 != mask & bit_array)
		{
			mirror |= mask;
		}
		
		bit_array >>= 1;
    }
    
    return mirror;
}

/*********************** -- BIT MIRROR LUT -- ************************/
bitarray_t BitArrBitMirrorLUT(bitarray_t bit_array)
{
bitarray_t mask = 0XFF;  /* point to the first byte */
bitarray_t mirror = 0;
size_t current_byte = 0;

/* loop 8 times for 8 bytes
  place in mirror the mirroring of current_byte
  shift mirror left
  shift bit_array right for scanning the next byte */  
for(current_byte = 0; current_byte < __CHAR_BIT__; ++current_byte)
{
mirror <<= __CHAR_BIT__;
mirror += BYTE_MIRROR_LUT[mask & bit_array];
bit_array >>= __CHAR_BIT__;
}

return mirror;
}

/******************** -- COUNT ON BITS LUT -- *******************/
size_t BitArrCountOnBitsLUT(bitarray_t bit_array)
{
bitarray_t tmp_first_byte = 0;
bitarray_t mask = 0XFF; /* point to the first byte */
size_t  counter = 0;
size_t current_byte = 0;

for(current_byte = 0; current_byte < __CHAR_BIT__; ++current_byte)
{
tmp_first_byte = mask & bit_array;
counter += COUNT_SET_BITS_LUT[(tmp_first_byte)];
bit_array >>= __CHAR_BIT__;
}

return counter;
}

/******************** -- COUNT OFF BITS LUT -- *******************/
size_t BitArrCountOffBitsLUT(bitarray_t bit_array)
{
return (BITTARRAY_T_BIT - BitArrCountOnBitsLUT(bit_array));
}
