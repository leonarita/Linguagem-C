#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

struct Arvore
{	int num;
	struct Arvore *esq, *dir;
};

struct Pilha
{	struct Arvore *num;
	struct Pilha *prox;
};

void main ()
{	setlocale (LC_ALL, "");

	struct Arvore *raiz = NULL;
	struct Arvore *aux, *aux1, *novo, *anterior;
	struct Pilha *topo, *aux_pilha;
	int op, achou, numero;
	
	do
	{	fflush (stdin);
		printf ("\n\n\t\tMENU DE OPÇÕES \n");
		printf ("\n\t1-Inserir na árvore");
		printf ("\n\t2-Consultar um nó da árvore");
		printf ("\n\t3-Consultar toda a árvore em ordem");
		printf ("\n\t4-Consultar toda a árvore em pré-ordem");
		printf ("\n\t5-Consultar toda a árvore em pós-ordem");
		printf ("\n\t6-Excluir um nó de árvore");
		printf ("\n\t7-Esvaziar a árvore");
		printf ("\n\t8-Sair");
		printf ("\n\nDigite sua opção: ");
		scanf ("%d", &op);
		
		if (op<1 || op>8)
			printf ("\n\n\tOpção inválida!");
			
		else if (op==1)
		{	printf ("\n\n\tDigite o número a ser inserido na árvore: ");
			novo = (struct Arvore *) malloc (sizeof(struct Arvore));
			scanf ("%d", &novo->num);
			novo->dir = NULL;
			novo->esq = NULL;
			
			if (raiz==NULL)
				raiz = novo;
			else
			{	aux = raiz;
				achou = 0;
				
				while (achou==0)
				{
					if (novo->num < aux->num)
					{
						if (aux->esq == NULL)
						{	aux->esq = novo;
							achou = 1;
						}
						else
							aux = aux->esq;
					}
					else if (novo->num >= aux->num)
					{
						if (aux->dir == NULL)
						{	aux->dir = novo;
							achou = 1;
						}
						else
							aux = aux->dir;
					}
				}
			}
			printf ("\n\t\tNúmero inserido na árvore!!");
		}
		
		else if (op==2)
		{
			if (raiz==NULL)
				printf ("\n\n\tÁrvore vazia!!");
			else
			{	printf ("\n\n\tDigite o elemento a ser consultado: ");
				scanf ("%d", &numero);
				achou=0;
				aux = raiz;
				
				while (aux!=NULL && achou==0)
				{	if (aux->num == numero)
					{	printf ("\n\n\tNúmero encontrado na árvore!");
						achou = 1;
					}
					else if (numero < aux->num)
						aux = aux->esq;
					else
						aux = aux->dir;
				}
				
				if (achou==0)
					printf ("\n\n\tNúmero não encontrado na árvore!");
			}
		}
		
		else if (op==3)
		{
			if (raiz==NULL)
			{	printf ("\n\n\tÁrvore vazia!!");
			}
			else
			{	printf ("\n\n\tListando todos os elementos da árvore em ordem: ");
				aux = raiz;
				topo = NULL;
				
				do
				{	while (aux!=NULL)
					{	aux_pilha = (struct Pilha *) malloc (sizeof(struct Pilha));
						aux_pilha->num = aux;
						aux_pilha->prox = topo;
						topo = aux_pilha;
						aux = aux->esq;
					}
					
					if (topo!=NULL)
					{	aux_pilha = topo;
						printf ("%d ", aux_pilha->num->num);
						aux = topo->num->dir;
						topo = topo->prox;
					}
				}
				while (topo!=NULL || aux!=NULL);
			}
		}
		
		else if (op==4)
		{
			if (raiz==NULL)
			{	printf ("\n\n\tÁrvore vazia!!");
			}
			else
			{	printf ("\n\n\tListando todos os elementos da árvore em pré-ordem: ");
				aux=raiz;
				topo=NULL;
				
				do
				{	while (aux!=NULL)
					{	aux_pilha = (struct Pilha *) malloc (sizeof(struct Pilha));
						printf ("%d ", aux->num);
						aux_pilha->num = aux;
						aux_pilha->prox = topo;
						topo = aux_pilha;
						aux = aux->esq;
					}
					
					if (topo!=NULL)
					{	aux_pilha = topo;
						topo = topo->prox;
						aux = aux_pilha->num->dir;
					}
				}
				while (topo!=NULL || aux!=NULL);
			}
		}
		
		else if (op==5)
		{
			if (raiz==NULL)
			{	printf ("\n\n\tÁrvore vazia!!");
			}
			else
			{	printf ("\n\n\tListando todos os elementos da árvore em pós-ordem: ");
				aux=raiz;
				topo=NULL;
				
				do
				{	do
					{	while (aux!=NULL)
						{	aux_pilha = (struct Pilha *) malloc (sizeof(struct Pilha));
							aux_pilha->num = aux;
							aux_pilha->prox = topo;
							topo = aux_pilha;
							aux = aux->esq;
						}
						
						if (topo->num->dir!=NULL)
							aux = topo->num->dir;
					}
					while (aux!=NULL);
					
					if (topo!=NULL)
					{	printf ("%d ", topo->num->num);
					
						if (topo->prox!=NULL)
						{
							if (topo->prox->num->dir!=NULL && topo->prox->num->dir!=topo->num)
							{	aux = topo->prox->num->dir;
								topo = topo->prox;
							}
							else
							{	while (topo->prox!=NULL && topo->prox->num->dir==topo->num)
								{	topo = topo->prox;
									printf ("%d ", topo->num->num);
								}
								topo = topo->prox;
								
								if (topo!=NULL)
									aux = topo->num->dir;
								else
									aux = NULL;
							}
						}
						else
						{	topo = topo->prox;
							aux = NULL;
						}
					}
				}
				while (topo!=NULL || aux!=NULL);
			}
		}
		
		else if (op==6)
		{
			if (raiz==NULL)
			{	printf ("\n\n\tÁrvore vazia!!");
			}
			else
			{	printf ("\n\n\tDigite o número que deseja excluir: ");
				scanf ("%d", &numero);
				aux = raiz;
				achou = 0;
				
				while (achou==0 && aux!=NULL)
				{
					if (aux->num==numero)
						achou = 1;
					else if (aux->num>numero)
						aux = aux->esq;
					else
						aux = aux->dir;
				}
				
				if (achou==0)
					printf ("\n\t\tNúmero não encontrado!");
				else
				{
					if (aux!=raiz)
					{	anterior = raiz;
					
						while (anterior->dir!=aux && anterior->esq!=aux)
						{
							if (anterior->num>numero)
								anterior = anterior->esq;
							else
								anterior = anterior->dir;
						}
						
						if (aux->dir==NULL && aux->esq==NULL)
						{
							if (anterior->dir==aux)
								anterior->dir = NULL;
							else
								anterior->esq = NULL;
							
							free (aux);
						}
						else
						{
							if (aux->dir!=NULL && aux->esq==NULL)
							{
								if (anterior->esq==aux)
									anterior->esq = aux->dir;
								else
									anterior->dir = aux->dir;
								free (aux);
							}
							else if (aux->esq!=NULL && aux->dir==NULL)
							{	if (anterior->esq==aux)
									anterior->esq = aux->esq;
								else
									anterior->dir = aux->esq;
								free (aux);
							}
							else if (aux->esq!=NULL && aux->dir!=NULL)
							{	if (anterior->dir==aux)
								{	anterior->dir = aux->dir;
									aux1 = aux->esq;
								}
								else
								{	anterior->esq = aux->dir;
									aux1 = aux->esq;
								}
								free (aux);
								
								aux = anterior;
								
								while (aux!=NULL)
								{
									if (aux->num<aux1->num)
									{	if (aux->dir==NULL)
										{	aux->dir = aux1;
											aux = NULL;
										}
										else
											aux = aux->dir;
									}
									else if (aux->num>aux1->num)
									{	if (aux->esq==NULL)
										{	aux->esq = aux1;
											aux = NULL;
										}
										else
											aux = aux->esq;
									}
								}
							}
						}
					}
					else
					{	if (aux->dir==NULL && aux->esq==NULL)
						{	free (aux);
							raiz = NULL;
						}
						else
						{	if (aux->dir!=NULL && aux->esq==NULL)
							{	raiz = aux->dir;
								free (aux);
							}
							else if (aux->esq!=NULL && aux->dir==NULL)
							{	raiz = aux->esq;
								free (aux);
							}
							else if (aux->esq!=NULL && aux->dir!=NULL)
							{	raiz = aux->dir;
								aux1 = aux->esq;
								free (aux);
								aux = raiz;
								
								while (aux!=NULL)
								{	if (aux->num < aux1->num)
									{	if (aux->dir==NULL)
										{	aux->dir = aux1;
											aux = NULL;
										}
										else
											aux = aux->dir;
									}
									else if (aux->num>aux1->num)
									{	if (aux->esq == NULL)
										{	aux->esq = aux1;
											aux = NULL;
										}
										else
											aux = aux->esq;
									}
								}
							}
						}
					}
					printf ("\n\t\tNúmero excluído da árvore!");
				}
			}
		}
		
		else if (op==7)
		{
			if (raiz==NULL)
				printf ("\n\n\tÁrvore vazia!!");
			else
			{	aux = raiz;
				topo = NULL;
				
				do
				{	while (aux!=NULL)
					{	aux_pilha = (struct Pilha *) malloc (sizeof(struct Pilha));
						printf ("\n\t\t%d ", aux->num);
						aux_pilha->num = aux;
						aux_pilha->prox = topo;
						topo = aux_pilha;
						aux = aux->esq;
					}
					
					if (topo!=NULL)
					{	aux_pilha = topo;
						topo = topo->prox;
						aux = aux_pilha->num->dir;
					}
				}
				while (topo!=NULL || aux!=NULL);
				
				aux_pilha = topo;
				
				while (aux_pilha!=NULL)
				{	topo=topo->prox;
					free (topo->num);
					free (aux_pilha);
					aux_pilha = topo;
				}
				raiz=NULL;
				printf ("\n\t\tPilha esvaziada!!");
			}
		}
		
		
		else if (op==8)
			printf ("\n\n\tAté mais!!");
			
		getch();
		system ("CLS");
	}
	while (op!=8);
}
