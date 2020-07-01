#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int funcao (int **piParametro)
{	printf ("%d\n", &piParametro);		//Endereço de memória de piParametro
	printf ("%d\n", piParametro);		//Conteudo de piParametro
	printf ("%d\n", *piParametro);		//Conteúdo do endereço apontado por piParametro (piVariavel)
	printf ("%d\n", **piParametro);		//Valor do endereço apontado por piParametro (*piVariavel)

	return 0;
}

int main (void)
{	setlocale (LC_ALL, "");

	int *piVariavel;
	piVariavel = (int *) malloc (sizeof(int));
	*piVariavel = 0;

	printf ("%d\n", &piVariavel);
	printf ("%d\n", piVariavel);
	printf ("%d\n\n\n\n", *piVariavel);

	funcao (&piVariavel);

	return 0;
}
