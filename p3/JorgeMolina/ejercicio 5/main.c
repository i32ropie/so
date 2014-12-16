/* 4.4 Ejercicio5

 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include "funciones.h"


main(int argc, char* argv[]){

  system("clear");
  if(argc != 3)
  {
    printf("\nUsa: ./main Nombre_fichero(sin .txt) Numero_copias\n");
    exit(EXIT_FAILURE);
  } 
 
  FILE* fichero;
  pthread_mutex_init(&escritor, NULL);
  pthread_cond_init(&escritos, NULL);
  pthread_cond_init(&leido, NULL);
  
  bytes = 0; //v.g
  hebras_leidas = 0; //v.g
  nhebras = atoi(argv[2]); //v.g

  char* nombref = (char*)malloc(20*sizeof(char));
  char* filename = (char*)malloc(20*sizeof(char));
  
  char** fichero_hebras = (char**)malloc(nhebras*sizeof(char*));
  pthread_t* tidc = (pthread_t*)malloc(nhebras*sizeof(pthread_t));
  pthread_t tid;
  int i, error;
  
   for(i = 0; i < nhebras; i++)
    fichero_hebras[i] = (char*)malloc(50*sizeof(char));
  
  sprintf(nombref, "%s", argv[1]); //Nombre del fichero para escritura, lo pasamos sin .txt
  sprintf(filename, "%s.txt", nombref); //nombre del fichero para lectura

  error = pthread_create(&tid, NULL, (void*)original, (void*)filename);
  if(error != 0)
    printf("\nLa hemos liado...");
    
  for(i = 0; i < nhebras; i++){ //Creamos las hebras que van a copiar el fichero.
    sprintf(fichero_hebras[i], "%s%d.txt", nombref, i);
    pthread_create(&tidc[i], NULL, (void*)copia, (void*)fichero_hebras[i]);
  }

  for(i = 0; i < nhebras; i++){ 
    pthread_join(tidc[i], NULL);
  }
  pthread_join(tid, NULL);
  
  pthread_mutex_destroy(&escritor);
  pthread_cond_destroy(&escritos);
  pthread_cond_destroy(&leido);
  
 }

