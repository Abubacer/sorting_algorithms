#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of ints,
 * in ascending order using the Bubble sort algorithm.
 * @array: the array to sort.
 * @size: the size of the array.
 *
 * Return: void.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int is_swapped, tmp;

	for (i = 0 ; i < size - 1 ; i++)
	{
		is_swapped = 0;
		for (j = 0 ; j < size - i - 1 ; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				is_swapped = 1;
				print_array(array, size);
			}
		}
	if (is_swapped == 0)
		break;
	}
}
