#define PORT 7777
#define MAXLINE 1024

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

int main()
{ 
	int sockfd;
	int bind_res; 
	int len;
	int recieved_bytes;
	char buffer[MAXLINE];	
	char *pong = "pong"; 
    struct sockaddr_in server_addr;
 	struct sockaddr_in client_addr; 

	/* create new socket */
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
 	if (0 > sockfd)
	{ 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

	memset(&server_addr, 0, sizeof(server_addr)); 
   	memset(&client_addr, 0, sizeof(client_addr)); 
     
	/* server information */
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	/* bind socket with server address */
	bind_res = bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr));
	if (0 > bind_res)
	{
	 	perror("bind failed"); 
        exit(EXIT_FAILURE); 
	}

	while (1)
	{
		/* recieve msg from client */
		recieved_bytes = recvfrom(sockfd, (char *)buffer, MAXLINE,  
		            			  MSG_WAITALL, (struct sockaddr *)&client_addr,
					   	  	      &len); 
		if (0 > recieved_bytes)
		{
			printf("didn't recieved nothing");
		}

	
		buffer[recieved_bytes] = '\0';
		printf("%s\n", buffer);	

		/* send msg to client */
		sendto(sockfd, (const char *)pong, strlen(pong), 
		   	   MSG_CONFIRM, (const struct sockaddr *)&client_addr, len);
	
	}

	return 0;
}
