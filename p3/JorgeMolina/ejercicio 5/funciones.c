#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "funciones.h"



/*-----------------------------------------------------------------

-----------------------------------------------------------------*/

void* original(void* filename){


  FILE* aux;
  printf("\nEl fichero que quiero leer. <%s>\n", (char*)filename);

  if((aux = fopen((char*)filename, "r")) == NULL){ //ABRIMOS EN MODO LECTURA
    printf("\nFichero no encontrado.");
    exit(EXIT_FAILURE);
    }

  do{
    pthread_mutex_lock(&escritor); //entrada en la S.C (*)
    printf("\nLeyendo!...\n");
    bytes = fread(linea, sizeof(char), 1024, aux); //Almacenamos en "bytes" los bytes leidos. 
    if(bytes > 0){ //Si ha almacenado algo quiere decir que el fichero no está vacío.
      pthread_cond_broadcast(&leido); //Esperamos a que todas las hebras ejecuten el wait. (signal masivo)
      pthread_cond_wait(&escritos, &escritor); //Hasta que la ultima hebra no lee, no manda la señal para continuar
      hebras_leidas = 0; //Actualizamos hebras leidas a 0.
      }
    else
      pthread_cond_broadcast(&leido); /*En el caso de no haber leido nada, esperamos 
                                                                                     */

    pthread_mutex_unlock(&escritor);
    }while(bytes > 0);
   
  fclose(aux);
  pthread_exit(NULL);

}


/*-----------------------------------------------------------------

-----------------------------------------------------------------*/

void* copia(void* fichero_hebras){
  FILE* aux;
  char* filename = (char*)malloc(20*sizeof(char));
  strcpy(filename, (char*) fichero_hebras);
        
          if((aux = fopen(filename, "a")) == NULL){ //Comprobación de errores.
            printf("\nFichero no encontrado.\n");
            exit(EXIT_FAILURE);
          }
          
do{
      
  pthread_mutex_lock(&escritor);
   while(!bytes > 0){  //Mientras no haya leido, me mantengo en espera de la señal broadcast.
   printf("\nEstoy aqui(funcion copia, esperando)\n");
   pthread_cond_wait(&leido, &escritor);
   }
  pthread_mutex_unlock(&escritor);
  
  if(bytes > 0){
   fprintf(aux, "%s",linea);
   fflush(aux); //COPIA
  
  pthread_mutex_lock(&escritor);
    hebras_leidas++; //Por cada hebra que haya leido, aumentamos la variable.
    printf("\nHebras_leidas puestas a %d \n", hebras_leidas);
    if(hebras_leidas == nhebras){ //La ultima hebra cumple el condicional
      pthread_cond_signal(&escritos); /*Al llegar la ultima hebra, manda una señal al lector
                                       para que continue y éste pone las hebras_leidas a 0.*/
     }
    pthread_cond_wait(&leido, &escritor); // El resto de hebras, se quedan en espera de que llegue
                                   // la ultima y hasta que el lector no ejecuta el broadcast
                                   // no continuan.
  pthread_mutex_unlock(&escritor); //Desbloqueo el mutex que ha puesto el lector (*)
  
  }
}while(bytes > 0);

pthread_exit(NULL);
}
