#include "main.h"

/**
 * flip_bits - returns number of bits to flip to get from n to m
 * @n: the first number
 * @m: the second number
 * Return: the number of bits to flip
 **/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int number = n ^ m, k = 1;
	unsigned int numberBitsFlip = 0, i = 0;

	k <<= 63;

	for (i = 0; i < 64; i++)
	{
		int curBitV = (number & k) ? 1 : 0;

		if (curBitV == 1)
			numberBitsFlip++;

		number <<= 1;
	}

	return (numberBitsFlip);
}
