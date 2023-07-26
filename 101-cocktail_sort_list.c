#include "sort.h"

/**
 * swap_nodes - a function that Swaps two nodes in a doubly linked list.
 * @list: the pointer to the head of the list.
 * @n1: the first node to swap
 * @n2: the cecond node to swap
 */
void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	listint_t *prev_node, *next_node;

	prev_node = n1->prev;
	next_node = n2->next;

	if (prev_node)
		prev_node->next = n2;
	else
		*list = n2;

	n1->prev = n2;
	n1->next = next_node;
	n2->prev = prev_node;
	n2->next = n1;

	if (next_node)
		next_node->prev = n1;
}

/**
 * cocktail_sort_list - a function that Sorts a doubly linked list,
 * using the Cocktail Shaker Sort algorithm.
 * @list: the pointer to the head of the list.
 *
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped;

	if (!list || !(*list) || !((*list)->next))
		return;

	do {
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
				current = current->prev;
			}
		}
		if (!swapped)
			break;
		swapped = 0;

		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
				current = current->next;
			}
		}
	} while (swapped);
}
