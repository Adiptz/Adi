#include <stdio.h>
#include <string.h>


/* assuming array contain at least one positive element - include 0*/
int MaxSubArray(int arr[], size_t arr_length, int *start_index, int *end_index)
{
	
	int sum = arr[0];
	int current_sum = 0;
	size_t current_start = 0;
	size_t current_end = 0;
	
	
	for (current_end = 0; current_end < arr_length; ++current_end) 
	{
		current_sum += arr[current_end];

		if (current_sum > sum)
		{
			sum = current_sum;
			*start_index = current_start;
			*end_index = current_end;
		}

		if (current_sum < 0)
		{
			++current_end;
			current_start = current_end;
			current_sum = arr[current_start];	
		}

	}	
	
	return sum;
}

int main()
{
	int arr1[] = {-2,1,-3,4,-1,9,-20,-5,3};
	int arr2[] = {-2, -1, -3, 1, -3, 1, 1, 1, 1};
    int arr3[] = {8,-5,-10,2,-1,-5};
    int arr4[] = {-2, 1, -3, 4, -1, 2, 3, -5, 4};
    int arr5[] = {-2, 1, -3, 4, -1, 9, -20, -5, 3};
    
	int start_index = 0;
	int end_index = 0;
	
	printf("max sub %d\n", MaxSubArray(arr1,9, &start_index, &end_index));
	printf("start %d end %d\n", start_index, end_index);

	printf("max sub %d\n", MaxSubArray(arr2,9, &start_index, &end_index));
	printf("start %d end %d\n", start_index, end_index);

	printf("max sub %d\n", MaxSubArray(arr3,6, &start_index, &end_index));
	printf("start %d end %d\n", start_index, end_index);
	
	printf("max sub %d\n", MaxSubArray(arr4,9, &start_index, &end_index));
	printf("start %d end %d\n", start_index, end_index);
	
	printf("max sub %d\n", MaxSubArray(arr5,9, &start_index, &end_index));
	printf("start %d end %d\n", start_index, end_index);
	return 0;
}
