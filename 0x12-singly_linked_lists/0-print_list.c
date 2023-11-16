#include <stdio.h>
#include "lists.h"

/*
 * print_list - print all the elements in a given linked list
 * @h: the linked list
 * Return: the number of printed elements (nodes)
 **/

size_t print_list(const list_t *h)
{
	char *strNull = "[0] (nil)";
	list_t *ptr = h;
	int numOfNodes = 0;

	if (h == NULL)
	{
		return (0);
	}

	while (ptr != NULL)
	{
		if (ptr->str == NULL);
			printf("%s\n", strNull);
		else
		{
			printf("[%d] %s\n", ptr->len, ptr->str);
		}

		ptr = ptr->next;
		numOfNodes++;
	}

	return (numOfNodes);
}
