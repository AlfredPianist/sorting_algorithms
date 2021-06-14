#include "sort.h"

/**
 * counting_sort - Counting sort implementation.
 * @array: Array to sort.
 * @size: Array's size.
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, i, total = 0;
	int *count_array = NULL, *copy_array = NULL;

	if (!array || size < 1)
		return;
	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	count_array = malloc(sizeof(int) * (max + 1));
	copy_array = malloc(sizeof(int) * size);
	if (!count_array || !copy_array)
	{
		if (count_array)
			free(count_array);
		if (copy_array)
			free(copy_array);
		exit(1);
	}

	for (i = 0; i <= max; i++)
		count_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		copy_array[i] = array[i];
	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;

	for (i = 0; i <= max; i++)
	{
		count_array[i] += total;
		total = count_array[i];
	}
	print_array(count_array, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		array[count_array[copy_array[i]] - 1] = copy_array[i];
		count_array[copy_array[i]]--;
	}
	free(copy_array), free(count_array);
}
