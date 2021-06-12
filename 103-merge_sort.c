#include "sort.h"


/**
 * merge_sort - Merge sort implementation
 * @array: array to sort
 * @size: array's size
 */
void merge_sort(int *array, size_t size)
{
	size_t size0, size1;

	if (!array || size == 1)
		return;

	size0 = size / 2;
	size1 = size - size0;

	merge_sort(array, size0);
	merge_sort(array + size0, size1);

	merge_arrays(array, size0, size1);
}

/**
 * merge_arrays - Sort two adjacents int arrays in memory
 * @array: pointer to the first array
 * @size0: first array's size
 * @size1: second array's size
 */
void merge_arrays(int *array, size_t size0, size_t size1)
{
	int *copy_array0 = NULL, *copy_array1 = NULL;
	unsigned int i, j;

	copy_array0 = malloc(sizeof(int) * (size0 + size1));
	if (!copy_array0)
		return;

	for (i = 0; i < size0 + size1; i++)
		copy_array0[i] = array[i];

	copy_array1 = copy_array0 + size0;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(copy_array0, size0);
	printf("[right]: ");
	print_array(copy_array1, size1);
	i = j = 0;
	while (i < size0 && j < size1)
	{
		if (copy_array0[i] <= copy_array1[j])
			array[i + j] = copy_array0[i], i++;
		else
			array[i + j] = copy_array1[j], j++;

	}
	while (i < size0)
	{
		array[i + j] = copy_array0[i];
		i++;
	}
	while (j < size1)
	{
		array[i + j] = copy_array1[j];
		j++;
	}
	printf("[Done]: ");
	print_array(array, size0 + size1);
	free(copy_array0);
}
