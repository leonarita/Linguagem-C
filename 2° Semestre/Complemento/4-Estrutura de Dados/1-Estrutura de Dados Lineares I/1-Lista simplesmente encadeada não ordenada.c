#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>

int main ()
{	setlocale (LC_ALL, "");
	
	typedef struct LISTA
	{	int num;
		struct LISTA *prox;
	}
	Lista;
	
	Lista *inicio = NULL;
	Lista *fim = NULL;
	Lista *aux, *anterior;
	
	int op, numero, achou;
	
	do
	{	printf ("\n\n\t\t\t\tMENU DE OPÇÕES\n");
		printf ("\n\t1-Inserir no início da lista");
		printf ("\n\t2-Inserir no fim da lista");
		printf ("\n\t3-Consultar toda a lista");
		printf ("\n\t4-Remover da lista");
		printf ("\n\t5-Esvaziar a lista");
		printf ("\n\t6-Sair");
		printf ("\n\nDigite sua opção: ");
		scanf ("%d", &op);
		
		if (op<1 || op>6)
			printf ("\n\n\tOpção inválida!!");
		
		if (op==1)
		{	printf ("\n\n\tDigite o número a ser inserido no início da lista: ");
			Lista *novo = (Lista *) malloc (sizeof(Lista));
			scanf ("%d", &novo->num);
			
			if (inicio == NULL)
			{	inicio = novo;
				fim = novo;
				fim->prox = NULL;
			}
			else
			{	novo->prox = inicio;
				inicio=novo;
			}
			printf ("\n\t\tNúmero inserido no início da lista!!");
		}
		
		if (op==2)
		{	printf ("\n\n\tDigite o número a ser inserido no fim da lista: ");
			Lista *novo = (Lista *) malloc (sizeof(Lista));
			scanf ("%d", &novo->num);
		
			if (inicio == NULL)
			{	inicio = novo;
				fim = novo;
				fim->prox = NULL;
			}
			else
			{	fim->prox = novo;
				fim = novo;
				fim->prox = NULL;
			}
			printf ("\n\t\tNúmero inserido no final da lista!!\n\n\n");
		}
		
		if (op==3)
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
		
		if (op==4)
		{	if (inicio==NULL)
				printf ("\n\n\tA lista está vazia!");
			else
			{	printf ("\n\n\tDigite o elemento a ser removido: ");
				scanf ("%d", &numero);
				
				aux = inicio;
				anterior = NULL;
				achou = 0;
				
				while (aux != NULL)
				{	if (aux->num == numero)	
					{	achou += 1;
						if (aux == inicio)
						{	inicio = aux->prox;
							free (aux);
							aux = inicio;
						}
						else if (aux == fim)
						{	anterior->prox = NULL;
							fim = anterior;
							free (aux);
							aux = NULL;
						}
						else
						{	anterior-> prox = aux->prox;
							free (aux);
							aux = anterior->prox;
						}
					}
					else
					{	anterior = aux;
						aux = aux->prox;
					}
				}
				if (achou==0)
					printf ("\n\t\tNúmero não encontrado!");
				else if (achou == 1)
					printf ("\n\t\tNúmero removido uma vez!");
				else
					printf ("\n\t\tNúmero removido %d vezes!", achou);
			}
		}
		
		if (op==5)
		{	if (inicio == NULL)
			{	printf ("\n\n\tLista vazia!!");
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
		
		if (op==6)
			printf ("\n\n\tAté a próxima!");

		getch();
		system ("CLS");
	}
	while (op != 6);
}
