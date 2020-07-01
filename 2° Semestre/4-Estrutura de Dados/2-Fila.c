#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

#define TAMANHO_MAXIMO 100

struct queue
{	int itens[TAMANHO_MAXIMO];
	int front,rear;
};

int empty(struct queue * pq)
{
	/* se o in�cio da Fila for igual ao Final da ila, a Fila est� vazia */
	if( pq->front == pq->rear )
	{	return 1;	}
	
	return 0;
}

void enqueue(struct queue * pq, int x)
{	if( pq->rear + 1 >= TAMANHO_MAXIMO )
	{	printf("\nEstouro da capacidade da Fila");
		exit(1);
	}
	pq->itens[pq->rear++] = x;
	return;
}

int size(struct queue * pq)
{	return (pq->rear);	}

int front(struct queue * pq)
{	/* o primeiro elemento sempre est� no in�cio do vetor */
	if (size(pq)==0)
	{	printf ("\n\n\tfila vazia!");
		return 0;
	}
	return pq->itens[0];
}

int dequeue(struct queue * pq)
{	int x, i;

	if (empty(pq))
	{	printf("\nFila vazia");
		return 0;
	}

	/* Salva o primeiro elemento e refaz o arranjo dos itens, puxando o segundo elemento
	para o primeiro, o terceiro para o segundo e assim sucessivamente. */
	
	x = pq->itens[0];
	
	for( i=0; i < pq->rear; i++)
	{	pq->itens[i] = pq->itens[i+1];	}
	
	pq->rear--;
	return x;
}

void mostra (struct queue *pq)
{	int i;
printf ("\n\n\n\tFILA: ");
	for (i=0; i<pq->rear; i++)
		printf (" %d", pq->itens[i]);
}

int main ()
{	setlocale (LC_ALL, "");
	int op;
	struct queue ElList;
	
	do
	{	printf ("\n\n\t\tMENU DE OP��ES\n");
		printf ("\n\t1-Insira um elemento na fila");
		printf ("\n\t2-Remove um elemento na fila");
		printf ("\n\t3-Verifica se a lista est� fila");
		printf ("\n\t4-Retorna o tamanho da fila");
		printf ("\n\t5-Retorna o pr�ximo elemento da fila");
		printf ("\n\t6-Sair");
		printf ("\n\nSelecione a op��o desejada: ");
		scanf ("%d", &op);
		
		if (op<1 || op>6)
			printf ("\n\n\tOp��o inv�lida!");
	
		if (op==1)
		{	int elem;
			printf ("\n\n\tInforme o elemento a ser inserido:");
			scanf ("%d", &elem);
			enqueue (&ElList, elem);
		}
		
		if (op==2)
			dequeue (&ElList);
		
		if (op==3)
		{	if (empty(&ElList)==1)
				printf ("\n\n\tA fila est� vazia!!");
			else
				printf ("\n\n\tA fila n�o est� vazia!!");
		}
		
		if (op==4)
			printf ("\n\n\tO tamanho da fila � %d", size(&ElList));
		
		if (op==5)
			printf ("\n\n\tO pr�ximo elemento da fila � %d", front(&ElList));
			
		if (op==6)
			printf ("\n\n\tAt� mais!!!");
			
		mostra (&ElList);
	}
	while (op!=6);
}
