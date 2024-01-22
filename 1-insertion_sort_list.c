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
	listint_t *current, *previous, *new_node, *temporary;

	if (!list || !(*list) || !((*list)->next))
		return;

    /* Initialize dancers for the insertion sort dance */
	previous = (*list);
	current = (*list)->next;

	while (current)
	{
		new_node = current->next;
		while (previous && current->n < previous->n)
		{
			/* Swap positions of the current and previous dancers */
			if (previous->prev)
				previous->prev->next = current;
			else
				*list = current;
			if (current->next)
				current->next->prev = previous;
			temporary = current->next;
			current->next = previous;
			current->prev = previous->prev;
			previous->next = temporary;
			previous->prev = current;

			print_list(*list); // Display the sorted list after each swap

            /* Move to the next pair of dancers, flowing to the left */
			previous = current->prev;
		}
        /* Move to the next unsorted element on the right */
		current = new_node;
		if (current)
			previous = current->prev;
	}
}
