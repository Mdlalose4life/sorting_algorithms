#include "sort.h"
/**
 * swap - swaps the nodes of a doubly linked list.
 * @node1: first node to be swapped.
 * @node2: sirst node to be swapped.
 * Return: void
 */
void swap(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list -  sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: Pinter to a linked list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *trev, *put, *temp;
	if (list == NULL || *list == NULL||(*list)->next == NULL)
		return;
	for (trev = (*list)->next; trev != NULL; trev = temp)
	{
		temp = trev->next;
		put = trev->prev;
		while (put != NULL && trev->n < put->n)
		{
			swap(list, &put, trev);
			print_list((const listint_t *)*list);
		}
	}
}
























