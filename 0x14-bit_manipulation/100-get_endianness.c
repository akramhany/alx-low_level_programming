#include "main.h"
#include <stdio.h>

/**
 * get_endianness - gets the endianness of the machine
 * Return: 0 if its big endian, 1 if little endian
 */

int get_endianness(void)
{
	int x = 1;
	char *y = (char *)(&x);

	if (*y + 48 == '1')
		return (1);
	else
		return (0);
}
