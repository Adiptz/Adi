#include <stdio.h>
#include "bit_array.h"

/**************************
 *    Author  : Adi       *
 *    Reviwer : Shieber   *
 *    Status  :  Sent     *
 **************************/

/********************************* -- IS BIT SET -- **********************************/
void IsBitSet_Test()
{
	size_t bit_array = 1;
	size_t bit_index = 0;
	
	puts("Is Bit Set\n");
	
	/* Check 1 */
	if(1 != BitArrIsBitSet(bit_array, bit_index))
	{
		printf("BitArrIsBitSet\nERROR WHEN :\nbit_array %lu\nbit_index %lu\n", bit_array,bit_index);
	}	
	
	for(bit_index = 1; bit_index < 64; ++bit_index)
	{
		if(0 != BitArrIsBitSet(bit_array, bit_index))
		{
		   printf("BitArrIsBitSet\nERROR WHEN :\nbit_array %lu\nbit_index %lu\n", bit_array, bit_index);
		}
	}
	
	/* Check 15 */
	bit_array = 15;
	bit_index = 0;
	
	for(bit_index = 0; bit_index < 4; ++bit_index)
	{
		if(1 != BitArrIsBitSet(bit_array, bit_index))
		{
			printf("ERROR WHEN :\nbit_array %lu\nbit_index %lu", bit_array, bit_index);
		}	
	}
	
	for(bit_index = 4; bit_index < 64; ++bit_index)
	{
		if(0 != BitArrIsBitSet(bit_array, bit_index))
		{
			printf("ERROR WHEN :\nbit_array %lu\nbit_index %lu", bit_array, bit_index);
		}	
	}	
}


/********************************* -- Count Bits ON -- **********************************/

void CountOnBits_test()
{
	puts("Count On Bits");
	
	if(3 != BitArrCountOnBits(1073750018))
	{
		puts("ERROR WHEN :\nbit_array 1073750018");
	}
	
	if(1 != BitArrCountOnBits(1))
	{
		puts("BitArrCountOnBits\nERROR WHEN :\nbit_array 1");
	}
}


/********************************* -- Count Bits Off -- **********************************/

void CountOffBits_test()
{
	puts("\nCount Off Bits");
	
	if(61 != BitArrCountOffBits(1073750018))
	{
		puts("BitArrCountOffBits\nERROR WHEN :\nbit_array 1073750018");
	}
	
	if(63 != BitArrCountOffBits(1))
	{
		puts("BitArrCountOffBits\nERROR WHEN :\nbit_array 1");
	}
}
/********************************* -- Bit to Str -- **********************************/

void BitArrBitToStr_test()
{
	char str[65];
	char str1[65];
	
	puts("\nBit To Str");
	
	printf("0000000000000000000000000000000000000000000000000000000000001010\n%s\n\n", BitArrBitToStr(10, str));
	printf("0000000100000001000000010000000100000001000000010000000100000001\n%s\n", BitArrBitToStr(72340172838076673, str1));
}


/********************************* -- Set Bit On -- **********************************/

void BitArrSetBitOn_test()
{
	puts("\nSet Bit On\n");
	
	if(1 != BitArrSetBitOn(0 , 0))
	{
		puts("Error : bit_array 0 | bit_index 0");
	}
	
	if(2 != BitArrSetBitOn(0 , 1))
	{
		puts("Error : bit_array 0 | bit_index 0");
	}
	
	if(16 != BitArrSetBitOn(0 , 4))
	{
		puts("Error : bit_array 0 | bit_index 0");
	}
}


/********************************* -- Set Bit On -- **********************************/

void BitArrSetBitOff_test()
{
	puts("Set Bit Off\n");
	
	if(0xFFFFFFFFFFFFFFFElu != BitArrSetBitOff(0xFFFFFFFFFFFFFFFFlu , 0))
	{
		puts("Error : bit_array 0xFFFFFFFFFFFFFFFF | bit_index 0");
	}
	
	if(0xFFFFFFFFFFFFFEFFlu != BitArrSetBitOff(0xFFFFFFFFFFFFFFFFlu, 8))
	{
		puts("Error : bit_array 0xFFFFFFFFFFFFFFFF | bit_index 8");
	}
	
	if(0x7FFFFFFFFFFFFFFFlu != BitArrSetBitOff(0xFFFFFFFFFFFFFFFFlu, 63))
	{
		puts("Error : bit_array 0xFFFFFFFFFFFFFFFF | bit_index 63");
	}
}

/******************************* -- Set Bit By Value -- ********************************/

void BitArrSetBit_test()
{
	puts("Set Bit By Value\n");
	
	if(0xFFFFFFFFFFFFFFFElu != BitArrSetBit(0xFFFFFFFFFFFFFFFFlu, 0 ,0 ))
	{
		puts("Error : bit_array 0xFFFFFFFFFFFFFFFF | bit_index 0 | value 0");
	}
	
	if(16 != BitArrSetBit(0, 4, 1))
	{
		puts("Error : bit_array 0 | bit_index 4 | value 1 ");
	}
}

/******************************** -- Flip Specific Bit -- *********************************/

void BitArrFlipBit_test()
{
	puts("Flip Single Bit\n");
	
	if(0xFFFFFFFFFFFFFFFElu != BitArrFlipBit(0xFFFFFFFFFFFFFFFFlu, 0))
	{
		puts("Error : bit_array 0xFFFFFFFFFFFFFFFF | bit_index 0 ");
	}
} 

/********************************** -- Flip All Bits -- ***********************************/

void BitArrFlipAllBits_test()
{
	puts("Flip All Bits\n");
	
	if(0xFFFFFFFFFFFFFFFFlu != 	BitArrFlipAllBits(0))
	{
		puts("Error : bit_array 0");
	}
	
	if(0 != BitArrFlipAllBits(0xFFFFFFFFFFFFFFFFlu))
	{
		puts("Error : bit_array 0xFFFFFFFFFFFFFFFF");
	}
}


/********************************* -- Flip All Bits ON -- **********************************/

void BitArrSetAllBitsOn_test()
{
	puts("Set All Bits On\n");
	
	if(0xFFFFFFFFFFFFFFFFlu != BitArrSetAllBitsOn(9223372036854775808)) /* binary : 100000.........0 */
	{
		puts ("Error when bit_array is 9223372036854775808");
	}
	
	if(0xFFFFFFFFFFFFFFFFlu != BitArrSetAllBitsOn(0))
	{
		puts ("Error when bit_array is 1");
	}
	
	if(0xFFFFFFFFFFFFFFFFlu != BitArrSetAllBitsOn(726736))
	{
		puts ("Error when bit_array is 726736");
	}

}

/********************************* -- Flip All Bits OFF -- **********************************/

void BitArrSetAllBitsOff_test()
{
	puts("Set All Bits Off\n");
	
	if(0 != BitArrSetAllBitsOff(9223372036854775808)) /* binary : 100000.........0 */
	{
		puts ("Error when bit_array is 9223372036854775808");
	}
	
	if(0 != BitArrSetAllBitsOff(1))
	{
		puts ("Error when bit_array is 1");
	}
	
	if(0 != BitArrSetAllBitsOff(726736))
	{
		puts ("Error when bit_array is 726736");
	}
}

/******************************* -- SWAP BITS -- ********************************/
void BitArrSwapBits_test()
{
	puts("Swap Bits\n");
	
	if(0xFFFFFFFFFFFFFFC8lu != BitArrSwapBits(0xFFFFFFFFFFFFFFD0, 3, 4))
	{
		puts("Error when arguments : (0xFFFFFFFFFFFFFFD0, 3, 4)");
	}
	
	if(7 != BitArrSwapBits(14, 0, 3))
	{
		puts("Error when arguments : (14, 0, 3)");
	}

}

/******************************* -- ROTATE BITS RITGHT -- ********************************/
void BitArrRotateBitsRight_test()
{
	puts("Rotate Bits Right\n");

	if(0x7FFFFFFFFFFFFFFFlu != BitArrRotateBitsRight(0xFFFFFFFFFFFFFFFElu, 1))
	{
		puts("Error when bit_array 0xFFFFFFFFFFFFFFFE | rotate_by = 1");
	}
	
	if(0xFFFFFFFFFFFFFFFFlu != BitArrRotateBitsRight(0xFFFFFFFFFFFFFFFFlu, 0))
	{
		puts("Error when bit_array 0xFFFFFFFFFFFFFFFF | rotate_by = 0");
	}
	
	if(0x1FFFFFFFFFFFFFFFlu != BitArrRotateBitsRight(0xFFFFFFFFFFFFFFF8lu, 3))
	{
		puts("Error when bit_array 0xFFFFFFFFFFFFFFF8lu | rotate_by = 3");
	}
}

/******************************* -- ROTATE BITS RITGHT -- ********************************/
void BitArrRotateBitsLeft_test()
{
	puts("Rotate Bits Left\n");
	
	if(1 !=  BitArrRotateBitsLeft(0x8000000000000000, 1))
	{
		puts("Error when bit_array 0x8000000000000000 | rotate_by 1");
	}
	
	if(16 !=  BitArrRotateBitsLeft(1, 4))
	{
		puts("Error when bit_array 1 | rotate_by 4");
	}
}

/********************************* -- BIT MIRROR -- **********************************/
void BitArrBitMirror_test()
{
	puts("Mirror Bits\n");
	
	if(0xFFFFFFFFFFFFFFF1 !=  BitArrBitMirror(0x8FFFFFFFFFFFFFFF))
	{
		puts("Error when bit_array = 0x8FFFFFFFFFFFFFFF");
	}
}


/************************************ -- MAIN -- *************************************/
int main()
{
	IsBitSet_Test();
	CountOnBits_test();
	CountOffBits_test();
	BitArrBitToStr_test();
	BitArrSetBitOn_test();
	BitArrSetBitOff_test();
	BitArrSetBit_test();
	BitArrFlipBit_test();
	BitArrFlipAllBits_test();
	BitArrSetAllBitsOn_test();
	BitArrSetAllBitsOff_test();
	BitArrSwapBits_test();
	BitArrRotateBitsRight_test();
	BitArrRotateBitsLeft_test();
	BitArrBitMirror_test();
	
	return 0;
}
