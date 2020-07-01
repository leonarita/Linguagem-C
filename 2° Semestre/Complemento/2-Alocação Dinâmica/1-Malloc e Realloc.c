#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void)
{	setlocale (LC_ALL, "");
	
	int *p;
	int i, k, n;
	
	printf ("\nDigite a quantidade de n�meros que ser�o digitados: ");
	scanf ("%d", &i);
	
/* A fun��o malloc reserva espa�o suiciente para um vetor de inteiros.
Caso sejam digitados 5 elementos, ser�o reservados 20 bytes, pois cada inteiro ocupa 4 bytes na mem�ria */

	p = (int *) malloc (i * sizeof(int));

	if (p == NULL)
	{	printf("\nErro de alocacao de mem�ria");
		exit(1);
	}
	
	for (k=0; k<i; k++)
	{	printf ("Digite o n�mero para o indice %d : ", k);
		scanf ("%d", &p[k]);
	}
	
	for (k=0; k<i; k++)
	{	printf ("O n�mero do indice %d � %d\n", k, p[k]);	}
	
	printf ("\nDigite quantos elementos quer adicionar ao vetor: ");
	scanf ("%d", &n);
	
/* A fun��o realloc aumenta ou diminui o tamanho do vetor dinamicamente.
Ela recebe o ponteiro para o vetor anterior e retorna o novo espa�o alocado. */

	p = (int *) realloc (p, (i+n) * sizeof(int));
	if (p == NULL)
	{	printf ("\nErro de re-alocacao de mem�ria");
		exit (1);
	}
	
	for (; k<(n+i); k++)
	{	printf ("Digite o n�mero para o indice %d : ", k);
		scanf ("%d", &p[k]);
	}
	
	for (k=0; k<(i+n); k++)
	{	printf("O numero do indice %d eh %d\n", k, p[k]);	}
	
	free(p);
	return 0;
}
