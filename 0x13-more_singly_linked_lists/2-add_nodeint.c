#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - add a new node at the beginning of a linked list
 * @head: the head of the linked list
 * @n: the value that would be stored in the new node
 * Return: address of the new node
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newNodePtr = NULL;

	newNodePtr = malloc(sizeof(listint_t));

	if (newNodePtr == NULL)
		return (NULL);

	newNodePtr->n = n;
	newNodePtr->next = (*head);
	(*head) = newNodePtr;

	return (*head);
}
