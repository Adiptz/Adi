#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>


void Adi(int signum)
{
	write(STDOUT_FILENO, "Adi\n",4);
}

void Daya(int signum)
{
	write(STDOUT_FILENO,"\n\nDAYA\n\n", 9);
}

void Vovi(int signum)
{
	write(STDOUT_FILENO, "VOVA THE QUEEN\n\n", 15);
}

void Handler(int signum)
{
	if (SIGINT == signum)
	{
		Daya(signum);
	}
	
	if (SIGUSR1 == signum)
	{
		Vovi(signum);
	}
	
	if (SIGTERM == signum)
	{
		Adi(signum);
	}
}

int main(void)
{
	 char s[200];
	
	
	struct sigaction sa;

    sa.sa_handler = Handler;
    sa.sa_flags = 0; 
    sigemptyset(&sa.sa_mask);
    
    sigaction(SIGTERM, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	
	
	raise(SIGUSR1);
/*	raise(SIGINT);*/
	 
	 while (1)
	 {
		 puts("Enter a string:\n");
		  (gets(s) == NULL);
	}	 
	return 0;
}
