#include<stdio.h>

int main ()
{
	char x[100];	//100 é a quantidade de caracteres que vai ser amazenada
	
	FILE *file = fopen ("Arquivo 1.txt", "r");
	
	fgets (x, 100, file);	//Digitar algo
	printf ("%s", x);
	
	freopen ("Arquivo 2.txt", "r", file);
	fgets (x, 100, file);
	printf ("%s", x);

	return 0;
}
