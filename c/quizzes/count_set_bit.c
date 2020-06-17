#include <stdlib.h>
#include <assert.h>

size_t CountSetBits(int num)
{
	size_t counter = 0;
	
	while (0 < num)
	{
		num = (num & (num -1));
		++counter;
	}

	return counter;
}


int main()
{
	assert(2 == CountSetBits(12));
	assert(1 == CountSetBits(8));
	assert(1 == CountSetBits(4));
	assert(2 == CountSetBits(5));
	assert(2 == CountSetBits(6));
	assert(3 == CountSetBits(7));

	return 0;
}
