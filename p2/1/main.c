#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char const *argv[])
{
	if(argc!=3)
	{
		printf("Numero de parametros pasados erroneo.\n");
		exit(EXIT_FAILURE);
	}

	char const *cad1=argv[1], *cad2=argv[2];
	pthread_t tip1, tip2;

	pthread_create(&tip1, NULL,(void *) imprime,(char * const) cad1);
	pthread_create(&tip2, NULL,(void *) imprime,(char * const) cad2);

	pthread_join(tip1, NULL);
	pthread_join(tip2, NULL);

	printf("\n");

	return 0;
}