#include "sort.h"

/**
 * @brief Sorts a doubly linked list of integers using insertion sort.
 *
 * This function implements the insertion sort algorithm to sort a
 * doubly linked list of integers in ascending order.
 *
 * @param list A pointer to the doubly linked list to be sorted.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *prev, *next;

	if (!list || *list == NULL || (*list)->next == NULL)
		return;
	tmp = (*list)->next;
	while (tmp)
	{
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			prev = tmp->prev;
			next = tmp->next;
			if (prev)
				prev->next = next;
			if (next)
				next->prev = prev;
			tmp->prev = prev->prev;
			tmp->next = prev;
			prev->prev = tmp;
			if (tmp->prev)
				tmp->prev->next = tmp;
			else
				*list = tmp;
			if (next)
				next->prev = prev;
			print_list((const listint_t *)*list);
		}
		tmp = tmp->next;
	}
}