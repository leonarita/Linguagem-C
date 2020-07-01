#include<stdio.h>
#include<locale.h>

int qtd=0;

void VerificarNumero (int n)
{	int i, achou=0;

	for (i=2; i<n; i++)
	{	if (n%i==0)
		{	achou++;
			break;
		}
	}
	
	if (achou==0)
	{	printf ("%d ", n);
		qtd++;
	}
}

void VerificarPrimos (int n)
{	int i;
	
	printf ("\n\n\nImprimindo os números primos: ");
	
	for (i=2; i<=n; i++)
	{	VerificarNumero (i);
	}
}

int main ()
{	setlocale (LC_ALL, "");

	int n;
	printf ("Digite um número: ");
	scanf ("%d", &n);
	
	VerificarPrimos (n);
	
	printf ("\n\n\t\t\tHá %d números primos até o número %d \n\n", qtd, n);
}
