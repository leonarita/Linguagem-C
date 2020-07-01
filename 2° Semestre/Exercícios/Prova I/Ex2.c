#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<locale.h>
#include<time.h>
#include<dos.h>

bool chave = false;
int cont[6] = {0,0,0,0,0,0};
int m;

void busca (int X[], int inicio, int fim, int n)
{	int i;
	for (i=inicio; i<=fim; i++)
	{
		cont[0]++;
		cont[m]++;
	
		if (X[i]==n)
		{	printf ("\nElemento %d encontrado na posição %d", n, i+1);
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

int main ()
{	setlocale (LC_ALL, "");

	clock_t inicio[6], fim[6];
	inicio[0] = clock();

	int X[60], i;
	
	for (i=0; i<=59; i++)
	{	X[i] = rand()%1000;	}
	
	printf ("Lista: ");
	for (i=0; i<=59; i++)
	{	printf ("\n\t%02d° termo: %03d ", i+1, X[i]);	}
	
	m=1;
	inicio[m] = clock();
	printf ("\n\n\n\tPrimeiro Elemento");
	chave = false;
	divide (X, 0, 59, X[0]);
	fim[m] = clock();
	
	m=2;
	inicio[m] = clock();
	printf ("\n\n\n\tTrigésimo Elemento");
	chave = false;
	divide (X, 0, 59, X[29]);
	fim[m] = clock();
	
	m=3;
	inicio[m] = clock();
	printf ("\n\n\n\tQuadragésimo Quinto Elemento");
	chave = false;
	divide (X, 0, 59, X[44]);
	fim[m] = clock();
	
	m=4;
	inicio[m] = clock();
	printf ("\n\n\n\tSexagésimo Elemento");
	chave = false;
	divide (X, 0, 59, X[59]);
	fim[m] = clock();
	
	m=5;
	inicio[m] = clock();
	printf ("\n\n\n\tElemento Inexistente (ex: 104)");
	chave = false;
	divide (X, 0, 59, 104);
	fim[m] = clock();
	
	printf ("\n\n\n\n");
	printf ("\t\t\t\t\t    Comparações       Tempo de execução");
	for (m=1; m<=5; m++)
		printf ("\n\t\t\t%d° resultado:    	%03d   	 	 %fs", m, cont[m], (float)(fim[m] - inicio[m])/CLK_TCK);
	
	
	fim[0] = clock();
	printf("\n\n\n\n\n\t\tTempo de execução: %f.",(float)(fim[0] - inicio[0])/CLK_TCK);
	printf("\n\t\tComparações totais: %d.", cont[0]);
}
