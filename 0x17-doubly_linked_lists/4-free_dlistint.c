#include "lists.h"

/**
 * free_dlistint - frees a dlist.
 * @head: head of the dlist.
 * Return: void.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *ptr = head;

	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
