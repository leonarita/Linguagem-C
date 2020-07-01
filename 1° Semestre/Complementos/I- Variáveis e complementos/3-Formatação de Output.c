#include <stdio.h>

int main ()
{
	int intVar = 9999999;
	int intVar2 = 10;
	double doubleVar=100.123456789;
	
	//Formatação variáveis inteiras
	printf ("Variavel inteira (%%d) = %d \n", intVar);	//Digito
	printf ("Variavel inteira (%%i) = %i \n", intVar);	//Inteiro
	printf ("Variavel inteira (%%x) = %x \n", intVar);	//Hexadecimal
	printf ("Variavel inteira (%%o) = %o \n", intVar);	//Octal
	printf ("\n");
	
	//Formatação variáveis double e float
	printf ("Variavel inteira (%%d) = %d \n", doubleVar);	//Digito
	printf ("Variavel inteira (%%i) = %i \n", doubleVar);	//Inteiro
	printf ("Variavel inteira (%%x) = %x \n", doubleVar);	//Hexadecimal
	printf ("Variavel inteira (%%o) = %o \n", doubleVar);	//Octal
	printf ("\n");
	
	//Deslocar a variável para esquerda
	printf ("Variavel inteira (%%d) = %5d \n", intVar2);	//Deslocou 5 casas
	printf ("Variavel inteira (%%d) = %3d \n", intVar2);	//Deslocou 3 casas
	printf ("\n");
	
	printf ("Variavel inteira (%%d) = %.2d \n", intVar);	//Limitou para duas casas decimais
	printf ("Variavel inteira (%%d) = %.1d \n", intVar);	//Limitou para uma casa decimal
}
