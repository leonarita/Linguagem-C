#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdbool.h>

#define N 4

typedef struct 
{	char Nome[20];
	float Matricula;
	float Cod;
	float Nota[3];
	float Media;
	char Resultado[13];
}
Aluno;

void Exibicao (Aluno Dados[])
{	int i, j;
	for (i=0; i<N; i++)
	{	printf ("\n\n\t%i° Aluno", i+1);
		printf ("\nMatrícula: %.0f", Dados[i].Matricula);
		printf ("\nNome: %s", Dados[i].Nome);
		printf ("\nCódigo da disciplina: %.0f", Dados[i].Cod);
		
		for (j=0; j<=2; j++)
			printf ("\nNota %d: %.2f", j+1, Dados[i].Nota[j]);
			
		printf ("\nMédia: %.2f", Dados[i].Media);
		printf ("\nResultado: %s", Dados[i].Resultado);
	}
}

void Bubble (Aluno *a, Aluno *b)
{	Aluno aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

int particao (Aluno X[], int p, int r)
{	int pivo, i, j;
	pivo = *X[(p+r)/2].Nome;
	i=p-1;
	j=r+1;
	
	while (i<j)
	{
		do {	j = j - 1;	}
		while (*X[j].Nome > pivo);
		
		do	{	i = i + 1;	}
		while (*X[i].Nome < pivo);
		
		if (i<j)
			Bubble (&X[i], &X[j]);
	}
	return j;
}

void quicksort (Aluno X[], int p, int r)
{
	int q;
	
	if (p<r)
	{	q = particao (X, p, r);
		quicksort (X, p, q);
		quicksort (X, q+1, r);
	}
}

void intercala (Aluno X[], int inicio, int fim, int meio)
{	int poslivre, inicio_vetor1, inicio_vetor2, i;
	Aluno aux[N];
	inicio_vetor1 = inicio;
	inicio_vetor2 = meio + 1;
	poslivre = inicio;
	
	while (inicio_vetor1 <= meio && inicio_vetor2 <= fim)
	{
		if ((strcmp(X[inicio_vetor1].Nome, X[inicio_vetor2].Nome))<0)
		{	aux[poslivre] = X[inicio_vetor1];
			inicio_vetor1 = inicio_vetor1 + 1;
		}
		else
		{	aux[poslivre] = X[inicio_vetor2];
			inicio_vetor2 = inicio_vetor2 + 1;
		}
		poslivre = poslivre + 1;
	}
	
	for (i=inicio_vetor1; i<=meio; i++)
	{	aux[poslivre] = X[i];
		poslivre = poslivre + 1;
	}
	
	for (i=inicio_vetor2; i<=fim; i++)
	{	aux[poslivre] = X[i];
		poslivre = poslivre + 1;
	}
	
	for (i=inicio; i<=fim; i++)
		X[i] = aux[i];
}

void merge (Aluno X[], int inicio, int fim)
{	int meio;

	if (inicio<fim)
	{	meio = (inicio+fim)/2;
		merge (X, inicio, meio);
		merge (X, meio+1, fim);
		intercala (X, inicio, fim, meio);
	}
}

void insertion (Aluno X[])
{	Aluno eleito;
	int j, i;
	
	for (i=0; i<=N-1; i++)
	{	eleito = X[i];
		j = i-1;
		
		while (j>=0 && X[j].Nome>eleito.Nome)
		{	X[j+1] = X[j];
			j=j-1;
		}
		X[j+1]=eleito;
	}
}

void selection (Aluno X[])
{	int i, j, pos;
	Aluno eleito, minimo;
	
	for (i=0; i<N-1; i++)
	{	eleito = X[i];
		minimo = X[i+1];
		pos = i+1;
		
		for (j=i+1; j<=N-1; j++)
		{	if (minimo.Nome > X[j].Nome)
			{	minimo = X[j];
				pos = j;
			}
		}
		if (minimo.Nome < eleito.Nome)
		{	X[i] = X[pos];
			X[pos] = eleito;
		}
	}
}

int main ()
{	setlocale (LC_ALL, "");

	Aluno Dados[N];
	int i, j;
	float aprov=0;
	float reprov=0;
	float rec=0;
	
	for (i=0; i<N; i++)
	{
		printf ("\t\t%d Aluno", i+1);
		
		Dados[i].Media=0;
		
		printf ("\nInforme a matrícula: ");
		scanf ("%f", &Dados[i].Matricula);
		fflush (stdin);
		
		printf ("Informe o nome: ");
		gets (Dados[i].Nome);
		fflush (stdin);
		
		printf ("Informe o código da disciplina: ");
		scanf ("%f", &Dados[i].Cod);
		fflush (stdin);
		
		for (j=0; j<=2; j++)
		{	printf ("Informe a %i° nota: ", j+1);
			scanf ("%f", &Dados[i].Nota[j]);
			fflush (stdin);
		}
		
		Dados[i].Media = ( Dados[i].Nota[0] + Dados[i].Nota[1] + Dados[i].Nota[2] ) / 3;
		
		if (Dados[i].Media >= 6)
		{	strcpy (Dados[i].Resultado, "Aprovado");
			aprov++;
		}
		else if (Dados[i].Media >= 4 && Dados[i].Media < 6)
		{	strcpy (Dados[i].Resultado, "Recuperação");
			rec++;
		}
		else
		{	strcpy (Dados[i].Resultado, "Reprovado");
			reprov++;
		}
		
		fflush (stdin);
		
		aprov = aprov / N;
		reprov = reprov / N;
		rec = rec / N;
		
		printf ("\n\n");
	}
	
	int op, opcao;
	do
	{	printf ("\nConsidere as seguintes opções: \n\t1-Alunos cadastrados na ordem de entrada \n\t2-Alunos cadastrados na ordem alfabética \n\t3-Porcentuais");
		printf ("\nQual opção você deseja? ");
		scanf ("%i", &op);
		fflush (stdin);
	}
	while (op<1 || op >3);

	if (op==1)
	{	printf ("\n\n\t\tAlunos cadastrados na ordem de entrada: ");
		Exibicao (Dados);
	}
	
	if (op==2)
	{	printf ("\n\nConsidere as opções abaixo: \n\t1-Bubble Sort \n\t2-Selection Sort \n\t3-Insertion Sort \n\t4-Merge Sort \n\t5-Quick Sort \nQual opção você deseja? ");
		scanf ("%d", &opcao);
		fflush (stdin);

		printf ("\n\n\t\tAlunos cadastrados na ordem de alfabética: ");	

		switch (opcao)
		{
			case 1:
				for (i=0; i<N-1; i++)
				{	for (j=i+1; j<N; j++)
					{	if ((strcmp(Dados[i].Nome, Dados[j].Nome))>0)
							Bubble(&Dados[i], &Dados[j]);
					}
				}
				Exibicao (Dados);
				break;
			
			case 2:
				selection (Dados);
				Exibicao (Dados);
				break;
			
			case 3:
				insertion (Dados);
				Exibicao (Dados);
				break;

			case 4:
				merge (Dados, 0, N-1);
				Exibicao (Dados);
				break;

			case 5:
				quicksort (Dados, 0, N-1);
				Exibicao (Dados);	
				break;

			default:
				printf ("\n\n\t\tComando inválido!");
		}
	}
	
	if (op==3)
		printf ("\n\n\t\tEstatísticas: \n\tAprovados: %.2f \n\tRecuperação: %.2f \n\tReprovados: %.2f", aprov, rec, reprov);
}
