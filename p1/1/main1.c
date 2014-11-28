#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	pid_t pid;
	int nEle,i;
	printf("Escriba el numero de procesos a crear: ");
	scanf("%d",&nEle);
	
	for(i=0 ; i<nEle ; i++)
	{
		pid=fork(); //El padre crea un hijo.
		switch(pid)
		{
			case -1: 
					perror("fork error");
					printf("errno value= %d\n", errno);
					exit(-1);
			case 0:
					printf("Soy el hijo %d, mi PID es %d, y el PID de mi padre es %d\n",i+1,getpid(),getppid()); //Muestra el hijo creado, con su padre creador.
					exit(0); //Mata al hijo creado, y el padre está libre de hijos.
					break;
			default:
					printf("Soy el padre y mi PID es %d y mi hijo es %d\n",getpid(), pid); //Se muestra el padre y el hijo creado.
					sleep(1); //Se dice al programa que espere, para que vaya ordenado.
					break;
		}
	}

	return 1;
}