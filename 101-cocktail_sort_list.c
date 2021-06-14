#include "sort.h"

/**
 * cocktail_sort_list - cocktail sort implementation
 * @list: double pointer to double linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *hi, *lo;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = lo = *list;
	hi = NULL;

	while (hi == NULL || (lo != hi && lo->prev != hi))
	{
		/* Up */
		while (current->next != NULL && current != hi)
		{
			if (current->n > current->next->n)
			{
				if (current == lo)
					lo = current->next;
				if (current->next == hi)
					hi = current;
				swap_nodes(list, current, current->next);
			}
			else
				current = current->next;
			if (current->next == NULL)
				hi = current->prev;
		}
		current = hi;

		while (current->prev != NULL && current != lo)
		{
			if (current->n < current->prev->n)
			{
				if (current == hi)
					hi = current->prev;
				if (current->prev == lo)
					lo = current;
				swap_nodes(list, current->prev, current);
			}
			else
				current = current->prev;
		}
		lo = lo->next;
	}
}

/**
 * swap_nodes - swap node_1 and node_2 from double linked list list
 * node_1 and node_2 are adyacent nodes
 * @list: double pointer to double linked list
 * @node_1: node 1
 * @node_2: node 2
*/

void swap_nodes(listint_t **list, listint_t *node_1, listint_t *node_2)
{
	node_1->next = node_2->next;
	if (node_2->next)
		node_2->next->prev = node_1;

	if (node_1->prev)
		node_1->prev->next = node_2;
	else
		*list = node_2;

	node_2->prev = node_1->prev;

	node_2->next = node_1;
	node_1->prev = node_2;

	print_list(*list);
}
