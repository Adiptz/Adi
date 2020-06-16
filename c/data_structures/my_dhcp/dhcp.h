#ifndef ILRD_DHCP_H
#define ILRD_DHCP_H

#define BYTES_IN_IP (4)

#include <stddef.h> /* size_t */

typedef enum
{
	SUCCESS,
	FAIL,
	INVALID_REQUEST
} dhcp_status_t;

typedef struct dhcp dhcp_t;

/*
 * Create a new DHCP server 
 * Param @net_id : network id
 * Param @num_bits_net_id : num of bits that represent network id, byte alligned
 * Return: pointer to new DHCP server
 * Errors: if memory allocation failed, returns NULL 
 */

dhcp_t *DHCPCreate(unsigned char net_id[BYTES_IN_IP], size_t num_bits_net_id);

/*
 * Destroy given DHCP server 
 * Param @dhcp : pointer to dhcp
 * Return: none
 * Errors: none
 */

void DHCPDestroy(dhcp_t *dhcp);

/*
 * allocate ip address. 
 * User can request to allocate a specific ip address, if the address is 
 * already leased, the user will receive the next available address
 * Param @dhcp : pointer to DHCP server 
 * Param @req_ip : requested ip address
 * Param @alloc_ip : return ip address
 * Return: dhcp_status_t: return lease status
 * Errors: if allocation success and requested ip is legal (net id must be same)
 * return SUCCESS, if requested ip is illegal - return INVALID_REQUEST,
 * if allocation fails return FAIL.
 */

dhcp_status_t DHCPLease(dhcp_t *dhcp, const unsigned char req_ip[BYTES_IN_IP],
						unsigned char alloc_ip[BYTES_IN_IP]);

/*
 * Release previously allocated ip address
 * Param @ip_to_release: ip address to be released
 * Return: dhcp_status_t:  return release status
 * Errors: if the address is a legal address to free return SUCCESS 
 * else return INVALID_REQUEST
 */

dhcp_status_t DHCPRelease(dhcp_t *dhcp, 
						  const unsigned char ip_to_release[BYTES_IN_IP]);

/*
 * Gets number of available addresses to lease.
 * Param @dhcp: pointer to dhcp
 * Return: number of available ip addresses
 * Errors: none 
 */

size_t DHCPCountFree(const dhcp_t *dhcp);

#endif /* ILRD_DHCP_H */
