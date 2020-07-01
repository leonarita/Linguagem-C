#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main ()
{	setlocale (LC_ALL, "");

	int *n=NULL, topo=0, op;
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
		{	if (topo==0)
			{	printf ("\n\n\tInforme o elemento a ser inserido: ");
				scanf ("%d", &n[0]);
				topo++;
			}
			else
			{	n = (int *) realloc (n, (topo+1) * sizeof(int));
				printf ("\n\n\tInforme o elemento a ser inserido: ");
				scanf ("%d", &n[topo]);
				topo++;
			}
		}
		
		if (op==2)
		{	if (topo==0)
				printf ("\n\n\tA pilha está vazia!");
			else
			{	topo--;
			//	n[topo]=NULL;
				n = (int *) realloc (n, (topo+1) * sizeof(int));
			}
		}
		
		if (op==3)
		{	free (n);
			printf ("\n\n\tAté mais!");
			break;
		}
		
		system ("cls");
		
		if (topo==0)
			printf ("\n\n\tA pilha está vazia!");
		else
		{	int i;
			printf ("\n\n\tPilha: ");
			for (i=0; i<topo; i++)
				printf ("%d ", n[i]);
		}
	}
	while (op!=3);
}
