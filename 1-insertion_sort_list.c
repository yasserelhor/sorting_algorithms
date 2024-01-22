#include "sort.h"

/*
 * insertion_sort_list - Sorts a doubly linked list of integers using the
 *                       insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 *
 * This function sorts a doubly linked list in ascending order using the
 * insertion sort algorithm. It iterates through the list, comparing each
 * element with its predecessors, and reorders them accordingly.
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
