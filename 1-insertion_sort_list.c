#include "sort.h"

/**
 * insertion_sort_list - Insertion sort implementation.
 * @list: The list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *current_next, *comp;

	if (!list || !*list || !(*list)->next)
		return;

	current = current_next = (*list)->next;
	while (current_next)
	{
		current = current_next;
		current_next = current_next->next;
		comp = current->prev;
		while (comp && comp->n > current->n)
		{
			comp->next = current->next;
			if (current->next)
				current->next->prev = comp;

			if (comp->prev)
				comp->prev->next = current;
			else
				*list = current;

			current->prev = comp->prev;

			current->next = comp;
			comp->prev = current;

			comp = current->prev;
			print_list(*list);
		}
	}
}
