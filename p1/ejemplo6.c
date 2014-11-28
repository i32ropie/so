#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h> //La incluyo para que funciones el EXIT_FAILURE

void main(void)
{
	pid_t pid;
	int status;
	pid = fork();
	switch(pid)
	{
		case -1: /* error del fork() */
				perror("fork error");
				printf("errno value= %d\n", errno);
				exit(-1); //exit(EXIT_FAILURE);
		case 0: /* proceso hijo */
				printf("Proceso hijo %d; padre = %d \n", getpid(), getppid());
				if(execlp("ls","ls","-l",NULL)==-1) //La orden hay que ponerla dos veces, luego se le pone las condiciones, y por último hay que poner un NULL para indicar que no se meterán más parámetros.
				{
					perror("Falla en la ejecucion exec de ls -l");
					printf("errno value= %d\n", errno);
					exit(EXIT_FAILURE);
				}
		default: /* padre */
				printf("Proceso padre\n");
				while(pid != wait(&status)); //Con esta orden, el padre espera a que cualquiera de sus hijos termine de ejecutarse para ejecutarse este.
/* Recuerde que en C, 0 significa falso y cualquier numero distinto de 0 es verdadero, por tanto el
bucle while() anterior no es mas que una forma de esperar a todos los hijos que tenga el proceso
padre hasta que no queden más. La función wait() se comenta después . Mientras hay hijos el valor
de la expresión será verdadera 
*/
	}
}