/************************************
*	Author: Daya					*
*	Reviewer: 					*
*	Status : 						*
*************************************/
#ifndef ILRD_TRIE_H
#define ILRD_TRIE_H

#include <assert.h> /* assert */
#include <stdlib.h> /* malloc, free */
#include <limits.h> /* CHAR_BIT, UCHAR_MAX */
#include <string.h> /* memcpy */
#include <math.h>   /* pow */


/******************************
******* define & typedef ******
******************************/
#define MAX_CHILDREN 2

/*TODO add const in static functions*/

/***************************
***** enum declarations ****
***************************/
enum {NOT_AVAILABLE, AVAILABLE};
enum {LEFT, RIGHT};

/***************************
*** structs declarations ***
***************************/

typedef struct trie_node trie_node_t;

struct trie_node
{
	trie_node_t *parent;
	trie_node_t *child[MAX_CHILDREN];
	int is_available;
};

/*****************************************************
****** forward declarations - service functions ******
*****************************************************/
/******************************************************************************/
/********************************* DHCPCreate *********************************/
/******************************************************************************/
static trie_node_t *TrieCreateNode(trie_node_t *parent);
static void *FreeAndNULL(void *pointer_to_free);

static void InitReserveIP(unsigned char req_last_ip[BYTES_IN_IP], 
					      unsigned char req_before_last_ip[BYTES_IN_IP], 
				   		  unsigned char req_first_ip[BYTES_IN_IP],
				   		  const unsigned char net_id[BYTES_IN_IP],
				   		  size_t net_id_bytes);

static int AllocReserveIP(unsigned char req_last_ip[BYTES_IN_IP], 
				   unsigned char req_before_last_ip[BYTES_IN_IP], 
				   unsigned char req_first_ip[BYTES_IN_IP], 
				   dhcp_t *new_dhcp);




/******************************************************************************/
/******************************** DHCPDestroy *********************************/
/******************************************************************************/
static void TrieDestroy(trie_node_t *root);

/******************************************************************************/
/********************************* DHCPLease **********************************/
/******************************************************************************/
static int IsSameNetID(size_t net_id_bytes, const unsigned char *req_ip, 
					   const unsigned char *net_id);
static int IsHostIDAvailable(trie_node_t *root, size_t host_id_bytes, 
						 	 const unsigned char *host_id);
static int TrieIsPathExist(trie_node_t *root, size_t host_id_bytes, 
						   const unsigned char *path);
static int TrieAllocReqHostID(trie_node_t *root, const unsigned char *path, 
							  size_t host_id_bytes);
static trie_node_t *TrieFreeNewPath(trie_node_t *node);						   
static int GetChildDirection(const trie_node_t *child);
static int IsLeaf(trie_node_t *node);
static void UpdateNotAvailabilityOfNodes(trie_node_t *node);
static int HasTwoChildren(trie_node_t *node);
static int IsChildrenNotAvailable(trie_node_t *node);
static int UpdateNextAvailableHostID(trie_node_t *root, size_t host_id_bytes, 	
						  			 unsigned char *new_host_id);
						  			 
/******************************************************************************/
/******************************** DHCPRelease *********************************/
/******************************************************************************/
static trie_node_t *GoToPathLeaf(trie_node_t *root, size_t host_id_bytes, 
								 const unsigned char *path);
static int IsReservedHostIP(const unsigned char *host_id_to_release, 
							unsigned char *net_id, size_t net_id_bytes);
static void UpdateAvailabilityOfNodes(trie_node_t *node);

#endif /*ILRD_TRIE_H*/

