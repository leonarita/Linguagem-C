#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct Pilha
{	int topo;		//Elementos preenchidos
	int capa;		//Capacidade total
	int *pElem;		//Os elementos inseridos
};

void exibir (struct Pilha *p)
{	int a = 0;

	while (a-1!=p->topo)
	{	printf ("%d   ", p->pElem[a]);
		a++;
	}
}

void E1 (struct Pilha *p)
{	struct Pilha aux;
	aux.topo = p->topo;
	int a = aux.topo;
	aux.pElem = (int *) malloc (p->topo * sizeof(int));
	int i;
	
	for (i=0; i<=p->topo; i++)
	{	aux.pElem[a] = p->pElem[i];
		a--;
	}
	
	for (i=0; i<=p->topo; i++)
	{	p->pElem[i] = aux.pElem[i];
	}
	
	free (aux.pElem);
}

void E2 (struct Pilha *p)
{	struct Pilha aux;
	aux.pElem = (int *) malloc (2 * sizeof(int));

	aux.pElem[0] = p->pElem[p->topo];
	aux.pElem[1] = p->pElem[0];
	p->pElem[0] = aux.pElem[0];
	p->pElem[p->topo] = aux.pElem[1];
	
	free (aux.pElem);
}

void E3 (struct Pilha *p)
{	struct Pilha par, impar;
	par.pElem = (int *) malloc (p->topo * sizeof(int));
	impar.pElem = (int *) malloc (p->topo * sizeof(int));
	int a=0, b=0, i;

	for (i=0; i<=p->topo; i++)
	{	if (p->pElem[i]%2 == 0)
		{	par.pElem[a] = p->pElem[i];
			a++;
		}
		else if (p->pElem[i]%2 != 0)
		{	impar.pElem[b] = p->pElem[i];
			b++;
		}
	}
	
	if (a>0)
		for (i=0; i<=a; i++)
		{	p->pElem[i] = par.pElem[i];	}
	
	if (b>0)
		for (i=0; i<=b; i++)
		{	p->pElem[i+a] = impar.pElem[i];	}
		
	free (par.pElem);
	free (impar.pElem);
}

void criarpilha (struct Pilha *p, int c)
{	p->topo = -1;
	p->capa = c;
	p->pElem = (int *) malloc (c * sizeof(int));
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

int desempilhar (struct Pilha *p)
{	int aux = p->pElem[p->topo];
	p->topo--;
	return aux;
}

int retornatopo (struct Pilha *p)
{	return p->pElem[p->topo];
}

int main()
{	setlocale (LC_ALL, "");
	
	struct Pilha minhapilha;
	int capacidade, op, ex;
	int valor;
	
	printf ("\n\t\tMenu de Exercícios\n");
	printf ("\n\tExercício 1- Inverter a ordem dos elementos");
	printf ("\n\tExercício 2- Inverter elementos do topo e da base");
	printf ("\n\tExercício 3- Elementos pares na base e elementos ímpares no topo");
	printf ("\n\nInforme o exercício desejado: ");
	scanf ("%d", &ex);

	printf ("\n\n\tInsira a capacidade da pilha: ");
	scanf ("%d", &capacidade);
	criarpilha (&minhapilha, capacidade);
	
	system ("cls");

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
					scanf ("%d", &valor);
					empilhar (&minhapilha, valor);
					printf ("\n\nPilha normal: ");
					exibir (&minhapilha);
					
					if (ex==1)
					{	E1 (&minhapilha);	}
					if (ex==2)
					{	E2 (&minhapilha);	}
					if (ex==3)
					{	E3 (&minhapilha);	}
					
				}
				break;
			
			case 2: //pop
				if (estavazia(&minhapilha) == 1)
					printf ("\n\n\tA pilha está vazia!");
				else
				{	valor = desempilhar (&minhapilha);
					printf ("\n\n\tElemento %d desempilhado!", valor);
				}
				printf ("\n\n\n");
				break;
			
			case 3: // mostrar o topo
				if (estavazia (&minhapilha) == 1)
					printf ("\n\n\tA pilha está vazia!");
				else 
				{
					valor = retornatopo (&minhapilha);
					printf ("\n\n\tElemento do topo: %d", valor);
				}
				printf ("\n\n\n");
				break;
			
			case 4:
				exit (0);
				free (minhapilha.pElem);
				break;
				
			default:
				printf ("\n\n\tOpção inválida!");
		}
		if (minhapilha.topo>0)
		{	printf ("\nPilha alterada: ");
			exibir (&minhapilha);
		}
		printf ("\n\n\nPressione enter para continuar...");
		getch();
		system ("cls");
	}
	system("PAUSE");
}
