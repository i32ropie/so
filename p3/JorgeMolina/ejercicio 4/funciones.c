#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "funciones.h"

/*------------------------------------------------------------------------
funcion LEERFICHERO ( Recibe como parametro el nombre del fichero
                      que vamos a leer)
------------------------------------------------------------------------*/
void* lectura(void* nombre){
  FILE* aux;
  char linea[256];
  
  pthread_mutex_lock(&lectores); //Bloqueamos la entrada al resto de lectores. (Entrada a la S.C)
    n_lectores++; //En caso de ser la primera hebra, n_lectores pasa a ser 1.
    if(n_lectores == 1){ //Solo la primera hebra de lectura bloquea a los escritores.
      pthread_mutex_lock(&escritores); //En caso de que esté ejecutandose un escritor, esperamos.
    }
  pthread_mutex_unlock(&lectores); //Dejamos libre la entrada a la S.C para el siguiente lector.
  
  printf("\tEl nombre del fichero que vamos a leer es: %s\n", (char*)nombre); //comprobacion...
  
  if((aux = fopen((char*)nombre, "r")) == NULL){ //Comprobación de errores.
    printf("\nFichero no encontrado.\n");
    exit(EXIT_FAILURE);
  }
    
    /*Poner como comentario el bucle while para demostrar la alternancia.*/
 /* while(fgets(linea, 256, aux)){ //Imprimimos el fichero de texto completo.
   printf("%s", linea);
  }*/

  fclose(aux); //Cerramos el fichero.
  
  pthread_mutex_lock(&lectores); //Entrada a la S.C
    n_lectores--; //Vamos decrementando n_lectores, hasta llegar a 0.
    if(n_lectores == 0){ //Si la hebra que entra en la S.C es la última, se encargará de desbloquear a los escritores.
      pthread_mutex_unlock(&escritores); //Desbloqueamos a los escritores.
    }
  pthread_mutex_unlock(&lectores); //Salida de la S.C
  
}

/*------------------------------------------------------------------------
funcion ESCRIBIRFICHERO ( Recibe como parametro el nombre del fichero
                          sobre el que vamos a escribir)
------------------------------------------------------------------------*/
void* escritura(void* nombre){
  FILE* aux;
  char texto[100];
  
  pthread_mutex_lock(&escritores); //Entrada a la S.C
  printf("\tEl nombre del fichero sobre el que vamos a escribir es: %s\n", (char*)nombre); //comprobacion...

  if((aux = fopen((char*)nombre, "a")) == NULL){ //Comprobación de errores.
    printf("\nFichero no encontrado.\n");
    exit(EXIT_FAILURE);
  }

  //printf("\nIntroduce el libro que quieres añadir al catalogo: ");
  sprintf(texto, " - NUEVO LIBRO\n");
  //fgets(texto, 100, stdin);
  
  fprintf(aux, "%s", texto); // Imprimimos "- NUEVO LIBRO\n" en el fichero.
  fclose(aux); //Cerramos el fichero
  pthread_mutex_unlock(&escritores); //Salida de la S.C 

}
