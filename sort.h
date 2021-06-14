#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

void bubble_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);

void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);
void recursive_quick_sort(int *oarray, size_t osize, int *array, size_t size);

void shell_sort(int *array, size_t size);

void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node_1, listint_t *node_2);

void counting_sort(int *array, size_t size);

void merge_sort(int *array, size_t size);
void merge_recursive(int *array, int *array_cpy, size_t size);
void merge_arrays(int *array, int *array_cpy_l, size_t size_l, size_t size_r);

void heap_sort(int *array, size_t size);
void build_heap(int *array, size_t size);
void sift_down(int *array, size_t size, size_t i, size_t osize);
void swap(int *num_1, int *num_2);

void radix_sort(int *array, size_t size);
listint_t *push(listint_t **bucket, listint_t **tail, int num);
int pop(listint_t **bucket, listint_t **tail);
int get_digit(int num, int digit);
void free_list(listint_t *list);

void bitonic_sort(int *array, size_t size);
void recursive_bitonic_sort(int *array, size_t size, int dir, size_t osize);
void merge_bitonic_sort(int *array, size_t size, int dir,
			size_t osize, int print);

void quick_sort_hoare(int *array, size_t size);
void recursive_hoare(int *array, size_t size, int *oarray, size_t osize);
void swap(int *a, int *b);

#endif
