#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "funciones.h"

int main(int argc, char const *argv[])
{
	int i;
	char c1,c2,c3,c4;
	pthread_t tid1, tid2, tid3;
	for(i=0 ; i<4 ; i++)
	{
		switch(i)
		{
			case 0:
				printf("Introduce el caracter %d: ",i+1);
				scanf("%c",&c1);
				break;
			case 1:
				printf("Introduce el caracter %d: ",i+1);
				getchar();
				scanf("%c",&c2);
				break;
			case 2:
				printf("Introduce el caracter %d: ",i+1);
				getchar();
				scanf("%c",&c3);
				break;
			case 3:
				printf("Introduce el caracter %d: ",i+1);
				getchar();
				scanf("%c",&c4);
				break;
			default:
				printf("Error\n");
		}
	}
	//printf("%c%c%c%c\n",c1,c2,c3,c4 );
	pthread_mutex_init(&lock,NULL);
	pthread_create(&tid1,NULL,(void *)funcion,&c1);
	pthread_create(&tid2,NULL,(void *)funcion,&c2);
	pthread_create(&tid3,NULL,(void *)funcion,&c3);

	pthread_mutex_lock(&lock);
	for(i=0 ; i<5 ; i++)
	{
		printf("%c",c4);
		usleep(100000);
		fflush(stdout);
	}
	pthread_mutex_unlock(&lock);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);

	pthread_mutex_destroy(&lock);
	printf("\n");
	return 0;
}