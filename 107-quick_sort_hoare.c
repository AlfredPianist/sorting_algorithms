#include "sort.h"

/**
 * bitonic_sort - Bitonic sort implementation.
 * @array: Array to sort.
 * @size: Array's size.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	recursive_bitonic_sort(array, size, 1, size);
}

/**
 * recursive_bitonic_sort - Recursive Bitonic sort implementation.
 * @array: Array to sort.
 * @size: Array's size.
 * @dir: Sorting direction, 1 is ascending, 0 is descending
 * @osize: Original array's size
 */
void recursive_bitonic_sort(int *array, size_t size, int dir, size_t osize)
{
	unsigned int k;

	if (size <= 1)
		return;

	k = size / 2;
	printf("Merging [%lu/%lu] (%s):\n", size, osize, dir == 1 ? "UP" : "DOWN");
	print_array(array, size);
	recursive_bitonic_sort(array, k, 1, osize);
	recursive_bitonic_sort(array + k, k, 0, osize);
	merge_bitonic_sort(array, size, dir, osize, 1);
}

/**
 * merge_bitonic_sort - merge two consecutive and bitonic arrays
 * @array: Array to sort.
 * @size: Array's size.
 * @dir: Sorting direction, 1 is ascending, 0 is descending
 * @osize: Original array's size
 * @print: flat to print result after merging, if is set to 1 the result
 * is printed, if it's set to cero the result is not printed
 */
void merge_bitonic_sort(int *array, size_t size,
			int dir, size_t osize, int print)
{
	unsigned int i, k;
	int tmp;

	if (size <= 1)
		return;

	k = size / 2;

	for (i = 0; i < k; i++)
	{
		if ((array[i + k] > array[i]) != dir)
			tmp = array[i], array[i] = array[i + k], array[i + k] = tmp;
	}
	merge_bitonic_sort(array, k, dir, osize, 0);
	merge_bitonic_sort(array + k, k, dir, osize, 0);
	if (print)
	{
		printf("Result [%lu/%lu] (%s):\n", size, osize, dir == 1 ? "UP" : "DOWN");
		print_array(array, size);
	}
}
