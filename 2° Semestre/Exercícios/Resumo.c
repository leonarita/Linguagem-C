#include<stdio.h>
#include<locale.h>
#include<stdbool.h>

//O vetor, quando passado para o parâmetro de uma função, é sujeito a alterações pela função diretamente (sem uso de ponteiro), uma vez que acessam ao endereço de memória
//Caso a função do argumento não tenha colchetes, passará o endereço de memória do vetor inteiro; caso contrário, passará uma posição (que será especificada) do vetor

bool chave = false;

void exibe (int X[], int inicio, int fim)
{	int i;
	printf ("\n\n\nVetor ordenado: ");
	for (i=inicio; i<=fim; i++)
		printf (" %d ", X[i]);
}

void busca (int X[], int inicio, int fim, int x)
{	int i;
	for (i=inicio; i<=fim; i++)
		if (X[i]==x)
		{	printf ("Elemento encontado na posição %d", i+1);
			chave = true;
		}
}

void troca (int X[], int i, int j)
{	int aux;
	aux = X[i];
	X[i] = X[j];
	X[j] = aux;
}

void ordena (int X[], int inicio, int meio, int fim)
{	int aux[fim+1], i, inicio_v1, inicio_v2, poslivre;
	inicio_v1 = inicio;
	inicio_v2 = meio+1;
	poslivre = inicio;
	
	while (inicio_v1<=meio && inicio_v2<=fim)
	{	if (X[inicio_v1]<=X[inicio_v2])
		{	aux[poslivre] = X[inicio_v1];
			inicio_v1++;
		}
		else
		{	aux[poslivre] = X[inicio_v2];
			inicio_v2++;
		}
		poslivre++;
	}
	
	for (i=inicio_v1; i<=meio; i++)
	{	aux[poslivre] = X[i];
		poslivre++;
	}
	
	for (i=inicio_v2; i<=fim; i++)
	{	aux[poslivre] = X[i];
		poslivre++;
	}
	
	for (i=inicio; i<=fim; i++)
		X[i]=aux[i];
}

void merge (int X[], int inicio, int fim)
{	int meio;
	if (inicio<fim)
	{	meio = (inicio+fim)/2;
		merge (X, inicio, meio);
		merge (X, meio+1, fim);
		ordena (X, inicio, meio, fim);
	}
}

void BuscaBin (int X[], int inicio, int fim, int x)
{	int meio;

	if (chave==false)
	{	if (inicio<fim)
		{	meio = (inicio+fim)/2;
			BuscaBin (X, inicio, meio, x);
			BuscaBin (X, meio+1, fim, x);
			if (chave==false)
				busca (X, inicio, meio, x);
			if (chave==false)
				busca (X, meio+1, fim, x);
		}
	}
}

int particao (int X[], int i, int j)
{	int pivo;
	pivo = X[(i+j)/2];
	i = i-1;
	j = j+1;
	
	while (i<j)
	{	do	{	i++;	}	while (X[i]<pivo);
		do	{	j--;	}	while (X[j]>pivo);
		if (i<j)
			troca (X, i, j);
	}
	return j;
}

void quick (int X[], int inicio, int fim)
{	int meio;
	if (inicio<fim)
	{	meio = particao (X, inicio, fim);
		quick (X, inicio, meio);
		quick (X, meio+1, fim);
	}
}

void tela1 (int X[], int inicio, int fim)
{	int op;

	do
	{	printf ("\n\n\nConsidere as ordenações abaixo: \n\t1-Bubble Sort \n\t2-Selection Sort \n\t3-Insertion Sort \n\t4-Merge Sort \n\t5-Quick Sort");
		printf ("\n\nQual ordenção você deseja manusear? ");
		scanf ("%d", &op);
		
		if (op==1)
		{	int i, j;
	
			for (i=0; i<fim; i++)
				for (j=i+1; j<=fim; j++)
					if (X[i]>X[j])
						troca (X, i, j);
			exibe(X, inicio, fim);
		}
		
		else if (op==2)
		{	int i, j, eleito, menor, pos;
	
			for (i=inicio; i<fim; i++)
			{	eleito = X[i];
				menor = X[i+1];
				pos = i+1;
				
				for (j=i+1; j<=fim; j++)
				{	if (menor>X[j])
					{	menor = X[j];
						pos = j;
					}
				}
				if (menor<eleito)
				{	X[i] = X[pos];
					X[pos] = eleito;
				}
			}
			exibe(X, inicio, fim);
		}
		
		else if (op==3)
		{	int i, j, eleito, pos;
	
			for (i=inicio; i<=fim; i++)
			{	eleito = X[i];
				j = i-1;
				
				while (j>=0 && X[j]>eleito)
				{	X[j+1] = X[j];
					j--;
				}
				X[j+1] = eleito;
			}
			exibe(X, inicio, fim);
		}
		
		else if (op==4)
		{	merge (X, inicio, fim);
			exibe(X, inicio, fim);
		}
		
		else if (op==5)
		{	quick (X, inicio, fim);
			exibe(X, inicio, fim);
		}
	
		else
		{	("Comando inválido! Tente novamente");
			sleep(2);
			system ("cls");
		}
	}	while (op>5 || op<1);
}

void tela2 (int X[], int inicio, int fim)
{	int op, elem;

	do
	{	printf ("\n\n\nConsidere as busca abaixo: \n\t1-Busca Sequencial \n\t2-Busca Binária");
		printf ("\n\nQual busca você deseja manusear? ");
		scanf ("%d", &op);
		
		printf ("\n\n\nInforme o elemento a ser procurado: ");
		scanf ("%d", &elem);
		
		printf ("\n\n\n");
		
		if (op==1)
			busca (X, inicio, fim, elem);
		if (op==2)
			BuscaBin (X, inicio, fim, elem);
		else
		{	("Comando inválido! Tente novamente");
			sleep(2);
			system ("cls");
		}
	}	while (op>2 || op<1);
}

int main ()
{	setlocale (LC_ALL, "");

	int v[] = {-8,-5,7,-6,4,10,-4,5,0,-7,2,-10,3,-9,9,8,-1,1,6,-3,-2};	//21 elementos
	int op;
	
	do
	{	printf ("Considere o seguinte vetor: v[] = {-8,-5,7,-6,4,-4,5,0,-7,2,-10,3,-9,9,8,-1,1,6,-3,-2}");
		printf ("\n\nConsidere as seguintes possibilidades abaixo: \n\t1-Ordenação \n\t2-Buscar elemento \n\nQual você deseja utilizar? ");
		scanf ("%d", &op);
		
		if (op==1)
			tela1(v, 0, 20);
		else if (op==2)
			tela2(v, 0, 20);
		else
		{	("Comando inválido! Tente novamente");
			sleep(2);
			system ("cls");
		}
	}	while (op>2 || op<1);
}
