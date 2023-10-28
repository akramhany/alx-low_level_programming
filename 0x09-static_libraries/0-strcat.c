#include "main.h"

/**
 * _strcat - a function that concatenates the src string with the dest
 * @dest: the destination string
 * @src: the source string
 * Return: char *
 */

char *_strcat(char *dest, char *src)
{
	int c_src = 0, c_dest = 0;

	while (dest[c_dest] != '\0')
	{
		c_dest++;
	}

	while (src[c_src] != '\0')
	{
		dest[c_dest++] = src[c_src];
		c_src++;
	}

	dest[c_dest] = '\0';
	return (dest);
}
