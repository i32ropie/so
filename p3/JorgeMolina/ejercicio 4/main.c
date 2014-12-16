/* 4.4 Ejercicio4 

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
    printf("\nUsa: ./main Número_de_hebras nombre_fichero.txt\n");
    exit(EXIT_FAILURE);
  } 
  
  FILE* fichero;
  char* nombre = (char*)malloc(100*sizeof(char)); //string dinámica.
  pthread_t* tidl = (pthread_t*)malloc(atoi(argv[1])*sizeof(pthread_t));
  pthread_t* tide = (pthread_t*)malloc(atoi(argv[1])*sizeof(pthread_t));
  int i;
  int errorl, errore; //Errores en pthread_create
  n_lectores = 0; //Var global
  int hebras = atoi(argv[1]); //Numero de hebras
  nombre = argv[2];
  
  pthread_mutex_init(&lectores, NULL);
  pthread_mutex_init(&escritores, NULL);
  
  
  printf("\n\tEl número de hebras que vamos a crear es de: %d\n\tEl nombre del fichero es: %s\n", hebras, argv[2]);


  if((fichero = fopen(nombre, "r+")) == NULL){ //Comprobación de errores.
    printf("\nFichero no encontrado.\n");
    exit(EXIT_FAILURE);
  }
  printf("\nFichero encontrado.\n");
  fclose(fichero); //Lo cerramos después de la comprobación.


  for( i = 0; i < hebras; i ++){ //CREAMOS LAS HEBRAS
    errorl = pthread_create(&tidl[i], NULL, (void*)lectura, (void*)nombre);
    errore = pthread_create(&tide[i], NULL, (void*)escritura, (void*)nombre);
    if(errorl != 0)
      printf("\nError al crear la hebra de lectura %d", i);
    if(errore != 0)
      printf("\nError al crear la hebra de escritura %d", i);
  }


  for( i = 0; i < hebras; i ++){ // TERMINAMOS LAS HEBRAS
    errorl = pthread_join(tidl[i], NULL);
    errore = pthread_join(tide[i], NULL);
    if(errorl != 0)
      printf("\nError al crear la hebra de lectura %d", i);
    if(errore != 0)
      printf("\nError al crear la hebra de escritura %d", i);
  }






pthread_mutex_destroy(&escritores);
pthread_mutex_destroy(&lectores);
}

