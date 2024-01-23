#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the QuickSort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */

void quick_sort(int *array, size_t size)
{
	int start = 0;
	int end = size - 1;
	int n_size;

	if (start < end)
	{
		n_size = partition(array, start, end);
		quick_sort(array, n_size);
		quick_sort(array + n_size + 1, end - n_size);
	}

}

/**
 * swap_array - Swaps two elements in an integer array.
 *
 * @array: Pointer to the array containing elements to be swapped.
 * @start: Index of the first element to be swapped.
 * @end: Index of the second element to be swapped.
 */


void swap_array(int *array, int start, int end)
{
	int swap = array[end];

	array[end] = array[start];
	array[start] = swap;
}


/**
 * partition - Lomuto partition scheme for the QuickSort algorithm.
 *
 * @array: Pointer to the array to be partitioned.
 * @start: Starting index of the partition.
 * @end: Ending index of the partition.
 *
 * Return: Index of the pivot after partitioning.
 */

int partition(int *array, int start, int end)
{
	int pivot = array[start];
	int i = start;
	int j = end;

	while (i <= j)
	{
		while (array[i] <= pivot)
		{
			i++;
		}

		while (array[j] > pivot)
		{
			j--;
		}

		if (i < j)
			swap_array(array, i, j);
	}
	swap_array(array, start, j);
	return (j);
}
