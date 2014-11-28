#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
int main(void)
	{
	pid_t hijo_pid;
	hijo_pid = fork();
	if (hijo_pid == -1)
	{
		perror("fork error");
		printf("errno value= %d\n", errno);
		exit(-1);
	}
	else
	{
		if (hijo_pid == 0) /* hijo */
		{
			printf("hijo con pid: %ld\n", (long)getpid());
			exit(EXIT_SUCCESS);
		}
		else /* padre */
		{
			printf("padre con pid: %ld\n", (long)getpid());
			exit(EXIT_SUCCESS);
		}
	}
}
