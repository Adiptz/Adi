#include <blabla.h>
#include <blabla.h>
#include <blabla.h>

void sig_from_parent(int signum)
{
	get parent pid();
	send a SIGUSR1 to parent;
}

void sig_from_child(int signum)
{
	send a SIGUSR2 to child;
}

int main()
{
	pid_t pid = fork();
	if (pid < 0)
	{
		fork failed;
	}
	if (0 == pid) /* you're at child process */
	{
		handler with sig_from_parent; /* SIGUSR1 to parent */ 
	}
	else /* you're at parent process */
	{
		handler with sig_from_child;   /* SIGUSR2 to child */
	}
	
	return 0;
}
