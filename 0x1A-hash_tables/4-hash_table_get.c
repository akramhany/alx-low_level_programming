#include "hash_tables.h"

/**
* hash_table_get - takes a hash table and a key, returns cors value.
* @ht: the hash table.
* @key: the key.
* Return: value if found, NULL if not.
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *ptr = NULL;
	unsigned long int index = 0;

	if (ht == NULL)
		return (NULL);

	index = key_index((const unsigned char *) key, ht->size);

	if (ht->array[index] == NULL)
		return (NULL);

	ptr = ht->array[index];
	while (ptr)
	{
		if (strcmp(key, ptr->key) == 0)
		{
			return (ptr->value);
		}
		ptr = ptr->next;
	}

	return (NULL);
}
