#include <sys/types.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <errno.h>

int main(int argc, char const *argv[])
{
	if (argc < 3)
	{
		printf("Error, debes introducir al menos un elemento.\n");
		exit(EXIT_FAILURE);
	}
	if(argc > 3)
	{
		printf("Error, debes introducir solo un elemento\n");
		exit(EXIT_FAILURE);
	}
	pid_t pid;
	int a=atoi(argv[1]),b=atoi(argv[2]);
	int i;
	int status;

	for(i=1 ; i<3 ; i++)
	{
		pid=fork();

		if(pid>0)
		{
			wait(&status);
			 printf("El factorial de %d es %d\n",atoi(argv[i]),WEXITSTATUS(status));
		}
		
		if(pid==0)
		{
			 execl("./factorial.out","./factorial.out",argv[i],NULL);

			 exit(EXIT_SUCCESS);
		}

		if(pid==-1)
		{
			printf("Error.\n");
			exit(EXIT_FAILURE);
		}
	}
	
	return 0;
}