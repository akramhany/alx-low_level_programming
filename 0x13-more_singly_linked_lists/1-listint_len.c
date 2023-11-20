#include <stdio.h>
#include "lists.h"

/**
 * listint_len - count the number of nodes in a list
 * @h: head pointer of the list
 * Return: number of nodes in the list
 */

size_t listint_len(const listint_t *h)
{
	int numOfNodes = 0;

	while (h != NULL)
	{
		numOfNodes++;
		h = h->next;
	}

	return (numOfNodes);
}
