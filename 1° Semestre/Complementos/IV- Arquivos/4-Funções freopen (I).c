#include<stdio.h>

int main ()
{
	char x[100];	//100 é a quantidade de caracteres que vai ser amazenada
	
	//Vai ler 49 caracteres mais o caractere nulo (\0)
	fgets (x, 50, stdin);	//Geralmente stdin representa o teclado

	printf ("%s", x);

	freopen ("arquivo 1.txt", "r", stdin);
	//Vai redirecionar o string de onde é lido para o endereço informado
	//No caso, a strind de onde é lido é o teclado

	fgets (x, 50, stdin);
	printf ("%s", x);

	return 0;
}
