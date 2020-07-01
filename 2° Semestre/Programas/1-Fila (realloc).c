#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main ()
{	setlocale (LC_ALL, "");
	int *n=NULL, ind=0, op=0;
	n = (int *) malloc (sizeof(int));
	
	do
	{	fflush (stdin);
		printf ("\n\n\t\tMENU DE OPÇÕES\n");
		printf ("\n\t1-Adicionar elemento");
		printf ("\n\t2-Excluir elemento");
		printf ("\n\t3-Sair");
		printf ("\n\nInforme a opção desejada: ");
		scanf ("%d", &op);
		
		if (op>3 || op<1)
			printf ("\n\n\tComando inválido!");
		
		if (op==1)
		{	if (ind==0)
			{	ind++;
				printf ("\n\n\tInforme o elemento a ser inserido: ");
				scanf ("%d", &*(n));
				//scanf ("%d", &n[0]);
			}
			else
			{	n = (int *) realloc (n, (ind+1)*sizeof(int));
			
				if (n == NULL)
				{	printf ("\n\t\tErro de re-alocação de memória");
					exit (1);
				}
	
				printf ("\n\n\tInforme o elemento a ser inserido: ");
				scanf ("%d", &*(n+ind));
				//scanf ("%d", &n[ind]);
				ind++;
			}
		}
		
		if (op==2)
		{	if (ind==0)
			{	printf ("\n\n\tA lista está vazia!");	}
			else if (ind==1)
			{	n[0] = 0;
				ind=0;
				n = (int *) realloc (n, (1)*sizeof(int));
			}
			else
			{	int i;
				for (i=1; i<=ind; i++)
					n[i-1]=n[i];
				ind--;
				n = (int *) realloc (n, (ind)*sizeof(int));
			}
		}
		
		if (op==3)
		{	free (n);
			printf ("\n\n\tAté mais!");
			break;
		}
		
		system ("cls");
		
		if (ind==0)
			printf ("\n\n\tFila vazia!!");
		else
		{	int i;
			printf ("\n\n\tFila: ");
			for (i=0; i<ind; i++)
				printf ("%d ", n[i]);
		}
	}
	while (op!=3);
}
