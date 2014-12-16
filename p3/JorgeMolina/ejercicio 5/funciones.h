#ifndef FUNCIONES_H
#define FUNCIONES_H

void* copia(void* fichero_hebras);
void* original(void* filename);
char linea[1024];

pthread_mutex_t escritor;
pthread_cond_t escritos;
pthread_cond_t leido;
int hebras_leidas;
int nhebras;
int bytes;

#endif
