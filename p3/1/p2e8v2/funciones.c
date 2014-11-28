#include <pthread.h>
#include "funciones.h"

void *funcion(void *iter)
{
	int i,j;
	pthread_mutex_lock(&lock);
	for(i=0 ; i<*((int*)iter) ; i++)
	{
		for(j=0 ; j<50 ; j++)
		{
			var+=1;
		}
	}
	pthread_mutex_unlock(&lock);
}