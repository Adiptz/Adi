
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */

#include "hash_table.h"
#include "dlist.h"

enum ret_val {SUCCESS, FAIL};

typedef size_t(*hash_func_t)(void *data);

typedef int(*cmp_func_t)(const void *key1, const void *key2);

typedef	int(*act_func)(void *table_data, void *param);

struct hash_table
{
	dlist_t **buckets;
	size_t num_of_buckets;
	hash_func_t hash_func;
	cmp_func_t cmp_func;
};

static dlist_iter_t FindIter(const hash_table_t *hash_table, void *data);

/******************************* -- CREATE -- *********************************/
hash_table_t *HashTableCreate(size_t num_of_buckets,
							  hash_func_t hash_func, 
							  cmp_func_t cmp_func)
{
	int i = 0;
	hash_table_t *hash_table = NULL;
	
	assert(0 < num_of_buckets);
	assert(NULL != hash_func);
	assert(NULL != cmp_func);
	
	hash_table = (hash_table_t *)malloc(sizeof(hash_table_t));
	if (NULL == hash_table)
	{
		return NULL;
	}	
	
	hash_table->buckets = (dlist_t **)malloc(sizeof(dlist_t *) *
											                    num_of_buckets);
	if(NULL == hash_table)
	{
		free(hash_table); hash_table = NULL;
		return NULL;	
	}

	/* put dlists pointers into buckets */
	for (i = 0; (size_t)i < num_of_buckets; ++i)
	{
		hash_table->buckets[i] = DListCreate();
		
		if (NULL == hash_table->buckets[i])
		{ 
			for (i -= 1; 0 <= i; --i)
			{
				DListDestroy(hash_table->buckets[i]);
			}
			
			free(hash_table); hash_table = NULL;
			free(hash_table->buckets); hash_table->buckets = NULL;
			return NULL;
		}
	}
	
	hash_table->cmp_func = cmp_func;
	hash_table->hash_func = hash_func;
	hash_table->num_of_buckets =  num_of_buckets;   

	return hash_table;
}

/******************************* -- DESTROY -- ********************************/
void HashTableDestroy(hash_table_t *hash_table)
{
	size_t i = 0;
	
	assert(NULL != hash_table);

	for (i = 0; i < hash_table->num_of_buckets; ++i)
	{
		DListDestroy(hash_table->buckets[i]);
	}
	
	free(hash_table->buckets); hash_table->buckets = NULL;
	free(hash_table); hash_table = NULL;	
}

/******************************* -- INSERT -- *********************************/
int HashTableInsert(hash_table_t *hash_table, void *data)
{
	size_t hash_value = 0;
	dlist_iter_t end = NULL;
	dlist_iter_t insert = NULL;

	assert(NULL != data);
	assert(NULL != hash_table);
	
	hash_value = hash_table->hash_func(data);
	end = DListEnd(hash_table->buckets[hash_value]);
	
	insert = DListPushBack(hash_table->buckets[hash_value], data);
	if (DListIsSameIter(insert, end))
	{
		return FAIL;
	}	
	
	return SUCCESS; 
}

/******************************* -- REMOVE -- *********************************/
void HashTableRemove(hash_table_t *hash_table, void *data)
{
	dlist_iter_t found = NULL;

	assert(NULL != hash_table);

	found = FindIter(hash_table, data); 
	if (NULL != found) 
	{
		DListRemove(found);
	}	
}

static dlist_iter_t FindIter(const hash_table_t *hash_table, void *data)
{
	dlist_t *dlist = NULL;
	dlist_iter_t end = NULL;
	dlist_iter_t begin = NULL;
	dlist_iter_t found = NULL;

	assert(NULL != hash_table);
	
	dlist = hash_table->buckets[hash_table->hash_func(data)];
	begin = DListBegin(dlist);
	end = DListEnd(dlist);
	found = DListFind(begin, end, (cmp_func)hash_table->cmp_func, data);

	return DListIsSameIter(found, end) ? NULL : found;
}

/******************************** -- FIND -- **********************************/
void *HashTableFind(const hash_table_t *hash_table, void *data)
{
	size_t hash_value = 0;
	dlist_iter_t begin = NULL;
	dlist_iter_t end = NULL;
	dlist_iter_t found = NULL;
	
	assert(NULL != hash_table);
	
	hash_value = hash_table->hash_func(data);
	begin = DListBegin(hash_table->buckets[hash_value]);
	end = DListEnd(hash_table->buckets[hash_value]);
	found = DListFind(begin, end, (cmp_func)hash_table->cmp_func, data);
										  
	if (DListIsSameIter(end, found))
	{
		return NULL;
	}
	
	return DListIterGetData(found);	
}

/****************************** -- FOR EACH -- ********************************/
int HashTableForEach(const hash_table_t *hash_table,
					 act_func act_func, void *param)
{
	size_t i = 0;
	int act_func_ret_val = SUCCESS; 
	
	assert(NULL != hash_table);
	
	for ( i = 0
		; i < hash_table->num_of_buckets
		  && SUCCESS == act_func_ret_val
		; ++i)
	{
		dlist_iter_t begin = DListBegin(hash_table->buckets[i]);
		dlist_iter_t end = DListEnd(hash_table->buckets[i]);	
	
		act_func_ret_val = DListForEach(begin, end, act_func, param);
	}

	return act_func_ret_val;
}

/******************************** -- SIZE -- **********************************/
size_t HashTableSize(const hash_table_t *hash_table)
{
	size_t i = 0;
	size_t hash_table_size = 0;
	
	assert(NULL != hash_table);
	   
	for (i = 0; i < hash_table->num_of_buckets; ++i)
	{
		hash_table_size += DListSize(hash_table->buckets[i]);
	}
	
	return hash_table_size;
}

/******************************* -- IS EMPTY -- *******************************/
int HashTableIsEmpty(const hash_table_t *hash_table)
{
	size_t i = 0; 
	
	assert(NULL != hash_table);
	 
	for (i = 0; i < hash_table->num_of_buckets; ++i)
	{
		if (!DListIsEmpty(hash_table->buckets[i]))
		{
			return 0;
		}
	}
	
	return 1;	
}		  				  	 
