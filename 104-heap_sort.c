#include "sort.h"

/**
 * heap_sort - Heap sort implementation.
 * @array: Array to sort.
 * @size: Array's size.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 1)
		return;

	build_heap(array, size);
	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		sift_down(array, i, 0, size);
	}
}

/**
 * build_heap - Build heap data structure.
 * @array: Array to sort.
 * @size: Array's size.
 */
void build_heap(int *array, size_t size)
{
	int i = 0;

	for (i = size / 2; i >= 0; i--)
		sift_down(array, size, i, size);
}

/**
 * sift_down - Sort recursively branch starting from index i
 *             in heap data structure.
 * @array: Array to sort.
 * @size: Array's size.
 * @i: Branch starting index.
 * @osize: Original array's size for printing purposes.
 */
void sift_down(int *array, size_t size, size_t i, size_t osize)
{
	unsigned int left, right, max;

	left = i * 2 + 1;
	right = left + 1;

	if (right < size && array[right] > array[left])
		max = right;
	else if (left < size)
		max = left;
	else
		max = i;

	max = array[i] < array[max] ? max : i;

	if (max != i)
	{
		swap(array + i, array + max);
		print_array(array, osize);
		sift_down(array, size, max, osize);
	}
}
/**
 * Swap - Swaps two int variables.
 * @num_1: Pointer for first variable.
 * @num_2: Pointer for second variable.
 */
void swap(int *num_1, int *num_2)
{
	int tmp;

	tmp = *num_1;
	*num_1 = *num_2;
	*num_2 = tmp;
}
