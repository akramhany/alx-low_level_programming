#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table.
 * @ht: the hash table that would be deleted.
 * Return: void
*/
void hash_table_delete(hash_table_t *ht)
{
	unsigned int i = 0;

	if (ht == NULL)
		return;

	while (i < ht->size)
	{
		linked_list_delete(ht->array[i]);
		i++;
	}

	free(ht->array);
	free(ht);
}

/**
 * linked_list_delete - takes a head of a linked list and deletes it.
 * @ptr: it begin with the header.
 * Return: void.
*/
void linked_list_delete(hash_node_t *ptr)
{
	if (ptr == NULL)
		return;

	linked_list_delete(ptr->next);

	free(ptr->key);
	free(ptr->value);
	free(ptr);
}
