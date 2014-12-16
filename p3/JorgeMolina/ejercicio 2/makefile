main: main.o funciones.o funciones.h
	gcc main.c funciones.c -o main -lpthread -g
main.o: main.c
	gcc -c main.c
funciones.o: funciones.c
	gcc -c funciones.c
clean:
	rm *.o main
