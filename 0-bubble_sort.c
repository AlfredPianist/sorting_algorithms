#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, n;
	short swapped;

	if (!array || size <= 1)
		return;

	n = size;
	do {
		swapped = 0;
		for (i = 1; i < n; i++)
			if (array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;

				swapped = 1;

				print_array(array, size);
			}
		n -= 1;
	} while (swapped == 1);
}
