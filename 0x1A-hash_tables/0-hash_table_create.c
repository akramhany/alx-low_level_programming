#include "hash_tables.h"

/**
* hash_table_create - creates a hash_table with a given size.
* @size: the size of the hash table.
* Return: pointer to the created hash_table
*/
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hs = (hash_table_t *) malloc(sizeof(hash_table_t));
	unsigned long int i = 0;

	if (hs == NULL)
		return (NULL);

	hs->size = size;
	hs->array = (hash_node_t **) malloc(sizeof(hash_node_t *) * size);

	if (hs->array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		hs->array[i] = NULL;
	}

	return (hs);
}
