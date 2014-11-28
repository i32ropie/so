#ifndef _FUNCIONES_H
#define _FUNCIONES_H

pthread_mutex_t lock;
int *critico;

void *ProdCons(void *hebra);

void rellenaCritico();

void muestraCritico();


#endif