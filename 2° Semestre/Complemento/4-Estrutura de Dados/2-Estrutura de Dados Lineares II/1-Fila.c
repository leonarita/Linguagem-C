#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>

typedef struct LISTA
{	int num;
	struct LISTA *prox;
}
Lista;

int main ()
{	setlocale (LC_ALL, "");

	Lista *inicio=NULL;
	Lista *fim=NULL;
	Lista *aux;
	int op;
	
	do
	{	printf ("\n\n\t\t\t\tMENU DE OPÇÕES\n");
		printf ("\n\t1-Inserir na fila");
		printf ("\n\t2-Consultar toda a fila");
		printf ("\n\t3-Remover da fila");
		printf ("\n\t4-Esvaziar a fila");
		printf ("\n\t5-Sair");
		printf ("\n\nDigite sua opção: ");
		scanf ("%d", &op);
				
		if (op<1 || op>5)
			printf ("\n\n\tOpção inválida!!");
		
		if (op == 1)
		{	printf ("\n\n\tDigite o número a ser inserido na fila: ");
			Lista *novo = (Lista *) malloc (sizeof(Lista));
			scanf ("%d", &novo->num);
			novo->prox = NULL;
			
			if (inicio == NULL)
			{	inicio = novo;
				fim = novo;
			}
			else
			{	fim->prox = novo;
				fim = novo;
			}
			printf ("\n\t\tNúmero inserido na lista!!");
		}
		
		if (op==2)
		{	if (inicio == NULL)
				printf ("\n\n\tLista vazia!!");
			else
			{	printf ("\n\n\tConsultando toda a lista: ");
				aux = inicio;
				
				while (aux != NULL)
				{	printf ("%d ", aux->num);
					aux = aux->prox;
				}
			}
		}
		
		if (op==3)
		{	if (inicio == NULL)
				printf ("\n\n\tA lista está vazia!");
			else
			{	printf ("\n\n\tNúmero %d removido!!", inicio->num);
				inicio = inicio->prox;
				free(aux);
			}
		}
		
		if (op==4)
		{	if (inicio == NULL)
			{	printf ("\n\n\tFila vazia!!");
			}
			else
			{	aux = inicio;
				
				while (aux != NULL)
				{	inicio = inicio->prox;
					free (aux);
					aux = inicio;
				}
				printf ("\n\n\tLista esvaziada!!");
			}
		}
		
		if (op==5)
			printf ("\n\n\tAté a próxima!");

		getch();
		system ("CLS");
	}
	while (op!=5);
}
