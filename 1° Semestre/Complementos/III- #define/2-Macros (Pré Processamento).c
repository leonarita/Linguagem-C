#include<stdio.h>
#include<locale.h>

#define MAIOR(x,y) x>y ? x : y
#define E_MINUSCULO(char) char>='a' && char<='z'

int main ()
{	setlocale (LC_ALL, "");
	char x;
	int i;

	for (i=1; i<=5; i++)
	{	printf ("Digite um algarismo (letra ou número): ");
		scanf ("%c", &x);
		fflush(stdin);
		
		if (E_MINUSCULO(x))
			printf ("É uma letra minuscula!\n\n");
		else
			printf ("Não é uma letra minuscula!\n\n");	}
		
	printf ("%i\n", MAIOR(100, 50));

	getchar();
}
