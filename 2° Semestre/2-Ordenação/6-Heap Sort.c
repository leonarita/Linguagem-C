#include<stdio.h>
#include<locale.h>

int X[11];

void heap_fica (int i, int qtde)
{
	int f_esq, f_dir, maior, aux;
	maior = i;
	
	if (2*i+1 <= qtde)				//o n� que est� sendo analisado tem filhos para esquerda
	{
		f_esq = 2*i+1;
		f_dir = 2*i;
		
		if (X[f_esq]>=X[f_dir] && X[f_esq]>X[i])
			maior=2*i+1;
		else if (X[f_dir]>X[f_esq] && X[f_dir]>X[i])
			maior=2*i;
	}
	else if (2*i <= qtde)			//o n� que est� sendo analisado tem filhos para direita
	{
		f_dir = 2*i;
		
		if (X[f_dir]>X[i])
			maior=2*i;
	}
	
	if(maior!=1 && X[i]!=X[maior])
	{	aux=X[i];
		X[i]=X[maior];
		X[maior]=aux;
		
		heap_fica (maior, qtde);
	}
}

void transforma_heap (int qtde)
{	int i, pai, aux;
	
	for (i=qtde/2; i>=1; i--)
	{	heap_fica(i, qtde);		}
}

void ordena (int qtde)
{	int i, aux, ultima_posi;

	for (i=qtde; i>=2; i--)
	{	aux=X[1];
		X[1]=X[i];
		X[i]=aux;
		ultima_posi = i-1;
		heap_fica(1, ultima_posi);
	}
}

void main ()
{	int i, qtde;
	setlocale (LC_ALL, "");

//	X[0]=0;
	//Carregando os n�meros no vetor
	for (i=1; i<=10; i++)
	{	printf ("Informe o %d� n�mero: ", i);
		scanf ("%d", &X[i]);
	}

	//Transforma o vetor digitado em um heap
	//Cada n� pai � maior que seus filhos
	qtde=10;
	transforma_heap (qtde);
	
	//Ordenando de forma crescente
	ordena (qtde);

	//Mostrando o vetor ordenado
	printf ("\n\nVetor Ordenado:");
	for (i=1; i<=10; i++)
		printf ("\n %d� n�mero: %d", i, X[i]);
		
	getch();
}
