#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct Pilha
{	int topo;
	int capa;
	float *pElem;
};

void criarpilha (struct Pilha *p, int c)
{	p->topo = -1;
	p->capa = c;
	p->pElem = (float*) malloc (c * sizeof(float));
}

int estavazia (struct Pilha *p)
{	if (p->topo == -1)
		return 1; // true
	else
		return 0; // false
}

int estacheia (struct Pilha *p)
{	if (p->topo == p->capa-1)
		return 1;
	else
		return 0;
}

void empilhar (struct Pilha *p, float v)
{	p->topo++;
	p->pElem[p->topo] = v;
}

float desempilhar (struct Pilha *p)
{	float aux = p->pElem[p->topo];
	p->topo--;
	return aux;
}

float retornatopo (struct Pilha *p)
{	return p->pElem[p->topo];
}

int main()
{	setlocale (LC_ALL, "");
	
	struct Pilha minhapilha;
	int capacidade, op;
	float valor;

	printf ("\nInsira a capacidade da pilha: ");
	scanf ("%d", &capacidade);
	criarpilha (&minhapilha, capacidade);

	while (1)
	{	printf("\nOPERAÇÕES DA PILHA\n");
		printf("\n\t1-push: empilhar");
		printf("\n\t2-pop: desempilhar");
		printf("\n\t3-top: mostrar o topo");
		printf("\n\t4-Sair");
		printf("\n\nInsira a opção desejada: ");
		scanf("%d", &op);
	
		switch (op)
		{
			case 1: //push
				if (estacheia(&minhapilha) == 1)
					printf ("\n\n\tA pilha está cheia!");
				else
				{	printf ("\n\n\tInforme o valor para ser inserido na pilha: ");
					scanf ("%f", &valor);
					empilhar (&minhapilha, valor);
				}
				break;
			
			case 2: //pop
				if (estavazia(&minhapilha) == 1)
					printf ("\n\n\tA pilha está vazia!");
				else
				{
					valor = desempilhar (&minhapilha);
					printf ("\n\n\tElemento %.1f desempilhado!", valor);
				}
				break;
			
			case 3: // mostrar o topo
			if ( estavazia (&minhapilha) == 1 )
				printf ("\n\n\tA pilha está vazia!");
			else {
			valor = retornatopo (&minhapilha);
			printf ("\n\n\tElemento do topo: %.1f", valor);
			}
			break;
			
			case 4:
				exit (0);
				
			default:
				printf ("\n\n\tOpção inválida!");
		}
		printf ("\n\n\n\n\n");
	}
	system("PAUSE");
}
