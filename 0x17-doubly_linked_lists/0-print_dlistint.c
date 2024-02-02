#include "lists.h"

/**
 * print_dlistint - prints all elements of a doubly linked list.
 * @h: the d linked list.
 * Return: the number of nodes.
 */
size_t print_dlistint(const dlistint_t *h)
{
	int numOfNodes = 0;

	if (h == NULL)
	{
		return (0);
	}
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		numOfNodes++;
	}

	return (numOfNodes);
}
