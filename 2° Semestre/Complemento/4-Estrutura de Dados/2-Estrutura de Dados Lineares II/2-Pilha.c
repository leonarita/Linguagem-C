#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>

typedef struct PILHA
{	int num;
	struct PILHA *prox;
}
Pilha;

int main ()
{	setlocale (LC_ALL, "");

	Pilha *topo=NULL;
	Pilha *aux;
	int op;
	
	do
	{	printf ("\n\n\t\t\t\tMENU DE OP��ES\n");
		printf ("\n\t1-Inserir na pilha");
		printf ("\n\t2-Consultar toda a pilha");
		printf ("\n\t3-Remover da pilha");
		printf ("\n\t4-Esvaziar a pilha");
		printf ("\n\t5-Sair");
		printf ("\n\nDigite sua op��o: ");
		scanf ("%d", &op);
				
		if (op<1 || op>5)
			printf ("\n\n\tOp��o inv�lida!!");
		
		if (op==1)
		{	printf ("\n\n\tDigite o n�mero a ser inserido na pilha: ");
			Pilha *novo = (Pilha *) malloc (sizeof(Pilha));
			scanf ("%d", &novo->num);
			
			novo->prox = topo;
			topo = novo;
			
			printf ("\n\t\tN�mero inserido na pilha!!");
		}
		
		if (op==2)
		{	if (topo == NULL)
				printf ("\n\n\tPilha vazia!!");
			else
			{	printf ("\n\n\tConsultando toda a pilha: ");
				aux = topo;
				
				while (aux != NULL)
				{	printf ("%d ", aux->num);
					aux = aux->prox;
				}
			}
		}
		
		if (op==3)
		{	if (topo==NULL)
				printf ("\n\n\tA pilha est� vazia!");
			else
			{	aux = topo;
				
				printf ("\n\n\tN�mero %d removido!!", topo->num);
				topo = topo->prox;
				free(aux);
			}
		}
		
		if (op==4)
		{	if (topo == NULL)
			{	printf ("\n\n\tPilha vazia!!");
			}
			else
			{	aux = topo;
				
				while (aux != NULL)
				{	topo = topo->prox;
					free (aux);
					aux = topo;
				}
				printf ("\n\n\tPilha esvaziada!!");
			}
		}
		
		if (op==5)
			printf ("\n\n\tAt� a pr�xima!");

		getch();
		system ("CLS");
	}
	while (op!=5);
}
