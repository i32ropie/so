#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int *vector;

void *funcion(void *tid);

pthread_t* reservaThread(int n);

void reservaVector();


#endif