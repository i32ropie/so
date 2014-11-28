#include <stdio.h>
#include "funciones.h"
#include <pthread.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	if(argc!=2)
	{
		printf("Error, debes pasarle como parametro en cuantos vectores dividir la suma.\n");
		exit(EXIT_FAILURE);
	}
	if(atoi(argv[1])<1 || atoi(argv[1])>10)
	{
		printf("Error, el numero de hebras a utilizar debe estar entre 1 y 10\n");
		exit(EXIT_FAILURE);
	}
	int i, n=atoi(argv[1]),vtid[10]={0,1,2,3,4,5,6,7,8,9};
	pthread_t *tid; //Para las 'n' hebras.
	void *suma; //Para el pthread_join.
	suma=(void *)malloc(sizeof(int));
	reservaThread(tid,n);
	reservaVector(vector);
	/*for(i=0 ; i<100 ; i++)
	{
		vector[i]=rand()%10;
	}*/
	printf("HOLA1.\n");
	for(i=0 ; i<10 ; i++)
	{
		printf("HOLA2/.\n");
		pthread_create(&(tid[i]),NULL,(void*)funcion,&vtid[i]);
		printf("HOLA2\\.\n");
	}
	printf("HOLA3.\n");

	for(i=0 ; i<10 ; i++)
	{
		pthread_join(tid[i],&suma);
	}


	printf("\n%d\n\n",*((int*)suma));

	free(tid);
	free(vector);

	return 0;
}


/*
Buenos días, intentando hacer la práctica 3, aunque me compila, siempre me da violación de segmento. He intentado tocar mil cosas, pero no consigo avanzar. Te adjunto mis archivos y te explico aquí lo que yo pienso sobre el programa, que quizá ahí resida el problema.
(En la versión primera)
      -Tengo el vector 'vtid' para pasarle al crear las hebras que numero de hebra es, también he pensado en pasarle la 'i', porque va tomando los mismos valores, pero creo recordar que seguía dando el mismo fallo.
      -Cuando creo 'void *suma', no se si tengo que hacerle un malloc, pero con él o sin él, me sigue dando la violación de segmento antes de su uso, a sí que...
      -He creado un vector de tids dinamico, para que el vector tenga el tamaño de hebras a crear.
      -Reservo la memoria del vector global de 100 elementos y lo inicializo con elementos entre 0 y 10. No sé si el vector para que se considere variable global hay que declararlo en el archivo 'funciones.h', pero lo he puesto ahí porque he pensado ahí era el mejor sitio porque en los .c añado 'funciones.h' y si lo ponía en el 'main.c' luego me daba problema en el 'funciones.c'. Lo he rellenado dentro de la función de reservar memoria

Eduardo Roldán Pijuán
Estudiante de grado en Ingeniería Informática
Escuela Politécnica Superior de Córdoba
Universidad de Córdoba
*/