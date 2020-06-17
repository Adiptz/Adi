#define _POSIX_C_SOURCE 200809L

#include <assert.h>    /* assert */
#include <stdio.h>     /* perror, printf */
#include <signal.h>    /* sig_atomic_t, sigaction, sigemptyset, kill, sinals */
#include <sys/types.h> /* pid_t */
#include <unistd.h>    /* fork, getppid, sleep */

#include "handler.c"

int PingPongProcesses(void);
char *ItoADecimal(int value, char *str);
size_t CountDigits(int value);

#define UNUSED(x) (void)(x)
#define DEC_BASE 10

int main()
{		
	if (ERROR == InitSigaction(SIGUSR1))
	{
		return ERROR;
	}
	
	if (ERROR == PingPongProcesses())
	{
		return ERROR;
	}
	
	return 0;
}

int PingPongProcesses(void)
{
	pid_t child_pid = fork();
	char *arg_list[3] = {NULL};
	char child_pid_string[] = {0};
	
	ItoADecimal(child_pid, child_pid_string); 
	
	arg_list[0] = "./ping.out";
	arg_list[1] = child_pid_string;
	arg_list[2] = NULL;
	
	if (FAIL == child_pid)
	{
		perror("Err : fork");
		return ERROR;
	}
	else if (0 == child_pid) /* child proccess */
	{
		if (ERROR == Action("pong\n", SIGUSR2, getppid()))
		{
			return ERROR;
		}
	}
	else /* parent proccess */
	{
		execvp("./ping.out", arg_list);
	}
	
	return SUCCESS;
}


char *ItoADecimal(int value, char *str)
{
	size_t num_of_digits = CountDigits(value);
	size_t i = 0;
	char *str_current = 0;
	long long_value = value;
	
	assert(NULL != str);
	
	str_current = str;
	
	if (long_value < 0)
	{
		*str_current = '-';
		str_current += (num_of_digits + 1);
		long_value = -long_value;	
	}
	else
	{
		str_current += num_of_digits;
	}
	*str_current = '\0';
	--str_current;
	
	for (i = 0; i < num_of_digits; ++i)
	{
		*str_current = (long_value % DEC_BASE) + '0';
		--str_current;
		long_value /= DEC_BASE;
	}
	
	return str;
}
 
 
size_t CountDigits(int value)
{
	size_t count = 0;
	while (0 != value)
	{
		++count;
		value /= DEC_BASE;
	}
	
	return count;
}
