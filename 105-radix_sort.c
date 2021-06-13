#include "sort.h"

/**
 * heap_sort - heap sort implementation
 * @array: array to sort
 * @size: array's size
 */
void radix_sort(int *array, size_t size)
{
	unsigned short i, j = 0, bucket_idx, lsd = 0, keep_going = 1;
	listint_t **buckets, **tails;

	buckets = malloc(sizeof(*buckets) * 10);
	tails = malloc(sizeof(*tails) * 10);
	if (!buckets || !tails)
		return;
	for (i = 0; i < 10; i++)
	{
		buckets[i] = NULL;
		tails[i] = NULL;
	}

	while (keep_going)
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
		j = 0;
		for (i = 0; i < 10; i++)
		{
			while (buckets[i])
			{
				array[j] = pop(buckets + i, tails + i);
				j++;
			}
		}
		lsd++;
		print_array(array, size);

	}
	free_list(buckets[0]);
	free(buckets), free(tails);
}

void free_list(listint_t *list)
{
	if (list == NULL)
		return;
	free_list(list->next);
	free(list);
}

listint_t *push(listint_t **bucket, listint_t **tail, int num)
{
	listint_t *newnode, *h;

	if (!bucket || !tail)
		return (NULL);

	h = *bucket;

	newnode = malloc(sizeof(listint_t));
	if (!newnode)
		return (NULL);

	*(int *)&(newnode->n) = num;
	newnode->prev = NULL;
	newnode->next = h;
	if (bucket && *bucket)
		(*bucket)->prev = newnode;

	*bucket = newnode;

	if (newnode->next == NULL)
		*tail = newnode;

	return (newnode);
}

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


int get_digit(int num, int digit)
{
	int i, pow_ten = 1;

	for (i = 0; i < digit; i++)
		pow_ten *= 10;

	return ((num % (pow_ten * 10) - num % pow_ten)
		/ pow_ten);
}
