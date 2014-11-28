#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
/*Pruebe por ejemplo: “./a.out tar -cf prueba.tar file1 file2 fileN” donde file1 hasta fileN son
ficheros que desea comprimir en el fichero prueba.tar
Pruébelo también sin usar nada en la linea de argumentos.
Por ultimo pruébelo usando un "file1" que no exista.
*/
void main(int argc, char **argv)
{
	pid_t pid;
	int valor;
	int prueba;
	pid = fork();
	switch(pid)
	{
		case -1: /* error del fork() */
				perror("fork error");
				printf("errno value= %d\n", errno);
				exit(-1);
		case 0: /* proceso hijo */
				printf("Soy el hijo y mi PID es:%d\n",getpid());
				if (execvp(argv[1], &argv[1]) < 0)
				{
					perror("exec");
					printf("errno value= %d\n", errno);
					exit(EXIT_FAILURE);
				}
		default: /* padre */
				printf("Valor del PID recibido por el padre en el fork, coincide con el PID del hijo:%d\n",pid);
				while ( (prueba=wait(&valor)) != pid);
					printf("Valor del prueba, es el PID del hijo devuelto por wait():%d\n",prueba);
				if (valor == 0) //El hijo termina satisfactoriamente
					printf("El mandato se ejecuto de forma normal\n");
				else
				{
					if (WIFEXITED(valor)) //Terminación normal, nadie para al proceso ni se recibe una señal
						//de otro proceso.
						printf("El hijo termino normalmente y su valor devuelto fue %d\n",WEXITSTATUS(valor));
				if (WIFSIGNALED(valor))
					printf("El hijo termino al recibir la señal %d\n", WTERMSIG(valor));
				}}
}