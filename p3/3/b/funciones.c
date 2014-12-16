#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <cstdlib.h>
#include "funciones.h"

void *Prod(void *nHebra){
	int aux=rand()%5;
	pthread_mutex_lock(&lock[aux]);

	while(critico[aux]==10){
		pthread_cond_lock(&lleno,&lock[aux]);
	}
	cout << "\033[1mPRODUCTOR " << *(int*)hebra << ":\033[0m Incremento una unidad la posición \033[32m" << aux << "\033[0m del vector." << endl;

}