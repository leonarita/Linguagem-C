#include<stdio.h>
#include<locale.h>

//S� funciona em vetores ordenados

int main ()
{	setlocale (LC_ALL, "");
	int np, i, inicio, fim, meio, achou, n;
	
	printf ("Informe o n�mero de termos do vetor: ");
	scanf ("%d", &n);
	
	int X[n];
	
	for (i=0; i<=n-1; i++)
	{	printf ("Digite o %d� termo: ", i+1);
		scanf ("%d", &X[i]);
	}
	
	printf ("\n\n\tDigite o n�mero a ser buscado no vetor: ");
	scanf ("%d", &np);
	
	achou=0;
	inicio=0;
	fim=n-1;
	meio=(inicio+fim)/2;
	
	while (inicio<=fim && achou==0)
	{	if (X[meio]==np)
			achou=1;
		else
		{	if (np<X[meio])
				fim=meio-1;
			else
				inicio=meio+1;
			meio=(inicio+fim)/2;
		}
	}
	
	if (achou==0)
		printf ("\t\tN�mero n�o encontrado no vetor.");
	else
		printf ("\t\tN�mero encontrado na posi��o %d", meio+1);
	
	getch();
}
