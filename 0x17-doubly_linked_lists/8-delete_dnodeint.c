#include "lists.h"



/**
 * dlistint_len - return the number of nodes in a dlinked list.
 * @head: head of the dlinked list.
 * Return: num of nodes.
 */
size_t dlistint_len(const dlistint_t *head)
{
	int numOfNodes = 0;

	while (head)
	{
		head = head->next;
		numOfNodes++;
	}

	return (numOfNodes);
}

/**
 * delete_dnodeint_at_index - delets a node at a given index.
 * @head: head of the llist.
 * @index: index of the node.
 * Return: 1 if succeeded, -1 if failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	size_t lenOfList = dlistint_len(*head);
	dlistint_t *ptr = NULL, *temp = NULL;

	if (index >= lenOfList)
		return (-1);

	if (*head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		temp = (*head);
		(*head) = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		temp->next = NULL;
		free(temp);
		return (1);
	}

	ptr = *head;
	while (index > 0)
	{
		ptr = ptr->next;
		index--;
	}

	temp = ptr->prev;
	temp->next = ptr->next;
	if (ptr->next)
		ptr->next->prev = temp;
	ptr->next = NULL, ptr->prev = NULL;
	free(ptr);

	return (1);
}
