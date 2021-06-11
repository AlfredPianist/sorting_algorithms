#include "sort.h"

/**
 * quick_sort - Quick sort implementation
 * (Lomuto partition scheme)
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	recursive_quick_sort(array, size, array, size);
}


/**
 * recursive_quick_sort - Recursive quick sort implementation
 * (Lomuto partition scheme)
 * @oarray: Original array to sort
 * @osize: Original array's size
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void recursive_quick_sort(int *oarray, size_t osize, int *array, size_t size)
{
	int p, lo = 0, hi = 0, tmp;

	p = array[size - 1];

	while (hi < (int)size)
	{
		if (array[hi] > p)
		{
			hi++;
		}
		else
		{
			if (lo == hi)
			{
				lo++;
				hi++;
			}
			else
			{
				tmp = array[lo];
				array[lo] = array[hi];
				array[hi] = tmp;
				lo++;
				hi++;
				print_array(oarray, osize);
			}
		}
	}
	if (lo > 2)
		recursive_quick_sort(oarray, osize, array, lo - 1);
	if (size - lo >= 2)
		recursive_quick_sort(oarray, osize, array + lo, size - lo);
}
