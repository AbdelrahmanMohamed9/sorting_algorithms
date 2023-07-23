#include "sort.h"

/**
 * insertion_sort_list - Rearrange a doubly linked list of integers
 *	in ascending order by applying the Insertion Sort algorithm.
 * @list: Reference to the linked list of integers that needs to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pr, *tp;

	if (!list || !*list)
		return;

	pr = (*list)->next;
	while (pr)
	{
		tp = pr->next;
		while (pr->prev && pr->prev->n > pr->n)
		{
			pr->prev->next = pr->next;
			if (pr->next)
				pr->next->prev = pr->prev;

			pr->next = pr->prev;
			pr->prev = pr->next->prev;
			pr->next->prev = pr;
			if (!pr->prev)
				*list = pr;
			else
				pr->prev->next = pr;
			print_list(*list);
		}
		pr = tp;
	}
}
