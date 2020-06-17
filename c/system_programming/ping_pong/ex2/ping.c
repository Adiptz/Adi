#define _POSIX_C_SOURCE 200809L

#include <signal.h>    /* sig_atomic_t, sigaction, sigemptyset, kill, sinals */
#include <sys/types.h> /* pid_t */
#include <unistd.h>    /* fork, getppid, sleep */
#include <stdio.h>     /* perror, printf */
#include <stdlib.h>    /* atoi */

#include "handler.c"

#define UNUSED(x) (void)(x)

int main(int arcg, char **argv)
{		
	UNUSED(arcg);
	
	if (ERROR == InitSigaction(SIGUSR2))
	{
		return ERROR;
	}
	
	if (ERROR == PingPongProcesses(argv[1]))
	{
		return ERROR;
	}
	
	return 0;
}

/*PingPongProcesses*/
int PingPongProcesses(char *child_pid_string)
{	
	pid_t child_pid = atoi(child_pid_string);
	
	flag = 1;
	
	if (ERROR == Action("ping\n", SIGUSR1, child_pid))
	{
		return ERROR;
	}			
	
	return SUCCESS;
}


