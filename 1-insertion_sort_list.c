#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list,
 * of ints in ascending order using the Insertion sort algorithm.
 * @list: the list to sort.
 *
 * Return: a pointer to the head list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *next_node, *prev_node, *new_node;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	prev_node = (*list);
	current_node = (*list)->next;

	while (current_node)
	{
		new_node = current_node->next;

		while (prev_node != NULL && current_node->n < prev_node->n)
		{
			if (prev_node->prev)
				prev_node->prev->next = current_node;
			else
				*list = current_node;

			if (current_node->next)
				current_node->next->prev = prev_node;

			next_node = current_node->next;
			current_node->next = prev_node;
			current_node->prev = prev_node->prev;
			prev_node->next = next_node;
			prev_node->prev = current_node;
			print_list(*list);
			prev_node = current_node->prev;
		}

		current_node = new_node;

		if (current_node)
			prev_node = current_node->prev;
	}
}
