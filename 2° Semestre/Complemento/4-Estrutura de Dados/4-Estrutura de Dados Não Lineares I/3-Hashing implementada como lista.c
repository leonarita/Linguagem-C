#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

const int tam=8;

typedef struct Hash
{	int chave;
	struct Hash *prox;
}
hash;

void inserir (hash *tabela[], int pos, int n)
{	hash *novo = (hash *) malloc (sizeof(hash));
	novo->chave = n;
	novo->prox = tabela[pos];
	tabela[pos] = novo;
}

int funcao_hashing (int num)
{	return num%tam;	}

void mostrar_hash (hash *tabela[])
{	hash *aux;
	int i;
	for (i=0; i<tam; i++)
	{	aux = tabela[i];
		
		while (aux!=NULL)
		{	printf ("\nEntrada %d: %d", i, aux->chave);
			aux = aux->prox;
		}
	}
}

void excluir_hash (hash *tabela[], int num)
{	int pos = funcao_hashing (num);
	hash *aux;
	
	if (tabela[pos]!=NULL)
	{	if (tabela[pos]->chave==num)
		{	aux = tabela[pos];
			tabela[pos] = tabela[pos]->prox;
			free (aux);
		}
		else
		{	aux = tabela[pos]->prox;
			hash *ant = tabela[pos];
			
			while (aux!=NULL && aux->chave!=num)
			{	ant = aux;
				aux = aux->prox;
			}
			
			if (aux!=NULL)
			{	ant->prox = aux->prox;
				free (aux);
			}
			else
				printf ("\n\n\tNúmero não encontrado!");
		}
	}
	else
		printf ("\n\n\tNúmero não encontrado!");
}

void main ()
{	setlocale (LC_ALL, "");

	hash *tabela[tam], *aux;
	int op, pos, num, i;
	
	for (i=0; i<tam; i++)
		tabela[i] = NULL;
		
	do
	{	printf ("\n\n\t\tMENU DE OPÇÕES\n");
		printf ("\n\t1-Inserir elemento");
		printf ("\n\t2-Mostrar tabela hashing");
		printf ("\n\t3-Excluir elemento");
		printf ("\n\t4-Sair");
		printf ("\n\nDigite sua opção: ");
		scanf ("%d", &op);
		
		if (op<1 || op>4)
			printf ("\n\n\tComando inválido!");
		else
		{	switch (op)
			{
				case 1:
					printf ("\n\n\tDigite um número: ");
					scanf ("%d", &num);
					pos = funcao_hashing(num);
					inserir (tabela, pos, num);
					break;
				
				case 2:
					mostrar_hash(tabela);
					break;
				
				case 3:
					printf ("\n\n\tDigite um número: ");
					scanf ("%d", &num);
					excluir_hash (tabela, num);
					break;
				
				case 4:
					printf ("\n\n\tAté mais!");
			}
		}
		getch();
		system ("CLS");
	}
	while (op!=4);
	
	for (i=0; i<tam; i++)
	{
		while (tabela[i]!=NULL)
		{	aux = tabela[i];
			tabela[i] = tabela[i]->prox;
			free (aux);
		}
		tabela[i] = NULL;
	}
}
