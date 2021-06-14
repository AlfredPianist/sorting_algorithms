#include "sort.h"

/**
 * radix_sort - Radix sort implementation.
 * @array: Array to sort.
 * @size: Array's size.
 */
void radix_sort(int *array, size_t size)
{
	unsigned short i, j, bucket_idx, lsd, keep_going = 1;
	listint_t **buckets, **tails;

	if (!array || size < 1)
		return;

	buckets = malloc(sizeof(*buckets) * 10);
	tails = malloc(sizeof(*tails) * 10);
	if (!buckets || !tails)
	{
		if (buckets)
			free(buckets);
		if (tails)
			free(tails);
		exit(1);
	}
	for (i = 0; i < 10; i++)
		buckets[i] = tails[i] = NULL;

	for (j = lsd = 0; keep_going; j = 0, lsd++)
	{
		keep_going = 0;
		for (i = 0; i < size; i++)
		{
			bucket_idx = get_digit(array[i], lsd);
			if (bucket_idx != 0)
				keep_going = 1;
			push(buckets + bucket_idx, tails + bucket_idx, array[i]);
		}
		if (keep_going == 0)
			break;
		for (i = 0; i < 10; i++)
			while (buckets[i])
			{
				array[j] = pop(buckets + i, tails + i);
				j++;
			}
		print_array(array, size);
	}
	free_list(buckets[0]), free(buckets), free(tails);
}

/**
 * get_digit - Gets the least significant digit passed as parameter of
 *             a given number.
 * @num: The number to be checked.
 * @digit: The position of the least significant digit beginning with 0.
 *
 * Return: The digit asked.
 */
int get_digit(int num, int digit)
{
	int i, pow_ten = 1;

	for (i = 0; i < digit; i++)
		pow_ten *= 10;

	return ((num % (pow_ten * 10) - num % pow_ten)
		/ pow_ten);
}

/**
 * push - Pushes a new node to the head of a doubly linked list structure,
 *        and updates the address of the tail.
 * @bucket: The list to be pushed the new node.
 * @tail: The address of the tail of the list.
 * @num: The number to be entered to the new node.
 *
 * Return: The new node.
 */
listint_t *push(listint_t **bucket, listint_t **tail, int num)
{
	listint_t *newnode, *h;

	if (!bucket || !tail)
		exit(1);

	h = *bucket;

	newnode = malloc(sizeof(listint_t));
	if (!newnode)
		exit(1);

	*(int *)&(newnode->n) = num;
	newnode->prev = NULL;
	newnode->next = h;
	if (bucket && *bucket)
		(*bucket)->prev = newnode;

	*bucket = newnode;

	if (!newnode->next)
		*tail = newnode;

	return (newnode);
}

/**
 * pop - Deletes the tail of a doubly linked list structure and returns
 *       its number.
 * @bucket: The list to be popped the new node.
 * @tail: The array of tail nodes to be updated.
 *
 * Return: The number of the freed node.
 */
int pop(listint_t **bucket, listint_t **tail)
{
	listint_t *remove;
	int num;

	if (!*tail || !*bucket)
		exit(1);

	remove = *tail;
	if ((*tail)->prev)
		*tail = (*tail)->prev;
	else
		*tail = *bucket = NULL;

	num = remove->n;
	free(remove);

	return (num);
}

/**
 * free_list - Frees a doubly linked list.
 * @list: The list to be freed.
 */
void free_list(listint_t *list)
{
	if (!list)
		return;
	free_list(list->next);
	free(list);
}
