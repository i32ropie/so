a.out: main.o funciones.o funciones.h
	gcc main.c funciones.c -lpthread -g

main.o: main.c
	gcc -c main.c

funciones.o: funciones.c
	gcc -c funciones.c

clean:
	@rm *.o *.out
	@echo Limpiado los archivos .o y los ejecutables.