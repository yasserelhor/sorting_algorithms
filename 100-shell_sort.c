#include "sort.h"

/**
 * swapValues - Swap the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */

void swapValues(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order
 *               using the Shell sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void shell_sort(int *array, size_t size)
{
	size_t Void, f, i;

	if (array == NULL || size < 2)
		return;

	for (Void = 1; Void < (size / 3);)
		Void = Void * 3 + 1;

	for (; Void >= 1; Void /= 3)
	{
		for (f = Void; f < size; f++)
		{
			i = f;
			while (i >= Void && array[i - Void] > array[i])
			{
				swapValues(array + i, array + (i - Void));
				i -= Void;
			}
		}
		print_array(array, size);
	}
}