#include "lists.h"

/**
 * dlistint_len - return the number of nodes in a dlinked list.
 * @h: head of the dlinked list.
 * Return: num of nodes.
 */
size_t dlistint_len(const dlistint_t *h)
{
	int numOfNodes = 0;

	while (h)
	{
		h = h->next;
		numOfNodes++;
	}

	return (numOfNodes);
}
