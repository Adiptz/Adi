/***************************
 * Author   : Hay Hoffman  *
 * Reviewer : Adi Peretz   *
 * Status   : Approve      *
 ***************************/
/**************************************includes********************************/
#include <assert.h> /*assert*/ /* XXX assert is the first include */
#include <stdlib.h> /*malloc, free*/
#include <limits.h> /*CHAR_BIT*/
#include <string.h> /*memcpy*/
#include "dhcp.h" /*dhcp API*/
/**********************************defines*************************************/
#define NUM_OF_CHILDREN (2)
/**********************************typedefs************************************/
typedef enum {LEFT, RIGHT} direction_t;
typedef enum {NOT_EXIST, EXIST} path_t;
typedef struct node node_t;
typedef struct alloc_parms parms_t; 
typedef unsigned char uchar;
typedef unsigned int uint; 
/*****************************structs declerations*****************************/
struct node 
{
	node_t *children[NUM_OF_CHILDREN]; 
};

struct dhcp 
{
	uint net_id; 
	size_t host_bit_num;
	size_t net_id_bit_num; 
	node_t *root; 
};

struct alloc_parms 
{
	uint traverse_mask; 
	uint height; 
	uint path; 
};
/***************************static functions declerations**********************/
static dhcp_status_t InitDHCP(dhcp_t *dhcp, uchar *net_id, size_t n_bits_net_id);
static dhcp_status_t InitRoot(dhcp_t *dhcp);
static node_t *CreateNode(void);
static void InitilizeTreePaths(dhcp_t *dhcp, uint path);
static void CopyPathToIP(dhcp_t * dhcp, uchar *alloc_ip, uint path);
static uint GetNetID(uchar *net_id, dhcp_t *dhcp);
static uint IPArrToUint(uchar *ip);
static size_t GetHostBitNum(dhcp_t *dhcp);
static void RecDestroyAllNodes(node_t *node);
static uint GetPath(dhcp_t *dhcp, uchar *ip);
static node_t *GetRoot(dhcp_t *dhcp);
static dhcp_status_t IterativeAlloc(dhcp_t* dhcp, uchar *alloc_ip);
static uint GetMaxPath(dhcp_t *dhcp);
static int IsNodeCreateNedded(node_t *node);
static void CreatePath(parms_t parms, node_t *node);
static uint GetTraverseMask(dhcp_t *dhcp);
static parms_t InitParm(dhcp_t *dhcp, uchar *alloc_ip);
static int IsPathExist(dhcp_t *dhcp, uint path);
static direction_t GetDirection(parms_t parms);
static node_t *RecRelease(node_t *node, parms_t parms);
static size_t NumOfChilden(node_t *node);
static int IsIllegalPath(dhcp_t *dhcp, uint path);
static uint GetNBitMask(size_t n_bits);
static size_t GetNetIDBitNum(dhcp_t *dhcp);
static int IsLeaf(parms_t parms);
static void UpdateTraverseParms(parms_t *parms, node_t **node);
static dhcp_status_t ResetPathTravers(dhcp_t *dhcp, parms_t *parms
														, node_t **node, uchar *alloc_ip);
/*************************************DHCPCreate******************************/
dhcp_t *DHCPCreate(unsigned char net_id[BYTES_IN_IP], size_t num_bits_net_id)
{
	dhcp_t *dhcp = NULL;
	dhcp_status_t init_status = 0;

	assert(NULL != net_id);

	dhcp = (dhcp_t *)malloc(sizeof(*dhcp));
	if (NULL == dhcp)
	{
		return NULL;
	}

	init_status = InitDHCP(dhcp, net_id, num_bits_net_id);
	if (FAIL == init_status)
	{
		free(dhcp); dhcp = NULL;
		return NULL;
	}

	return dhcp;
}

/*************************************InitDHCP*********************************/
static dhcp_status_t InitDHCP(dhcp_t *dhcp, uchar *net_id, size_t n_bits_net_id)
{
	dhcp_status_t root_init = 0; 
	
	assert(NULL != dhcp);
	
	dhcp->net_id_bit_num = n_bits_net_id;
	dhcp->host_bit_num = (BYTES_IN_IP * CHAR_BIT) - n_bits_net_id;
	dhcp->net_id = GetNetID(net_id, dhcp);
	
	root_init = InitRoot(dhcp);
	if (FAIL == root_init)
	{
		return FAIL;
	}

	
	return SUCCESS;
}

/*************************************InitRoot**********************************/
static dhcp_status_t InitRoot(dhcp_t *dhcp)
{	
	assert(NULL != dhcp);
	
	dhcp->root = CreateNode(); 
	if (NULL == dhcp->root)
	{
		return FAIL;
	}
	
	InitilizeTreePaths(dhcp, 0);
	InitilizeTreePaths(dhcp, GetMaxPath(dhcp));
	InitilizeTreePaths(dhcp,  GetMaxPath(dhcp) - 1);
	
	return SUCCESS; 
}

/*************************************CreateNode******************************/
static node_t *CreateNode(void)
{
	node_t * node= (node_t *)malloc(sizeof(*node));
	if (NULL == node)
	{
		return NULL;
	}
	
	node->children[LEFT] = NULL;
	node->children[RIGHT] = NULL;
	
	return node; 
}

/*************************************InitilizeTreePaths*************************/
static void InitilizeTreePaths(dhcp_t *dhcp, uint path)
{
	uchar ip[BYTES_IN_IP] = {0};
	
	assert(NULL != dhcp);
	
	CopyPathToIP(dhcp, ip, path);
	IterativeAlloc(dhcp, ip);
}

/*********************************CopyPathToIP*********************************/
static void CopyPathToIP(dhcp_t * dhcp, uchar *alloc_ip, uint path)
{
	uint u_alloc_ip = 0; 
	uint mask = 0xff;
	size_t i = BYTES_IN_IP; 
	
	assert(NULL != alloc_ip);
	
	u_alloc_ip = IPArrToUint(alloc_ip);
	u_alloc_ip -= GetPath(dhcp, alloc_ip);
	u_alloc_ip += path; 
	
	while (i--) 
	{
		alloc_ip[i] = u_alloc_ip & mask;
		u_alloc_ip >>= CHAR_BIT;
	}
}

/*************************************IPArrToUint*******************************/
static uint IPArrToUint(uchar *ip) 
{
	size_t i = 0;
	uint converted_ip = 0;

	assert(NULL != ip);

	for (i = 0; i < 4; ++i)
	{
		converted_ip <<= CHAR_BIT;
		converted_ip += ip[i];
	}

	return converted_ip;
}

/************************************GetPath***********************************/
static uint GetPath(dhcp_t *dhcp, uchar *ip)
{
	uint bit_mask = 0;
	uint converted_ip = 0;
	
	assert(NULL != ip);
	assert(NULL != dhcp);
	
	converted_ip = IPArrToUint(ip);
	bit_mask = GetNBitMask (GetHostBitNum(dhcp));
	
	return bit_mask & converted_ip;
}

/*************************************GetNetID*********************************/
static uint GetNetID(uchar *net_id, dhcp_t *dhcp)
{
	uint bit_mask = 0;
	uint converted_ip = 0;
	
	assert(NULL != net_id);
	assert(NULL != dhcp);
	
	converted_ip= IPArrToUint(net_id);
	bit_mask = GetNBitMask(GetNetIDBitNum(dhcp));
	
	return (bit_mask & (converted_ip >> GetHostBitNum(dhcp)));
}

/*************************************GetNBitMask*****************************/
static uint GetNBitMask(size_t n_bits)
{
	uint nbit_mask = 0; 
	uint single_bit_mask = 1u;
	size_t i = 0; 	
	
	for (i = 0; i < n_bits; ++i)
	{
		nbit_mask |= single_bit_mask; 
		single_bit_mask <<= 1;
	}
	
	return nbit_mask;
}

/*************************************GetHostBitNum**************************/
static size_t GetHostBitNum(dhcp_t *dhcp)
{
	assert(NULL != dhcp);
	
	return dhcp->host_bit_num;
}

/*************************************GetNetIDBitNum**************************/
static size_t GetNetIDBitNum(dhcp_t *dhcp)
{		
	assert(NULL != dhcp);
	
	return dhcp->net_id_bit_num;
}

/*************************************DHCPDestroy*****************************/
void DHCPDestroy(dhcp_t *dhcp) 
{
	assert(NULL != dhcp);
	
	RecDestroyAllNodes(dhcp->root);
	free(dhcp); dhcp = NULL;
}

/*********************************RecDestroyAllNodes**************************/
static void RecDestroyAllNodes(node_t *node)
{
	if (NULL == node)
	{
		return;  
	}

	RecDestroyAllNodes(node->children[LEFT]);
	RecDestroyAllNodes(node->children[RIGHT]);
	free(node); node = NULL;
}

/*********************************DHCPLease**********************************/
dhcp_status_t DHCPLease(dhcp_t *dhcp, 
						const unsigned char req_ip[BYTES_IN_IP],
						unsigned char alloc_ip[BYTES_IN_IP])
{
	assert(NULL != dhcp);
	assert(NULL != req_ip);
	assert(NULL != alloc_ip);
	
	if (GetNetID((uchar *)req_ip ,dhcp) != dhcp->net_id)
	{
		return INVALID_REQUEST; 
	}
	
	memcpy(alloc_ip, req_ip, BYTES_IN_IP);
	
	return IterativeAlloc(dhcp, alloc_ip);
}

/*********************************IterativeAlloc*********************************/
static dhcp_status_t IterativeAlloc(dhcp_t* dhcp, uchar *alloc_ip)
{
	parms_t parms = {0,0,0}; 
	node_t *node = NULL;
	dhcp_status_t is_path_exist = 0; 
	
	assert(NULL != dhcp);
	assert(NULL != alloc_ip);
	
	parms = InitParm(dhcp, alloc_ip); 
	node = GetRoot(dhcp);
	
	while (FAIL != is_path_exist)
	{
		direction_t direction = GetDirection(parms);
		
		if (IsNodeCreateNedded(node->children[direction]))
		{
			CreatePath(parms, node);
			CopyPathToIP(dhcp, alloc_ip, parms.path);
			
			return SUCCESS;
		}
		
		UpdateTraverseParms(&parms, &node);
		
		if (IsLeaf(parms) && !IsNodeCreateNedded(node))
		{
			is_path_exist = ResetPathTravers(dhcp, &parms, &node ,alloc_ip);
		}
	}
	
	return FAIL; 	
}

/**************************UpdateTraverseParms********************************/
static void UpdateTraverseParms(parms_t *parms, node_t **node)
{
	direction_t direction = 0; 
	
	assert(NULL != parms);
	assert(NULL != node);	
	
	direction = GetDirection(*parms);
	
	parms->traverse_mask >>= 1;
	--parms->height; 
	*node = (*node)->children[direction];
}

/*********************************IsLeaf****************************************/
static int IsLeaf(parms_t parms)
{
	return (0 == parms.height);
}
/*********************************InitParm**************************************/
static parms_t InitParm(dhcp_t *dhcp, uchar *alloc_ip)
{
	parms_t parms ;
	
	assert(NULL != dhcp);
	assert(NULL != alloc_ip);
	
	parms.traverse_mask = GetTraverseMask(dhcp); 
	parms.path  = GetPath(dhcp, alloc_ip);
	parms.height = GetHostBitNum(dhcp);
	
	return parms; 
}

/*********************************GetMaxPath**********************************/
static uint GetMaxPath(dhcp_t *dhcp)
{
	assert(NULL != dhcp);
	
	return (1 << GetHostBitNum(dhcp)) - 1;
}

/*********************************UpdateNextPath******************************/
static uint UpdateNextPath(uint path, uint max_path)
{
	if (max_path == path || (max_path - 1) == path)
	{
		return 0; 
	}
	
	return ++path; 
}

/*********************************CreatePath***********************************/
static void CreatePath(parms_t parms, node_t *node)
{
	while (!IsLeaf(parms))
	{
		direction_t direction = GetDirection(parms);
		
		node->children[direction] = CreateNode();
		UpdateTraverseParms(&parms, &node);
	}
}

/*********************************ResetPathTravers******************************/
static dhcp_status_t ResetPathTravers(dhcp_t *dhcp, parms_t *parms
														, node_t **node, uchar *alloc_ip)
{
	assert(NULL != parms);
	assert(NULL != *node);
	assert(NULL != dhcp);
	assert(NULL != alloc_ip);
	
	parms->path = UpdateNextPath(parms->path, GetMaxPath(dhcp));
	if (parms->path == GetPath(dhcp, alloc_ip))
	{
		return FAIL;
	}
	
	parms->traverse_mask =  GetTraverseMask(dhcp);
	parms->height = GetHostBitNum(dhcp);
	*node = GetRoot(dhcp);
	
	return SUCCESS; 
}

/******************************GetTraverseMask********************************/
static uint GetTraverseMask(dhcp_t *dhcp)
{
	assert(NULL != dhcp);
	
	return 1u << (GetHostBitNum(dhcp) - 1);
}

/**************************IsNodeCreateNedded********************************/
static int IsNodeCreateNedded(node_t *node)
{
	return (node == NULL);
}

/*********************************GetRoot**************************************/
static node_t *GetRoot(dhcp_t *dhcp)
{
	assert(NULL != dhcp);
	
	return dhcp->root;
}

/*********************************DHCPCountFree******************************/
size_t DHCPCountFree(const dhcp_t *dhcp)
{
	size_t counter = 0; 
	size_t i = 0; 
	uint max_path = GetMaxPath((dhcp_t *)dhcp);
	
	assert(NULL != dhcp);
	
	for(i = 1; i < max_path - 1; ++i)
	{
		if (IsPathExist((dhcp_t *)dhcp, i))
		{
			++counter; 
		}		
	}
	
	return max_path - 2 - counter; 
}

/*********************************IsPathExist***********************************/
static int IsPathExist(dhcp_t *dhcp, uint path)
{
	parms_t parms = {0, 0, 0};
	node_t *node = NULL;
	uchar ip[BYTES_IN_IP] = {0};
	
	assert(NULL != dhcp);
	
	node = GetRoot(dhcp);
	
	CopyPathToIP(dhcp, ip, path);
	parms = InitParm(dhcp, ip);
	
	while (!IsLeaf(parms)) 
	{
		direction_t direction = GetDirection(parms);
		
		 if (IsNodeCreateNedded(node->children[direction]))
		{
			return NOT_EXIST;
		}
		
		UpdateTraverseParms(&parms, &node);
	}
	
	return EXIST;
}	
/*********************************GetDirection*********************************/
static direction_t GetDirection(parms_t parms)
{
	return ((parms.path & parms.traverse_mask) != 0); 
}

/*********************************DHCPRelease********************************/
dhcp_status_t DHCPRelease(dhcp_t *dhcp, 
						  const unsigned char ip_to_release[BYTES_IN_IP])
{
	parms_t parms = {0,0,0}; 
	node_t *root = NULL;
	direction_t direction = 0;
		
	assert(NULL != dhcp);
	assert(NULL != ip_to_release);
	
	parms = InitParm(dhcp,(uchar *)ip_to_release); 
	
	if (!IsPathExist(dhcp, parms.path) || IsIllegalPath(dhcp, parms.path))
	{
		return INVALID_REQUEST;
	}
		
	root = GetRoot(dhcp);
	direction = GetDirection(parms);
	
	root->children[direction] = RecRelease(root->children[direction], parms);
	
	return SUCCESS;
}
/*********************************IsIllegalPath**********************************/
static int IsIllegalPath(dhcp_t *dhcp, uint path)
{
	uint max_path = 0; 
	
	assert(NULL != dhcp);
	
	max_path = GetMaxPath(dhcp);
	
	if ((0 == path) || (max_path == path) || (max_path - 1 == path))
	{
		return 1; 
	}
	
	return 0;
}
/*********************************RecRelease**********************************/
static node_t *RecRelease(node_t *node, parms_t parms)
{
	direction_t direction = 0;
	
	
	if(0 == NumOfChilden(node))
	{
		free(node); node = NULL;
		
		return NULL;
	}
		
	parms.traverse_mask >>= 1;
	direction = GetDirection(parms);

	node->children[direction] = RecRelease(node->children[direction], parms);
																  
	if(0 == NumOfChilden(node))
	{
		free(node); node = NULL;
		
		return NULL;
	}
	
	return node;																	  
}

/*********************************NumOfChilden********************************/
static size_t NumOfChilden(node_t *node)
{	
	return ((NULL != node->children[RIGHT]) + (NULL != node->children[LEFT])); 
}
