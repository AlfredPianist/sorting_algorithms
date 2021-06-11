#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *current_next, *comp;

	if (!list || !*list || !(*list)->next)
		return;

	current = current_next = (*list)->next;
	while (current_next)
	{
		current_next = current_next->next;
		comp = current->prev;
		while (comp && comp->n > current->n)
		{
			
		}
	}
}
