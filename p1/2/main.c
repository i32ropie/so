#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

main()
{
	pid_t pid;
	int i,n,status;

	printf("Introduce el numero de procesos hijo a crear de un mismo proceso padre: ");
	scanf("%d",&n);
	//Hacer bucle para que 'n' sea mayor de 0.

	for(i=1 ; i<=n ; i++)
	{
		pid=fork();
		
		if(pid > 0)
		{
			printf("PADRE: Hijo %d creado",i);
			wait(&status); //Así se espera a que el hijo creado muera. Hay que declarar status.
			if(WIFEXITED(status)!=0) //Hay que declarar status.
			{
				printf("Hijo %d terminado, y su valor es %d.\n",i,WEXITSTATUS(status)); //Hay que declarar status.
			}
		}
		
		if(pid == 0)
		{
			sleep(10*i);
			printf("Hola soy el hijo %d y mi padre es %d",getpid(),getppid());
			exit(i); //Muere el hijo, y es lo que se mostrará en WEXISTATUS(status).
		}

		if(pid == -1)
		{
			printf("Error\n");
			exit(EXIT_FAILURE);
		}
	}

exit(0);
}