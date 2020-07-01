#include<stdio.h>
#include<locale.h>

int main ()
{	setlocale (LC_ALL, "");
	int np, i, achou, n;
	
	printf ("Informe o número de termos do vetor: ");
	scanf ("%d", &n);
	
	int X[n];
	
	//VETOR COM NÚMEROS ORDENADOS
	for (i=0; i<=n-1; i++)
	{	printf ("Digite o %d° termo: ", i+1);
		scanf ("%d", &X[i]);
	}
	
	printf ("\n\n\tDigite o número a ser buscado no vetor: ");
	scanf ("%d", &np);
	
	achou=0;
	i=0;
	
	while (i<=9 && achou==0 && n>=X[i])
	{	if (X[i]==np)
			achou=1;
		else
			i++;
	}
	
	if (achou==0)
		printf ("\t\tNúmero não encontrado no vetor.");
	else
		printf ("\t\tNúmero encontrado na posição %d", i+1);
	
	getch();
}
