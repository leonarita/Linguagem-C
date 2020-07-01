#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>	//Variáveis boolerianas (bool)

int main ()
{
	char variavelChar = 'a';
	printf ("%c\n", variavelChar);
	scanf ("%c", &variavelChar);
	printf ("%c\n", variavelChar);
	
	bool variavelBool = true;   //false (Aparece 0 ao executar) ou true (Aparece 1 ao executar)
	printf ("%i\n", variavelBool);
	
	long int variavelInt1 = 10324323232;   //Lida com números grandes
	printf ("%i\n", variavelInt1);
	scanf ("%i", &variavelInt1);
	printf ("%i\n", variavelInt1);
	
	const int variavelInt2 = 10;   //Não pode alterar variável
	printf ("%i\n", variavelInt2);
	scanf ("%i", &variavelInt2);
	printf ("%i\n", variavelInt2);
	//Const dá para usar em float, char, ...
	
	float variavelFloat = 10.10;
	printf ("%f\n", variavelFloat);
	scanf ("%f", &variavelFloat);
	printf ("%f\n", variavelFloat);
	
	double variavelDouble1 = 10.10;   //Mais precisa do que a float
	printf ("%f\n", variavelDouble1);
	scanf ("%lf", &variavelDouble1);
	printf ("%f\n", variavelDouble1);
	//long double, const double
	
	unsigned double variavelDouble2 = -10.10;   //Unsigned limita para valores positivos: unsigned float, unsigned int
	printf ("%f\n", variavelDouble2);
	scanf ("%lf", &variavelDouble2);
	printf ("%f\n", variavelDouble2);
	
	//Overflow e Underflow(Transbordamento)
	short x=214783647;		//Overflow -> A variável não tem bits suficiente para armazenar esse número positivo
	short y=-214783648;		//Underflow -> A variável não tem bits suficiente para armazenar esse número negativo
	//Inteira que armazena numeros menores do que o int
	printf ("%i \n", x);
	printf ("%i \n", y);
	
	//long long int, unsigned long int, ...	*/
	//extern int
	
	return 0;
}
