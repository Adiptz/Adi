#include <stdio.h> /* printf */
#include <assert.h> /* assert */
#include <string.h> /* strcmp */
#include "circ_buff.h"

/******************************* -- TESTS -- *********************/
void CheckWriteRead_test()
{
	circ_buff_t *test = CircBuffCreate(6);
	char src[40] = "abcd";
	char dest[50] = "";
	CircBuffWrite(test, src, 4);
	CircBuffRead(test, dest, 4);
	
	assert(0 == strcmp(dest, src));
	
	CircBuffDestroy(test);
}

void WriteToFullBuffer_test()
{

	circ_buff_t *test = CircBuffCreate(4);
	char src[40] = "abcd";	
	CircBuffWrite(test, src, 4);
	
	assert(0 == CircBuffWrite(test, src, 1));
	
	CircBuffDestroy(test);
}

void ReadFromEmptyBuffer_test()
{
	char dest[50] = "";
	circ_buff_t *test = CircBuffCreate(8);
		
	assert(0 == CircBuffRead(test, dest, 4));
	
	CircBuffDestroy(test);
}

void ReadMoreThanYouCan_test()
{
	circ_buff_t *test = CircBuffCreate(6);
	char src[40] = "abcd";
	char dest[50] = "";
	
	CircBuffWrite(test, src, 4);
	
	assert(4 == CircBuffRead(test, dest, 9));
	
	CircBuffDestroy(test);
}

void WriteInCircle_test()
{
	circ_buff_t *test = CircBuffCreate(10);
	char src[40] = "abcdef";
	char dest[50] = "";
	
	CircBuffWrite(test, src, 5);
	CircBuffRead(test, dest, 5);
	
	assert(10 == CircBuffWrite(test, src, 10));
	
	CircBuffDestroy(test);
}

void IsEmpty_test()
{
	char src[40] = "abcdef";

	circ_buff_t *test = CircBuffCreate(5);
	
	assert(1 == CircBuffIsEmpty(test));
	
	CircBuffWrite(test, src, 5);	
	
	assert(0 == CircBuffIsEmpty(test));
	
	CircBuffDestroy(test);
}

void CircBuffCapacity_test()
{
	circ_buff_t *test = CircBuffCreate(5);
	circ_buff_t *test1 = CircBuffCreate(1);

	assert(5 == CircBuffCapacity(test));	
	assert(1 == CircBuffCapacity(test1));
	
	CircBuffDestroy(test);
	CircBuffDestroy(test1);
}

void CircBuffFreeSpace_test()
{
	circ_buff_t *test = CircBuffCreate(5);	
	char src[40] = "abcdef";

	assert (5 == CircBuffFreeSpace(test));
	
	CircBuffWrite(test, src, 2);
	
	assert (3 == CircBuffFreeSpace(test));
	
	CircBuffWrite(test, src, 2);
	
	assert (1 == CircBuffFreeSpace(test));
	
	CircBuffDestroy(test);	
}


int main()
{ 
	CheckWriteRead_test();
	WriteToFullBuffer_test();
	ReadFromEmptyBuffer_test();
	WriteInCircle_test();
	IsEmpty_test();
	CircBuffCapacity_test();
	CircBuffFreeSpace_test();
		 	
	return 0;
}

