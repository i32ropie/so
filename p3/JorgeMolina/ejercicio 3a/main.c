/* 4.3 Ejercicio3 


a) Implemente el problema para hilos teniendo en cuenta que la sección crítica va a ser un array de enteros con una capacidad de 5 elementos. Haga una implementación usando mutexs pero no variables de condición, por lo que se producirá espera activa en casos en los que no haya sitio donde producir o no haya items que consumir. 

b) Modifique el apartado a) usando variables de condición junto con mutexs para evitar espera activa. Cuando el consumidor toma un producto notifica al productor que puede comenzar a trabajar nuevamente porque al menos hay un hueco donde poner una producción. En caso contrario si el buffer se vacía, el consumidor se pone a dormir y en el momento en que el productor agrega un producto crea una señal para despertarlo. Consulte la documentación de clases de teoría si lo considera oportuno. A continuación se muestra una solución en pseudocódigo:  */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include "funciones.h"


main(int argc, char* argv[]){

  srand(time(NULL)); //Creamos la semilla.
  int nele = 5; //Número de elementos del vector.
  int error; //Variable que necesitaremos para controlar los errores de pthread_create y pthread_join.
  int i;
  int hebras = atoi(argv[1]); //Número de hebras que vamos a crear.
  pthread_t* tid = (pthread_t*)malloc(hebras*sizeof(pthread_t)); //Reservamos memoria para un vector de hebras.
  
  
  crear_reservarMem_vector(nele); //Reservamos memoria del vector y lo creamos.
  printvector(V, nele); //Imprimimos el vector.

  for(i = 0; i < nele; i++){
    pthread_mutex_init(&vlock[i], NULL); //Iniciamos el mutex[i]
  }

  for(i = 0; i < hebras; i ++){ //Creamos n hebras.
   error = pthread_create(&tid[i], NULL, (void*)ProductorConsumidor, (void*)&hebras);
   //Capturamos los errores que se pueden producir al crear una hebra.
   switch (error)
   {
     case 0: //Correcto.
       printf("\n\n    (Hilo ppal.) Se ha creado la hebra [%d].", i);
       break;
     case EAGAIN: /*El sistema no puede crear más hebras bien porque se ha llegado al máximo PTHREAD_THREADS_MAX
o bien porque se ha quedado sin recursos para ello.*/
       printf("    (Hilo ppal.) Se produjo el error EAGAIN (sin recursos o máximo de hebras alcanzado).\n");
       break;
     case EINVAL: //La configuración especificada en el parámetro attr no es correcta.
       printf("    (Hilo ppal.) Se produjo el error EINVAL (valores de attr incorrectos).\n");
       break;
     case EPERM:  /*El proceso no tiene los permisos apropiados para configurar la política de planificacion
o la configuración indicada en el parámetro attr.*/
       printf("    (Hilo ppal.) Se produjo el error EPERM (sin privilegios para configurar la planificación o attr).\n");
       break;
   }
  }

  for(i = 0; i < hebras; i ++){ //Finalizamos las hebras.
   error = pthread_join(tid[i], NULL);
   switch (error)
   {
     case 0: //Correcto.
       printf("\n        (Hilo ppal.) Terminó correctamente la hebra [%d].\n", i);
       break;
     case EDEADLK: //Se quiso hacer un join a sí misma.
        printf("       ** (Hilo ppal.) Se quiso hacer un join a sí mismo.\n");
        break;
     case EINVAL: //La hebra ha sido detached u otra hebra está esperando a que termine.
        printf("       ** (Hilo ppal.) Se produjo el error EINVAL (la hebra ha sido detached u otra hebra está esperando a que termine.).\n");
        break;
     case ESRCH:  //Se ha hecho un pthread_join sobre una hebra que no existe.
        printf("       ** (Hilo ppal.) Se produjo el error ESRCH (la hebra no existe).\n");
        break;
   }
  }	
	
	
  printvector(V, nele); //Imprimimos el vector nuevamente.	
	
  for(i = 0; i < nele; i++){
    pthread_mutex_destroy(&vlock[5]); //Destruimos el mutex[i].
  }

}

