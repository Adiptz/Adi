#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netdb.h> 
#include <netinet/in.h>

#define PORT 7777
#define MAXLINE 100

void CopyPingToBuffer(char *buffer)
{
	size_t i = 0;
	const char *ping = "ping";    
	size_t size_of_ping = strlen(ping);

	for (i = 0; i < size_of_ping; ++i)
	{
		buffer[i] = ping[i];	
	}
}

int main()
{ 
	int sockfd;
	int len;
	int recieved_bytes; 
	char buffer[MAXLINE];
 	struct sockaddr_in server_addr;
 	struct sockaddr_in client_addr; 

	/* create new socket */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
 	if (0 > sockfd)
	{ 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
	
	memset(&server_addr, 0, sizeof(server_addr)); 

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	if (0 != connect(sockfd, (struct sockaddr *)&server_addr,
				   	 sizeof(server_addr)))
	{
		printf("connection with the server failed\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		/* send msg to server */
		memset(&buffer, '\0', sizeof(buffer));
		CopyPingToBuffer(buffer);
		write(sockfd, buffer, sizeof(buffer));

		sleep(1);

		/* get msg from server */		
		memset(&buffer, '\0', sizeof(buffer));
		read(sockfd, buffer, sizeof(buffer)); 
		printf("%s\n", buffer);
	}

    close(sockfd); 

	return 0;
} 
