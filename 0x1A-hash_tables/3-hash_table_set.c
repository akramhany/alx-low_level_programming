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
	unsigned long int index = 0;
	hash_node_t *new_node = NULL;

	if (ht == NULL)
		return (0);

	index = key_index((const unsigned char *) key, ht->size);
	new_node = (hash_node_t *) malloc(sizeof(hash_node_t));

	if (new_node == NULL)
		return (0);

	new_node->key = (char *) malloc(strlen(key) + 1);
	new_node->value = (char *) malloc(strlen(value) + 1);

	if (new_node->key == NULL || new_node->value == NULL)
		return (0);

	strcpy(new_node->key, key);
	strcpy(new_node->value, value);

	handle_insert(ht, index, new_node, key);
	return (1);
}

/**
* handle_insert - takes a hash table, index and a node, then insert it into it
* @ht: the hash table.
* @index: index of the node.
* @new_node: node to insert.
* @key: key of the inserted value
* Return: void
*/
void handle_insert(hash_table_t *ht, unsigned long int index,
		   hash_node_t *new_node, const char *key)
{
	hash_node_t *ptr = NULL;

	ptr = ht->array[index];
	if (ptr == NULL)
	{
		ht->array[index] = new_node;
		new_node->next = NULL;
		return;
	}

	if (strcmp(ptr->key, key) == 0)
	{
		free(ptr);
		ht->array[index] = new_node;
		new_node->next = NULL;
		return;
	}

	while (ptr->next)
	{
		if (strcmp(ptr->next->key, key) == 0)
		{
			new_node->next = ptr->next->next;
			free(ptr->next);
			ptr->next = new_node;
			return;
		}
		ptr = ptr->next;
	}

	new_node->next = ht->array[index];
	ht->array[index] = new_node;
}
