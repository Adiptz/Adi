#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

#define PORT 7777
#define MAXLINE 1024

int main()
{ 

	int sockfd;
	int len;
	int recieved_bytes; 
	char buffer[MAXLINE];
	char *ping = "ping";    
	struct sockaddr_in server_addr;


	/* create new socket */
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
 	if (0 > sockfd)
	{ 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

	memset(&server_addr, 0, sizeof(server_addr)); 

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	while (1)
	{
		sendto(sockfd, (const char *)ping, strlen(ping), 
		   	   MSG_CONFIRM, (const struct sockaddr *)&server_addr,  
		       sizeof(server_addr));

		recieved_bytes = recvfrom(sockfd, (char *)buffer, MAXLINE,  
		            			  MSG_WAITALL, (struct sockaddr *)&server_addr,
					   	  	      &len);
		if (0 > recieved_bytes)
		{
			printf("didn't recieved nothing");
		}


		buffer[recieved_bytes] = '\0';
		printf("%s\n", buffer);

		sleep(1);
	}
	

	return 0;
}
