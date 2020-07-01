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
		printf ("\n\n\t\tMENU DE OP��ES \n");
		printf ("\n\t1-Inserir na �rvore");
		printf ("\n\t2-Consultar um n� da �rvore");
		printf ("\n\t3-Consultar toda a �rvore em ordem");
		printf ("\n\t4-Consultar toda a �rvore em pr�-ordem");
		printf ("\n\t5-Consultar toda a �rvore em p�s-ordem");
		printf ("\n\t6-Excluir um n� de �rvore");
		printf ("\n\t7-Esvaziar a �rvore");
		printf ("\n\t8-Sair");
		printf ("\n\nDigite sua op��o: ");
		scanf ("%d", &op);
		
		if (op<1 || op>8)
			printf ("\n\n\tOp��o inv�lida!");
			
		else if (op==1)
		{	printf ("\n\n\tDigite o n�mero a ser inserido na �rvore: ");
			scanf ("%d", &numero);
			raiz = inserir (raiz, numero);
			printf ("\n\t\tN�mero inserido na �rvore!");
		}
		
		else if (op==2)
		{	if (raiz==NULL)
				printf ("\n\n\t�rvore vazia!");
			else
			{	printf ("\n\n\tDigite o n�mero a ser consultado: ");
				scanf ("%d", &numero);
				achou = 0;
				achou = consultar (raiz, numero, achou);
				
				if (achou==0)
					printf ("\n\t\tN�mero n�o encontrado na �rvore!");
				else
					printf ("\n\t\tN�mero encontrado na �rvore!");
			}
		}
		
		else if (op==3)
		{	if (raiz==NULL)
				printf ("\n\n\t�rvore vazia!");
			else
			{	printf ("\n\n\tListando todos os elementos da �rvore em ordem: ");
				mostraremordem (raiz);
			}
		}
		
		else if (op==4)
		{	if (raiz==NULL)
				printf ("\n\n\t�rvore vazia!");
			else
			{	printf ("\n\n\tListando todos os elementos da �rvore em pr�-ordem: ");
				mostrarpreordem (raiz);
			}
		}
		
		else if (op==5)
		{	if (raiz==NULL)
				printf ("\n\n\t�rvore vazia!");
			else
			{	printf ("\n\n\tListando todos os elementos da �rvore em p�s-ordem: ");
				mostrarposordem (raiz);
			}
		}
		
		else if (op==6)
		{	if (raiz==NULL)
				printf ("\n\n\t�rvore vazia!");
			else
			{	printf ("\n\n\tDigite o n�mero que deseja excluir: ");
				scanf ("%d", &numero);
				achou = 0;
				achou = consultar (raiz, numero, achou);
				
				if (achou==0)
					printf ("\n\t\tN�mero n�o encontrado na �rvore!");
				else
				{	raiz = remover (raiz, numero);
					printf ("\n\t\tN�mero exclu�do da �rvore!");
				}
			}
		}
		
		else if (op==7)
		{	if (raiz==NULL)
				printf ("\n\n\t�rvore vazia!");
			else
			{	raiz = desalocar (raiz);
				printf ("\n\t\t�rvore esvaziada!");
			}
		}
		
		else if (op==8)
			printf ("\n\n\tAt� mais!!");
			
		getch();
		system ("CLS");
	}
	while (op!=8);
}
