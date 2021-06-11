#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	/* int array[] = {8, 83, 67, 35, 43, 89, 12, 78, 17, 54, */
	/* 	       29, 95, 22, 40, 39, 42, 91, 27, 13, 16}; */
	/* int array[] = {1}; */
	/* int array[] = {34, 5}; */
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	shell_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
