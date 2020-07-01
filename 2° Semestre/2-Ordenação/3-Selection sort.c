#include<stdio.h>
#include<locale.h>

//INSERTION SORT
int main ()
{	setlocale(LC_ALL, "");
	int X[6], i, j, eleito, menor, pos, m;
	
	for (i=0; i<=5; i++)
	{	printf ("Digite o %d número: ", i+1);
		scanf ("%d", &X[i]);
		printf ("\n");	}
	
	for (i=0; i<=4; i++)
	{	eleito = X[i];
	
		//encontrando o menor número à direita do eleito com sua respectiva posição
		//Posição do eleito = 1
		//Primeito número à direita do eleito na posição = i+1
		menor = X[i+1];
		pos = i+1;
			
		//Laço que percorre os elementos que estão à direita do número eleito, retornando o menor número à direita e sua posição
		for (j=i+1; j<=5; j++)
		{	if (X[j] < menor)
			{	menor = X[j];
				pos = j;
			}	}
		
		//Troca o número eleito com o número da posição pos
		//O número da posição pos é o menor número à direits do número eleito
		if (menor < eleito)
		{	X[i] = X[pos];
			X[pos] = eleito;	}
	}
	
	for (i=0; i<=5; i++)
		printf ("\n\n%d° número: %d ", i+1, X[i]);
}
