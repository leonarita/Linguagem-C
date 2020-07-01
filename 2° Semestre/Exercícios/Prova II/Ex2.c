#include <stdio.h>
#include <stdlib.h>

struct Fila 
{	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens; 
};

void criarFila( struct Fila *f, int c ) 
{	f->capacidade = 1;
	f->dados = (float*) malloc (sizeof(float));
}

void inserir(struct Fila *f, float v) 
{	f->dados = (float *) realloc (f->dados, (f->capacidade+1)* sizeof(float));
	f->dados[f->capacidade-1] = v;
}

int remover( struct Fila *f )
{	int i;

	for (i=0; i<f->capacidade-1; i++)
	{	f->dados[i] = f->dados[i+1];
	}
	f->dados = (float *) realloc (f->dados, (f->capacidade-1)* sizeof(float));
}

int estaVazia( struct Fila *f ) 
{ // retorna verdadeiro se a fila está vazia
	return (f->nItens==0);
}

int estaCheia( struct Fila *f )
{ // retorna verdadeiro se a fila está cheia
	return (f->nItens == f->capacidade);
}

void mostrarFila(struct Fila *f)
{	int cont;

	for (cont=0; cont < f->capacidade-1;cont++)
		printf("%.2f\t",f->dados[cont]);
	printf("\n\n");
}

void main ()
{	int opcao, capa;
	float valor;
	struct Fila umaFila;
	int i, cap=1, j;
	float *aux = (float *) malloc (sizeof(float));
	float auxiliar;

	criarFila(&umaFila, capa);
	
	do
	{	printf("\nValor do elemento a ser inserido? ");
		scanf("%f", &valor);
		if (valor<0)
			break;
		aux = (float *) realloc (aux, (cap+1)*sizeof(float));
		aux[cap-1] = valor;
		cap++;
	}
	while (valor>0);
	
	printf ("\n\n\tVetor (não ordenado): ");
	for (i=0; i<cap-1; i++)
		printf ("%.2f ", aux[i]);
	
	for (i=0; i<cap-2; i++)
		for (j=i+1; j<cap-1; j++)
			if (aux[i]>aux[j])
			{	auxiliar = aux[i];
				aux[i] = aux[j];
				aux[j] = auxiliar;
			}
	
	printf ("\n\n\tLista (ordenada): ");
	for (i=0; i<cap-1; i++)
	{	inserir (&umaFila, aux[i]);
		printf ("%.2f ", umaFila.dados[i]);
		umaFila.capacidade++;
	}

	// apresenta menu
	while (1)
	{	printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpcao? ");
		scanf("%d", &opcao);

		
		switch(opcao)
		{
			case 0: exit(0);

			case 1: // insere elemento
				if (estaCheia(&umaFila))
					printf("\nFila Cheia!!!\n\n");

				else 
				{	printf("\nValor do elemento a ser inserido? ");
					scanf("%f", &valor);
					inserir(&umaFila,valor);
				}
				break;

			case 2: // remove elemento
				if (estaVazia(&umaFila))
					printf("\nFila vazia!!!\n\n");
				else 
				{	printf("\n%1f removido com sucesso\n\n", umaFila.dados[0]) ;
					valor = remover(&umaFila);
					printf("\nConteudo da fila => ");
					umaFila.capacidade--;
					mostrarFila(&umaFila);
					
				}
				break;

			case 3: // mostrar fila
				if (estaVazia(&umaFila))
					printf("\nFila vazia!!!\n\n");
				else 
				{	printf("\nConteudo da fila => ");
					mostrarFila(&umaFila);
				}
				break;

			default:
				printf("\nOpcao Invalida\n\n");
		}
	}
	
	system ("CLS");
	
	system("PAUSE");
}

