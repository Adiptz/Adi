/********************
*	Author: Adi    	*
*	Reviewer: Dor   *
*	Status : S		*
*********************/

#define MAX_CHILDREN 2

enum {NOT_AVAILABLE, AVAILABLE};

typedef struct trie_node trie_node_t;

struct trie_node
{
	trie_node_t *parent;
	trie_node_t *child[MAX_CHILDREN];
	int is_available;
};

/*****************************  CREATE and DESTROY ****************************/
trie_node_t *TrieCreateNode(trie_node_t *parent);

void TrieDestroy(trie_node_t *root);

/* nodes */
void TrieUpdateAvailabilityOfNodes(trie_node_t *node);

trie_node_t *TrieGetPathLeaf(const trie_node_t *root, size_t host_id_bytes, 
							  const unsigned char *path);

/* paths */
int TrieIsHostIDAvailable(const trie_node_t *root, size_t host_id_bytes, 
						  const unsigned char *host_id);

int TrieIsPathExist(const trie_node_t *root, size_t host_id_bytes, 
					const unsigned char *path);

int TrieUpdateNextAvailableHostID(const trie_node_t *root, size_t host_id_bytes, 	
						  		  unsigned char *new_host_id);
						  		  
int TrieAllocReqHostID(trie_node_t *root, const unsigned char *path, 
					   size_t host_id_bytes);

trie_node_t *TrieFreeNewPath(trie_node_t *node);
