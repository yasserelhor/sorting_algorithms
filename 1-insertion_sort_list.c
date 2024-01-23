#include "sort.h"

/**
 * insertion_sort_list - Organizes a doubly linked list of
 * integers in ascending order by
 * applying the Insertion Sort algorithm.
 * @list: Lista that need to be printed :)
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *previous, *next;

	if (!list || *list == NULL || (*list)->next == NULL)
		return;
	temp = (*list)->next;
	while (temp)
	{
		while (temp->prev && temp->n < temp->prev->n)
		{
			previous = temp->prev;
			next = temp->next;
			if (previous)
				previous->next = next;
			if (next)
				next->prev = previous;
			temp->prev = previous->prev;
			temp->next = previous;
			previous->prev = temp;
			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;
			if (next)
				next->prev = previous;
			print_list((const listint_t *)*list);
		}
		temp = temp->next;
	}
}
