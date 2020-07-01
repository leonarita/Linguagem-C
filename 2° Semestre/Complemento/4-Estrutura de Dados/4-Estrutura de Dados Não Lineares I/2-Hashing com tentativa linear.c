#include<stdio.h>
#include<locale.h>

const int tam=8;

typedef struct Hash
{	int chave;
	char livre;		// L = Livre,	O = Ocupado,	R = Removido 
}
hash;

int funcao_hashing (int num)
{	return num%tam;	}

void mostrar_hash (hash tabela[])
{	int i;
	for (i=0; i<tam; i++)
	{	if (tabela[i].livre=='O')
			printf ("\nEntrada %d: %d", i, tabela[i].chave);
	}
}

void inserir (hash tabela[], int n)
{	int k=1;
	int pos = funcao_hashing (n);

	while (k<=tam && tabela[pos].livre!='L' && tabela[pos].livre!='R')
	{	pos = (pos+k)%tam;
		k++;
	}
	
	if (k<=tam)
	{	tabela[pos].chave = n;
		tabela[pos].livre = 'O';
	}
	else
		printf ("\n\n\tTabela cheia!");
}

int buscar (hash tabela[], int n)
{	int k=1;
	int pos = funcao_hashing (n);
	
	while (k<=tam && tabela[pos].livre!='L' && tabela[pos].chave!=n)
	{	pos = (pos+k)%tam;
		k++;
	}
	
	if (tabela[pos].chave==n && tabela[pos].livre!='R')
		return pos;
	else
		return tam;
}

void remover (hash tabela[], int n)
{	int posicao = buscar (tabela, n);

	if (posicao<tam)
		tabela[posicao].livre = 'R';
	else
		printf ("\n\n\tElemento não está presente!");
}

void main ()
{	setlocale (LC_ALL, "");
	hash tabela[tam];
	int op, num, i;
	
	for (i=0; i<tam; i++)
		tabela[i].livre = 'L';
		
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
					inserir (tabela, num);
					break;
				
				case 2:
					mostrar_hash(tabela);
					break;
				
				case 3:
					printf ("\n\n\tDigite um número: ");
					scanf ("%d", &num);
					remover (tabela, num);
					break;
				
				case 4:
					printf ("\n\n\tAté mais!");
			}
		}
		getch();
		system ("CLS");
	}
	while (op!=4);
}
