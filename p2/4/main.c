#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char const *argv[])
{
	if(argc!=3)
	{
		printf("Ha introducido un numero incorrecto de parametros.");
		exit(EXIT_FAILURE);
	}
	
	pthread_t tid1,tid2;
	char cad1[256],cad2[256];
	strcpy(cad1,argv[1]);
	strcpy(cad2,argv[2]);
	
	pthread_create(&tid1,NULL,(void *)funcion,cad1);
	pthread_create(&tid2,NULL,(void *)funcion,cad2);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);


	return 0;
}