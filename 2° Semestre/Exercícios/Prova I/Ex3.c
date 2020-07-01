#include<stdio.h>
#include<locale.h>

void troca (int X[], int i, int j)
{	int aux;
	aux = X[i];
	X[i] = X[j];
	X[j] = aux;
}

int particao (int X[], int i, int j)
{	int pivo;
	pivo = X[(i+j)/2];
	i = i-1;
	j = j+1;
	
	while (i<j)
	{	do {	i++;	}	while (X[i]<pivo);
		do {	j--;	}	while (X[j]>pivo);
		if (i<j)
			troca (X, i, j);	
	}
	return j;
}

void quick (int X[], int inicio, int fim)
{	int meio;
	if (inicio<fim)
	{	meio = particao (X, inicio, fim);
		quick (X ,inicio, meio);
		quick (X, meio+1, fim);
	}
}

int main ()
{	setlocale (LC_ALL, "");

	int A[6], B[6], C[12], i;
	
	printf ("\t\tQuick Sort");
	
	printf ("\n\nMatriz A\n");
	for (i=0; i<=5; i++)
	{	printf ("\tInsira o %i° elemento da matriz A: ", i+1);
		scanf ("%d", &A[i]);
	}
	quick (A, 0, 5);
	
	printf ("\n\nMatriz B\n");
	for (i=0; i<=5; i++)
	{	printf ("\tInsira o %i° elemento da matriz B: ", i+1);
		scanf ("%d", &B[i]);
	}
	quick (B, 0, 5);
	
	for (i=0; i<=5; i++)
		C[i]=A[i];
	
	for (i=0; i<=5; i++)
		C[i+6]=B[i];
		
	printf ("\n\nMatriz C (unidade de A e B) \n\t");
	for (i=0; i<=11; i++)
		printf ("%d ", C[i]);
	quick (C, 0, 11);
		
	printf ("\n\nMatrizes ordenadas");
	printf ("\n\tMatriz A: ");
	for (i=0; i<=5; i++)
		printf ("%d ", A[i]);
	printf ("\n\tMatriz B: ");
	for (i=0; i<=5; i++)
		printf ("%d ", B[i]);
	printf ("\n\tMatriz C: ");
	for (i=0; i<=11; i++)
		printf ("%d ", C[i]);
}
