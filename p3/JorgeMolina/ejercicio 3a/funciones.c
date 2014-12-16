#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "funciones.h"

/*-----------------------------------------------------------------
FUNCION 'ProductorConsumidor'
  Usaremos esta función para ir modificando el vector según sea
 productor, se aumentará el valor de la posición, o consumidor, 
 se decrementará el valor de la posición.
-----------------------------------------------------------------*/
void* ProductorConsumidor(void* hebras){

  int pos = rand()%5; // Posición del vector bloqueada.
  int num = rand()%(*(int*)hebras);
  
  pthread_mutex_lock(&vlock[pos]); //Entrada en la sección crítica.
  
  //Vamos a hacer que los productores sean los pares y los consumidores sean los impares de un numero al azar.
  if(num%2 == 0){ //Par (Productor).
    printf("\nSoy un 'productor' y voy a aumentar la posición [%d] en 1.", pos);
    V[pos]++;
  }

  if(num%2 != 0){ //Impar (Consumidor).
    printf("\nSoy un 'consumidor' y voy a decrementar la posicion [%d] en 1.", pos);
    V[pos]--;
  }
  
  pthread_mutex_unlock(&vlock[pos]); //Salida de la sección crítica.
  sleep(1); //Limpiar la consola de mensajes correctos de create y join.
}


/*-----------------------------------------------------------------
FUNCION crear_reservarMem_vector
  Reservamos memoria para el vector que tenemos declarado como variable
 global y le vamos asignando un valor aleatorio entre 0 y 10.
-----------------------------------------------------------------*/
void crear_reservarMem_vector(int nele){

  int i;
  V = (int*)malloc(nele*sizeof(int));

  for(i = 0; i < nele; i ++){
    V[i] = rand()%11;
  }
  
}


/*-----------------------------------------------------------------
FUNCION printvector
  Imprimimos un vector que se lo pasamos por parámetro.
-----------------------------------------------------------------*/
void printvector(int* V, int nele){

  int i;
  printf("\n");
  for(i = 0; i < nele; i ++){
    printf("%d\t", V[i]);
  }
  printf("\n");
}
