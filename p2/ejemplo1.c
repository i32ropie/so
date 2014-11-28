#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//Declaración de una estructura
struct param
{
	char * frase;
	int numero;
};
/* Función que se asignará a los hilos que se creen. Recibe un puntero a estructura */
void *hiloMensaje (void *mensa)
{
	//Casting siempre necesario, ya que realmente lo que recibe es un puntero a void
	struct param *aux = (struct param *) mensa;
	printf("%s %d\n", aux->frase, aux->numero);
}

int main()
{
	pthread_t thd1, thd2; //Declaración de dos hebras, hilos o procesos ligeros. NO CREACION
	//Inicializacion de 2 estructuras de tipo “struct param”
	struct param param1 = {"Soy el hilo: ", 1};
	struct param param2 = {"Digo otra cosa ", 2};
	/* Creamos dos hilos. La función la pasaremos como (void *) nombreFuncion. Es decir, hacemos un casting a (void *),
	aunque por defecto no es necesario, ya que el nombre de una función es su dirección de memoria. También es
	importante realizar esto con la dirección de memoria de la variable que contiene los parámetros que se le pasan a la
	función */
	pthread_create (&thd1, NULL, (void *) hiloMensaje, (void *) &param1);
	pthread_create (&thd2, NULL, (void *) hiloMensaje, (void *) &param2);
	/* Esperamos la finalización de los hilos. Si la función devolviera algo habría que recogerlo con el segundo
	argumento, que en este caso esta a NULL. Cuando el segundo argumento no es NULL, se recogen los resultados que
	vienen de pthread_exit(), que se explicará a continuación.*/
	/*Si no se ponen estos join() en el programa principal y simplemente lanzamos los dos hilos y finalizamos, lo más
	probable es que los hilos no lleguen a ejecutarse completamente o incluso que no lleguen ni a terminar de arrancar
	antes de que el programa principal termine.*/
	pthread_join(thd1, NULL);
	pthread_join(thd2, NULL);
	printf("Han finalizado los thread.\n");
}