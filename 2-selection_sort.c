#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 *                  the Selection Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t minv = 0;
	size_t req = 0;
	size_t pass = 0, i = 0;
	int tem = 0;

	if (array == NULL || size < 2)
	{
		return;
	}
	req = size - 1;
	for (pass = 0; pass < req; pass++)
	{
		minv = pass;
		for (i = pass + 1; i < size; i++)
		{
			if (array[i] < array[minv])
			{
				minv = i;
			}
		}
		tem = array[pass];
		array[pass] = array[minv];
		array[minv] = tem;
		if (minv > pass)
		{
			print_array(array, size);
		}
	}
}
