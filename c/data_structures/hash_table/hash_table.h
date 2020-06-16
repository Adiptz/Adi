/****************************************
 * Title       : Hash Table             *
 * Author      : Vladimir               *
 * Group       : OL712                  *
 * Version     : 1.2                    *
 * Last update : 29.09.2019 09:29       *
 ****************************************/
#ifndef __ILRD_HASH_TABLE_H
#define __ILRD_HASH_TABLE_H

#include <stddef.h> /* size_t */

typedef struct hash_table hash_table_t;

/*
 * Create hash table.
 * Param @hash_func: function for hashing data. Gets data, returns hash code.
 * Param @hash_cmp: function to compare data.
 * Param @num_buckets: number of buckets determined by hash function range.
 * Return: pointer to the created hash table.
 * Errors: if allocation is failed, returns NULL.
 */
hash_table_t *HashTableCreate(size_t num_of_buckets,
							  size_t (*hash_func)(void *data),
							  int (*hash_cmp_func)(const void *key1,
							  				  	   const void *key2));
/* 
 * Destroy the hash table.
 * Param @hash_table: pointer to the hash table.
 */
void HashTableDestroy(hash_table_t *hash_table);

/*
 * Insret data to the hash table.
 * Param @hash_table: pointer to the hash table.
 * Param @data: pointer to the data to insert.
 * Return: on success, 0 is returned.
 * Errors: if allocaition is failed, returns non-zero value.
 */
int HashTableInsert(hash_table_t *hash_table, void *data);

/*
 * Remove data from the hash table.
 * Param @hash_table: pointer to the hash table.
 * Param @data: data to remove.
 */
void HashTableRemove(hash_table_t *hash_table, void *data);

/*
 * Find data in the hash table.
 * Param @hash_table: pointer to the hash table.
 * Param @data: data to find.
 * Return: if data not found, NULL is returned, else poiter to the found data.
 */
void *HashTableFind(const hash_table_t *hash_table, void *data);

/*
 * Perform @act_func for each element in the hash table,
 * stops if action returns non-zero.
 * Param @hash_table: pointer to the hash table.
 * Param @act_func: function to perfom.
 * Return: on success, 0 is returned.
 * Errors: on fail, non-zero is returned.
 */
int HashTableForEach(const hash_table_t *hash_table,
					 int (*act_func)(void *table_data,
					 				 void *param),
					 				 void *param);

/*
 * Get size of the hash table.
 * Param @hash_table: pointer to the hash table.
 * Return: size of the hash table.
 */
size_t HashTableSize(const hash_table_t *hash_table);

/*
 * Check if hash table is empty.
 * Param @hash_table: pointer to the hash table.
 * Return: 1 if hash table is empty, 0 otherwise.
 */
int HashTableIsEmpty(const hash_table_t *hash_table);

#endif /* __ILRD_HASH_TABLE_H */

