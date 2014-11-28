#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void *imprime(void *cadena)
{
	char *cad=(char *)cadena;
	int i=0;
	for(i=0 ; i<(strlen(cad)) ; i++)
	{
		printf("%c",cad[i]);
		fflush(stdout);
		sleep(1);
	}
}