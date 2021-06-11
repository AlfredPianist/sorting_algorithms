#include "sort.h"

/**
 * shell_sort - shell sort implementation
 * (Lomuto partition scheme)
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j, tmp, comp_index;

	if (!array || size < 2)
		return;

	for (gap = 1; gap < size; gap = 3 * gap + 1)
		;

	while (gap >= 1)
	{
		gap = (gap - 1) / 3;
		/* printf("gap = %lu\n", gap); */
		if (gap * 3 + 1 < size)
			print_array(array, size);
		for (i = 0; i < gap; i++)
		{
			for (j = i + gap; j < size; j = j + gap)
			{
				comp_index = j;
				while (array[comp_index] < array[comp_index - gap] && comp_index >= gap)
				{
					tmp = array[comp_index];
					array[comp_index] = array[comp_index - gap];
					array[comp_index - gap] = tmp;
					comp_index -= gap;
				}
			}
		}
	}
}
