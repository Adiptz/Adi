
#include <limits.h>
#include <string.h>
#include <math.h>
#include "dhcp_test.h" /* colors and libraries */

/******************************************************************************/
/**************************** forward declaration *****************************/
/******************************************************************************/
void DHCPLease_test();
void DHCPCreate_Destroy_test();
void FullTrie_test();
void DHCPRlease_test();

/******************************************************************************/
/*********************************** main *************************************/
/******************************************************************************/
int main()
{	
	DHCPCreate_Destroy_test();
	DHCPLease_test();
	FullTrie_test();
	DHCPRlease_test();
	
	return 0;
}

/******************************************************************************/
/**************************** test functions **********************************/
/******************************************************************************/
#define NET_ID_BYTE3 3
#define BITS 2
#define RESERVED_IP 3

/********************************** Rlease ************************************/
void DHCPRlease_test()
{
	unsigned char net_id[NET_ID_BYTE3] = {1, 1, 1};
	unsigned char req_ip[BYTES_IN_IP] = {1, 1, 1, 1};
	unsigned char alloc_ip[BYTES_IN_IP] = {0};
	unsigned char ip_to_release_at_the_begining[BYTES_IN_IP] = {1, 1, 1, 1};
	unsigned char ip_to_release_at_the_end[BYTES_IN_IP] = {1, 1, 1, 253};
	unsigned char first_ip[BYTES_IN_IP] = {1, 1, 1, 0};
	unsigned char last_ip[BYTES_IN_IP] = {1, 1, 1, 255};
	unsigned char before_last_ip[BYTES_IN_IP] = {1, 1, 1, 254};
	size_t i = 1;
	
	dhcp_t *dhcp = DHCPCreate(net_id, NET_ID_BYTE3 * CHAR_BIT);
	assert(dhcp != NULL);

	puts(BYEL "Rlease_test" RESET);

	assert(pow(BITS, (BYTES_IN_IP - NET_ID_BYTE3) * CHAR_BIT) - RESERVED_IP == 	
		   DHCPCountFree(dhcp));

	assert(INVALID_REQUEST == DHCPRelease(dhcp, ip_to_release_at_the_begining)); 
	
	assert(pow(BITS, (BYTES_IN_IP - NET_ID_BYTE3) * CHAR_BIT) - RESERVED_IP == 	
		   DHCPCountFree(dhcp));
		   
	/*lease all available ip*/
	while (i < 254)
	{
		assert(SUCCESS == DHCPLease(dhcp, req_ip, alloc_ip));
		assert(pow(BITS, (BYTES_IN_IP - NET_ID_BYTE3) * CHAR_BIT) - RESERVED_IP - i 
			   == DHCPCountFree(dhcp));
		++i;		
	}
	
	assert(0 == DHCPCountFree(dhcp));
	
	assert(FAIL == DHCPLease(dhcp, req_ip, alloc_ip));	

	/*Relese*/
	assert(SUCCESS == DHCPRelease(dhcp, ip_to_release_at_the_begining));
	assert(1 == DHCPCountFree(dhcp));
	assert(INVALID_REQUEST == DHCPRelease(dhcp, ip_to_release_at_the_begining));
	assert(1 == DHCPCountFree(dhcp));
	assert(SUCCESS == DHCPRelease(dhcp, ip_to_release_at_the_end));
	assert(2 == DHCPCountFree(dhcp));
	assert(INVALID_REQUEST == DHCPRelease(dhcp, ip_to_release_at_the_end));
	assert(2 == DHCPCountFree(dhcp));
	assert(INVALID_REQUEST == DHCPRelease(dhcp, first_ip));
	assert(2 == DHCPCountFree(dhcp));
	assert(INVALID_REQUEST == DHCPRelease(dhcp, last_ip));
	assert(2 == DHCPCountFree(dhcp));
	assert(INVALID_REQUEST == DHCPRelease(dhcp, before_last_ip));
	assert(2 == DHCPCountFree(dhcp));

	i = 1;
	++ip_to_release_at_the_begining[3];
	while (i < 252)
	{
		assert(SUCCESS == DHCPRelease(dhcp, ip_to_release_at_the_begining));
		assert(2 + i == DHCPCountFree(dhcp));
		++i;
		++ip_to_release_at_the_begining[3];		
	}

	assert(pow(BITS, (BYTES_IN_IP - NET_ID_BYTE3) * CHAR_BIT) - RESERVED_IP == 	
		   DHCPCountFree(dhcp));

	DHCPDestroy(dhcp);	
}

/********************************* FullTrie ***********************************/
void FullTrie_test()
{	
	unsigned char net_id[NET_ID_BYTE3] = {1, 1, 1};
	unsigned char req_ip[BYTES_IN_IP] = {1, 1, 1, 1};
	unsigned char alloc_ip[BYTES_IN_IP] = {0};
	size_t i = 1;
	/*size_t j = 0;*/
	
	dhcp_t *dhcp = DHCPCreate(net_id, NET_ID_BYTE3 * CHAR_BIT);
	assert(dhcp != NULL);

	puts(BYEL "FullTrie_test" RESET);

	assert(pow(BITS, (BYTES_IN_IP - NET_ID_BYTE3) * CHAR_BIT) - RESERVED_IP == 	
		   DHCPCountFree(dhcp));

	/*lease all available ip*/
	while (i < 254)
	{
		assert(SUCCESS == DHCPLease(dhcp, req_ip, alloc_ip));	
		/*for (j = 0; j < BYTES_IN_IP; ++j){printf("%d ", alloc_ip[j]);}puts("");*/
		assert(pow(BITS, (BYTES_IN_IP - NET_ID_BYTE3) * CHAR_BIT) - RESERVED_IP - i 
			   == DHCPCountFree(dhcp));
		++i;		
	}
	
	assert(0 == DHCPCountFree(dhcp));
	
	assert(FAIL == DHCPLease(dhcp, req_ip, alloc_ip));	

	DHCPDestroy(dhcp);	
}

/*********************************** Lease ************************************/
void DHCPLease_test()
{	
	unsigned char net_id[BYTES_IN_IP] = {1};
	unsigned char req_ip1[BYTES_IN_IP] = {1, 0, 0, 0};
	unsigned char req_ip2[BYTES_IN_IP] = {1, 0, 0, 0};
	unsigned char req_ip3[BYTES_IN_IP] = {1, 255, 255, 255};
	unsigned char req_ip4[BYTES_IN_IP] = {1, 255, 255, 254};
	unsigned char req_ip5[BYTES_IN_IP] = {1, 255, 255, 253};
	unsigned char req_ip6[BYTES_IN_IP] = {1, 0, 0, 255};
	unsigned char req_ip7[BYTES_IN_IP] = {1, 255, 0, 255};
	unsigned char req_ip8[BYTES_IN_IP] = {1, 0, 0, 10};
	unsigned char req_ip_net_no_valid[BYTES_IN_IP] = {0, 255, 0, 255};	
	unsigned char alloc_ip[BYTES_IN_IP] = {0};
	unsigned char alloc_ip1[BYTES_IN_IP] = {0};
	unsigned char zero_array_to_compare[BYTES_IN_IP] = {0, 0, 0, 0};
	
	/*size_t i = 0;*/
	
	dhcp_t *dhcp = DHCPCreate(net_id, 8);
	assert(dhcp != NULL);

	puts(BYEL "Lease_test" RESET);

	/*for (i = 0; i < BYTES_IN_IP; ++i){printf("%d ", alloc_ip[i]);}puts("");*/
	
	assert(SUCCESS == DHCPLease(dhcp, req_ip1, alloc_ip));	
	/*for (i = 0; i < BYTES_IN_IP; ++i){printf("%d ", alloc_ip[i]);}puts("");*/
	++req_ip1[3];
	assert(0 == memcmp(req_ip1, alloc_ip, 4));

	assert(SUCCESS == DHCPLease(dhcp, req_ip2, alloc_ip));
	/*for (i = 0; i < BYTES_IN_IP; ++i){printf("%d ", alloc_ip[i]);}puts("");*/
	++req_ip1[3];
	assert(0 == memcmp(req_ip1, alloc_ip, 4));

	assert(SUCCESS == DHCPLease(dhcp, req_ip3, alloc_ip));	
	/*for (i = 0; i < BYTES_IN_IP; ++i){printf("%d ", alloc_ip[i]);}puts("");*/
	++req_ip1[3];
	assert(0 == memcmp(req_ip1, alloc_ip, 4));

	assert(SUCCESS == DHCPLease(dhcp, req_ip4, alloc_ip));	
	/*for (i = 0; i < BYTES_IN_IP; ++i){printf("%d ", alloc_ip[i]);}puts("");*/
	++req_ip1[3];
	assert(0 == memcmp(req_ip1, alloc_ip, 4));

	assert(SUCCESS == DHCPLease(dhcp, req_ip5, alloc_ip));	
	/*for (i = 0; i < BYTES_IN_IP; ++i){printf("%d ", alloc_ip[i]);}puts("");*/
	assert(0 == memcmp(req_ip5, alloc_ip, 4));
	
	assert(SUCCESS == DHCPLease(dhcp, req_ip6, alloc_ip));	
	/*for (i = 0; i < BYTES_IN_IP; ++i){printf("%d ", alloc_ip[i]);}puts("");*/
	assert(0 == memcmp(req_ip6, alloc_ip, 4));
	
	assert(SUCCESS == DHCPLease(dhcp, req_ip7, alloc_ip));	
	/*for (i = 0; i < BYTES_IN_IP; ++i){printf("%d ", alloc_ip[i]);}puts("");*/
	assert(0 == memcmp(req_ip7, alloc_ip, 4));
	
	assert(INVALID_REQUEST == DHCPLease(dhcp, req_ip_net_no_valid, alloc_ip1));	
	/*for (i = 0; i < BYTES_IN_IP; ++i){printf("%d ", alloc_ip1[i]);}puts("");*/
	assert(0 == memcmp(zero_array_to_compare, alloc_ip1, 4));

	assert(SUCCESS == DHCPLease(dhcp, req_ip8, alloc_ip));	
	/*for (i = 0; i < BYTES_IN_IP; ++i){printf("%d ", alloc_ip[i]);}puts("");*/

	assert(SUCCESS == DHCPLease(dhcp, req_ip8, alloc_ip));	
	/*for (i = 0; i < BYTES_IN_IP; ++i){printf("%d ", alloc_ip[i]);}puts("");*/


	DHCPDestroy(dhcp);	
}

/****************************** Create_Destroy ********************************/
void DHCPCreate_Destroy_test()
{		
	unsigned char net_id[BYTES_IN_IP] = {1};
	dhcp_t *dhcp = DHCPCreate(net_id, 8);
	assert(dhcp != NULL);

	puts(BYEL "Create_Destroy_test" RESET);
	
	DHCPDestroy(dhcp);	
}

