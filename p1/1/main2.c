#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	pid_t pid;
	int i,nEle;

	printf("Introduce el numero de hijos que quieres crear consecutivamente: ");
	scanf("%d",&nEle);

	for(i=0 ; i<nEle ; i++)
	{
		pid=fork();
		switch(pid)
		{
			case -1: 
					perror("Fork error");
					printf("errno value=%d\n",errno);
					exit(-1);
			case 0:
					//pid=fork(); Este no hay que ponerlo, porque entonces los hijos se duplicarían.
					break;
			default:
					printf("Soy el padre %d, mi PID es %d y el PID de mi hijo es %d\n",i+1,getpid(),pid);
					exit(0);
		}
	}


	return 0;

}