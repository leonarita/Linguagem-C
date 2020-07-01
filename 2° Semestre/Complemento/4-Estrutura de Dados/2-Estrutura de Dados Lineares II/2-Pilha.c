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
	{	printf ("\n\n\t\t\t\tMENU DE OPÇÕES\n");
		printf ("\n\t1-Inserir na pilha");
		printf ("\n\t2-Consultar toda a pilha");
		printf ("\n\t3-Remover da pilha");
		printf ("\n\t4-Esvaziar a pilha");
		printf ("\n\t5-Sair");
		printf ("\n\nDigite sua opção: ");
		scanf ("%d", &op);
				
		if (op<1 || op>5)
			printf ("\n\n\tOpção inválida!!");
		
		if (op==1)
		{	printf ("\n\n\tDigite o número a ser inserido na pilha: ");
			Pilha *novo = (Pilha *) malloc (sizeof(Pilha));
			scanf ("%d", &novo->num);
			
			novo->prox = topo;
			topo = novo;
			
			printf ("\n\t\tNúmero inserido na pilha!!");
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
				printf ("\n\n\tA pilha está vazia!");
			else
			{	aux = topo;
				
				printf ("\n\n\tNúmero %d removido!!", topo->num);
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
			printf ("\n\n\tAté a próxima!");

		getch();
		system ("CLS");
	}
	while (op!=5);
}
