#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
/*Pruebe por ejemplo: “./a.out tar -cf prueba.tar file1 file2 fileN” donde file1 hasta fileN son
ficheros que desea comprimir en el fichero prueba.tar*/
void main(int argc, char **argv)
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
				if ( execvp(argv[1], &argv[1]) < 0 )
				{
					perror("exec");
					printf("errno value= %d\n", errno);
				}
		break; //exit(EXIT_FAILURE);
		default: /* padre */
				printf("Proceso padre\n");
	}
}