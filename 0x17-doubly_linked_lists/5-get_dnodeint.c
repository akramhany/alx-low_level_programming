#include "lists.h"

/**
 * get_dnodeint_at_index - gets the node at a certain index.
 * @head: head of the dlinked list.
 * @index: index of the node.
 * Return: pointer at the node.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *ptr = head;

	while (index > 0 && ptr)
	{
		ptr = ptr->next;
		index--;
	}

	return (ptr);
}
