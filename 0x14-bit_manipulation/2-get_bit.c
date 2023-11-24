#include "main.h"

/**
 * get_bit - returns the value of a bit at given index
 * @n: the number in which we would return the bit from
 * @index: index of the bit
 * Return: the value of the bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i;
	unsigned long int k = 1;

	k <<= 63;

	for (i = 0; i < 64; i++)
	{
		int c = (k & n) ? 1 : 0;

		n <<= 1;

		if (i == 63 - index)
			return (c);
	}

	return (-1);
}
