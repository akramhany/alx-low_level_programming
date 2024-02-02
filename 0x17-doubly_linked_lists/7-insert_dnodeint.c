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

/**
 * insert_dnodeint_at_index - inserts a node at a given index.
 * @h: head of the llist.
 * @idx: index of the node.
 * @n: value stored in the node.
 * Return: pointer at the newly inserted node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	size_t lenOfList = dlistint_len(*h);
	dlistint_t *newNode = NULL, *ptr = NULL;

	if (idx > lenOfList)
		return (NULL);

	newNode = malloc(sizeof(dlistint_t));

	if (!newNode)
		return (NULL);

	newNode->n = n;
	if (*h == NULL)
	{
		(*h) = newNode;
		return (newNode);
	}

	if (idx == 0)
	{
		newNode->next = *h;
		(*h)->prev = newNode;
		*h = newNode;
		return (newNode);
	}

	ptr = *h;
	while (idx > 1)
	{
		ptr = ptr->next;
		idx--;
	}

	newNode->next = ptr->next;
	ptr->next = newNode;
	newNode->prev = ptr;
	if (newNode->next)
		newNode->next->prev = newNode;

	return (newNode);
}
