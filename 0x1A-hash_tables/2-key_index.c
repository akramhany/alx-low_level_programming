#include "hash_tables.h"

/**
* key_index - a function that gives you the index of a key.
* @key: the key in which i would hash into an index.
* @size: the size of the hash table.
* Return: the index of the key.
*/
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hashed_value = hash_djb2(key);

	return (hashed_value % size);
}
