#include <iostream>
#include <unistd.h> //Se necesita "unistd.h"
//Aunque esté en c++, hay que poner "unistd.h" en vez de "cunistd" como en la biblioteca "stdio.h" que ponemos "cstdio". No sé por qué.
//Aquí viene la lista de los distintos parámetros que se pueden usar: "http://en.wikipedia.org/wiki/ANSI_escape_code#CSI_codes" y lo encontré en StackOverFlow: "http://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal"

using namespace std;
int main(){
	cout << "COLORES DE LETRA" << endl;
	cout << "\033[30mColor 30\033[0m -> \\033[30m" << endl; //GRIS OSCURO
	cout << "\033[31mColor 31\033[0m -> \\033[31m" << endl; //ROJO
	cout << "\033[32mColor 32\033[0m -> \\033[32m" << endl; //VERDE
	cout << "\033[33mColor 33\033[0m -> \\033[33m" << endl; //AMARILLO
	cout << "\033[34mColor 34\033[0m -> \\033[34m" << endl; //AZUL OSCURILLO
	cout << "\033[35mColor 35\033[0m -> \\033[35m" << endl; //MORADO
	cout << "\033[36mColor 36\033[0m -> \\033[36m" << endl; //AZUL CLARITO
	cout << "\033[37mColor 37\033[0m -> \\033[37m" << endl; //GRIS CLARITO
	cout << "\033[38mColor 38\033[0m -> \\033[38m" << endl; //DEFAULT
	cout << "\033[39mColor 39\033[0m -> \\033[39m" << endl; //DEFAULT

	cout << endl << "COLORES DE FONDO" << endl;
	cout << "\033[40mColor 40\033[0m -> \\033[40m" << endl; //GRIS OSCURO
	cout << "\033[41mColor 41\033[0m -> \\033[41m" << endl; //ROJO
	cout << "\033[42mColor 42\033[0m -> \\033[42m" << endl; //VERDE
	cout << "\033[43mColor 43\033[0m -> \\033[43m" << endl; //AMARILLO
	cout << "\033[44mColor 44\033[0m -> \\033[44m" << endl; //AZUL OSCURILLO
	cout << "\033[45mColor 45\033[0m -> \\033[45m" << endl; //MORADO
	cout << "\033[46mColor 46\033[0m -> \\033[46m" << endl; //AZUL CLARITO
	cout << "\033[47mColor 47\033[0m -> \\033[47m" << endl; //GRIS CLARITO
	cout << "\033[48mColor 48\033[0m -> \\033[48m" << endl; //DEFAULT
	cout << "\033[49mColor 49\033[0m -> \\033[49m" << endl; //DEFAULT

	cout << endl << "OTROS CÓDIGOS" << endl;
	cout << "Cancelar todos los atributos activos -> \\033[0m" << endl;
	cout << "\033[1mTexto en negrita\033[0m -> \\033[1m" << endl;

	cout << endl << "VARIOS CÓDIGOS A LA VEZ" << endl;
	cout << "\033[31;47mTexto rojo sobre fondo gris clarito\033[0m -> \\033[31;47m" << endl;
	cout << "\033[31;47mTexto rojo sobre fondo gris clarito con una \033[1mpalabra\033[0m\033[31;47m en negrita\033[0m -> Empieza igual que el de antes, pero antes de palabra añadimos \\033[1m y despues, reseteamos atributos con \\033[0m y volvemos a poner lo que teníamos con \\033[31;47m" << endl;
	cout << "\033[30mA\033[31mR\033[32mC\033[33mO\033[34mI\033[35mR\033[36mI\033[37mS\033[38m" << endl;

	return 0;
}