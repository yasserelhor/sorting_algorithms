#include "sort.h"

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
 * sorter - Recursive function to sort an array using sorter.
 * @arr: The array to be sorted.
 * @low: The starting index.
 * @high: The ending index.
 * @arr_size: The size of the array.
 */

void sorter(int *arr, int low, int high, size_t arr_size)
{
	if (low < high)
	{
		int pivot_idx = partition(arr, low, high, arr_size);

		sorter(arr, low, pivot_idx - 1, arr_size);
		sorter(arr, pivot_idx + 1, high, arr_size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the sorter algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	sorter(array, 0, size - 1, size);
}


