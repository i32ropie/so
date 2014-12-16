#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "funciones.h"

/*-----------------------------------------------------------------
FUNCION 'Productor'
  Usaremos esta función para ir aumentando la posicion del vector si y
 solo si es menor que 10, ya que no admitiremos un vector que esté fuera
 de [0-10].
-----------------------------------------------------------------*/
void* Productor(void* arg){

  int pos = rand()%5; // Posición del vector bloqueada.
  
  pthread_mutex_lock(&vlock[pos]); //Entrada en la sección crítica.

    while(V[pos] == 10){
      pthread_cond_wait(&lleno, &vlock[pos]); //Si está lleno (entandamos por lleno 10) no aumentamos más y esperamos a que lo decrementen.
    }
    printf("\nSoy un 'productor' y voy a aumentar la posición [%d] en 1.", pos);
    V[pos]++;
    pthread_cond_signal(&vacio); //Al haber aumentado en 1 la posicion del vector, desbloqueamos al consumidor.
  
  pthread_mutex_unlock(&vlock[pos]); //Salida de la sección crítica.
}

/*-----------------------------------------------------------------
FUNCION 'Consumidor'
  Usaremos esta función para decrementar la posición del vector si y
 solo si es mayor que 0, ya que no admitiremos un vector que esté fuera
 de [0-10].
-----------------------------------------------------------------*/
void* Consumidor(void* arg){

  int pos = rand()%5; // Posición del vector bloqueada.
  
  pthread_mutex_lock(&vlock[pos]); //Entrada en la sección crítica.  

    while(V[pos]==0){
      pthread_cond_wait(&vacio, &vlock[pos]);
    }
    printf("\nSoy un 'consumidor' y voy a decrementar la posicion [%d] en 1.", pos);
    V[pos]--;
    pthread_cond_signal(&lleno);  
  
  pthread_mutex_unlock(&vlock[pos]); //Salida de la sección crítica.
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
