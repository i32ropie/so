#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "funciones.h"

int main(int argc, char const *argv[])
{
	if(argc!=2) //Hay que introducir por parámetro el número de hebras.
	{
		system("clear");
		printf("\e[1;33mError, debes pasar un parámetro que será el número de hebras.\n");
		exit(EXIT_FAILURE);
	}

	pthread_t *tid=(pthread_t*)malloc(atoi(argv[1])*sizeof(pthread_t)); //Declaro el número de hebras introducido por parámetro.
	int i;
	srand(time(NULL));
	
	system("clear");
	printf("Productor: Coge un elemento aleatorio del vector. Si este es par, lo incrementa, si es impar, lo decrementa.\nConsumidor: Coge un elemento aleatorio del vector. Si este es par, lo decrementa, si es impar, lo incrementa.\n\n");
	if(pthread_mutex_init(&lock,NULL)) //Inicio el lock con control de error.
	{
		printf("\e[1;33mError asignando el MUTEX_INIT\n");
		exit(EXIT_FAILURE);
	}
	
	if((critico=(int*)malloc(5*sizeof(int)))==NULL) //Reservo memoria de array de enteros con control de error.
	{
		printf("\e[1;33mError asignando el memoria para la variable global crítico\n");
		exit(EXIT_FAILURE);
	}	
	
	rellenaCritico(); //Relleno el vector
	muestraCritico(); //Muestro el vector

	for(i=0 ; i<atoi(argv[1]) ; i++)
	{
		if(pthread_create(&(tid[i]),NULL,(void*)ProdCons,&i)) //Creo el numero de hebras introducido como parámetro con control de error.
		{
			printf("\e[1;33mError creando la hebra %d\n",i+1);
			exit(EXIT_FAILURE);
		}
		usleep(500000);
	}
	printf("\033[1;33mTODAS LAS HEBRAS CREADAS Y EJECUTADAS.\033[0m\n");
	sleep(1);
	muestraCritico();
	for(i=0 ; i<atoi(argv[1]) ; i++)
	{
		if(pthread_join(tid[i],NULL)) //Creo el numero de hebras introducido como parámetro con control de error.
		{
			printf("\e[1;33mError recogiendo la hebra %d\n",i+1);
			exit(EXIT_FAILURE);
		}
	}



	if(pthread_mutex_destroy(&lock)) //Inicio el lock con control de error.
	{
		printf("\e[1;33mError asignando el MUTEX_DESTROY\n");
		exit(EXIT_FAILURE);
	}
	printf("\n\n");
	return 0;
}