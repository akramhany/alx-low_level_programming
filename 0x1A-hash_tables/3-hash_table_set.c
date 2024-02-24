#include "hash_tables.h"

/**
 * hash_table_set - adds a value to a certain hash table.
 * @ht: the hash table to add into.
 * @key: the key to index the hash table.
 * @value: the value that would be stored.
 * Return: 1 if success, 0 if not.
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = key_index((const unsigned char *) key, ht->size);
	hash_node_t *new_node = (hash_node_t *) malloc(sizeof(hash_node_t));
	hash_node_t *ptr = NULL;

	if (new_node == NULL)
		return (0);

	new_node->key = (char *) malloc(strlen(key) + 1);
	new_node->value = (char *) malloc(strlen(value) + 1);

	if (new_node->key == NULL || new_node->value == NULL)
		return (0);

	strcpy(new_node->key, key);
	strcpy(new_node->value, value);

	ptr = ht->array[index];
	if (ptr == NULL)
	{
		ht->array[index] = new_node;
		new_node->next = NULL;
		return (1);
	}

	if (strcmp(ptr->key, key) == 0)
	{
		free(ptr);
		ht->array[index] = new_node;
		new_node->next = NULL;
		return (1);
	}

	while (ptr->next)
	{
		if (strcmp(ptr->next->key, key) == 0)
		{
			new_node->next = ptr->next->next;
			free(ptr->next);
			ptr->next = new_node;
			return (1);
		}
		ptr = ptr->next;
	}

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
