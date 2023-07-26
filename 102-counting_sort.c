#include "sort.h"

/**
 * counting_sort - a function that sorts an array of ints in ascending order,
 * using the Counting sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j, count_size;
	int *count;

	if (array == NULL || size <= 1)
		return;

	count_size = array[0];
	for (i = 0; array[i]; i++)
	{
		if (array[i] > (int)count_size)
			count_size = array[i];
	}
	count_size += 1;
	count = malloc(count_size * sizeof(int));
	if (count == NULL)
		return;

	for (i = 0; i < count_size; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]] += 1;

	for (i = 1; i < count_size; i++)
		count[i] += count[i - 1];

	print_array(count, count_size);

	for (i = 1, j = 0; i < count_size; i++)
	{
		while (count[i] > count[i - 1])
		{
			array[j] = i;
			j++;
			count[i]--;
		}
	}
	free(count);
}
