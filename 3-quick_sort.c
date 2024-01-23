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
	if (array == NULL || size <= 1)
		return;
	quicksort(array, 0, size - 1, size);
}


/**
 * partition - Partition the array using the last element as the Shift.
 * @array: The array to be partitioned.
 * @low: The starting index.
 * @high: The ending index.
 * @size: The size of the array.
 *
 * Return: The index of the Shift after partitioning.
 */

int partition(int *array, int low, int high, size_t size)
{
	int Shift = array[high], i = low - 1, temp;
	int j = low;

	while (j < high)
	{
		if (array[j] <= Shift)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != j)
		print_array(array, size);
	return (i + 1);
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


