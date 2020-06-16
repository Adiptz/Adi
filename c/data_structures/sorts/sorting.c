/*************************
 * Author   : Adi        *
 * Reviewer : Daniel     *
 * Status   : Approve    *
 *************************/

#include <assert.h> /* assert */
#include <stdlib.h> /* malloc, calloc, free */
#include <string.h> /* memcpy, memset */

#include "sorting.h"

enum {SUCCESS, FAIL};

				
typedef struct quick_data
{
	void *arr_to_sort;
	size_t element_size;
	int(*cmp_func)(const void *data1, const void *data2);
}quick_data_t;

/************************ -- FORWARD DECLERATIONS -- **************************/
static void SwapInts(int *a, int *b);

static void FillHistogram(unsigned int *histogram,
						  int *arr, 
						  size_t arr_size,
						  int shifting);
						  
static void PrefixSumHistogram(unsigned int *histogram, size_t histogram_size);

static void FillSortArr(int *sorted_arr,
						int *arr,
				        unsigned int *histogram,
				        int shifting,
				        size_t arr_size);
				        
static void *FreeAndNull(void *memory_to_free);	  

static void SwapPointers(int **pointer1, int **pointer2);
 
static void FillHistogramRadix(unsigned int *histogram, int *arr,
						       int shifting, int mask,
						       size_t arr_length);
				  
static void FillSortArrRadix(int *sorted_arr,
							 int *arr,
				             unsigned int *histogram,
				             int mask,
				             size_t arr_length,
				             int shifting);

static void CountingSortForRadix(unsigned int *histogram,
								 size_t histogram_length,
								 size_t arr_length,
								 int *arr,
								 int mask,
								 int *sorted_arr,
								 int shifting);
								 
								 
/* Quick Sort */
static void RecQuickSort(quick_data_t *quick_data,
				  		 size_t low_index,
				  		 size_t high_index);
static size_t Partition(quick_data_t *quick_data,
				 size_t low_index,
				 size_t high_index);
static void SwapData(quick_data_t *quick_data, size_t index1, size_t index2);
static void *GetData(quick_data_t *quick_data, size_t index);
/******************************************************************************/

     
/****************************** -- INSERTION -- *******************************/
void Insertion(int *arr, size_t size)
{
	size_t i = 0;
	
	for (i = 1; i < size; ++i)
	{
		if (arr[i] < arr[i - 1])
		{
			int tmp = arr[i];
			size_t j = 0;
			
			for (j = i; j != 0 && tmp < arr[j - 1]; --j)
			{
				arr[j] = arr[j - 1];
			}
			
			arr[j] = tmp;
		}	
	}
}


/****************************** -- SELECTION -- *******************************/
void Selection(int *arr, size_t size)
{
	size_t i = 0;
	
	assert(NULL != arr);
	
	for (i = 0; i < size ; ++i)
	{
		size_t min = i;
		size_t j = 0;
		
		for (j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}		
		}
		
		SwapInts(&arr[i], &arr[min]);	
	}
}

/******************************* -- BUBBLE -- *********************************/
void Bubble(int *arr, size_t size)
{	
	size_t has_change = 1;
	
	assert(NULL != arr);
	
	while(has_change)
	{		
		size_t i = 0;
		size_t last_index_swapped = 0;

		for (i = 0; i < (size - 1); ++i)
		{
						
			if (arr[i] > arr[i + 1])
			{
				SwapInts(&arr[i], &arr[i + 1]);
				last_index_swapped = i + 1;
			}
		}
		
		has_change = last_index_swapped;
	}
}

/******************************* -- COUNTING -- *******************************/
int Counting(int arr[], size_t size, int min, int max)
{
	int shifting = -(min);
	int *sorted_arr = NULL;
	unsigned int *histogram = NULL;
	size_t num_range = (max - min + 1);
	size_t array_size_bytes = size * sizeof(int);
	
	assert(NULL != arr);
	
	histogram = (unsigned int *)calloc(num_range, sizeof(unsigned int));
	if (NULL == histogram)
	{
		return FAIL;
	}
	
	sorted_arr = (int *)malloc(array_size_bytes);
	if (NULL == sorted_arr)
	{
		histogram = FreeAndNull(histogram);
		return FAIL; 
	}
	
	FillHistogram(histogram, arr, size, shifting);
	PrefixSumHistogram(histogram, num_range);
	FillSortArr(sorted_arr, arr, histogram, shifting, size);
	
	memcpy(arr, sorted_arr, array_size_bytes);
	
	histogram = FreeAndNull(histogram);
	sorted_arr = FreeAndNull(sorted_arr);
	
	return SUCCESS;
}		

/******************************** -- RADIX -- *********************************/
int Radix(int arr[], size_t arr_length, unsigned int num_of_bits) 
{ 
	int *sorted_arr = NULL;
	unsigned int *histogram = NULL;
	unsigned int iter = 0;
	int mask = ~((~0) << num_of_bits);
	size_t histogram_length = mask + 1; 
	size_t histogram_size_in_bytes = histogram_length * sizeof(unsigned int);
	const unsigned int BITS_IN_BYTE = 8;
	const unsigned int BITS_IN_INT = sizeof(int) * BITS_IN_BYTE;
	
	assert(NULL != arr);
	assert(0 ==  BITS_IN_INT % num_of_bits); 
	assert(num_of_bits < BITS_IN_INT);
	assert(0 < num_of_bits);
	
	histogram = (unsigned int *)malloc(histogram_size_in_bytes);
	if (NULL == histogram)
	{
		return FAIL;
	}
	
	sorted_arr = (int *)malloc(arr_length * sizeof(int));
	if (NULL == sorted_arr)
	{
		histogram = FreeAndNull(histogram);
		return FAIL; 
	}
		
	for (; 0 != mask; mask <<= num_of_bits, ++iter)
	{		
	    int shifting = iter * num_of_bits;
		
		memset(histogram, 0, histogram_size_in_bytes);
		
		CountingSortForRadix(histogram,
							 histogram_length,
							 arr_length,
							 arr,
							 mask,
							 sorted_arr,
							 shifting);
									
		SwapPointers(&arr, &sorted_arr);		
	} 
	
	histogram = FreeAndNull(histogram);
	sorted_arr = FreeAndNull(sorted_arr);
	
	return SUCCESS;
}


/******************************* -- QUICK -- **********************************/
void Quick(void *arr_to_sort, size_t element_size, size_t num_of_elements,
				int(*cmp_func)(const void *data1, const void *data2))
{
	size_t low_index = 0;
	size_t high_index =  num_of_elements - 1;
	
	quick_data_t quick_data = {NULL};
	
	assert(NULL != arr_to_sort);
	assert(NULL != cmp_func);
	
	quick_data.arr_to_sort = arr_to_sort;
	quick_data.element_size = element_size;
	quick_data.cmp_func = cmp_func;
	
	RecQuickSort(&quick_data, low_index, high_index);
}

static void RecQuickSort(quick_data_t *quick_data,
				  		 size_t low_index,
				  		 size_t high_index)
{
	assert(NULL != quick_data);
	
	if (low_index < high_index)
	{
		size_t pivot = Partition(quick_data, low_index, high_index);

		if (0 < pivot)	
		{				
			RecQuickSort(quick_data, low_index, pivot - 1);
		}
		
		RecQuickSort(quick_data, pivot + 1, high_index);
	}
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
static size_t Partition(quick_data_t *quick_data,
						size_t low_index,
				 		size_t high_index)
{
	void *pivot_data = NULL;
	size_t runner_index = 0;
	
	assert(NULL != quick_data);
	
	pivot_data = GetData(quick_data, high_index);	
	
	for (runner_index = low_index; runner_index < high_index; ++runner_index)
	{
		void *index_data = GetData(quick_data, runner_index);
		
		if (0 > quick_data->cmp_func(index_data, pivot_data))
		{
			SwapData(quick_data, runner_index, low_index);
			++low_index;
		}
	}
	
	SwapData(quick_data, low_index, high_index);
	
	return low_index;

}

static void SwapData(quick_data_t *quick_data, size_t index1, size_t index2)
{
	char temp = 0; 
	char *data1 = NULL;
	char *data2 = NULL;
	size_t index = 0; 
	
	assert(NULL != quick_data);
	
	data1 = (char *)quick_data->arr_to_sort +
										    (index1 * quick_data->element_size);

	data2 = (char *)quick_data->arr_to_sort +
										    (index2 * quick_data->element_size);
	
	for (index = 0; index < quick_data->element_size; ++index)
	{
		temp = data1[index];
		data1[index] = data2[index];
		data2[index] = temp;
	}
}

static void *GetData(quick_data_t *quick_data, size_t index)
{
	assert(NULL != quick_data);
	
	return ((char *)quick_data->arr_to_sort +
											(index * quick_data->element_size)); 
}



/**************************** -- HELP FUNCTIONS -- ****************************/
static void SwapInts(int *a, int *b)
{
	int tmp = 0;
	
	assert(NULL != a);
	assert(NULL != b);
	
	tmp = *a; 
	*a = *b;
	*b = tmp;	
}

/******************** -- counting-- *************************/
static void FillHistogram(unsigned int *histogram, int *arr,
						  size_t arr_size, int shifting)
{
	size_t i = 0;
	
	assert(NULL != arr);
	assert(NULL != histogram);
	
	for (i = 0; i < arr_size; ++i)
	{
		++histogram[arr[i] + shifting];
	}
}


static void FillSortArr(int *sorted_arr, int *arr,
				        unsigned int *histogram, int shifting, size_t arr_size)
{
	int i = 0;
	
	assert(NULL != arr);
	assert(NULL != sorted_arr);
	assert(NULL != histogram);
	
	for (i = arr_size - 1; 0 <= i; --i)
	{
		sorted_arr[histogram[arr[i] + shifting] - 1] = arr[i];
		--histogram[(arr[i] + shifting)];	
	}
	
}

static void PrefixSumHistogram(unsigned int *histogram, size_t histogram_size)
{
	size_t i = 0;
	
	assert(NULL != histogram);
			
	for (i = 1; i < histogram_size; ++i)
	{
		histogram[i] += histogram[i - 1];
	}	
}

static void FillHistogramRadix(unsigned int *histogram, int *arr,
						       int shifting, int mask,
						       size_t arr_length)	  
{
	size_t i = 0;
		
	assert(NULL != arr);
	assert(NULL != histogram);

	for (i = 0; i < arr_length; ++i) 
	{	 
		++histogram[(arr[i] & mask) >> shifting];
	}
}

static void FillSortArrRadix(int *sorted_arr, int *arr,
				             unsigned int *histogram, int mask,
				             size_t arr_length, int shifting)
{
	size_t i = 0;
	
	assert(NULL != arr);
	assert(NULL != sorted_arr);
	assert(NULL != histogram);
	
	for (i = arr_length; 0 < i; --i)
	{
		sorted_arr[histogram[(arr[i - 1] & mask) >> shifting] - 1] = arr[i - 1];
		--histogram[(arr[i - 1] & mask) >> shifting];	
	}
}

static void CountingSortForRadix(unsigned int *histogram,
								 size_t histogram_length,
								 size_t arr_length,
								 int *arr,
								 int mask,
								 int *sorted_arr,
								 int shifting)
{
	FillHistogramRadix(histogram, arr, shifting, mask, arr_length); 
		
	PrefixSumHistogram(histogram, histogram_length);
		
	FillSortArrRadix(sorted_arr,arr, histogram,mask,arr_length,shifting);		

}

static void *FreeAndNull(void *memory_to_free)
{	
	free(memory_to_free);
	
	return NULL;
}

static void SwapPointers(int **pointer1, int **pointer2)
{
	int *tmp = NULL;
	
	assert(NULL != pointer1);
	assert(NULL != pointer2);
	
	tmp = *pointer1;
	*pointer1 = *pointer2;
	*pointer2 = tmp;
}	
	
