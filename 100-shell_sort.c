#include "sort.h"

/**
 * shell_sort - a function that sorts an array of ints,
 * in ascending order using the Shell sort algorithm, the Knuth sequence.
 * @array: the array to sort.
 * @size: the size of the array.
 *
 * Return: void.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap, ks_max;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (gap = 1 ; gap < size ; gap = (gap * 3) + 1)
	{
		ks_max = gap;
	}
	for (gap = ks_max ; gap > 0 ; gap = (gap - 1) / 3)
	{
		for (i = gap ; i < size ; i++)
		{
			tmp = array[i];
			for (j = i ; j >= gap &&
				array[j - gap] > tmp ; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
