#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* a fun��o recebe um ponteiro para uma matriz */
void aloca (int ***p, int x, int y)
{	int i;
	
	*p = (int **) malloc (sizeof(int) * x);
	
	if (*p == NULL)
	{	printf ("\nErro de aloca��o de mem�ria!");
		exit (1);
	}
	
	for (i=0; i<y; i++)
	{	(*p)[i] = (int *) malloc (sizeof(int) * y);
	
		if ((*p)[i] == NULL)
		{	printf ("\nErro de aloca��o de mem�ria!");
			exit (1);
		}
	}

	return;
}

int main (void)
{	setlocale (LC_ALL, "");
	
	int **p; /* declara��o de uma matriz com duas dimens�es */
	int i,k;
	
	aloca (&p, 4, 5); /* passando para a fun��o o endere�o de mem�ria do ponteiro */
	
	for (i=0; i<4; i++)
		for (k=0; k<5; k++)
			p[i][k] = i + k;
	
	for (i=0; i<4; i++)
	{	for (k=0; k<5; k++)
			printf ("%d ", p[i][k]); /* refer�ncia aos elementos atrav�s de linha e coluna */
		printf ("\n");
	}
	
	return 0;
}
