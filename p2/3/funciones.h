#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <pthread.h>

int *vector;

void *funcion(void *tid);

void reservaThread(pthread_t *tid, int n);

void reservaVector(int *v);


#endif