#include "lists.h"


/**
 * add_dnodeint - adds a node to a dlistint.
 * @head: head of the node.
 * @n: value stored in the node.
 * Return: pointer to the added node.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newNode = malloc(sizeof(dlistint_t));

	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	if (*head == NULL)
	{
		*head = newNode;
		return (newNode);
	}

	newNode->next = *head;
	*head = newNode;

	return (newNode);
}
