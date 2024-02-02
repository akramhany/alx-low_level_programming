#include "lists.h"

/**
 * sum_dlistint - return the sum of all numbers in the list.
 * @head: head of the list.
 * Return: the sum of all nums in the list.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
