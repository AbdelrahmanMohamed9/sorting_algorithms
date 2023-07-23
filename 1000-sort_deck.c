#include "deck.h"

/**
 * get_val - Retrieve the numerical value of
 *	a card based on its string representation.
 *
 * @str: String representation of the playing card.
 *
 * Return: Numeric value of the card (ranging from 0 to 12).
 */
int get_val(const char *str)
{
	int n;
	char *array[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (n = 0; n < 13; n++)
		if (strcmp(str, array[n]) == 0)
			return (n);
	exit(1);
}

/**
 * swap_node - Exchange a node with the subsequent node in the linked list.
 *
 * @list: that is the Double Dointer to A Beginning of A List.
 * @node: that is the Node To Swap.
 */
void swap_node(deck_node_t **list, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * sort_deck - Arrange a deck of cards represented
 *	as a linked list in sorted order.
 *
 * @deck: that is Double Pointer to A Deck to Sort.
 */
void sort_deck(deck_node_t **deck)
{
	char swp = 1, v, p;
	deck_node_t *cur;

	if (!deck || !*deck || !(*deck)->next)
		return;

	cur = *deck;
	while (swp != 0)
	{
		swp = 0;
		while (cur->next)
		{
			v = get_val(cur->card->value) + 13 * cur->card->kind;
			p = get_val(cur->next->card->value) + 13 * cur->next->card->kind;
			if (v > p)
			{
				swap_node(deck, cur);
				swp = 1;
			}
			else
				cur = cur->next;
		}
		if (swp == 0)
			break;

		swp = 0;
		while (cur->prev)
		{
			v = get_val(cur->card->value) + 13 * cur->card->kind;
			p = get_val(cur->prev->card->value) + 13 * cur->prev->card->kind;
			if (v < p)
			{
				swap_node(deck, cur->prev);
				swp = 1;
			}
			else
				cur = cur->prev;
		}
	}
}
