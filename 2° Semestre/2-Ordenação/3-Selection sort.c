#include<stdio.h>
#include<locale.h>

//INSERTION SORT
int main ()
{	setlocale(LC_ALL, "");
	int X[6], i, j, eleito, menor, pos, m;
	
	for (i=0; i<=5; i++)
	{	printf ("Digite o %d n�mero: ", i+1);
		scanf ("%d", &X[i]);
		printf ("\n");	}
	
	for (i=0; i<=4; i++)
	{	eleito = X[i];
	
		//encontrando o menor n�mero � direita do eleito com sua respectiva posi��o
		//Posi��o do eleito = 1
		//Primeito n�mero � direita do eleito na posi��o = i+1
		menor = X[i+1];
		pos = i+1;
			
		//La�o que percorre os elementos que est�o � direita do n�mero eleito, retornando o menor n�mero � direita e sua posi��o
		for (j=i+1; j<=5; j++)
		{	if (X[j] < menor)
			{	menor = X[j];
				pos = j;
			}	}
		
		//Troca o n�mero eleito com o n�mero da posi��o pos
		//O n�mero da posi��o pos � o menor n�mero � direits do n�mero eleito
		if (menor < eleito)
		{	X[i] = X[pos];
			X[pos] = eleito;	}
	}
	
	for (i=0; i<=5; i++)
		printf ("\n\n%d� n�mero: %d ", i+1, X[i]);
}
