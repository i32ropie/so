#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

int main()
{
	pid_t pid;

	pid=fork();

	if(pid>0)
	{
		printf("Soy el padre, y este es mi ID: %d.\n",getpid());
		//sleep(30);
		exit(EXIT_SUCCESS);
	}
	if(pid==0)
	{
		sleep(30);
	}

	return 0;
}