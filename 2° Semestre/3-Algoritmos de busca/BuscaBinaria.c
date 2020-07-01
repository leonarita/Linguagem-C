#include<stdio.h>
#include<locale.h>
#include<stdbool.h>

bool chave = false;

bool buscaBinaria (int V[], int inicio, int fim, int num)
{	int i;
	
	for (i=inicio; i<=fim; i++)
		if (num == V[i])
		{	printf ("\n\n\t\t\tN�mero foi encontrado na posi��o %d\n", i);
			return 1;	}
		else
		{	printf ("\n\tN�mero n�o foi encontrado na posi��o %d", i);
			return 0;	}
}

void dividir (int V[], int inicio, int fim, int num)
{	int meio;

	if (inicio<fim)
	{	meio = (inicio+fim)/2;
		if (chave==false)
			dividir (V, inicio, meio, num);
		if (chave==false)
			dividir (V, meio+1, fim, num);
		if (chave==false)
			chave = buscaBinaria (V, inicio, meio, num);
		if (chave==false)
			chave = buscaBinaria (V, meio+1, fim, num);
	}
}

int main ()
{
	setlocale (LC_ALL, "");
	int V[10] = {8,5,6,7,3,2,1,4,9,10};
	int num;
	
	printf ("Informe o n�mero que deseja ser procurado no vetor: ");
	scanf ("%d", &num);
	printf ("\n\n\n");
	
	dividir (V, 0, 9, num);
}
