#include "lists.h"


/**
 * add_dnodeint_end - adds a node to a dlistint.
 * @head: head of the node.
 * @n: value stored in the node.
 * Return: pointer to the added node.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newNode = malloc(sizeof(dlistint_t));
	dlistint_t *ptr = NULL;

	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	if (*head == NULL)
	{
		*head = newNode;
		return (newNode);
	}

	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;

	ptr->next = newNode;
	newNode->prev = ptr;

	return (newNode);
}
