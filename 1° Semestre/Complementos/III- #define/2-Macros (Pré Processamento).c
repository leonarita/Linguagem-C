#include<stdio.h>
#include<locale.h>

#define MAIOR(x,y) x>y ? x : y
#define E_MINUSCULO(char) char>='a' && char<='z'

int main ()
{	setlocale (LC_ALL, "");
	char x;
	int i;

	for (i=1; i<=5; i++)
	{	printf ("Digite um algarismo (letra ou n�mero): ");
		scanf ("%c", &x);
		fflush(stdin);
		
		if (E_MINUSCULO(x))
			printf ("� uma letra minuscula!\n\n");
		else
			printf ("N�o � uma letra minuscula!\n\n");	}
		
	printf ("%i\n", MAIOR(100, 50));

	getchar();
}
