/*  4.2 Ejercicio2
Cree un programa a partir del cual se creen tres hilos diferentes. Cada hilo debe escribir un carácter
en pantalla 5 veces seguidas. Estructure su programa de manera que no haya intercalado de
caracteres entre los hilos, lo cuales deben estar ejecutándose de forma paralela (ojo, no lo haga
secuencialmente). El main o hebra principal también debe escribir en pantalla. De esta forma, una
posible salida por pantalla podría ser esta:
*****+++++-----/////
Evidentemente, la sección crítica será la salida estándar del sistema. Probablemente necesitará usar
la función fflush() entre escrituras. Ponga también un sleep(1) entre ellas para observar las salidas
por pantalla.*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "funciones.h"


main(){


cuenta = 0;
pthread_t* tid = (pthread_t*)malloc(3*sizeof(pthread_t));
int i;
pthread_mutex_init(&lock, NULL);

	for(i = 0; i < 5; i++){
		printf("*");
	}
		fflush(stdout);

	for(i = 0; i < 3; i++){
		pthread_create(&tid[i], NULL, (void*)funcion, NULL);
	}

	for(i = 0; i < 3; i++){
		pthread_join(tid[i], NULL);
	}

pthread_mutex_destroy(&lock);
}

