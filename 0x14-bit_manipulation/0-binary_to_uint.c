#include "main.h"

/**
 * binary_to_uint - converts binary number to an unsigned int
 * @b: the binary number in a form of a string
 * Return: the converted number or 0
 */

unsigned int binary_to_uint(const char *b)
{
	int len = 0, i, unsignedInt = 0;

	if (b == NULL)
		return (0);

	while (b[len] != '\0')
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
		len++;
	}

	for (i = 0; i < len; i++)
	{
		int counter = len - i - 1, temp = 1;

		if (b[i] == '0')
			continue;

		while (counter--)
		{
			temp *= 2;
		}

		unsignedInt += temp;
	}

	return (unsignedInt);
}
