#include <assert.h> /* assert */
#include <stdlib.h> /* free */
#include <stdio.h> /* printf */

#include "hash_table.h"

#define UNUSED(x) ((void)x)

static size_t HashFunc(void *key)
{
	return (size_t)(*(unsigned char *)key);
}

static int HashCmp(const void *key1, const void *key2)
{
	return strcmp(key1, key2);
}

static int PrintForEach(void *table_data, void *param)
{
	UNUSED(param);
	puts((char *)table_data);
	return 0;
}

static int FreeForEach(void *table_data, void *param)
{
	UNUSED(param);
	free(table_data);
	return 0;
}

static void CreateDestroy_test();
static void Insert_Size_test();
static void Remove_test();
static void ForEach_test();
static void Find_test();
static void Dictionary();

int main()
{
	CreateDestroy_test();
	Insert_Size_test();	
	Remove_test();
	ForEach_test();
	Find_test();
	Dictionary();
	
	return 0; 
}		


static void CreateDestroy_test()
{
	hash_table_t *hash_table = HashTableCreate(256, HashFunc, HashCmp);
	
	assert(NULL != hash_table);
	assert(1 == HashTableIsEmpty(hash_table));
	
	HashTableDestroy(hash_table);
}

static void Insert_Size_test()
{
	char *str = NULL;
	hash_table_t *hash_table = HashTableCreate(256, HashFunc, HashCmp);
	assert(NULL != hash_table);
	
	assert(1 == HashTableIsEmpty(hash_table));

	str = "a";
	assert(0 == HashTableInsert(hash_table, str));
	assert(1 == HashTableSize(hash_table));
	
	str = "b";
	assert(0 == HashTableInsert(hash_table, str));
	assert(2 == HashTableSize(hash_table));
	
	str = "c";
	assert(0 == HashTableInsert(hash_table, str));
	assert(3 == HashTableSize(hash_table));

	str = "d";
	assert(0 == HashTableInsert(hash_table, str));
	assert(4 == HashTableSize(hash_table));

	str = "e";
	assert(0 == HashTableInsert(hash_table, str));
	assert(5 == HashTableSize(hash_table));

	str = "f";
	assert(0 == HashTableInsert(hash_table, str));
	assert(6 == HashTableSize(hash_table));
	
	assert(0 == HashTableIsEmpty(hash_table));

	UNUSED(str);

	HashTableDestroy(hash_table);	
}

static void Remove_test()
{
	int i = 0, status = 0;
	char *str[] = {"a", "b", "c", "d"};
	char *not_find = "hello";
	hash_table_t *hash_table = HashTableCreate(256, HashFunc, HashCmp);
	
	assert(NULL != hash_table);
	assert(1 == HashTableIsEmpty(hash_table));

	for (i = 0; i < 4 && 0 == status; ++i)
	{
		status = HashTableInsert(hash_table, str[i]);
	}

	assert(4 == HashTableSize(hash_table));	
	assert(0 == HashTableIsEmpty(hash_table));

	for (i = 0; i < 4; ++i)
	{
		HashTableRemove(hash_table, str[i]);
	}

	HashTableRemove(hash_table, &not_find);
	
	assert(1 == HashTableIsEmpty(hash_table));

	HashTableDestroy(hash_table);	
}

static void ForEach_test()
{
	char *str1 = "a", *str2 = "b", *str3 = "c", *str4 = "d";
	hash_table_t *hash_table = HashTableCreate(256, HashFunc, HashCmp);
	
	assert(NULL != hash_table);
	assert(1 == HashTableIsEmpty(hash_table));

	HashTableInsert(hash_table, str1);
	HashTableInsert(hash_table, str2);
	HashTableInsert(hash_table, str3);
	HashTableInsert(hash_table, str4);
	
	assert(4 == HashTableSize(hash_table));
	assert(0 == HashTableIsEmpty(hash_table));

	HashTableForEach(hash_table, PrintForEach, NULL);

	HashTableDestroy(hash_table);	
}

static void Find_test()
{
	int i = 0, status = 0;
	char *str[] = {"a", "b", "c", "d"};
	char *not_find = "hello";
	hash_table_t *hash_table = HashTableCreate(256, HashFunc, HashCmp);
	
	assert(NULL != hash_table);
	assert(1 == HashTableIsEmpty(hash_table));

	for (i = 0; i < 4 && 0 == status; ++i)
	{
		status = HashTableInsert(hash_table, str[i]);
	}
	
	assert('b' == *(char *)HashTableFind(hash_table, str[1]));
	assert('c' == *(char *)HashTableFind(hash_table, str[2]));
	
	assert(NULL == HashTableFind(hash_table, &not_find));

	UNUSED(not_find);
	
	HashTableDestroy(hash_table);		
}

static void Dictionary()
{
	char str[50] = "";
	char *found = NULL;
	char *to_find = NULL;
	char *to_remove = NULL;
	void *str_to_insert = NULL;
	char *zoo = "zoo";
	hash_table_t *hash_table = HashTableCreate(256, HashFunc, HashCmp);

	FILE *file = fopen("/usr/share/dict/words", "r");
	if (NULL == file)
	{
		return;
	}

	while (1 == fscanf(file, "%50s", str))
	{
		size_t len = (strlen(str) + 1) * sizeof(char);
		str_to_insert = (char *)malloc(len);
		memcpy(str_to_insert, str, len);
		HashTableInsert(hash_table, str_to_insert);
	}	

		assert(NULL == HashTableFind(hash_table, &zoo));
	
	UNUSED(found);

	fclose(file);
	HashTableForEach(hash_table, FreeForEach, NULL);
	HashTableDestroy(hash_table);	
}
