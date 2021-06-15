#ifndef DECK_H

#define DECK_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct card_value - value of a card
 *
 * @value: Numeric value of text
 * From "Ace" to "King"
 * @text: Kind of the card
 */
typedef struct card_value
{
	char *text;
	int value;
} card_value;

/**
 * enum kind_e - numeric values for kinds of cards
 * @SPADE: spade value 0
 * @HEART: heart value 1
 * @CLUB: club value 2
 * @DIAMOND: diamond value 3
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
int comp_cards(const deck_node_t *a, const deck_node_t *b);
void reorg_deck(deck_node_t **deck, deck_node_t *order[52]);
void selection_sort_deck(deck_node_t **array, size_t size);
#endif

