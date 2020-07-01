#include<stdio.h>
#include<locale.h>

void Intercala (int X[], int inicio, int fim, int meio);
void merge (int X[], int inicio, int fim);

void troca (int X[], int i, int j);
int particao (int X[], int p, int r);
void quicksort (int X[], int p, int r);

void main ()
{	setlocale (LC_ALL, "");
	int n, i, opcao;
	
	printf ("Informe a quantidade de elementos a serem ordenados: ");
	scanf ("%d", &n);
	
	int X[n];
	
	for (i=0; i<=n-1; i++)
	{	printf ("Informe o %d° número: ", i+1);
		scanf("%d", &X[i]);
	}
	
	do {
		printf ("\n\n\nConsidere as seguintes ordenações: \n\t 1-Merge Sort \n\t 2-Quick Sort \n\nQual opção você deseja? ");
		scanf ("%d", &opcao);
		printf ("\n\n\n\n\n");
			
		switch (opcao)
		{
			case 1:
				system ("cls");
				merge(X, 0, n-1);
				break;
			case 2:
				system ("cls");
				quicksort (X, 0, n-1);
				break;
			default:
				printf ("Opção de ordenação inválida.");
				sleep(1);
				system("cls");
				break;
		}
	} while (opcao<1 || opcao>2);
	
	for (i=0; i<=n-1; i++)
		printf ("\n %d° número: %d", i+1, X[i]);
}


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
	
	for (i=inicio_vetor1; i<=meio; i++)
	{	aux[poslivre] = X[i];
		poslivre = poslivre + 1;
	}
	
	for (i=inicio_vetor2; i<=fim; i++)
	{	aux[poslivre] = X[i];
		poslivre = poslivre + 1;
	}
	
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
