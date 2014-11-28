#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "funciones.h"

int main(int argc, char const *argv[])
{
	if(argc!=2)
	{
		printf("Error, tienes que pasar el numero de hilos a crear como parametro.\n\n");
		exit(EXIT_FAILURE);
	}

	int resultado=0, i, hebras=atoi(argv[1]);
	pthread_t tid;

	for(i=0 ; i<hebras ; i++)
	{
		pthread_create(&tid,NULL,(void*)funcion,(int*)&resultado);
		sleep(1);
		pthread_join(tid,NULL);
	}
	printf("La suma de todas las hebras es %d.\n\n",resultado);


	return 0;
}