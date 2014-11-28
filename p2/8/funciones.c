#include "funciones.h"

void *funcion(void *iter)
{
	int i,j;
	for(i=0 ; i<*((int*)iter) ; i++)
	{
		for(j=0 ; j<50 ; j++)
		{
			var+=1;
		}
	}
}