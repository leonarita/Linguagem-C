#include <stdio.h>
#include <stdlib.h>

struct Pilha
{	int topo; 		/* posição do elemento topo */
	int capa;		//Elementos da pilha
	float *pElem;
};

void exibe (struct Pilha *p, float v[])
{	int i=p->topo;

	printf ("Pilha (de %d elementos): ", p->topo+1);
	do
	{	printf ("%.2f ", p->pElem[i]);
		i--;	}
	while (i!=-1);
	
	i=p->topo;
	
	printf ("\nVetor (de %d elementos): ", p->topo+1);
	do
	{	printf ("%.2f ", v[i]);
		i--;	}
	while (i!=-1);
}

void criarpilha( struct Pilha *p, int c )
{  p->topo = -1;
   p->capa = c;
   p->pElem = (float*) malloc (c * sizeof(float));
}

int estavazia ( struct Pilha *p )
{   if( p-> topo == -1 )
      return 1;   // true
    else
      return 0;   // false
}

int estacheia ( struct Pilha *p )
{	if (p->topo == p-> capa - 1)
    	return 1;
	else
		return 0;
}

void empilhar ( struct Pilha *p, float v)
{	p->topo++;
	p->pElem [p->topo] = v;
}

float desempilhar ( struct Pilha *p )
{   float aux = p->pElem [p->topo];
   p->topo--;
   return aux;
}

float retornatopo ( struct Pilha *p )
{   return p->pElem [p->topo];
}

void colocarVetor (struct Pilha *p, float v[])
{	v[p->topo] = p->pElem[p->topo];
}

int main()
{
	struct Pilha minhapilha;
	int capacidade, op, i;
	float valor;
	
	printf( "\nCapacidade da pilha? " );
	scanf( "%d", &capacidade );
	criarpilha (&minhapilha, capacidade);
	
	float aux[capacidade];
		
	while( 1 )
	{ /* loop infinito */
		printf("\nOPERACOES DA PILHA:\n--------------------\n");
        printf("1- empilhar (push)\n");
		printf("2- desempilhar (POP)\n");
		printf("3- Mostrar o topo \n");
		printf("4- Mostrar a pilha e o vetor \n");
		printf("0- sair\n");
		printf("\nopcao? ");
		scanf("%d", &op);
		
		switch (op){
			case 1: //push
				if( estacheia( &minhapilha ) == 1 )
					printf("\nPILHA CHEIA! \n");
				else
				{	printf("\nVALOR? ");
					scanf("%f", &valor);
					empilhar (&minhapilha, valor);
					colocarVetor (&minhapilha, aux);
				}
				break;

			case 2: //pop
				if ( estavazia(&minhapilha) == 1 )
					printf( "\nPILHA VAZIA! \n" );
				else
				{	valor = desempilhar (&minhapilha);
					printf ( "\n%.1f DESEMPILHADO!\n", valor );
				}
				break;

			case 3: // mostrar o topo
				if ( estavazia (&minhapilha) == 1 )
					printf( "\nPILHA VAZIA!\n" );
				else
				{	valor = retornatopo (&minhapilha);
					printf ( "\nTOPO: %.1f\n", valor );
				}
				break;
				
			case 4:
				exibe (&minhapilha, aux);
				break;
				
			case 0: 
				exit(0);
				break;
				
			default: printf( "\nOPCAO INVALIDA! \n" );
		}
	}
system("PAUSE");
}

