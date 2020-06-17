#define _POSIX_C_SOURCE 200809L

#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 


void Handler(int signum)
{
	printf("GOT SIGNAL");
}


int main()
{
	int i = 0;
	struct sigaction sa;

	sa.sa_handler = Handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);

	while (1)
	{
		printf("%d\n", i);
		++i;
		sleep(1);
	}
	
	return 0;
}

