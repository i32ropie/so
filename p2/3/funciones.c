#include "funciones.h"
#include <pthread.h>
#include <stdlib.h>


void *funcion(void *vtid)
{
	int *suma;
	suma=(int *)malloc(sizeof(int));
	*suma=0;
	int i;
	for(i=((100/10)*(*(int *)vtid)) ; i<((100/10)*(*(int*)vtid+1)) ; i++) //(100/10) donde 100 es el tamaño del vector y 10 el numero de hilos.
	{
		(*suma)+=vector[i];
	}

	pthread_exit((void *) suma);
}


void reservaThread(pthread_t *tid, int n)
{
	tid=(pthread_t *)malloc(n*sizeof(pthread_t));
}

void reservaVector(int *vector)
{
	int i;
	vector=(int *)malloc(100*sizeof(int));
	/*for(i=0 ; i<100 ; i++)
	{
		vector[i]=rand()%10;
	}*/
}