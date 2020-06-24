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

void CopyPongToBuffer(char *buffer)
{
	size_t i = 0;
	const char *pong = "pong";
	size_t size_of_pong = strlen(pong);

	for (i = 0; i < size_of_pong; ++i)
	{
		buffer[i] = pong[i];	
	}
}

int main()
{ 
	int len;
	int sockfd;
	int bind_res;
	int accept_socket;
	const char *pong = "pong";
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



	/* bind socket with server address */
	bind_res = bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr));
	if (0 > bind_res)
	{
	 	perror("bind failed"); 
        exit(EXIT_FAILURE); 
	}
	
	/* server is ready to listen */
	if ((listen(sockfd, 5)) != 0)
	{ 
		printf("Listen failed...\n"); 
		 exit(EXIT_FAILURE); 
	} 

	/* accept data-package from client */
	accept_socket = accept(sockfd, (struct sockaddr *)&client_addr, &len);
	if (0 > accept_socket)
	{
		perror("server accept failed\n");
		exit(0);	
	}
	
memset(&buffer, '\0', sizeof(buffer));
	
	while (1)
	{
		/* get msg from client */		
		read(accept_socket, buffer, sizeof(buffer)); 
		printf("%s\n", buffer);
		
		sleep(1);

		/* send msg to client */
		memset(&buffer, '\0', sizeof(buffer));
		CopyPongToBuffer(buffer);
		write(accept_socket, buffer, sizeof(buffer));
		memset(&buffer, '\0', sizeof(buffer));
	}
	
    close(sockfd); 

	return 0;
} 

