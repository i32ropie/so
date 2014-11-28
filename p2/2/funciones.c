#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>

void *funcion(void *resultado)
{
	int a,b;
	srand(time(NULL));
	a=rand()%20;
	b=rand()%20;
	printf("Creado a=%d b=%d, a+b=%d\n", a,b,a+b);
	(*(int*)resultado)+=a+b;
}