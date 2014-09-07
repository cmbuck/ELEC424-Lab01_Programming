#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "read_data.h"

/* 
 * Takes a file name as input from command line
 * which contains array of integers. These are
 * sorted either in ascending order or descending
 * order. The array is printed out both pre- and 
 * post-sort.
 *
 * DO NOT EDIT THIS MAIN FUNCTION 
 */
int
main(int argc, char **argv)
{
	int i;
        int num;
	int to_sort_array[MAX_NUM];
	int sorted_array[MAX_NUM];
	
	if (argc != 2) {
		perror("Input arguments are not correct.\n");
		return 1;
	}

	/* Fill the input array */
	num = fillInput(to_sort_array, argv[1]);
	if (num <= 0) {
		perror("Data initilization error.\n");
		return 1;
	}

	/* Print input and sort */
	printf("Unsorted array:\t");
	for (i = 0; i < num; i++) {
		printf("%d ",to_sort_array[i]);
	}
	printf("\n");

	merge_sort(to_sort_array, sorted_array, num);
#ifdef DSC
	printf("Sorted (descending) array: ");
#elif ASC
	printf("Sorted (ascending) array: ");
#endif
	for (i = 0; i < num; i++) {
		printf("%d ",sorted_array[i]);
	}
	printf("\n");
	return 0;
}

/*
 * INSERT DESCRIPTION HERE
 */
void 
merge_sort(int input_array[], int output_array[], int num)
{
	/* COMPLETE ME */
	if (num == 0)
		return;
	else if (num == 1)
	{
		output_array[0] = input_array[0];
		return;
	}

	else //num > 1
	{
		int mid = num / 2;
		int left_in[mid], left_out[mid];
		int right_in[num - mid], right_out[num - mid];
		//mid is exclusive of left, and inclusive in right
		//copy the input array to the new arrays
		memcpy(left_in, &input_array[0], mid * sizeof(int));
		memcpy(right_in, &input_array[mid], (num - mid) * sizeof(int));
		//recurse on each half
		merge_sort(left_in, left_out, mid);
		merge_sort(right_in, right_out, num - mid);
		//merge the two arrays
		int i,l,r;
		l = r = 0;
		char asc = 1; //in ascending order?
#ifdef DSC
		asc = 0;
#elif ASC
		asc = 1;
#endif
		for (i = 0; i < num; i++)
		{
			if (asc) {
				if (r == num - mid || 
				  (l < mid && left_out[l] < right_out[r]))
					output_array[i] = left_out[l++];
				else 
					output_array[i] = right_out[r++];
			}
			else { //dsc
				if (r == num - mid ||
				  (l < mid && left_out[l] > right_out[r]))
					output_array[i] = left_out[l++];
				else
					output_array[i] = right_out[r++];
			}
		}
	}
}

//void
//mergeSortRecurse(int arr[], 
