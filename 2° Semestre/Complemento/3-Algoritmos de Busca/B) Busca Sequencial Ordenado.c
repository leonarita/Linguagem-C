#include<stdio.h>
#include<locale.h>

int main ()
{	setlocale (LC_ALL, "");
	int np, i, achou, n;
	
	printf ("Informe o n�mero de termos do vetor: ");
	scanf ("%d", &n);
	
	int X[n];
	
	//VETOR COM N�MEROS ORDENADOS
	for (i=0; i<=n-1; i++)
	{	printf ("Digite o %d� termo: ", i+1);
		scanf ("%d", &X[i]);
	}
	
	printf ("\n\n\tDigite o n�mero a ser buscado no vetor: ");
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
		printf ("\t\tN�mero n�o encontrado no vetor.");
	else
		printf ("\t\tN�mero encontrado na posi��o %d", i+1);
	
	getch();
}
