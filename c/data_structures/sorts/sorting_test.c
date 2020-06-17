#include <stdio.h>

#include "sorting.h"


int CmpInts(const void *data1, const void *data2)
{
	return *(int *)data1 - *(int *)data2;
}


void PrintArray(int *arr, size_t size)
{
	size_t i;
	for(i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
}

void Bubble_test()
{
	int arr[] = {2, 3, 1, 4, 5};
	size_t size = 5;
	
	Bubble(arr, size);
	
	PrintArray(arr, size);
	
	puts("");
}

void Selection_test()
{
	int arr[] = {1, 2, 3, 4, 5};
	size_t size = 5;
	
	Selection(arr, size);
	
	PrintArray(arr, size);
	
	puts("");
}

void Insertion_test()
{
	int arr[] = {3, 5, 2, 7, 1, 5};
	size_t size = 6;
	
	Insertion(arr, size);
	
	PrintArray(arr, size);
	
	puts("");
}

void Counting_test()
{
	int arr[] = { 1, -9, 1 , 4, 7 , 9 , 1, 0};
	size_t size = 8;
	
	Counting(arr, size, -9, 9);
	
	PrintArray(arr, size);
	
	puts("");
}

void Radix_test()
{
	int arr[] = {2,1,3,6,5,6};
	size_t size = 6;
	
	Radix(arr, size, 2);
	
	PrintArray(arr, size);
	
	puts("");
}

void Quick_test()
{
	int arr[] = {2,1,3,6,5,4};
	
	size_t element_size_in_bytes = 4;
	size_t num_of_elements = 6;
	
	Quick(arr, element_size_in_bytes, num_of_elements, CmpInts);
	
	PrintArray(arr, num_of_elements);

	puts("");
}

int main()
{
	Bubble_test();
	Selection_test();
	Insertion_test();
	Counting_test();
	Radix_test();
	Quick_test();
	
	return 0;
}
