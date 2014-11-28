#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

int main()
{
	FILE *f;
	pid_t pid;
	int status,i1,i2,i;

	if((f=fopen("prueba.txt","w"))==NULL)
	{
		printf("\nERROR, NO SE PUDO CREAR EL FICHERO 'prueba.txt'.\n");
		exit(EXIT_FAILURE);
	}

		//FORMA FEA, NO ME GUSTA
/*
	pid=fork();


	if(pid>0)
	{
		for(i1=0 ; i1<10 ; i1++)
		{
			fprintf(f,"%d)++++++++++\n",i1+1);
			sleep(1);
			fflush(f);
		}
		wait(&status);
	}
	if(pid==0)
	{
		for(i2=0 ; i2<10 ; i2++)
		{
			sleep(1);
			fprintf(f,"%d)----------\n",i2+1);
			//sleep(1);
			fflush(f);
		}
		exit(EXIT_SUCCESS);
	}
	if(pid==-1)
	{
		printf("Error al crear el proceso hijo");
		exit(EXIT_FAILURE);
	}

*/

		//FORMA BONITA, SI ME GUSTA

	for(i=0 ; i<10 ; i++)
	{
		pid=fork();
		if(pid>0)
		{
			fprintf(f, "%d)++++++++++\n",i+1);
			sleep(1);
			fflush(f);
			wait(&status);
		}
		if(pid==0)
		{
			sleep(1);
			fprintf(f, "%d)----------\n", i+1);
			fflush(f);
			exit(EXIT_SUCCESS);
		}
	}


	fclose(f);

	system("cat prueba.txt");

	return 0;
}