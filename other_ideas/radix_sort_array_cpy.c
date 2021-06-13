#include "sort.h"

/**
 * radix_sort - Radix sort implementation w/ array copy.
 * @array: Array to sort.
 * @size: Array's size.
 */
void radix_sort(int *array, size_t size)
{
	unsigned short i, j, bucket_idx, keep_going = 1;
	listint_t **buckets, **tails;
	array_t **array_cpy;

	buckets = malloc(sizeof(*buckets) * 10);
	tails = malloc(sizeof(*tails) * 10);
	array_cpy = malloc(sizeof(*array_cpy) * size);
	if (!buckets || !tails || !array_cpy)
	{
		if (buckets)
			free(buckets);
		if (tails)
			free(tails);
		if (array_cpy)
			free(array_cpy);
		exit(1);
	}
	for (i = 0; i < 10; i++)
		buckets[i] = tails[i] = NULL;
	for (i = 0; i < size; i++)
	{
		array_cpy[i] = malloc(sizeof(**array_cpy));
		if (!array_cpy[i])
		{
			for (j = 0; j <= i; j++)
				free(array_cpy[j]);
			free(array_cpy);
			if (buckets)
				free(buckets);
			if (tails)
				free(tails);
			exit(1);
		}
		array_cpy[i]->orig_n = array_cpy[i]->mod_n = array[i];
	}

	for (j = 0; keep_going; j = 0)
	{
		keep_going = 0;
		for (i = 0; i < size; i++)
		{
			bucket_idx = get_digit(array_cpy, i);
			keep_going = bucket_idx != 0 ? 1 : 0;
			push(buckets + bucket_idx, tails + bucket_idx, array_cpy[i]);
		}
		if (keep_going == 0)
			break;
		for (i = 0; i < 10; i++)
			while (buckets[i])
			{
				free(array_cpy[j]);
				array_cpy[j] = pop(buckets + i, tails + i);
				array[j] = array_cpy[j]->orig_n;
				j++;
			}
		print_array(array, size);
	}
	for (i = 0; i < size; i++)
		free(array_cpy[i]);
	free_list(buckets[0]);
	free(buckets), free(tails), free(array_cpy);
}

/**
 * get_digit - Gets the least significant digit of a given number.
 * @array: The array to retrieve the number to be checked.
 * @idx: The index of the array.
 *
 * Return: The digit asked.
 */
int get_digit(array_t **array, int idx)
{
	int digit;

	digit = array[idx]->mod_n % 10;
	array[idx]->mod_n /= 10;

	return (digit);
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
listint_t *push(listint_t **bucket, listint_t **tail, array_t *num)
{
	listint_t *newnode, *h;

	if (!bucket || !tail)
		exit(1);

	h = *bucket;

	newnode = malloc(sizeof(listint_t));
	if (!newnode)
		exit(1);

	*(int *)&(newnode->n) = num->orig_n;
	newnode->mod_n = num->mod_n;

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
array_t *pop(listint_t **bucket, listint_t **tail)
{
	listint_t *remove;
	array_t *num;

	if (!*tail || !*bucket)
		exit(1);

	num = malloc(sizeof(num));
	if (!num)
		exit(1);

	remove = *tail;
	if ((*tail)->prev)
		*tail = (*tail)->prev;
	else
		*tail = *bucket = NULL;

	num->orig_n = remove->n;
	num->mod_n = remove->mod_n;

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
