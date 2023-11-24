#include "main.h"

/**
 * clear_bit - a function that sets the value of a bit to 0 at a given index
 * @n: the number to set the bit on
 * @index: index of the bit
 * Return: 1 if success, -1 if not
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int number = 1, counter = index;

	if (index > 63)
		return (-1);

	while (counter-- > 0)
		number *= 2;

	number = ~number;

	*n = (*n) & number;

	return (1);
}
