/********************
*	Author: Adi    	*
*	Reviewer: Dor   *
*	Status : S		*
*********************/

#include <assert.h> /* assert */
#include <stdlib.h> /* malloc, free */
#include <limits.h> /* CHAR_BIT, UCHAR_MAX */
#include <string.h> /* memcpy */

#include "dhcp.h"   /* dhcp_funcs */
#include "trie.h"   /* trie funcs */

struct dhcp
{
	trie_node_t *root;
	size_t available_ip_adresses;
	size_t host_id_bits;
	unsigned char net_id[BYTES_IN_IP];
};

/*****************************
 **** service functions ******
 *****************************/

/* initials */
static int InitDhpcStruct(dhcp_t *new_dhcp,
						  size_t net_id_bits, 
						  const unsigned char *net_id);
static void InitReserveIP(unsigned char *req_last_ip, 
					      unsigned char *req_before_last_ip, 
				   		  unsigned char *req_first_ip,
				   		  const unsigned char *net_id,
				   		  size_t net_id_bytes);
				   		  

/* aloc and realese ip */							
static int AllocReserveIP(const unsigned char *net_id,
			              size_t net_id_bits, 
						  dhcp_t *new_dhcp);
static int AllocReqIP(const unsigned char *req_ip,
					  unsigned char *alloc_ip,
					  dhcp_t *dhcp,
					  size_t host_id_bytes);
static int AllocNewIP(const unsigned char *req_ip,
					  unsigned char *alloc_ip,
					  dhcp_t *dhcp,
					  size_t host_id_bytes);
static int ReleaseIP(dhcp_t *dhcp,
					 size_t host_id_bytes, 
				     const unsigned char *ip_to_release);
				  
/* chekcing */
static int IsSameNetID(size_t net_id_bytes,
					   const unsigned char *req_ip, 
					   const unsigned char *net_id);
static int IsReservedHostIP(const unsigned char *host_id_to_release, 
							const unsigned char *net_id,
							size_t net_id_bytes);

/*others */
static void *FreeAndNULL(void *pointer_to_free);


/******************************** -- CREATE -- ********************************/
dhcp_t *DHCPCreate(unsigned char net_id[BYTES_IN_IP],
				   size_t net_id_bits)
{
	dhcp_t *new_dhcp = NULL;
	int alloc_status = 0;
	int init_dhcp_status = 0;
	
	assert(NULL != net_id);
	
	new_dhcp = (dhcp_t *)malloc(sizeof(dhcp_t));
	if (NULL == new_dhcp)
	{
		return NULL;
	}

	init_dhcp_status = InitDhpcStruct(new_dhcp, net_id_bits, net_id);
	if (FAIL == init_dhcp_status)
	{
		new_dhcp = FreeAndNULL(new_dhcp);
		return NULL;
	}
				  
	alloc_status = AllocReserveIP(net_id, net_id_bits, new_dhcp);
	if (FAIL == alloc_status)
	{
		DHCPDestroy(new_dhcp);
		return NULL;
	}
	
	return new_dhcp;
}

static int InitDhpcStruct(dhcp_t *new_dhcp, size_t net_id_bits, 
						  const unsigned char *net_id)
{
	assert(NULL != new_dhcp);
	assert(NULL != net_id);
		
	new_dhcp->root = TrieCreateNode(NULL);
	if (NULL == new_dhcp->root)
	{
		return FAIL;
	}
	
	new_dhcp->host_id_bits = BYTES_IN_IP * CHAR_BIT - net_id_bits;
	new_dhcp->available_ip_adresses = 1 << new_dhcp->host_id_bits;
	memcpy(new_dhcp->net_id , net_id, net_id_bits / CHAR_BIT);
	
	return SUCCESS;
}

static void *FreeAndNULL(void *pointer_to_free)
{
	free(pointer_to_free);
	return NULL;
}

static int AllocReserveIP(const unsigned char *net_id, size_t net_id_bits, 
						  dhcp_t *dhcp)
{
	int lease_status = 0;
	unsigned char req_last_ip[BYTES_IN_IP] = {0};
	unsigned char req_before_last_ip[BYTES_IN_IP] = {0};
	unsigned char req_first_ip[BYTES_IN_IP] = {0};
	
	assert(NULL != net_id);
	assert(NULL != dhcp);
	
	InitReserveIP(req_last_ip, req_before_last_ip, req_first_ip, net_id, 
				  net_id_bits / CHAR_BIT);
				  	
	lease_status = DHCPLease(dhcp, req_last_ip, req_last_ip);
	if (FAIL == lease_status)
	{
		return FAIL;
	}

	lease_status = DHCPLease(dhcp, req_before_last_ip, req_before_last_ip);
	if (FAIL == lease_status)
	{
		return FAIL;
	}

	lease_status = DHCPLease(dhcp, req_first_ip, req_first_ip);
	if (FAIL == lease_status)
	{
		return FAIL;
	}
	
	return SUCCESS;
}

static void InitReserveIP(unsigned char *req_last_ip, 
				   		  unsigned char *req_before_last_ip, 
				   		  unsigned char *req_first_ip,
				   		  const unsigned char *net_id,
				   		  size_t net_id_bytes)
{
	size_t i = 0;
	
	assert(NULL != req_last_ip);
	assert(NULL != req_before_last_ip);
	assert(NULL != req_first_ip);
	assert(NULL != net_id);
	
	/*copying net_id to reserved IPs*/
	for (i = 0; i < net_id_bytes; ++i)
	{
		req_last_ip[i] = net_id[i];
		req_before_last_ip[i] = net_id[i];
		req_first_ip[i] = net_id[i];
	}
	
	/*fill host id of reserved IPs*/
	for (i = i; i < BYTES_IN_IP; ++i)
	{
		req_last_ip[i] = UCHAR_MAX;
		req_before_last_ip[i] = UCHAR_MAX;
		req_first_ip[i] = 0;		
	}
	
	req_before_last_ip[BYTES_IN_IP - 1] = UCHAR_MAX - 1; 
}

/******************************* -- DESTROY -- ********************************/
void DHCPDestroy(dhcp_t *dhcp)
{
	assert(NULL != dhcp);
	
	TrieDestroy(dhcp->root); dhcp->root = NULL;
	dhcp = FreeAndNULL(dhcp);
}

/******************************** -- LEASE -- *********************************/
dhcp_status_t DHCPLease(dhcp_t *dhcp, const unsigned char req_ip[BYTES_IN_IP],
						unsigned char alloc_ip[BYTES_IN_IP])
{
	size_t net_id_bytes = 0;
	size_t host_id_bytes = 0;

	assert(NULL != dhcp);
	assert(NULL != req_ip);
	assert(NULL != alloc_ip);
	
	net_id_bytes = ((CHAR_BIT * BYTES_IN_IP) - dhcp->host_id_bits) / CHAR_BIT;
	host_id_bytes = BYTES_IN_IP - net_id_bytes;
	
	if (!IsSameNetID(net_id_bytes, req_ip, dhcp->net_id))
	{
		return INVALID_REQUEST;
	}
	
	if (TrieIsHostIDAvailable(dhcp->root, host_id_bytes, &req_ip[net_id_bytes]))
	{
		return AllocReqIP(req_ip, alloc_ip, dhcp, host_id_bytes);
	}
	
	return AllocNewIP(req_ip, alloc_ip, dhcp, host_id_bytes);
}

static int IsSameNetID(size_t net_id_bytes, const unsigned char *req_ip, 
					   const unsigned char *net_id)
{	
	assert(NULL != req_ip);
	assert(NULL != net_id);
	assert(0 < net_id_bytes);
	
	return !(memcmp(req_ip, net_id, sizeof(unsigned char) * net_id_bytes));
}

static int AllocReqIP(const unsigned char *req_ip, unsigned char *alloc_ip,
					  dhcp_t *dhcp, size_t host_id_bytes)
{
	int alloc_req_status = 0;
	size_t net_id_bytes = BYTES_IN_IP - host_id_bytes;
	
	assert(NULL != req_ip);
	assert(NULL != alloc_ip);
	assert(NULL != dhcp);
	
	alloc_req_status = TrieAllocReqHostID(dhcp->root, &req_ip[net_id_bytes], 
										  host_id_bytes);
	if (FAIL == alloc_req_status)
	{
		return FAIL;
	}
	
	memcpy(alloc_ip, req_ip, sizeof(unsigned char) * BYTES_IN_IP);
	
	--dhcp->available_ip_adresses;
	return SUCCESS;
}

static int AllocNewIP(const unsigned char *req_ip, unsigned char *alloc_ip,
					  dhcp_t *dhcp, size_t host_id_bytes)
{
	unsigned char *new_req_ip = NULL;
	int update_host_id_status = 0;
	int alloc_req_status = 0;
	size_t net_id_bytes = BYTES_IN_IP - host_id_bytes;
	
	assert(NULL != req_ip);
	assert(NULL != alloc_ip);
	assert(NULL != dhcp);
	
	new_req_ip = (unsigned char *)calloc(BYTES_IN_IP, sizeof(unsigned char));
	if (NULL == new_req_ip)
	{
		return FAIL;
	}
	
	update_host_id_status = TrieUpdateNextAvailableHostID(dhcp->root, 
														  host_id_bytes,
													      &new_req_ip
													      [net_id_bytes]);
	if (FAIL == update_host_id_status)
	{
		new_req_ip = FreeAndNULL(new_req_ip);
		return FAIL;
	}
	
	alloc_req_status = TrieAllocReqHostID(dhcp->root, &new_req_ip[net_id_bytes], 
										  host_id_bytes);
	if (FAIL == alloc_req_status)
	{
		new_req_ip = FreeAndNULL(new_req_ip);
		return FAIL;
	}
	
	/*copy net_id*/
	memcpy(alloc_ip, req_ip, sizeof(unsigned char) * net_id_bytes);
	/*copy host_id*/
	memcpy(&alloc_ip[net_id_bytes], &new_req_ip[net_id_bytes], 
		   sizeof(unsigned char) * host_id_bytes);
		   
	new_req_ip = FreeAndNULL(new_req_ip);
	
	--dhcp->available_ip_adresses;
	return SUCCESS;
}


/****************************** -- RELEASE -- *********************************/
dhcp_status_t DHCPRelease(dhcp_t *dhcp, 
						  const unsigned char ip_to_release[BYTES_IN_IP])
{
	size_t net_id_bytes = 0;
	size_t host_id_bytes = 0;
	
	assert(NULL != dhcp);
	assert(NULL != ip_to_release);
	
	net_id_bytes = BYTES_IN_IP - (dhcp->host_id_bits / CHAR_BIT);
	host_id_bytes = BYTES_IN_IP - net_id_bytes;
	
	if (!IsSameNetID(net_id_bytes, ip_to_release, dhcp->net_id))
	{
		return INVALID_REQUEST;
	}
	
	if (IsReservedHostIP(&ip_to_release[net_id_bytes], 
						 dhcp->net_id, net_id_bytes))
	{
		return INVALID_REQUEST;
	}
	
	if (TrieIsPathExist(dhcp->root, dhcp->host_id_bits / CHAR_BIT,
					&ip_to_release[net_id_bytes]))
	{
		return ReleaseIP(dhcp, host_id_bytes, ip_to_release);
	}
	
	return INVALID_REQUEST;
}

static int IsReservedHostIP(const unsigned char *host_id_to_release, 
							const unsigned char *net_id, size_t net_id_bytes)
{
	unsigned char req_last_ip[BYTES_IN_IP] = {0};
	unsigned char req_before_last_ip[BYTES_IN_IP] = {0};
	unsigned char req_first_ip[BYTES_IN_IP] = {0};
	
	assert(NULL != host_id_to_release);
	assert(NULL != net_id);
	
	InitReserveIP(req_last_ip, req_before_last_ip, req_first_ip, net_id, 
				  net_id_bytes);
	
	if (0 == memcmp(&req_last_ip[net_id_bytes], host_id_to_release, 
					BYTES_IN_IP - net_id_bytes))
	{
		return 1;
	}
	
	if (0 == memcmp(&req_before_last_ip[net_id_bytes], host_id_to_release, 
					BYTES_IN_IP - net_id_bytes))
	{
		return 1;
	}
	
	if (0 == memcmp(&req_first_ip[net_id_bytes], host_id_to_release, 
					BYTES_IN_IP - net_id_bytes))
	{
		return 1;
	}

	return 0;
}

static int ReleaseIP(dhcp_t *dhcp, size_t host_id_bytes, 
				  const unsigned char *ip_to_release)
{
	size_t net_id_bytes = BYTES_IN_IP - host_id_bytes;
	trie_node_t *path_leaf = TrieGetPathLeaf(dhcp->root, host_id_bytes, 
								 			  &ip_to_release[net_id_bytes]);
		
	trie_node_t *node_to_update = TrieFreeNewPath(path_leaf);
	
	node_to_update->is_available = AVAILABLE;
	TrieUpdateAvailabilityOfNodes(node_to_update);
	
	++dhcp->available_ip_adresses;
	return SUCCESS;
}

/****************************** -- COUNT FREE -- ******************************/
size_t DHCPCountFree(const dhcp_t *dhcp)
{
	assert(NULL != dhcp);
	
	return dhcp->available_ip_adresses;
}

