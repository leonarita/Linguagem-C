#include<stdio.h>
#include<locale.h>

void troca (int X[], int i, int j)
{	int aux;

	aux = X[i];
	X[i] = X[j];
	X[j] = aux;
}

int particao (int X[], int p, int r)
{	int pivo, i, j;
	pivo = X[(p+r)/2];
	i=p-1;
	j=r+1;
	
	while (i<j)
	{
		do {	j = j - 1;	}
		while (X[j] > pivo);
		
		do	{	i = i + 1;	}
		while (X[i] < pivo);
		
		if (i<j)
			troca (X, i, j);
	}
	return j;
}

void quicksort (int X[], int p, int r)
{
	int q;
	
	if (p<r)
	{	q = particao (X, p, r);
		quicksort (X, p, q);
		quicksort (X, q+1, r);
	}
}

void main ()
{	setlocale (LC_ALL, "");
	int X[10], i;

	//Carregando os números no vetor
	for (i=0; i<=9; i++)
	{	printf ("Informe o %d° número: ", i+1);
		scanf("%d", &X[i]);
	}

	//Ordenando o vetor ordenado
	quicksort (X, 0, 9);

	//Mostrando o vetor ordenado
	printf ("\n\nVetor Ordenado:");
	for (i=0; i<=9; i++)
		printf ("\n %d° número: %d", i+1, X[i]);
}
