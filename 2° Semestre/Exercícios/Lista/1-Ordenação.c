#include<stdio.h>
#include<locale.h>

int BubbleSort (int X[], int n);
int SelectionSort(int X[], int n);
int InsertionSort(int X[], int n);

int i, j, m;

int main ()
{	setlocale(LC_ALL, "");
	int opcao, X[6];
		
	for (i=0; i<=5; i++)
	{	printf ("Digite o %d n�mero: ", i+1);
		scanf ("%d", &X[i]);
	}
	
	do {
		printf ("\n\n\nConsidere as seguintes ordena��es: \n\t 1-Bubble Sort \n\t 2-Selection Sort \n\t 3-Insertion Sort \n\nQual op��o voc� deseja? ");
		scanf ("%d", &opcao);
		printf ("\n\n\n\n\n");
			
		switch (opcao)
		{
			case 1:
				system ("cls");
				BubbleSort(X,5);
				break;
			case 2:
				system ("cls");
				SelectionSort(X,5);
				break;
			case 3:
				system ("cls");
				InsertionSort(X,5);
				break;
			default:
				printf ("Op��o de ordena��o inv�lida.");
				sleep(1);
				system("cls");
				break;
		}
	} while (opcao<1 || opcao>3);
}



int BubbleSort (int X[], int n)
{	setlocale(LC_ALL, "");
	int aux;
	
	printf ("\n\n\t\t\t\t\t\tBUBBLE SORT");

	printf ("\n\nVetor original: ");
	for (i=0; i<=n; i++)
		printf ("\n\t%d� n�mero: %d ", i+1, X[i]);
	printf ("\n\n");
	
	printf ("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n\n");
	
	for (i=0; i<=n-1; i++)
	{	for (j=i+1; j<=n; j++)
		{	if (X[i]>X[j])
			{		printf ("\n\nComo V[%d]=%d � maior do que V[%d]=%d , ent�o eles v�o trocar de posi��o", i+1, X[i], j+1, X[j]);
					printf ("\n\t - O valor de X[%d] � armazenado na vari�vel aux", i+1);
					printf ("\n\t - O valor de X[%d] � armazenado na vari�vel V[%d]", j+1, i+1);
					printf ("\n\t - O valor de aux � armazenado na vari�vel V[%d]", j+1);
					printf ("\n\n\t\t Vetor antes de troca: ");
					for (m=0; m<=n; m++)
						printf ("%d ", X[m]);
					
				aux = X[i];
				X[i] = X[j];
				X[j] = aux;
				
					printf ("\n\t\t Vetor depois de troca: ");
					for (m=0; m<=n; m++)
						printf ("%d ", X[m]);
					printf ("\n\n");
					printf ("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n\n");
			}
		}
	}

	printf ("\n\n\n\nVetor ordenado: ");
	for (i=0; i<=n; i++)
		printf ("\n\t%d� n�mero: %d ", i+1, X[i]);
}



int InsertionSort (int X[], int n)
{	setlocale(LC_ALL, "");
	int eleito;
	
	printf ("\n\n\t\t\t\t\t\tINSERTION SORT");
	
	printf ("\n\nVetor original: ");
	for (i=0; i<=n; i++)
		printf ("\n\t%d� n�mero: %d ", i+1, X[i]);
	printf ("\n\n");
	
	printf ("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n\n");
	
	for (i=1; i<=n; i++)
	{	eleito = X[i];
		j = i-1;
		
			printf ("\n\n\t\t\t\t\t\t%d� PASSO", i);
			
			printf ("\n\n O X[%d]=%d vai ser deslocado anteriormente da posi��o X[%d]=%d", i+1, X[i], j+1, X[j]);
			printf ("\n\n\t\t\t\t Vetor antes: ");
			for (m=0; m<=n; m++)
				printf ("%d ", X[m]);
		
			printf ("\n\n\n - A vari�vel eleito recebe X[i]=X[%d] para ser armazenado: eleito=%d", i+1, eleito);
			printf ("\n - A vari�vel j recebe i-1 para ser par�metro de voltas do ciclo: j=%d \n", j+1);
	
		while (j>=0 && X[j]>eleito)
		{		printf ("\n\t - j=%d : Como X[%d]=%d � maior do que eleito=%d, ent�o X[%d] incrementa uma posi��o, sendo atribuido � posi��o[%d]",j+1, j+1, X[j], eleito, j+1, j+2);
		
			X[j+1]=X[j];
			j=j-1;
		}
			if (j>=-1)
				printf ("\n\t - j=%d : Nada mais � incrementado", j+1);
		
		X[j+1] = eleito;
		
			printf ("\n\t\t - O valor de eleito vai ser atribuido � vari�vel X[j+1]: X[%d]=%d", j+2, eleito);
		
			printf ("\n\n\t\t\t\t Vetor depois: ");
			for (m=0; m<=n; m++)
				printf ("%d ", X[m]);
			printf ("\n\n\n\n\n");
				
			printf ("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n\n");

	}
	
	printf ("\n\n");
	for (i=0; i<=n; i++)
		printf ("%d� n�mero: %d \n", i+1, X[i]);
}



int SelectionSort (int X[], int n)
{	setlocale(LC_ALL, "");
	int eleito, menor, pos;
	
	printf ("\n\n\t\t\t\t\t\tSELECTION SORT");
	
	printf ("\n\nVetor original: ");
	for (i=0; i<=n; i++)
		printf ("\n\t%d� n�mero: %d ", i+1, X[i]);
	printf ("\n\n");
	
	printf ("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n\n");
	
	for (i=0; i<=n-1; i++)
	{	eleito = X[i];
		menor = X[i+1];
		pos = i+1;
		
		printf ("\n\n\t\t\t\t\t\t%d� PASSO", i+1);
		
		printf ("\n\n\t\t\t\t Vetor antes: ");
		for (m=0; m<=n; m++)
			printf ("%d ", X[m]);
			
		printf ("\n\n\n - A vari�vel eleito recebe X[i]=X[%d] e serve como auxiliar para guardar o valor dele para que n�o seja perdido ao trocar valores: eleito=%d", i+1, eleito);
		printf ("\n - A vari�vel menor recebe X[i+1]=X[%d] para ser o par�metro de compara��o: menor=%d", i+2, menor);
		printf ("\n - A vari�vel pos recebe i+1=%d para que esteja em sintonia com a vari�vel menor: pos=%d", i+2, pos);
		
		for (j=i+1; j<=n; j++)
		{		printf ("\n\n - Compara a vari�vel X[%d]=%d com a vari�vel menor=%d a fim de identificar o menor valor do vetor", j+1, X[j], menor);
		
			if (X[j] < menor)
			{	printf ("\n\tComo a vari�vel menor � maior do que a vari�vel X[%d], menor recebe X[%d]:\n\t\t menor (antes) = %d", j+1, j+1, menor);
				
				menor = X[j];
				pos = j;
				
				printf ("\n\t\t menor (depois) = %d", menor);
			}	}

		if (menor < eleito)
		{	X[i] = X[pos];
			X[pos] = eleito;
			
			printf ("\n\n - Como a vari�vel eleito=%d � maior do que a vari�vel menor=%d, eles trocam de posi��o", eleito, menor);
		}
		
		printf ("\n\n\t\t\t\t Vetor depois: ");
		for (m=0; m<=n; m++)
			printf ("%d ", X[m]);
		printf ("\n\n\n\n\n");
		printf ("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n\n");
	}

	printf ("\n\n\n\nVetor ordenado: ");
	for (i=0; i<=n; i++)
		printf ("\n\t%d� n�mero: %d ", i+1, X[i]);
}
