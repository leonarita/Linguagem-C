#include<stdio.h>
#include<locale.h>

//SELECTION SORT
int main ()
{	setlocale(LC_ALL, "");
	int X[6], i, j, eleito, m;
	
	for (i=0; i<=5; i++)
	{	printf ("Digite o %d número: ", i+1);
		scanf ("%d", &X[i]);
	}
	
	//Ordenando em forma crescente
	//Laço com a quantidade de elementos do vetor-1
	for (i=1; i<=5; i++)
	{	eleito = X[i];
		j = i-1;

	//Laço que percorre os elementos à esquerda do número eleito ou até encontrar a posição para realocação do número eleito respeitando a ordenação procurada
		while (j>=0 && X[j]>eleito)
		{	X[j+1]=X[j];
			j=j-1;	}
		
		X[j+1] = eleito;
	}
	
	printf ("\n\n");
	for (i=0; i<=5; i++)
		printf ("%d° número: %d \n", i+1, X[i]);
}
