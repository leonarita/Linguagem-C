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
	{	printf ("\n\n\t\t\t\tMENU DE OPÇÕES\n");
		printf ("\n\t1-Inserir no início da lista");
		printf ("\n\t2-Inserir no fim da lista");
		printf ("\n\t3-Consultar a lista do início ao fim");
		printf ("\n\t4-Consultar a lista do fim ao início");
		printf ("\n\t5-Remover da lista");
		printf ("\n\t6-Esvaziar a lista");
		printf ("\n\t7-Sair");
		printf ("\n\nDigite sua opção: ");
		scanf ("%d", &op);
		
		if (op<1 || op>7)
			printf ("\n\n\tOpção inválida!!");
		
		if (op==1)
		{	printf ("\n\n\tDigite o número a ser inserido no início da lista: ");
			Lista *novo = (Lista *) malloc (sizeof(Lista));
			scanf ("%d", &novo->num);
			
			if (inicio == NULL)
			{	inicio = novo;
				fim = novo;
				novo->prox = NULL;
				novo->ant = NULL;
			}
			else
			{	novo->prox = inicio;
				inicio->ant=novo;
				novo->ant = NULL;
				inicio = novo;
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
				novo->prox = NULL;
				novo->ant = NULL;
			}
			else
			{	fim->prox = novo;
				novo->ant = fim;
				novo->prox = NULL;
				fim = novo;
			}
			printf ("\n\t\tNúmero inserido no final da lista!!\n\n\n");
		}
		
		if (op==3)
		{	if (inicio == NULL)
				printf ("\n\n\tLista vazia!!");
			else
			{	printf ("\n\n\tConsultando a lista do início ao fim: ");
				aux = inicio;
				
				while (aux != NULL)
				{	printf ("%d ", aux->num);
					aux = aux->prox;
				}
			}
		}
		
		if (op==4)
		{	if (inicio == NULL)
				printf ("\n\n\tLista vazia!!");
			else
			{	printf ("\n\n\tConsultando a lista do fim ao início: ");
				aux = fim;
				
				while (aux != NULL)
				{	printf ("%d ", aux->num);
					aux = aux->ant;
				}
			}
		}
		
		if (op==5)
		{	if (inicio==NULL)
				printf ("\n\n\tA lista está vazia!");
			else
			{	printf ("\n\n\tDigite o elemento a ser removido: ");
				scanf ("%d", &numero);
				
				aux = inicio;
				achou = 0;
				
				while (aux != NULL)
				{	if (aux->num == numero)	
					{	achou += 1;
						if (aux == inicio)
						{	inicio = aux->prox;
							if (inicio != NULL)
								inicio->ant = NULL;
							free (aux);
							aux = inicio;
						}
						else if (aux == fim)
						{	fim = fim->ant;
							fim->prox = NULL;
							free (aux);
							aux = NULL;
						}
						else
						{	aux->ant->prox = aux->prox;
							aux->prox->ant = aux->ant;
							Lista *aux2;
							aux2 = aux->prox;
							free (aux);
							aux = aux2;
						}
					}
					else
					{	aux = aux->prox;
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
		
		if (op==6)
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
		
		if (op==7)
			printf ("\n\n\tAté a próxima!");

		getch();
		system ("CLS");
	}
	while (op != 7);
}
