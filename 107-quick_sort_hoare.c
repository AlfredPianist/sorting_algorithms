#include "sort.h"

/**
 * quick_sort_hoare - Quick sort implementation. (Hoare scheque)
 * @array: Array to sort.
 * @size: Array's size.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	recursive_hoare(array, size, array, size);
}

/**
 * recursive_hoare - Recursive quick sort implementation. (Hoare scheque)
 * @array: Array to sort.
 * @size: Array's size.
 * @oarray: original array
 * @osize: original array's size
 */
void recursive_hoare(int *array, size_t size, int *oarray, size_t osize)
{
	unsigned int lo = 0, hi;
	int p, tmp;

	if (size <= 1)
		return;

	hi = size - 1;
	p = array[size - 1];
	while (lo < hi)
	{
		if (array[lo] < p)
			lo++;
		else
		{
			if (array[hi] > p)
				hi--;
			else
			{
				tmp = array[lo];
				array[lo] = array[hi];
				array[hi] = tmp;
				hi--;
				lo++;
				print_array(oarray, osize);
			}
		}
	}
	if (lo == hi && array[lo] < p)
		lo++;
	recursive_hoare(array, lo, oarray, osize);
	recursive_hoare(array + lo, size - lo, oarray, osize);
}
