#include <stdio.h>
#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list
 * @h: pointer to the list_t list
 *
 * Return: number of elements in h
 */

size_t list_len(const list_t *h)
{
	int lengthOfList = 0;

	while (h != NULL)
	{
		h = h->next;
		lengthOfList++;
	}

	return (lengthOfList);
}
