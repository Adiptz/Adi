#define _POSIX_C_SOURCE 200809L

#include <signal.h>    /* sig_atomic_t, sigaction, sigemptyset, kill, sinals */
#include <sys/types.h> /* pid_t */
#include <unistd.h>    /* fork, getppid, sleep */
#include <stdio.h>     /* perror, printf */

void Handler(int signum);
int InitSigaction(int signum);
int Action(const char *str, int signum, pid_t pid);

#define UNUSED(x) (void)(x)

enum {FAIL = -1, SUCCESS, ERROR};

volatile sig_atomic_t flag = 0;


int InitSigaction(int signum)
{
	struct sigaction sa;

	sa.sa_handler = Handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	
	if (FAIL == sigaction(signum, &sa, NULL))
	{
		perror("error with sigaction");
		return ERROR;
	}
	
	return SUCCESS;
}

int Action(const char *str, int signum, pid_t pid)
{
	while (1)
	{
		if (flag)
		{
			flag = 0;
			printf("%s ", str);
			fflush(stdout);
			
			if (FAIL == kill(pid, signum))
			{
				perror("error with kill");
				return ERROR;
			}
			
		}
		sleep(1);
	}
	
	return SUCCESS;
}

void Handler(int signum)
{
	UNUSED(signum);
	
	flag = 1;
}
