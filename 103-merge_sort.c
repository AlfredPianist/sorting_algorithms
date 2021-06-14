#include "sort.h"

/**
 * merge_sort - Merge sort implementation.
 * @array: Array to sort.
 * @size: Array's size.
 */
void merge_sort(int *array, size_t size)
{
	int *cpy_array;
	size_t i;

	if (!array || size < 1)
		return;

	cpy_array = malloc(sizeof(*cpy_array) * size);
	if (!cpy_array)
		exit(1);

	for (i = 0; i < size; i++)
		cpy_array[i] = array[i];

	merge_recursive(array, cpy_array, size);
	free(cpy_array);
}

/**
 * merge_recursive - Merge sort recursive helper function.
 * @array: Array to sort.
 * @array_cpy: Copy of the original array to be sorted.
 * @size: Array's size.
 */
void merge_recursive(int *array, int *array_cpy, size_t size)
{
	int size_l, size_r;

	if (size == 1)
		return;

	size_l = size / 2;
	size_r = size - size_l;

	merge_recursive(array, array_cpy, size_l);
	merge_recursive(array, array_cpy + size_l, size_r);

	merge_arrays(array, array_cpy, size_l, size_r);
}

/**
 * merge_arrays - Sort two adjacents int arrays in memory
 * @array: Array to sort.
 * @array_cpy_l: Pointer to the left array to be sorted.
 * @size_l: Left array's size.
 * @size_r: Right array's size.
 */
void merge_arrays(int *array, int *array_cpy_l, size_t size_l, size_t size_r)
{
	int *array_cpy_r = NULL;
	unsigned int i, j;

	array_cpy_r = array_cpy_l + size_l;
	printf("Merging...\n");
	printf("[left]: "), print_array(array_cpy_l, size_l);
	printf("[right]: "), print_array(array_cpy_r, size_r);
	i = j = 0;
	while (i < size_l && j < size_r)
	{
		if (array_cpy_l[i] <= array_cpy_r[j])
			array[i + j] = array_cpy_l[i], i++;
		else
			array[i + j] = array_cpy_r[j], j++;

	}
	while (i < size_l)
	{
		array[i + j] = array_cpy_l[i];
		i++;
	}
	while (j < size_r)
	{
		array[i + j] = array_cpy_r[j];
		j++;
	}
	printf("[Done]: ");
	print_array(array, size_l + size_r);

	for (i = 0; i < size_l + size_r; i++)
		array_cpy_l[i] = array[i];
}
