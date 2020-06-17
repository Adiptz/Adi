/*****************************************
 *     PING PONG BETWEEN 2 PROCESSES     *
 *          Author : Adi Peretz          *
 *****************************************/

#define _POSIX_C_SOURCE 200809L

/*#include <sys/types.h> */
#include <stdio.h> /* printf */
#include <signal.h> /* sigaction, SIGUSR1, SIGUSR2 */
#include <unistd.h> /* fork, getppid */

#define UNUSED(x) ((void)x)

void Handler(int signum);
volatile sig_atomic_t flag = 1;
void PingPong(int signal, char *string_to_print, pid_t pid);


int main()
{
	struct sigaction sa;
	pid_t child_pid = 0;
	char *pong = "pong                                               X\n";
	char *ping = "ping  X\n";
  
  
    sa.sa_handler = Handler;
    sa.sa_flags = 0; 
    sigemptyset(&sa.sa_mask);
    	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	
	child_pid = fork();

	if (0 == child_pid) /* child process */
	{
		PingPong(SIGUSR2, pong, getppid());
	}
	else if (0 < child_pid) /* parent process */
	{
        PingPong(SIGUSR1, ping, child_pid);
	}

	return 0;
}

void Handler(int signum)
{
	UNUSED(signum);
	flag = 1;
}

void PingPong(int signal, char *string_to_print, pid_t pid)
{
		while(1)
		{
			if (1 == flag)
			{

				flag = 0;
				printf("%s", string_to_print);
				kill(pid, signal);
			}
			
			sleep(1);
		}
}

