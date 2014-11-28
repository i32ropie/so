
#include "funciones.h"


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
	tid = reservaThread(n);
	reservaVector();
	//printf("HOLA.\n");
	for(i=0 ; i<n ; i++)
	{
		//printf("HOLA%d/.\n",i);
		pthread_create(&(tid[i]),NULL,(void*)funcion,&vtid[i]);
		//printf("HOLA%d\\.\n",i);
	}
	//printf("HOLA____.\n");

	for(i=0 ; i<n ; i++)
	{
		pthread_join(tid[i],&suma);
	}


	printf("\n%d\n\n",*((int*)suma));

	free(tid);
	free(vector);

	return 0;
}