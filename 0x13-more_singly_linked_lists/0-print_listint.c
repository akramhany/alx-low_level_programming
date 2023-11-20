#include <stdio.h>
#include "lists.h"

/**
 * print_listint - prints a list
 * @h: head pointer for the linked list
 * Return: the number nodes in the list
 */

size_t print_listint(const listint_t *h)
{
	int numOfNodes = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		numOfNodes++;
		h = h->next;
	}

	return (numOfNodes);
}
