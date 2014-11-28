#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "funciones.h"

void *funcion(void *cad)
{
	int i;
	pthread_mutex_lock(&lock);
	for(i=0 ; i<5 ; i++)
	{
		printf("%c",*(char *)cad);
		usleep(100000);
		fflush(stdout);
	}
	pthread_mutex_unlock(&lock);
}