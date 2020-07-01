#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>

int main ()
{	setlocale (LC_ALL, "");
	
	typedef struct LISTA
	{	int num;
		struct LISTA *prox;
		struct LISTA *ant;
	}
	Lista;
	
	Lista *inicio = NULL;
	Lista *fim = NULL;
	Lista *aux;
	
	int op, numero, achou;
	
	do
	{	printf ("\n\n\t\t\t\tMENU DE OP��ES\n");
		printf ("\n\t1-Inserir no in�cio da lista");
		printf ("\n\t2-Inserir no fim da lista");
		printf ("\n\t3-Consultar a lista do in�cio ao fim");
		printf ("\n\t4-Consultar a lista do fim ao in�cio");
		printf ("\n\t5-Remover da lista");
		printf ("\n\t6-Esvaziar a lista");
		printf ("\n\t7-Sair");
		printf ("\n\nDigite sua op��o: ");
		scanf ("%d", &op);
		
		if (op<1 || op>7)
			printf ("\n\n\tOp��o inv�lida!!");
		
		if (op==1)
		{	printf ("\n\n\tDigite o n�mero a ser inserido no in�cio da lista: ");
			Lista *novo = (Lista *) malloc (sizeof(Lista));
			scanf ("%d", &novo->num);
			
			if (inicio == NULL)
			{	inicio = novo;
				fim = novo;
				novo->prox = inicio;
				novo->ant = inicio;
			}
			else
			{	novo->prox = inicio;
				inicio->ant = novo;
				novo->ant = fim;
				fim->prox = novo;
				inicio = novo;
			}
			printf ("\n\t\tN�mero inserido no in�cio da lista!!");
		}
		
		if (op==2)
		{	printf ("\n\n\tDigite o n�mero a ser inserido no fim da lista: ");
			Lista *novo = (Lista *) malloc (sizeof(Lista));
			scanf ("%d", &novo->num);
		
			if (inicio == NULL)
			{	inicio = novo;
				fim = novo;
				novo->prox = inicio;
				novo->ant = inicio;
			}
			else
			{	fim->prox = novo;
				novo->ant = fim;
				fim = novo;
				fim->prox = inicio;
				inicio->ant = fim;
			}
			printf ("\n\t\tN�mero inserido no final da lista!!\n\n\n");
		}
		
		if (op==3)
		{	if (inicio == NULL)
				printf ("\n\n\tLista vazia!!");
			else
			{	printf ("\n\n\tConsultando a lista do in�cio ao fim: ");
				aux = inicio;
				
				do
				{	printf ("%d ", aux->num);
					aux = aux->prox;
				}
				while (aux != inicio);
			}
		}
		
		if (op==4)
		{	if (inicio == NULL)
				printf ("\n\n\tLista vazia!!");
			else
			{	printf ("\n\n\tConsultando a lista do in�cio ao fim: ");
				aux = fim;
				
				do
				{	printf ("%d ", aux->num);
					aux = aux->ant;
				}
				while (aux != fim);
			}
		}
		
		if (op==5)
		{	if (inicio==NULL)
				printf ("\n\n\tA lista est� vazia!");
			else
			{	printf ("\n\n\tDigite o elemento a ser removido: ");
				scanf ("%d", &numero);
				
				aux = inicio;
				achou = 0;
				int quantidade=0;
				
				do
				{	quantidade++;
					aux = aux->prox;
				}
				while (aux != inicio);
				
				int elemento = 1;
				
				do
				{	if (inicio==fim && inicio->num==numero)
					{	inicio = NULL;
						free (inicio);
						achou++;
					}
					else
					{	if (aux->num == numero)
						{	achou++;
							if (aux == inicio)	
							{	inicio = aux->prox;
								inicio->ant = fim;
								fim->prox = inicio;
								free (aux);
								aux = inicio;
							}
							else if (aux == fim)
							{	fim = fim->ant;
								fim->prox = inicio;
								free (aux);
								aux = NULL;
							}
							else
							{	aux->ant->prox = aux->prox;
								aux->prox->ant = aux->ant;
								Lista *aux2;
								aux2 = aux;
								aux = aux->prox;
								free (aux2);
							}
						}
						else
						{	aux = aux->prox;
						}
					}
					elemento++;
				}
				while (elemento <= quantidade);
				
				if (achou==0)
					printf ("\n\t\tN�mero n�o encontrado!");
				else if (achou == 1)
					printf ("\n\t\tN�mero removido uma vez!");
				else
					printf ("\n\t\tN�mero removido %d vezes!", achou);
			}
		}
		
		if (op==6)
		{	if (inicio == NULL)
			{	printf ("\n\n\tLista vazia!!");
			}
			else
			{	aux = inicio;
				
				do
				{	inicio = inicio->prox;
					free (aux);
					aux = inicio;
				}
				while (aux != fim);
				
				free (fim);
				inicio = NULL;
				printf ("\n\n\tLista esvaziada!!");
			}
		}
		
		if (op==7)
			printf ("\n\n\tAt� a pr�xima!");

		getch();
		system ("CLS");
	}
	while (op != 7);
}
