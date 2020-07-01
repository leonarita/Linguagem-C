#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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

void Ex3 ()
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

bool chave = false;

void busca (int X[], int inicio, int fim, int n)
{	int i;
	for (i=inicio; i<=fim; i++)
	{	if (X[i]==n)
		{	printf ("\nElemento encontrado na posição %d", i+1);
			chave=true;
			break;
		}
		
		if (i==59 && X[i]!=n)
		{	printf ("\nElemento inexistente na lista");
			chave=true;
		}
	}
}

void divide (int X[], int inicio, int fim, int n)
{	int meio;
	if (inicio<fim)
	{	meio = (inicio+fim)/2;
		divide (X, inicio, meio, n);
		divide (X, meio+1, fim, n);
		if (chave==false)
			busca (X, inicio, meio, n);
		if (chave==false)
			busca (X, meio+1, fim, n);
	}
}

void Ex2 ()
{	setlocale (LC_ALL, "");

	int X[60], i;
	
	for (i=0; i<=59; i++)
	{	X[i] = rand()%1000;	}
	
	printf ("Lista: ");
	for (i=0; i<=59; i++)
	{	printf ("%d ", X[i]);	}
	
	printf ("\n\n\n\tPrimeiro Elemento");
	chave = false;
	divide (X, 0, 59, X[0]);
	
	printf ("\n\n\n\tTrigésimo Elemento");
	chave = false;
	divide (X, 0, 59, X[29]);
	
	printf ("\n\n\n\tQuadragésimo Quinto Elemento");
	chave = false;
	divide (X, 0, 59, X[44]);
	
	printf ("\n\n\n\tSexagésimo Elemento");
	chave = false;
	divide (X, 0, 59, X[59]);
	
	printf ("\n\n\n\tElemento Inexistente (ex: 104)");
	chave = false;
	divide (X, 0, 59, 104);
}

float potencia (float taxa, float meses)
{	if (meses==0)
		return 1;
	else
		return taxa*potencia(taxa, meses-1);
}

void Ex1 ()
{	setlocale (LC_ALL, "");
	float capital, taxa, meses;
	
	printf ("Informe o capital: R$");
	scanf ("%f", &capital);
	printf ("Informe a taxa de juros (em porcentagem): ");
	scanf ("%f", &taxa);
	taxa=1+(taxa/100);
	printf ("Informe o tempo (em meses): ");
	scanf ("%f", &meses);
	
	printf ("\n\n\n\n\tConsiderando o capital de %.2f aplicado a uma taxa de %f ao mês durante %.0f meses", capital, taxa, meses);
	taxa = potencia (taxa, meses);
	printf ("\n\n\n\n\tO valor do juros compostos é R$%f", capital*taxa);
}

int main ()
{	setlocale (LC_ALL, "");

	int o;
	printf ("MENU PROVA \n\n\t1-Questão 13 \n\t2-Questão 14 \n\t3-Questão 15 \n\nInsira a opção desejada: ");
	scanf ("%d", &o);
	
	switch (o)
	{	case 1:
			Ex1();
			break;
		case 2:
			Ex2();
			break;
		case 3:
			Ex3();
			break;
		default:
			printf ("Opção inválida");
	}
}
