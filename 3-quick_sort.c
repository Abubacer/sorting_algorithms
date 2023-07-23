#include "sort.h"

/**
 * recurs_quicksort - a function that recursively sorts array of ints,
 * by separating into two sub-array using Lomuto partition scheme.
 * @array: the array to sort.
 * @low: the index in array that starts partition.
 * @high: the index in array that ends partition.
 * @size: the size of the array.
 *
 * Return: void.
 */
void recurs_quicksort(int *array, int low, int high, size_t size)
{
	size_t pivot_elemt;

	if (low < high)
	{
		pivot_elemt = lomuto_partition(array, low, high, size);
		recurs_quicksort(array, low, pivot_elemt - 1, size);
		recurs_quicksort(array, pivot_elemt + 1, high, size);
	}
}

/**
 * lomuto_partition - a function that divides an array into two sub-arrays.
 * based on a chosen pivot element.
 * @array: the array to sort.
 * @low: the index in array that starts partition.
 * @high: the index in array that ends partition.
 * @size: the size of the array.
 *
 * Return: the new index at which to start new recursive partition.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int i, idx_start, idx_end, tmp;

	idx_end = array[high];
	idx_start = low;

	for (i = low ; i < high ; i++)
	{
		if (array[i] < idx_end)
		{
			tmp = array[idx_start];
			array[idx_start] = array[i];
			array[i] = tmp;
			if (array[idx_start] != array[i])
				print_array(array, size);
			idx_start++;
		}
	}
	tmp = array[idx_start];
	array[idx_start] = array[high];
	array[high] = tmp;
	if  (array[idx_start] != array[high])
		print_array(array, size);

	return (idx_start);
}

/**
 * quick_sort - a function that sorts an array of ints,
 * in ascending order using the quick sort algorithm.
 * @array: the array to sort.
 * @size: the size of the array.
 *
 * Return: void.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recurs_quicksort(array, 0, size - 1, size);
}
