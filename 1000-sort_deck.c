#include "deck.h"

/**
 * comp_cards - compare two cards from double linked list
 * @a: first card
 * @b: second card
 * Return: return a positive value if first card is bigger than
 * the second one, negative value if the oposite or cero if the
 * cards are equal
 */
int comp_cards(const deck_node_t *a, const deck_node_t *b)
{

	card_value values[] = {{"Ace", 1}, {"2", 2}, {"3", 3},
			       {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8},
			       {"9", 9}, {"10", 10}, {"Jack", 11},
			       {"Queen", 12}, {"King", 13}};
	int i, a_val, b_val;

	if (a->card->kind != b->card->kind)
		return (a->card->kind - b->card->kind);
	for (i = 0; i < 13; i++)
	{
		if (strcmp(values[i].text, a->card->value) == 0)
			a_val = values[i].value;
		if (strcmp(values[i].text, b->card->value) == 0)
			b_val = values[i].value;
	}
	return (a_val - b_val);
}

/**
 * reorg_deck - Organize doble linked list deck according to the
 * pointers in array of pointers order
 * @deck: deck to organize
 * @order: order of pointers
 */
void reorg_deck(deck_node_t **deck, deck_node_t *order[52])
{
	int i;
	deck_node_t *card_tmp;

	card_tmp = *deck = order[0];
	card_tmp->prev = NULL;
	for (i = 1; i < 52; i++)
	{
		card_tmp->next = order[i];
		order[i]->prev = card_tmp;
		card_tmp = card_tmp->next;
	}
	card_tmp->next = NULL;
}

/**
 * sort_deck - sort a double linked list deck of cards using selection sort
 * @deck: deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *order[52];
	deck_node_t *card_tmp = NULL;
	int i;

	card_tmp = *deck;
	for (i = 0; i < 52; i++)
	{
		order[i] = card_tmp;
		card_tmp = card_tmp->next;
	}
	selection_sort_deck(order, 52);
	reorg_deck(deck, order);
}

/**
 * selection_sort_deck - sort an array of pointers to the card's nodes
 * of a double linked list
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort_deck(deck_node_t **array, size_t size)
{
	deck_node_t *tmp;
	size_t i, j, min;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			min = comp_cards(array[j], array[min]) < 0 ? j : min;
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
		}
	}
}
