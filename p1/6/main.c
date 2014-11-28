#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	if(argc<3)
	{
		printf("Error, has introducido un numero de parametros menor al experado.\n");
		exit(EXIT_FAILURE);
	}

	pid_t pid;
	int status;

	pid=fork();

	if(pid==0)
	{
		execlp(argv[1], argv[1], NULL);
	}
	
	if(pid>0)
	{
		sleep(1);
		pid=fork();
		if(pid==0)
		{
			 execvp(argv[2], &argv[2]);
		}
	//	while(pid != wait(&status));
	}

		while(pid != wait(&status));


	return 0;
}