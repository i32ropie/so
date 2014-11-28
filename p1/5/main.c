#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
	if(argc!=3)
	{
		printf("Error, numero de parametros introducidos erroneo.\n");
		exit(EXIT_FAILURE);
	}

	pid_t pid;
	int status;

	pid=fork();

	if(pid>0)
	{
		printf("PADRE: Mi PID es %d, y he creado un hijo con PID %d.\n",getpid(),pid);
		wait(&status);
		printf("El hijo ha muerto, y ha devuelto %d.\n",WEXITSTATUS(status));
	}

	if(pid==0)
	{
		printf("HIJO: Mi PID es %d, y el pid de mi padre es %d.\n",getpid(),getppid());
		sleep(atoi(argv[1]));
		exit(atoi(argv[2]));
	}

	if(pid==-1)
	{
		printf("Error al crear el hijo.\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}