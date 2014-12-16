#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <cstdlib.h>
#include "funciones.h"

int main(int argc, char const *argv[])
{
	if(argc!=2){
		system("clear");
		cout << "Error, no has introducido el número de hebras a crear." << endl;
		exit(EXIT_FAILURE);
	}

	pthread_t *tid=(pthread_t*)malloc(atoi(argv[1])*sizeof(pthread_t)); //Declaro el número de hebras introducido por parámetro.
	int i;
	srand(time(NULL));
	system("clear");
	printf("\033[1mINCIO DEL PROGRAMA\033[0m\n\n");
	for(i=0 ; i<5 ; i++){
		if(pthread_mutex_init(&lock[i],NULL)){ //Inicio el lock con control de error.
			printf("\e[1;33mError asignando el MUTEX_INIT\n");
			exit(EXIT_FAILURE);
		}
	}
	if(pthread_cond_init(&lleno,NULL)){ //Inicio el cond con control de error.
		printf("\e[1;33mError asignando el MUTEX_INIT\n");
		exit(EXIT_FAILURE);
	}
	if(pthread_cond_init(&vacio,NULL)){ //Inicio el cond con control de error.
		printf("\e[1;33mError asignando el MUTEX_INIT\n");
		exit(EXIT_FAILURE);
	}

	if((critico=(int*)malloc(5*sizeof(int)))==NULL){ //Reservo memoria de array de enteros con control de error.
		printf("\e[1;33mError asignando el memoria para la variable global crítico\n");
		exit(EXIT_FAILURE);
	}	
	
	rellenaCritico(); //Relleno el vector
	muestraCritico(); //Muestro el vecto

	for(i=0 ; i<atoi(argv[1]) ; ++i){
		if((i%2)==0){
			if(pthread_create(&(tid[i]),NULL,(void*)Prod,&i)) //Creo el numero de hebras introducido como parámetro con control de error.
			{
				printf("\e[1;33mError creando la hebra %d\n",i+1);
				exit(EXIT_FAILURE);
			}
		}
		else{
			if(pthread_create(&(tid[i]),NULL,(void*)Cons,&i)) //Creo el numero de hebras introducido como parámetro con control de error.
			{
				printf("\e[1;33mError creando la hebra %d\n",i+1);
				exit(EXIT_FAILURE);
			}
		}
		usleep(500);
	}

	return 0;
}