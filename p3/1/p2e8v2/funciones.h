#ifndef _FUNCIONES_H
#define _FUNCIONES_H


#include <pthread.h>
int var;
pthread_mutex_t lock;

void *funcion(void *iter);

#endif