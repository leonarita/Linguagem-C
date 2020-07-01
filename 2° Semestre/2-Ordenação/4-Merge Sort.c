#include<stdio.h>
#include<locale.h>

void Intercala (int X[], int inicio, int fim, int meio)
{
	int poslivre, inicio_vetor1, inicio_vetor2, i;
	int aux[10];
	inicio_vetor1 = inicio;
	inicio_vetor2 = meio + 1;
	poslivre = inicio;
	
	while (inicio_vetor1 <= meio && inicio_vetor2 <= fim)
	{
		if (X[inicio_vetor1] <= X[inicio_vetor2])
		{	aux[poslivre] = X[inicio_vetor1];
			inicio_vetor1 = inicio_vetor1 + 1;
		}
		else
		{	aux[poslivre] = X[inicio_vetor2];
			inicio_vetor2 = inicio_vetor2 + 1;
		}
		poslivre = poslivre + 1;
	}
	
	//Se ainda existem números no primeiro vetor que não foram intercalados
	for (i=inicio_vetor1; i<=meio; i++)
	{	aux[poslivre] = X[i];
		poslivre = poslivre + 1;
	}
	
	//Se ainda existem números no segundo vetor que não foram intercalados
	for (i=inicio_vetor2; i<=fim; i++)
	{	aux[poslivre] = X[i];
		poslivre = poslivre + 1;
	}
	
	//Retorna os valores do vetor aux para o vetor X
	for (i=inicio; i<=fim; i++)
		X[i]=aux[i];
}

void merge (int X[], int inicio, int fim)
{	int meio;
	
	if (inicio<fim)
	{	meio = (inicio+fim)/2;
		merge (X, inicio, meio);
		merge (X, meio+1, fim);
		Intercala (X, inicio, fim, meio);
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
	merge(X, 0, 9);
	
	//Mostrando o vetor ordenado
	printf ("\n\nVetor Ordenado:");
	for (i=0; i<=9; i++)
		printf ("\n %d° número: %d", i+1, X[i]);
}
