//Programa que calcula factorial de un numero pasado por linea de ordenes.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		printf("Error, debes introducir al menos un elemento.\n");
		exit(EXIT_FAILURE);
	}
	if(argc > 2)
	{
		printf("Error, debes introducir solo un elemento\n");
		exit(EXIT_FAILURE);
	}

	int numero=atoi(argv[1]);
	int resultado=numero;
	int i;
	for(i=numero-1 ; i>0 ; i--)
	{
		resultado=resultado*i;
	}

	//printf("El factorial de %d es %d.\n",atoi(argv[1]),resultado);

	sleep(1);

	return resultado;
}