#include<stdio.h>
#include<locale.h>
#include<math.h>

int minimo (int i)
{	int nivel = ((int) (log(i)/log(2))) + 1;
	
	if (nivel%2==0)
		return 0;
	else
		return 1;
}

void trocar (int vet[], int x, int y)
{	int temp;
	temp = vet[x];
	vet[x] = vet[y];
	vet[y] = temp;
}

void subir_max (int vet[], int i)
{	int avo = i/4;

	if (avo>=1 && vet[i]>vet[avo])
	{	trocar (vet, i, avo);
		subir_max (vet, avo);
	}
}

void subir_min (int vet[], int i)
{	int avo = i/4;

	if (avo>=1 && vet[i]<vet[avo])
	{	trocar (vet, i, avo);
		subir_min (vet, avo);
	}
}

void subir (int vet[], int i)
{	int pai = i/2;

	if (minimo(i))
	{
		if (pai>=1)
		{
			if (vet[i]>vet[pai])
			{	trocar (vet, i, pai);
				subir_max (vet, pai);
			}
			else
				subir_min (vet, pai);
		}
	}
	else
	{
		if (pai>=1)
		{
			if (vet[i]<vet[pai])
			{	trocar (vet, i, pai);
				subir_min (vet, pai);
			}
			else
				subir_max (vet, i);
		}
	}
}

void inserir_num (int vet[], int num, int i)
{	vet[i] = num;
	subir (vet, i);
}

int maior_prior (int vet[], int tam)
{
	if (tam==1)
		return 1;
	else if (tam>2 && vet[3]>vet[2])
		return 3;
	else
		return 2;
}

int min_descendente (int vet[], int i, int tam)
{	int m=0;

	if (2*i<=tam)
	{
		m = 2*i;
		
		if (vet[m+1]<vet[m])
			m++;
			int k;
		
			for (k=4*i; (k<=4*i+3) && k<=tam; k++)
				if (vet[k]<vet[m])
					m = k;
	}
	return m;
}

void descer_min (int vet[], int i, int tam)
{
	if (2*i<=tam)
	{	int m = min_descendente (vet, i, tam);
	
		if (vet[i]>vet[m])
		{	trocar (vet, i, m);
		
			if (m >= 4*i)
			{	int p=m/2;
				
				if (vet[p]<vet[m])
					trocar (vet, p, m);
					
				descer_min (vet, m, tam);
			}
		}
	}
}

int max_descendente (int vet[], int i, int tam)
{	int m=0;

	if (2*i<=tam)
	{	m=2*i;
	
		if (vet[m+1]>vet[m])
			m++;
		
		int k;
		for (k=4*i; (k<=4*i+3) && k<=tam; k++)
			if (vet[k]>vet[m])
				m = k;
	}
	return m;
}

void descer_max (int vet[], int i, int tam)
{
	if (2*i<=tam)
	{	int m = max_descendente (vet, i, tam);
	
		if (vet[i]<vet[m])
		{	trocar (vet, i, m);
		
			if (m >= 4*i)
			{	int p=m/2;
				
				if (vet[p]>vet[m])
					trocar (vet, p, m);
					
				descer_max (vet, m, tam);
			}
		}
	}
}

void descer (int vet[], int i, int tam)
{
	if (minimo(i))
		descer_min (vet, i, tam);
	else
		descer_max (vet, i, tam);
}

void impressao (int vet[], int tam)
{
	if (tam==0)
		printf ("\n\n\tLista de prioridades vazia!");
	else
	{	printf ("\n\n\tTodos os elementos da lista de prioridades: ");
		int j;
		
		for (j=1; j<=tam; j++)
			printf ("%d ", vet[j]);
	}
}

void main ()
{	int vet[11], tam, op, mp, num;
	setlocale (LC_ALL, "");
	
	tam=0;

	do
	{	printf ("\n\n\t\tMENU DE OPÇÕES - HEAP MÁXIMO E MÍNIMO \n");
		printf ("\n\t1-Inserir o elemento na lista de prioridades");
		printf ("\n\t2-Consultar o elemento de menor prioridade");
		printf ("\n\t3-Consultar o elemento de maior prioridade");
		printf ("\n\t4-Remover o elemento de menor prioridade");
		printf ("\n\t5-Remover o elemento de maior prioridade");
		printf ("\n\t6-Consultar toda a lista");
		printf ("\n\t7-Sair");
		printf ("\n\nDigite sua opção: ");
		scanf ("%d", &op);
		
		if (op>7 || op<1)
			printf ("\n\n\tOpção inválida!!");
		
		if (op==1)
		{	if (tam<=9)
			{	printf ("\n\n\tDigite um número: ");
				scanf ("%d", &num);
				tam++;
				inserir_num (vet, num, tam);
				printf ("\n\n\t\tNúmero inserido!");
			}
			else
				printf ("\n\n\tLista de prioridades lotada!");
		}
		
		if (op==2)
		{	if (tam==0)
				printf ("\n\n\tLista de prioridades vazia!");
			else
				printf ("\n\n\tElemento de menor prioridade: %d", vet[1]);
		}
		
		if (op==3)
		{	if (tam==0)
				printf ("\n\n\tLista de prioridades vazia!");
			else
			{	mp = maior_prior (vet, tam);
				printf ("\n\n\tElemento de maior prioridade: %d", vet[mp]);
			}
		}
		
		if (op==4)
		{	if (tam==0)
				printf ("\n\n\tLista de prioridades vazia!");
			else
			{	printf ("\n\n\tO elemento removido: %d", vet[1]);
				vet[1] = vet[tam];
				tam--;
				descer (vet, 1, tam);
			}
		}
		
		if (op==5)
		{	if (tam==0)
				printf ("\n\n\tLista de prioridades vazia!");
			else if (tam==2)
				tam=1;
			else
			{	int max=2;
			
				if (tam>=3)
				{
					if (vet[3]>vet[2])
						max=3;
				}
				
				printf ("\n\n\tO elemento removido: %d", vet[max]);
				vet[max] = vet[tam];
				tam--;
				descer (vet, max, tam);
			}
		}
		
		if (op==6)
			impressao (vet, tam);
		
		if (op==7)
		{	printf ("\n\n\tAté a próxima!!");
		}
		
		getch();
		system ("CLS");
		
	}
	while (op!=7);
}
