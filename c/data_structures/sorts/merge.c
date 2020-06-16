#include <assert.h> /* assert */
#include <stdio.h> /* FIXME */
#include <stdlib.h> /* malloc, free */
#include <string.h> /* memcpy */


void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

enum{SUCCESS, FAIL};

typedef int (*is_before_t)(int a, int b);

int is_before(int a, int b)
{
	return (a > b);
}


static int RecMerge(int *arr,
					size_t left_index,
					size_t right_index,
					is_before_t is_before);

static int FinalMerge(int *arr,
					  size_t left_index,
					  size_t middle_index,
				      size_t right_index,
				      is_before_t is_before);
				       
	       
/******************************* -- MAIN PART -- ******************************/
int Merge(int *arr, size_t size, is_before_t is_before)
{
	size_t left_index = 0;
	size_t right_index = size - 1;
	
	assert(NULL != arr);
	assert(NULL != is_before);
	
	RecMerge(arr, left_index, right_index, is_before);
	
	return SUCCESS;
}


static int RecMerge(int *arr,
					size_t left_index,
					size_t right_index,
					is_before_t is_before) 
{ 
   	int status = 0;

    if (left_index < right_index )
    { 
        size_t middle_index = left_index + (right_index - left_index) / 2; 
  
        RecMerge(arr, left_index, middle_index, is_before); /* Sort left half */
        RecMerge(arr, middle_index + 1, right_index, is_before); /* Sort right half */
  
		status = FinalMerge(arr, left_index, middle_index, right_index, is_before); 
    }
    
    return status;
} 


static int FinalMerge(int *arr,
					   size_t left_index,
					   size_t middle_index,
				       size_t right_index,
				       is_before_t is_before)
{
	size_t i = 0, j = 0, k = left_index;
	size_t length_left = middle_index - left_index + 1;
	size_t length_right = right_index - middle_index;
	
	int *buff = (int *)malloc(sizeof(int) * (length_left + length_right));
	if (NULL == buff)
	{
		return FAIL;
	}
	
	memcpy(buff, arr, (length_left + length_right));
	
	for (i = left_index, j = 0, k = length_left
		; j < length_left && k < right_index
		; ++i)
	{
		if (is_before(buff[j], buff[k]))
		{
			arr[i] = buff[j++];
		}
		else
		{
			arr[i] = buff[k++];
		}
	}
	
	while (j < length_left)
	{
		arr[i++] = buff[j++];
	}
	
	while (k < right_index)
	{
		arr[i++] = buff[k++];
	}
	
	free(buff); buff = NULL;

	return SUCCESS;
}


int main()
{
    int arr[] = {7, 6, 5}; 
  
    printf("Given array is \n"); 
    printArray(arr, 3); 

    Merge(arr, 3, is_before); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, 3); 
    return 0; 
}

