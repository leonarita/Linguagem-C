#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void)
{	setlocale (LC_ALL, "");

	/* A declara��o de uma matriz de 2 dimens�es exige um ponteiro para ponteiro. */
	
	int **p;
	int i,j,k,x;

	printf ("\nDigite as dimens�es da matriz: ");
	scanf ("%d %d", &i, &j);
	
/* Aloca��o da primeira dimens�o. Internamente, a fun��o calloc far� uma multiplica��o da
quantidade de elementos pelo tamanho de cada elemento para saber quanto de mem�ria deve ser alocada. */

	p = calloc (i, sizeof(int));

	if (p == NULL)
	{	printf("\nErro de alocacao de mem�ria");
		exit(1);
	}
	
	for (k=0; k<i; k++)
	{
		/* Aloca��o das linhas de cada coluna (segunda dimens�o) */
		
		p[k] = calloc (j, sizeof(int));
		
		if (p[k] == NULL)
		{	printf ("\nErro de alocacao de mem�ria");
			exit (1);
		}
	}
	
	for (k=0; k<i; k++)
	{	for (x=0; x<j; x++)
		{	printf ("Digite o n�mero para o indice %d,%d : ", k,x);
			scanf ("%d", &p[k][x]);
		}
	}
	
	for (k=0; k<i; k++)
	{	for (x=0; x<j; x++)
			printf ("O n�mero do indice %d,%d � %d\n", k,x, p[k][x]);
	}
	
	printf ("\nLiberando mem�ria alocada");
	for( k=0;k<i;k++)
		free(p[k]); 
	
	/* Primeiro deve ser liberada a mem�ria para linha da matriz... */
	
	free(p); 
	
	/* ... para depois liberar a mem�ria do vetor que continha as linhas. */
}
