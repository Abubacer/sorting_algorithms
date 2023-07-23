#include "sort.h"

/**
 * selection_sort - a function that sorts an array of ints,
 * in ascending order using the Selection sort algorithm.
 * @array: the array to sort.
 * @size: the size of the array.
 *
 * Return: void.
 */
void selection_sort(int *array, size_t size)
{
	size_t	i, j;
	int min_idx, tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0 ; i < size - 1 ; i++)
	{
		min_idx = i;

		for (j = i + 1 ; j < size ; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (min_idx != (int)i)
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
