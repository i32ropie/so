#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
void main()
{
	pid_t pid;
	pid = fork();
	switch(pid)
	{
		case -1: /* error del fork() */
				perror("fork error");
				printf("errno value= %d\n", errno);
		break;
		case 0: /* proceso hijo */
				printf("Proceso hijo %d; padre = %d \n", getpid(), getppid());
		break;
		default: /* padre */printf("Proceso %d; padre = %d \n", getpid(), getppid());
	}
}