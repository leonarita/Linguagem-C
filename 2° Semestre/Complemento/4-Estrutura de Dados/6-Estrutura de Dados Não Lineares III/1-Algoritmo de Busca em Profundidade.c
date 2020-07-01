#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

//Revisar!!

struct vertice
{	int num;
	struct vertice *prox;
};

struct listaadj
{	struct vertice *listav;	};

struct queue
{	int numv;
	struct queue *prox;
};

void empilhar (struct queue *pilha, int n)
{	struct queue *novo = (struct queue *) malloc (sizeof(struct queue));
	novo->numv = n;
	novo->prox = pilha;
	pilha = novo;
}

void desempilhar (struct queue *pilha, int v)
{	if (pilha->numv == v)
	{	struct queue *aux;
		aux = pilha;
		pilha = pilha->prox;
		free (aux);
	}
}

void buscaprof (struct listaadj Adj[], int tam, int v, int marcado[], struct queue *pilha)
{	struct vertice *vert;
	int w, i;
	
	marcado[v] = 1;
	empilhar (pilha, v);
	
	for (i=1; i<=tam; i++)
	{	vert = Adj[v].listav;
	
		while (vert!=NULL)
		{	w = vert->num;
		
			if (marcado[w]!=1)
			{	printf (" %d", w);
				buscaprof (Adj, tam, w, marcado, pilha);
			}
			vert = vert->prox;
		}
	}
	desempilhar (pilha, v);
}

void mostrar_Adj (struct listaadj Adj[], int tam)
{	struct vertice *v;
	int i;
	
	for (i=1; i<=tam; i++)
	{	v = Adj[i].listav;
		printf ("\n\n\tEntrada %d ", i);
		
		while (v!=NULL)
		{	printf ("(%d, %d)", i, v->num);
			v = v->prox;
		}
	}
}

void main ()
{	setlocale (LC_ALL, "");
	
	struct queue *pilha = NULL;
	int *marcado = NULL;
	struct listaadj * Adj = NULL;
	struct vertice *novo, *aux;
	int tam, org, dest, op, num, tipo, i;
	
	printf ("\n\n\t\tTipos de Grafos\n");
	printf ("\n\t1-Não Orientado \n\t2-Orientado");
	printf ("\n\nInsira o tipo de grafo desejado: ");
	scanf ("%d", &tipo);
	
	printf ("\n\nInsira o número de vértices do grafo: ");
	scanf ("%d", &tam);
	
	Adj = (struct listaadj *) malloc ((tam+1) * sizeof(struct listaadj));
	marcado = (int *) malloc ((tam+1) * sizeof(int));
	
	for (i=0; i<=tam; i++)
	{	marcado[i] = 0;
		Adj[i].listav = NULL;
	}
	
	printf ("\n\n\tArestas do grafo: VérticeOrigem (-1 para parar): ");
	scanf ("%d", &org);
	printf ("\tArestas do grafo: VérticeDestino (-1 para parar): ");
	scanf ("%d", &dest);
	
	while (org!=-1 && dest!=-1)
	{	novo = (struct vertice *) malloc (sizeof(struct vertice));
		novo->num = dest;
		novo->prox = Adj[org].listav;
		Adj[org].listav = novo;
		
		if (tipo==1)
		{	novo = (struct vertice *) malloc (sizeof(struct vertice));
			novo->num = org;
			novo->prox = Adj[dest].listav;
			Adj[dest].listav = novo;
		}
		
		printf ("\n\n\tArestas do grafo: VérticeOrigem (-1 para parar): ");
		scanf ("%d", &org);
		printf ("\tArestas do grafo: VérticeDestino (-1 para parar): ");
		scanf ("%d", &dest);
	}
	
//	system ("cls");
	
	do
	{	printf ("\n\n\t\tMenu\n");
		printf ("\n\t1-Busca em profundidade");
		printf ("\n\t2-Mostrar lista de adjacencias");
		printf ("\n\t3-Sair");
		printf ("\n\nDigite sua opção: ");
		scanf ("%d", &op);
		
		if (op==1)
		{	printf ("\n\n\tDigite um vértice de partida da busca: ");
			scanf ("%d", &num);
			printf (" %d", num);
			buscaprof (Adj, tam, num, marcado, pilha);
			int i;
			
			for (i=1; i<=tam; i++)
				marcado[i] = 0;
		}
		
		else if (op==2)
			mostrar_Adj (Adj, tam);
		
		else if (op==3)
			printf ("\n\n\tAté mais!");
			
		else if (op<1 || op>3)
			printf ("\n\n\tOpção inválida!");
		
		getch();
		system ("CLS");
	}
	while (op!=3);
	
	free (marcado);
	
	for (i=1; i<=tam; i++)
	{
		while (Adj[i].listav!=NULL)
		{	aux = Adj[i].listav;
			Adj[i].listav = Adj[i].listav->prox;
			free (aux);
		}
	}
	free (Adj);
}
