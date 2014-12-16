#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "funciones.h"

void *ProdCons(void *hebra)
{
	int aux,i;
	aux=rand()%5;
	if(pthread_mutex_lock(&lock))
	{
		printf("\e[1;33mError asignando el MUTEX_LOCK\n");
		exit(EXIT_FAILURE);
	}

	if(((*(int*)hebra)%2)==0) //Productor. Coge un elemento aleatorio del vector. Si este es par, lo incrementa, si es impar, lo decrementa.
	{
		if((critico[aux]%2)==0)
		{
			printf("\nProductor \e[1;33m%d\033[0m: El valor de la posicion \e[1;31m%d\033[0m del vector critico es \e[1;31m%d\033[0m, como es par, incremento su valor.\n",(*(int*)hebra)+1,aux,critico[aux]);
			critico[aux]++;
		}
		else 
		{
			printf("\nProductor \e[1;33m%d\033[0m: El valor de la posicion \e[1;31m%d\033[0m del vector critico es \e[1;31m%d\033[0m, como es impar, decremento su valor.\n",(*(int*)hebra)+1,aux,critico[aux]);
			critico[aux]--;
		}
		printf("\tPosicion \e[1;31m%d\033[0m del vector actualizado a \e[1;31m%d\033[0m\n",aux,critico[aux]);
		printf("VECTOR: \033[1;36m<");
		for(i=0 ; i<5 ; i++)
		{
			if(i!=aux)
			{
				printf("%d",critico[i]);
			}
			else
			{
				printf("\e[1;31m%d\033[36m",critico[i]);
			}
			if(i!=4) printf(",");
		}
		printf(">\033[0m\n");

	}
	else //Consumidor.Coge un elemento aleatorio del vector. Si este es par, lo decrementa, si es impar, lo incrementa.
	{
		if((critico[aux]%2)!=0)
		{
			printf("\nConsumidor \e[1;33m%d\033[0m: El valor de la posicion \e[1;31m%d\033[0m del vector critico es \e[1;31m%d\033[0m, como es impar, incremento su valor.\n",(*(int*)hebra)+1,aux,critico[aux]);
			critico[aux]++;
		}
		else 
		{
			printf("\nConsumidor \e[1;33m%d\033[0m: El valor de la posicion \e[1;31m%d\033[0m del vector critico es \e[1;31m%d\033[0m, como es par, decremento su valor.\n",(*(int*)hebra)+1,aux,critico[aux]);
			critico[aux]--;
		}
		printf("\tPosicion \e[1;31m%d\033[0m del vector actualizado a \e[1;31m%d\033[0m\n",aux,critico[aux]);
		printf("VECTOR: \033[1;36m<");
		for(i=0 ; i<5 ; i++)
		{
			if(i!=aux)
			{
				printf("%d",critico[i]);
			}
			else
			{
				printf("\e[1;31m%d\033[36m",critico[i]);
			}
			if(i!=4) printf(",");
		}
		printf(">\033[0m\n");

	}

	if(pthread_mutex_unlock(&lock))
	{
		printf("\e[1;33mError asignando el MUTEX_UNLOCK\n");
		exit(EXIT_FAILURE);
	}

}

void rellenaCritico()
{
	int i;
	for(i=0 ; i<5 ; i++) //Relleno el vector aleatoriamente.
	{
		critico[i]=rand()%10;
	}
}

void muestraCritico()
{
	int i;
	printf("VECTOR: \033[1;32m<");
	for(i=0 ; i<5 ; i++)
	{
		printf("%d",critico[i]);
		if(i!=4) printf(",");
	}
	printf(">\033[0m");
}