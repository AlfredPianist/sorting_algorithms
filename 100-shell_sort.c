#include "sort.h"

/**
 * shell_sort - Shell sort implementation (with Knuth sequence).
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	ssize_t gap, i, j;
	int tmp;

	if (!array || size < 2)
		return;

	for (gap = 1; gap < (ssize_t)size; gap = 3 * gap + 1)
		;

	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < (ssize_t)size; i++)
		{
			tmp = array[i];
			for (j = i - gap; j > -1 && array[j] > tmp; j -= gap)
				array[j + gap] = array[j];
			array[j + gap] = tmp;
		}
		print_array(array, size);
	}
}
