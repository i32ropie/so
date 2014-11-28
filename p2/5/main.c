#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(int argc, char const *argv[])
{
	if(argc<2)
	{
		printf("Error, debes introducir al menos un fichero de texto al que contabilizar las lineas.\n");
		exit(EXIT_FAILURE);
	}
	pthread_t *tid=malloc(sizeof(argc));
	FILE **f=malloc(sizeof(argc));
	int i=0 ,j=0;
	void *suma;
	for(i=0 ; i<argc-1 ; i++)
	{
		if((f[j]=fopen(argv[i+1],"r")==NULL)
		{
			printf("Error al leer el archivo %d=%s\n",i+1,argv[i+1]);
		}
		else
		{
			printf("Exito al leer el archivo %d=%s\n",i+1,argv[i+1]);
			pthread_create(&(tid[j]),NULL,(void *)funcion,f[j]);
			j++;
			fclose(&f[j]);
		}
	}
	for(i=0 ; i<j ; i++)
	{
		pthread_join(tid[i],&suma);
	}



	return 0;
}