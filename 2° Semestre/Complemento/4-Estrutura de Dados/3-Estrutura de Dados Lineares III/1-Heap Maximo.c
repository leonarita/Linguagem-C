#include<stdio.h>
#include<locale.h>

int Pai (int x)
{	return x/2;	}

void heap_fica (int vet[], int i, int qtde)
{	int f_esq, f_dir, maior, aux;
	maior = i;
	
	if (2*i+1 <= qtde)
	{	f_esq = 2*i+1;
		f_dir = 2*i;
		
		if (vet[f_esq]>=vet[f_dir] && vet[f_esq]>vet[i])
			maior = 2*i+1;
		else if (vet[f_dir]>vet[f_esq] && vet[f_dir]>vet[i])
			maior = 2*i;
	}
	else if (2*i <= qtde)
	{	f_dir = 2*i;
		if (vet[f_dir]>vet[i])
			maior = 2*i;
	}
	if (maior!=1)
	{	aux = vet[i];
		vet[i] = vet[maior];
		vet[maior] = aux;
		heap_fica (vet, maior, qtde);
	}
}

int main ()
{	setlocale (LC_ALL, "");
	int vet[11];
	int op=0, tam=0, ind, num;
	
	do
	{	printf ("\n\n\t\tMENU DE OPÇÕES - HEAP MÁXIMO \n");
		printf ("\n\t1-Inserir o elemento na lista de prioridades");
		printf ("\n\t2-Consultar o elemento de maior prioridade");
		printf ("\n\t3-Remover o elemento de maior prioridade");
		printf ("\n\t4-Consultar toda a lista");
		printf ("\n\t5-Sair");
		printf ("\n\nDigite sua opção: ");
		scanf ("%d", &op);
		
		if (op>5 || op<1)
			printf ("\n\n\tOpção inválida!!");
		
		if (op==1)
		{	if (tam<10)
			{	tam++;
				printf ("\n\n\tDigite um número: ");
				scanf ("%d", &num);
				ind = tam;
				
				while (ind>1 && vet[Pai(ind)]<num)
				{	vet[ind] = vet[Pai(ind)];
					ind = Pai(ind);
				}
				
				vet[ind] = num;
				printf ("\n\n\t\tNúmero inserido!");
			}
			else
				printf ("\n\n\tLista de prioridades lotada!");
		}
		
		if (op==2)
		{	if (tam==0)
				printf ("\n\n\tLista de prioridades vazia!");
			else
				printf ("\n\n\tElemento de maior prioridade: %d", vet[1]);
		}
		
		if (op==3)
		{	if (tam==0)
				printf ("\n\n\tLista de prioridades vazia!");
			else
			{	int maior_prior = vet[1];
				vet[1] = vet[tam];
				tam--;
				heap_fica (vet, 1, tam);
				printf ("\n\n\tO elemento removido: %d", maior_prior);
			}
		}
		
		if (op==4)
		{	if (tam==0)
				printf ("\n\n\tLista de prioridades vazia!");
			else
			{	printf ("\n\n\tTodos os elementos da lista de prioridades: ");
				int j;
				for (j=1; j<=tam; j++)
					printf ("%d ", vet[j]);
			}
		}
		
		if (op==5)
		{	printf ("\n\n\tAté a próxima!!");
		}
				
		getch();
		system ("CLS");
	}
	while (op!=5);
}
