#include "sort.h"

void heapify(int *array, size_t size, int i);
/**
  * heap_sort - a function that sorts an array of ints in ascending order
  * using heap sort algorithm.
  * @array: the array to sort
  * @size: the size of array
  *
  */
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	if (array == NULL || size < 2)
		return;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for (i = (int)size - 1; i >= 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heapify(array, i, 0);
	}
}

/**
  * heapify - a function that builds the heap and maintain the heap property
  * during the sorting process.
  * @array: the array to sort
  * @i: the index of the node to be heapified.
  * @n: the number of element in the array.
  * @size: the size of array
  *
  */
void heapify(int *array, size_t size, int i)
{
	int largest, left, right, tmp;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < (int)size && array[left] > array[largest])
		largest = left;

	if (right < (int)size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		tmp = array[i];
		array[i] = array[largest];
		array[largest] = tmp;
		/*print_array(array, size);*/
		heapify(array, size, largest);
	}
}
