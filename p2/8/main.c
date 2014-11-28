#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "funciones.h"

int main(int argc, char const *argv[])
{
	if(argc!=3)
	{
		printf("Error, debes introducir 2 numeros.\n");
		exit(EXIT_FAILURE);
	}
	var=0;
	int n=atoi(argv[1]),iter=atoi(argv[2]),i;
	pthread_t *tid;
	tid=(pthread_t*)malloc(n*sizeof(pthread_t));
	for(i=0 ; i<n ; i++)
	{
		pthread_create(&(tid[i]),NULL,(void *)funcion,&iter);
	}
	for(i=0 ; i<n ; i++)
	{
		pthread_join(tid[i],NULL);
	}
	printf("\n\tLa variable global vale: %d\n\n",var);
	return 0;
}