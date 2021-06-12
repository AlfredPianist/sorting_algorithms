#include "sort.h"

/**
 * counting_sort - counting sort implementation
 * @array: array to sort
 * @size: array's size
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, i, total = 0;
	int *count_array = NULL, *copy_array = NULL;

	count_array = malloc(sizeof(int) * (max + 1));
	if (count_array == NULL)
		exit(1);
	copy_array = malloc(sizeof(int) * size);
	if (copy_array == NULL)
		exit(1);
	for (i = 0; i < (int)size; i++)
		copy_array[i] = array[i];

	print_array(array, size);
	print_array(copy_array, size);

	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	for (i = 0; i <= max; i++)
		count_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;

	for (i = 0; i <= max; i++)
	{
		count_array[i] += total;
		total = count_array[i];
	}
	print_array(count_array, max + 1);
	print_array(array, size);
	print_array(copy_array, size);

	for (i = 0; i < (int)size; i++)
	{
		array[count_array[copy_array[i]] - 1] = copy_array[i];
		count_array[copy_array[i]]--;
	}
}