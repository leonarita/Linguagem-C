#include<stdio.h>
#include<locale.h>

//SELECTION SORT
int main ()
{	setlocale(LC_ALL, "");
	int X[6], i, j, eleito, m;
	
	for (i=0; i<=5; i++)
	{	printf ("Digite o %d n�mero: ", i+1);
		scanf ("%d", &X[i]);
	}
	
	//Ordenando em forma crescente
	//La�o com a quantidade de elementos do vetor-1
	for (i=1; i<=5; i++)
	{	eleito = X[i];
		j = i-1;

	//La�o que percorre os elementos � esquerda do n�mero eleito ou at� encontrar a posi��o para realoca��o do n�mero eleito respeitando a ordena��o procurada
		while (j>=0 && X[j]>eleito)
		{	X[j+1]=X[j];
			j=j-1;	}
		
		X[j+1] = eleito;
	}
	
	printf ("\n\n");
	for (i=0; i<=5; i++)
		printf ("%d� n�mero: %d \n", i+1, X[i]);
}
