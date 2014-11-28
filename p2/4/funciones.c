#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#include "funciones.h"

void *funcion(char *cad)
{
	char aux[256];
	sprintf(aux,"ffmpeg -i %s.mp4 -f mp3 -ab 192000 -ar 48000 -vn %s.mp3",cad,cad);
	system(aux);
	pthread_exit(EXIT_SUCCESS);
}