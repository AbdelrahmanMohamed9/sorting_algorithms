#include "sort.h"

/**
 * swap - that is the Swap the node with a next node in a list.
 *
 * @list: that is the double pointer to a beginning of a list.
 * @node: that is node to swap.
 */
void swap(listint_t **list, listint_t *node)
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
 * cocktail_sort_list - that is Sort the DL list of int in ascending order
 *                      using a Cocktail shaker sort algorithm.
 *
 * @list: that is the double pointer to a head of a doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	char v = 1;
	listint_t *tp;

	if (!list || !*list)
		return;

	tp = *list;
	while (v != 0)
	{
		v = 0;
		while (tp->next)
		{
			if (tp->next->n < tp->n)
			{
				swap(list, tp);
				v = 1;
				print_list(*list);
			}
			else
				tp = tp->next;
		}
		if (v == 0)
			break;
		v = 0;
		while (tp->prev)
		{
			if (tp->prev->n > tp->n)
			{
				swap(list, tp->prev);
				v = 1;
				print_list(*list);
			}
			else
				tp = tp->prev;
		}
	}
}
