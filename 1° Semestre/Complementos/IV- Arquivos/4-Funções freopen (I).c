#include<stdio.h>

int main ()
{
	char x[100];	//100 � a quantidade de caracteres que vai ser amazenada
	
	//Vai ler 49 caracteres mais o caractere nulo (\0)
	fgets (x, 50, stdin);	//Geralmente stdin representa o teclado

	printf ("%s", x);

	freopen ("arquivo 1.txt", "r", stdin);
	//Vai redirecionar o string de onde � lido para o endere�o informado
	//No caso, a strind de onde � lido � o teclado

	fgets (x, 50, stdin);
	printf ("%s", x);

	return 0;
}
