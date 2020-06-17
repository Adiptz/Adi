#include "memcpy.h"

void BytesCopy6_test();
void BytesCopy12_test();
void NotAlignedSrc();
void LongNotAlignedSrc();

int main()
{
	BytesCopy6_test();
	BytesCopy12_test();
	NotAlignedSrc();
	LongNotAlignedSrc();
	return 0;
}

void BytesCopy6_test()
{
	char *src_6_bytes = "hello";
	char dest[20];
	void *test = NULL;
	
	test = Memcpy(dest, src_6_bytes, 6);
	assert(0 == strcmp(dest, src_6_bytes));
	assert(0 == strcmp((char *)test, src_6_bytes));
}

void BytesCopy12_test()
{
	char *src_12_bytes = "hello world";
	char dest1[14];
	void *test2 = NULL;

	test2 = Memcpy(dest1, src_12_bytes, 12);
	assert(0 == strcmp(dest1, src_12_bytes));
	assert(0 == strcmp((char *)test2, src_12_bytes));
}

void NotAlignedSrc()
{
	char *src_12_bytes = "hello world";
	char dest[14];
	void *test = NULL;

	test = Memcpy(dest + 1 ,src_12_bytes, 12);
	assert(0 == strcmp(dest + 1, src_12_bytes));
	assert(0 == strcmp((char *)test, src_12_bytes));

}

void LongNotAlignedSrc()
{
	char *src_12_bytes = "hello world how are you";
	char dest[30];
	void *test = NULL;

	test = Memcpy(dest + 1 ,src_12_bytes, 24);
	assert(0 == strcmp(dest + 1, src_12_bytes));
	assert(0 == strcmp((char *)test, src_12_bytes));
}
