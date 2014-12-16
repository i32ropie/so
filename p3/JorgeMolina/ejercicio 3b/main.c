/* 4.3 Ejercicio3 

b) Modifique el apartado a) usando variables de condición junto con mutexs para evitar espera activa. Cuando el consumidor toma un producto notifica al productor que puede comenzar a trabajar nuevamente porque al menos hay un hueco donde poner una producción. En caso contrario si el buffer se vacía, el consumidor se pone a dormir y en el momento en que el productor agrega un producto crea una señal para despertarlo. Consulte la documentación de clases de teoría si lo considera oportuno. A continuación se muestra una solución en pseudocódigo:  */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include "funciones.h"


main(int argc, char* argv[]){

  system("clear");
  if(argc != 2)
  {
    printf("\nUsa: ./main Número_de_hebras\n");
    exit(EXIT_FAILURE);
  } 
  
  srand(time(NULL)); //Creamos la semilla.
  int nele = 5; //Número de elementos del vector.
  int error; //Variable que necesitaremos para controlar los errores de pthread_create y pthread_join.
  int i;
  int hebras = atoi(argv[1]); //Número de hebras que vamos a crear.
  pthread_t* tid = (pthread_t*)malloc(hebras*sizeof(pthread_t)); //Reservamos memoria para un vector de hebras.

  pthread_cond_init(&lleno, NULL); //Iniciamos la variable de condicion
  pthread_cond_init(&vacio, NULL); //Iniciamos la variable de condicion
   
  for(i = 0; i < nele; i++){
    pthread_mutex_init(&vlock[i], NULL); //Iniciamos el mutex[i]
  }
    
  crear_reservarMem_vector(nele); //Reservamos memoria del vector y lo creamos.
  printvector(V, nele); //Imprimimos el vector.


  for(i = 0; i < hebras; i ++){ //Creamos n hebras.

   if(i%2 == 0)
     error = pthread_create(&tid[i], NULL, (void*)Productor, (void*)&hebras); //Creamos un PRODUCTOR
   if(i%2 != 0)
     error = pthread_create(&tid[i], NULL, (void*)Consumidor, (void*)&hebras); //Creamos un CONSUMIDOR
     
   if(error != 0)
     printf("\tError al crear la hebra\n");
  }

  for(i = 0; i < hebras; i ++){ //Finalizamos las hebras.
   error = pthread_join(tid[i], NULL);
   
   if(error != 0)
     printf("\tError al terminar la hebra\n");
  }	
	
	
  printvector(V, nele); //Imprimimos el vector nuevamente.	
	
  for(i = 0; i < nele; i++){
    pthread_mutex_destroy(&vlock[5]); //Destruimos el mutex[i].
  }
   pthread_cond_destroy(&lleno); //Destruimos la variable condicion.
   pthread_cond_destroy(&vacio); //Destruimos la variable condicion.

}

