#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @mod_n: Modified integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	int mod_n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * struct array_s - Array structure with original and modified number
 *
 * @orig_n: Original number
 * @mod_n: Modified number
 */
typedef struct array_s
{
	int orig_n;
	int mod_n;
} array_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

void shell_sort(int *array, size_t size);

void radix_sort(int *array, size_t size);
listint_t *push(listint_t **bucket, listint_t **tail, array_t *num);
array_t *pop(listint_t **bucket, listint_t **tail);
int get_digit(array_t **array, int idx);
void free_list(listint_t *list);

void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
