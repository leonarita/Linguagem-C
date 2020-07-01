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

struct fila
{	int numv;
	struct fila *prox;
};

void inserir (struct fila *inicio, struct fila *fim, int n)
{	struct fila *novo = (struct fila *) malloc (sizeof(struct fila));
	novo->numv = n;
	novo->prox = NULL;
	
	if (inicio==NULL)
	{	fim = novo;
		inicio = fim;
	}
	else
	{	fim->prox = novo;
		fim = novo;
	}
}

int remover (struct fila *inicio, struct fila *fim)
{
	if (inicio!=NULL)
	{	int vert;
	
		if (inicio==fim)
			fim = NULL;
		
		vert = inicio->numv;
		inicio = inicio->prox;
		return vert;
	}
	printf ("\n\n\tLista vazia!");
	return 0;
}

void buscalargura (struct listaadj Adj[], struct fila *inicio, struct fila *fim, int tam, int v, int marcado[], int dist[])
{	struct vertice *listavert;
	int w, vertice;
	marcado[v] = 1;
	dist[v] = 0;
	inserir (inicio, fim, v);
	
	while (inicio!=NULL)
	{	vertice = remover (inicio, fim);
		int i;
		
		for (i=1; i<=tam; i++)
		{	listavert = Adj[vertice].listav;
		
			while (listavert != NULL)
			{	w = listavert->num;
			
				if (marcado[w]==0)
				{	marcado[w]=1;
					dist[w] = dist[vertice]+1;
					inserir (inicio, fim, w);
				}
				listavert = listavert->prox;
			}
		}
	}
}

void mostrar_Adj (struct listaadj Adj[], int tam)
{	struct vertice *v;
	int i;
	printf ("\n\n");
	
	for (i=1; i<=tam; i++)
	{	v = Adj[i].listav;
		printf ("\n\tEntrada %d ", i);
		
		while (v!=NULL)
		{	printf ("(%d, %d)", i, v->num);
			v = v->prox;
		}
	}
}

void mostrar_dist (int dist[], int tam, int o)
{	printf ("\n\n\tDistância da origem %d para os demais vértice", o);
	int i;

	for (i=1; i<=tam; i++)
	{	printf ("\nVértice %d - %d", i, dist[i]);	}
}

void main ()
{	setlocale (LC_ALL, "");

	struct fila *inicio=NULL, *fim=NULL, *temp;
	int *marcado, *dist;
	struct listaadj *Adj;
	struct vertice *novo, *aux;
	int tam, org, dest, op, num=0, tipo, flag=0, i;
	
	printf ("\n\n\t\tTipos de Grafos\n");
	printf ("\n\t1-Não Orientado \n\t2-Orientado");
	printf ("\n\nInsira o tipo de grafo desejado: ");
	scanf ("%d", &tipo);
	
	printf ("\n\nInsira o número de vértices do grafo: ");
	scanf ("%d", &tam);
	
	Adj = (struct listaadj *) malloc ((tam+1) * sizeof(struct listaadj));
	marcado = (int *) malloc ((tam+1) * sizeof(int));
	dist = (int *) malloc ((tam+1) * sizeof(int));
	
	for (i=0; i<=tam; i++)
	{	Adj[i].listav = NULL;
		marcado[i] = 0;
	}
	
	printf ("\n\n\tArestas do grafo: VérticeOrigem (-1 para parar): ");
	scanf ("%d", &org);
	printf ("\tArestas do grafo: VérticeDestino (-1 para parar): ");
	scanf ("%d", &dest);
	
	while (org!=-1 && dest!=-1)
	{	novo = (struct vertice *) malloc (sizeof(struct vertice));
		novo->num = dest;
		novo->prox = Adj[org].listav;
		
		if (tipo==1)
		{	novo->num= org;
			novo->prox = Adj[dest].listav;
			Adj[dest].listav = novo;
		}
		
		printf ("\n\n\tArestas do grafo: VérticeOrigem (-1 para parar): ");
		scanf ("%d", &org);
		printf ("\tArestas do grafo: VérticeDestino (-1 para parar): ");
		scanf ("%d", &dest);
	}
	
	do
	{	printf ("\n\n\t\tMenu\n");
		printf ("\n\t1-Busca em largura");
		printf ("\n\t2-Mostrar lista de adjacencias");
		printf ("\n\t3-Menor distância a partir do vértice de origem");
		printf ("\n\t4-Sair");
		printf ("\n\nDigite sua opção: ");
		scanf ("%d", &op);
		
		if (op==1)
		{	printf ("\n\n\tDigite um vértice de partida da busca: ");
			scanf ("%d", &num);
			int i;
			
			for (i=1; i<=tam; i++)
			{	marcado[i] = 0;
				dist[i] = 0;
			}
			
			buscalargura (Adj, inicio, fim, tam, num, marcado, dist);
			flag = 1;
		}
		
		else if (op==2)
			mostrar_Adj (Adj, tam);
			
		else if (op==3)
		{
			if (flag==0)
				printf ("\n\n\tÉ necessário realizar a busca primeiro");
			else
				mostrar_dist (dist, tam, num);
		}
		
		else if (op==4)
			printf ("\n\n\tAté mais!");
			
		else if (op<1 || op>4)
			printf ("\n\n\tOpção inválida!");
		
		getch();
		system ("CLS");
	}
	while (op!=4);
	
	free (marcado);
	free (dist);
	
	for (i=1; i<=tam; i++)
	{
		while (Adj[i].listav!=NULL)
		{	aux = Adj[i].listav;
			Adj[i].listav = Adj[i].listav->prox;
			free (aux);
		}
	}
	free (Adj);
	
	while (inicio!=NULL)
	{	temp = inicio;
		inicio = inicio->prox;
		free (aux);
	}
}

