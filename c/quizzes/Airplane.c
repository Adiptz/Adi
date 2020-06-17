#include <stdio.h>


int MissingAirplane(int arr[], size_t arr_size)
{
	size_t i = 0;
	int result = 0;
	
	for (i = 0; arr_size > i;  ++i)
	{
		result ^= arr[i];
	}
	
	
	return result;

}

int main()
{
	int arr[] = {1, 4, 4, 1, 6, 5, 2, 2, 5};
	int vova[] = {1, 2, 5, 2, 5};
	
	printf("%d\n", MissingAirplane(arr, 9));
	printf("%d\n", MissingAirplane(vova, 5));
	
	return 0;
	



}
