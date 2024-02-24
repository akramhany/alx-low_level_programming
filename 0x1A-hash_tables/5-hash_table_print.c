#include "hash_tables.h"

/**
 * hash_table_print - takes a hash table and print each key/value.
 * @ht: the hash table.
 * Return: void.
*/
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *ptr = NULL;
	unsigned int i = 0;
	char x = 0;

	if (ht == NULL)
		return;

	printf("{");
	while (i < ht->size)
	{
		ptr = ht->array[i];
		while (ptr)
		{
			if (x)
			{
				printf(", ");
			}
			printf("'%s': '%s'", ptr->key, ptr->value);
			ptr = ptr->next;
			x = 1;
		}
		i++;
	}

	printf("}\n");
}
