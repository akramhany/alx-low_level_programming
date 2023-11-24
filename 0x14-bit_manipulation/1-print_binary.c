#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number
 * Return: void
 */

void print_binary(unsigned long int n)
{
	int leadingZero = 1;
	int i;
	unsigned long int k = (unsigned long int) 1 << 63;

	for (i = 0; i < 64; i++)
	{
		char c = (k & n) ? '1' : '0';

		n <<= 1;

		if (c == '0' && leadingZero)
			continue;

		leadingZero = 0;
		_putchar(c);
	}

	if (leadingZero)
		_putchar('0');
}
