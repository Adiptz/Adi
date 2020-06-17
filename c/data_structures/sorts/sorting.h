
#ifndef __ILRD_OL712_SORTING_H
#define __ILRD_OL712_SORTING_H

#include <stddef.h> /* size_t */
/*
 * Sorts @arr using insertion sort.
 * @arr: array to sort.
 * @size: number of elements in arr.
 */
void Insertion(int *arr, size_t size);

/*
 * Sorts @arr using selection sort.
 * @arr: array to sort.
 * @size: number of elements in arr.
 */
void Selection(int *arr, size_t size);

/*
 * Sorts @arr using bubble sort.
 * @arr: array to sort.
 * @size: number of elements in arr.
 */
void Bubble(int *arr, size_t size);

/*
 * Sorts @arr using counting sort
 * @arr: array to sort.
 * @size: number of elements in arr (must be at least 1).
 * @min: at most the smallest element in @arr.
 * @max: at least the biggest element in @arr.
 * return: 0 if success, non-zero otherwise
 */
int Counting(int arr[], size_t size, int min, int max);

/*
 * Sorts @arr using counting sort
 * @arr: array to sort.
 * @size: number of elements in arr (must be at least 1).
 * @num_of_bits: non-zero num of bits used as base for radix sort.
 * return: 0 if success, non-zero otherwise
 */
int Radix(int arr[], size_t size, unsigned int num_of_bits);

/*
 * Sorts @arr using merge sort
 * @arr: array to sort.
 * @size: number of elements in arr (must be at least 1).
 * @is_before: function to compare elements
 * return: 0 if success, non-zero otherwise
 */
int Merge(int *arr, size_t size, int (*is_before)(int a, int b));


void Quick(void *arr_to_sort, size_t element_size, size_t num_of_elements,
				int(*cmp_func)(const void *data1, const void *data2));
				
#endif /* __ILRD_OL712_SORTING_H */

