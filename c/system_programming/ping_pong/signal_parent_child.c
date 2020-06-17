#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
// function declaration 
void sighup(); 
void sigint(); 
void sigquit(); 
void sigusr1();

void main() 
{ 
    int pid; 
  
  	pid = fork();
  	
    /* get child process */
    if (pid < 0)
    { 
        perror("fork"); 
        exit(1); 
    } 
  
    if (pid == 0) /* child */
    { 
    	while(1)
    	{
		    signal(SIGHUP, sighup); 
		    signal(SIGINT, sigint); 
		    signal(SIGQUIT, sigquit); 
    	}
    } 
  
    else /* parent */
    { /* pid hold id of child */
	    signal(SIGUSR1, sigusr1); 
        printf("\nPARENT: sending SIGHUP\n\n"); 
  
        sleep(3); /* pause for 3 secs */
        printf("\nPARENT: sending SIGINT\n\n"); 
        kill(pid, SIGINT); 
  
        sleep(3); /* pause for 3 secs */
        printf("\nPARENT: sending SIGQUIT\n\n"); 
        kill(pid, SIGQUIT); 
        sleep(3); 
    } 
} 
  
void sigusr1() 
{ 
	
    printf("MY PARENT SENT ME SIGUSR1"); 
}
// sighup() function definition 
void sighup() 
{ 
    printf("CHILD: I have received a SIGHUP\n"); 
    kill(0, SIGUSR1);
} 
  
// sigint() function definition 
void sigint() 
{ 
    printf("CHILD: I have received a SIGINT\n"); 
} 
  
// sigquit() function definition 
void sigquit() 
{ 
    printf("My DADDY has Killed me!!!\n"); 
    exit(0); 
} 
