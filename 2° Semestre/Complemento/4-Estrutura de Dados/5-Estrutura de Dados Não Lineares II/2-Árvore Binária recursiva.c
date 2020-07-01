#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

struct Arvore
{	int num;
	struct Arvore *esq, *dir;
};

struct Arvore *inserir (struct Arvore *aux, int num)
{
	if (aux==NULL)
	{	aux = (struct Arvore *) malloc (sizeof(struct Arvore));
		aux->num = num;
		aux->esq = NULL;
		aux->dir = NULL;
	}
	else if (num<aux->num)
		aux->esq = inserir(aux->esq, num);
	else
		aux->dir = inserir(aux->dir, num);
	return aux;
}

int consultar (struct Arvore *aux, int num, int achou)
{
	if (aux!=NULL && achou==0)
	{	if (aux->num==num)
			achou=1;
		else if (num<aux->num)
			achou = consultar (aux->esq, num, achou);
		else
			achou = consultar (aux->dir, num, achou);
	}
	return achou;
}

void mostraremordem (struct Arvore *aux)
{	if (aux!=NULL)
	{	mostraremordem (aux->esq);
		printf ("%d ", aux->num);
		mostraremordem (aux->dir);
	}
}

void mostrarpreordem (struct Arvore *aux)
{	if (aux!=NULL)
	{	printf ("%d ", aux->num);
		mostrarpreordem (aux->esq);
		mostrarpreordem (aux->dir);
	}
}

void mostrarposordem (struct Arvore *aux)
{	if (aux!=NULL)
	{	mostrarposordem (aux->esq);
		mostrarposordem (aux->dir);
		printf ("%d ", aux->num);
	}
}

struct Arvore *remover (struct Arvore *aux, int num)
{	struct Arvore *p, *p2;

	if (aux->num==num)
	{
		if (aux->esq==aux->dir)
		{	free (aux);
			return NULL;
		}
		else if (aux->esq==NULL)
		{	p=aux->dir;
			free (aux);
			return p;
		}
		else if (aux->dir==NULL)
		{	p = aux->esq;
			free (aux);
			return p;
		}
		else
		{	p2 = aux->dir;
			p = aux->dir;
			
			while (p->esq!=NULL)
				p = p->esq;
			
			p->esq = aux->esq;
			free (aux);
			return p2;
		}
	}
	
	else if (aux->num<num)
		aux->dir = remover (aux->dir, num);
	else
		aux->esq = remover (aux->esq, num);
	
	return aux;
}

struct Arvore *desalocar (struct Arvore *aux)
{
	if (aux!=NULL)
	{	aux->esq = desalocar (aux->esq);
		aux->dir = desalocar (aux->dir);
		free (aux);
	}
	return NULL;
}

void main ()
{	setlocale (LC_ALL, "");

	struct Arvore *raiz = NULL;
	struct Arvore *aux;
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
			scanf ("%d", &numero);
			raiz = inserir (raiz, numero);
			printf ("\n\t\tNúmero inserido na árvore!");
		}
		
		else if (op==2)
		{	if (raiz==NULL)
				printf ("\n\n\tÁrvore vazia!");
			else
			{	printf ("\n\n\tDigite o número a ser consultado: ");
				scanf ("%d", &numero);
				achou = 0;
				achou = consultar (raiz, numero, achou);
				
				if (achou==0)
					printf ("\n\t\tNúmero não encontrado na árvore!");
				else
					printf ("\n\t\tNúmero encontrado na árvore!");
			}
		}
		
		else if (op==3)
		{	if (raiz==NULL)
				printf ("\n\n\tÁrvore vazia!");
			else
			{	printf ("\n\n\tListando todos os elementos da árvore em ordem: ");
				mostraremordem (raiz);
			}
		}
		
		else if (op==4)
		{	if (raiz==NULL)
				printf ("\n\n\tÁrvore vazia!");
			else
			{	printf ("\n\n\tListando todos os elementos da árvore em pré-ordem: ");
				mostrarpreordem (raiz);
			}
		}
		
		else if (op==5)
		{	if (raiz==NULL)
				printf ("\n\n\tÁrvore vazia!");
			else
			{	printf ("\n\n\tListando todos os elementos da árvore em pós-ordem: ");
				mostrarposordem (raiz);
			}
		}
		
		else if (op==6)
		{	if (raiz==NULL)
				printf ("\n\n\tÁrvore vazia!");
			else
			{	printf ("\n\n\tDigite o número que deseja excluir: ");
				scanf ("%d", &numero);
				achou = 0;
				achou = consultar (raiz, numero, achou);
				
				if (achou==0)
					printf ("\n\t\tNúmero não encontrado na árvore!");
				else
				{	raiz = remover (raiz, numero);
					printf ("\n\t\tNúmero excluído da árvore!");
				}
			}
		}
		
		else if (op==7)
		{	if (raiz==NULL)
				printf ("\n\n\tÁrvore vazia!");
			else
			{	raiz = desalocar (raiz);
				printf ("\n\t\tÁrvore esvaziada!");
			}
		}
		
		else if (op==8)
			printf ("\n\n\tAté mais!!");
			
		getch();
		system ("CLS");
	}
	while (op!=8);
}
