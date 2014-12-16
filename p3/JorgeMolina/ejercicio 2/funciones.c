#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "funciones.h"


void* funcion(){
	

int j;

pthread_mutex_lock(&lock);		

	if(cuenta == 0){
	
		for(j = 0; j < 5; j++){
			sleep(1);
			printf("+");
		}
			fflush(stdout);
			cuenta++;
		}
		

	if(cuenta == 1){

		for(j = 0; j < 5; j++){
			sleep(1);
			printf("-");

		}
			fflush(stdout);
			cuenta++;
		}
		
	
	if(cuenta == 2){
	
		for(j = 0; j < 5; j++){
			sleep(1);
			printf("/");
		}
			fflush(stdout);
			cuenta++;
		}
	
pthread_mutex_unlock(&lock);

}
