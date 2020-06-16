

int main()
{
	int arr[] = {1,2,3,4,5,6}; 
	int arr1[] = {1,2,3,4}; 
	int arr10[] = {1,2,3,4,5,6,7,8,9,10};
	int data_at_the_end = 6; 
	int data_at_the_begin = 1;
	int test_2 = 2;
	int data_not_exict = 9;
	
/*	 Jump Search Test */
	
	void *found_data = JSearch(&data_at_the_end, arr, 6, 4, CmpInt);
	printf("6 : %d\n", *(int *)found_data);

	found_data = JSearch(&data_at_the_begin, arr, 6, 4, CmpInt);
	printf("1 : %d\n", *(int *)found_data);
	
	assert(NULL == JSearch(&data_not_exict, arr, 6, 4, CmpInt));
	
	
/*	 Recursive Binary-Search Test */
	found_data = BSearchRecursive(&data_at_the_end, arr, 6, 4, CmpInt);
	printf("6 : %d\n", *(int *)found_data);

	found_data = BSearchRecursive(&data_at_the_begin, arr, 6, 4, CmpInt);
	printf("1 : %d\n", *(int *)found_data);
	
	found_data = BSearchRecursive(&test_2, arr10, 10, 4, CmpInt);
	printf("2 : %d\n", *(int *)found_data);
	
	assert(NULL == BSearchRecursive(&data_not_exict, arr, 6, 4, CmpInt));
	assert(NULL == BSearchRecursive(&data_not_exict, arr1, 4, 4, CmpInt));
	
/*	 Iterative Binary-Search Test */
	found_data = BSearchIterative(&data_at_the_end, arr, 6, 4, CmpInt);
	printf("6 : %d\n", *(int *)found_data);

/*	found_data = BSearchRecursive(&data_at_the_begin, arr, 6, 4, CmpInt);*/
	printf("1 : %d\n", *(int *)found_data);
	assert(NULL == BSearchRecursive(&data_not_exict, arr, 6, 4, CmpInt));
	
	return 0;

}
