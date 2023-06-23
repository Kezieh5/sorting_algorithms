#include "sort.h"
/**
 * swap_list - function to help sort doubly-linked list.
 *@head: head of the list.
 *@nd1: first node to be swapped/sorted.
 *@nd2: second node to be swapped/sorted.
 * Return: void.
 */
void swap_list(listint_t **head, listint_t **nd1, listint_t *nd2)
{
	(*nd1)->next = nd2->next;
	if (nd2->next != NULL)
		nd2->next->prev = *nd1;
	nd2->prev = (*nd1)->prev;
	nd2->next = *nd1;
	if ((*nd1)->prev != NULL)
		(*nd1)->prev->next = nd2;
	else
		*head = nd2;
	(*nd1)->prev = nd2;
	*nd1 = nd2->prev;
}
/**
 * insertion_sort_list - sorts a double linked list with insertion method.
 *@list: list to be sorted.
 * Return: void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		listint_t *insert = current->prev;

		while (insert != NULL && current->n < insert->n)
		{
			if (insert->prev != NULL)
				insert->prev->next = current;
			else
				*list = current;

			if (current->next != NULL)
				current->next->prev = insert;

			insert->next = current->next;
			current->prev = insert->prev;
			insert->prev = current;
			current->next = insert;

			insert = current->prev;
			print_list((const listint_t *)*list);
		}

		current = current->next;
	}
}
