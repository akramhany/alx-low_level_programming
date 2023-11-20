#include <stdio.h>
#include "lists.h"

/**
 * print_listint - prints a list
 * @h: head pointer for the linked list
 * Return: the number nodes in the list
 */

size_t print_listint(const listint_t *h)
{
	listint_t *ptr = h;
	int numOfNodes = 0;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		numOfNodes++;
	}

	return (numOfNodes);
}
