#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

struct Arvore
{	int num, altd, alte;
	struct Arvore *esq, *dir;
};

struct Arvore *rotacao_esquerda (struct Arvore *aux)
{	struct Arvore *aux1, *aux2;
	aux1 = aux->dir;
	aux2 = aux1->esq;
	aux->dir = aux2;
	aux1->esq = aux;
	
	if (aux->dir==NULL)
		aux->altd = 0;
	else if (aux->dir->alte > aux->dir->altd)
		aux->altd = aux->dir->alte+1;
	else
		aux->altd = aux->dir->altd+1;
	
	if (aux1->esq->alte > aux1->esq->altd)
		aux1->alte = aux1->esq->alte+1;
	else
		aux1->alte = aux1->esq->altd+1;
		
	return aux1;
}

struct Arvore *rotacao_direita (struct Arvore *aux)
{	struct Arvore *aux1, *aux2;

	aux1 = aux->esq;
	aux2 = aux1->dir;
	aux->esq = aux2;
	aux1->dir = aux;
	
	if (aux->esq==NULL)
		aux->alte=0;
	else if (aux->esq->alte > aux->esq->altd)
		aux->alte=aux->esq->alte+1;
	else
		aux->alte=aux->esq->alte+1;
		
	if (aux1->dir->alte > aux1->dir->altd)
		aux1->altd=aux1->dir->alte+1;
	else
		aux1->altd=aux1->dir->altd+1;
		
	return aux1;
}

struct Arvore *balanceamento (struct Arvore *aux)
{	int d, df;
	d = aux->altd - aux->alte;
	
	if (d==2)
	{	df = aux->dir->altd - aux->dir->alte;
	
		if (df>=0)
			aux = rotacao_esquerda (aux);
		else
		{	aux->dir = rotacao_direita (aux->dir);
			aux = rotacao_esquerda (aux);
		}
	}
	
	else if (d==-2)
	{	df = aux->esq->altd - aux->esq->alte;
	
		if (df<=0)
			aux = rotacao_direita (aux);
		else
		{	aux->esq = rotacao_esquerda (aux->esq);
			aux = rotacao_direita (aux);
		}
	}
	return aux;
}

struct Arvore *inserir (struct Arvore *aux, int num)
{	struct Arvore *novo;

	if (aux==NULL)
	{	novo = (struct Arvore *) malloc (sizeof(struct Arvore));
		novo->num = num;
		novo->altd = 0;
		novo->alte = 0;
		novo->esq = NULL;
		novo->dir = NULL;
		aux = novo;
	}
	else if (num < aux->num)
	{	aux->esq = inserir (aux->esq, num);
		
		if (aux->esq->altd > aux->esq->alte)
			aux->alte = aux->esq->altd + 1;
		else
			aux->alte = aux->esq->alte + 1;
		aux = balanceamento (aux);
	}
	else
	{	aux->dir = inserir (aux->dir, num);
		
		if (aux->dir->altd > aux->dir->alte)
			aux->altd = aux->dir->altd + 1;
		else
			aux->altd = aux->dir->alte + 1;
		aux = balanceamento (aux);
	}
	return aux;
}

int consultar (struct Arvore *aux, int num, int achou)
{
	if (aux!=NULL && achou==0)
	{
		if (aux->num == num)
			achou = 1;
		else if (num < aux->num)
			achou = consultar (aux->esq, num, achou);
		else
			achou = consultar (aux->dir, num, achou);
	}
	return achou;
}

void mostraremordem (struct Arvore *aux)
{
	if (aux!=NULL)
	{	mostraremordem (aux->esq);
		printf ("%d ", aux->num);
		mostraremordem (aux->dir);
	}
}

void mostrarpreordem (struct Arvore *aux)
{
	if (aux!=NULL)
	{	printf ("%d ", aux->num);
		mostrarpreordem (aux->esq);
		mostrarpreordem (aux->dir);
	}
}

void mostrarposordem (struct Arvore *aux)
{
	if (aux!=NULL)
	{	mostrarpreordem (aux->esq);
		mostrarpreordem (aux->dir);
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

struct Arvore *atualiza (struct Arvore *aux)
{
	if (aux!=NULL)
	{	aux->esq = atualiza (aux->esq);
	
		if (aux->esq == NULL)
			aux->alte = 0;
		else if (aux->esq->alte > aux->esq->altd)
			aux->alte = aux->esq->alte +1;
		else
			aux->alte = aux->esq->altd +1;
		
		aux->dir = atualiza (aux->dir);
	
		if (aux->dir == NULL)
			aux->altd = 0;
		else if (aux->dir->alte > aux->dir->altd)
			aux->altd = aux->dir->alte +1;
		else
			aux->altd = aux->dir->altd +1;
		aux = balanceamento (aux);
	}
	return aux;
}

struct Arvore *deslocar (struct Arvore *aux)
{	if (aux!=NULL)
	{	aux->esq = deslocar (aux->esq);
		aux->dir = deslocar (aux->dir);
		free (aux);
	}
	return NULL;
}

void main ()
{	setlocale (LC_ALL, "");

	struct Arvore *raiz=NULL;
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
				aux = raiz;
				mostrarposordem (aux);
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
					raiz = atualiza (raiz);
					printf ("\n\t\tN�mero exclu�do da �rvore!");
				}
			}
		}
		
		else if (op==7)
		{	if (raiz==NULL)
				printf ("\n\n\t�rvore vazia!");
			else
			{	raiz = deslocar (raiz);
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
