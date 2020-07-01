#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Ler 12 elementos em uma matriz A tipo vetor. Após sua leitura, colocar os seus elementos em ordem crescente. 
// Depois ler uma matriz B também com 12 elementos. Colocar os elementos de B em ordem crescente. Criar uma matriz C, 
// onde cada elemento de C é a soma do elemento correspondente de A com B. Colocar em ordem crescente a matriz C e apresentar os seus valores.

//Recebe como parâmetro um vetor (não precisa de colchetes)
int ordena (int *v);
//Quando chamar a função, o argumento (vetor) não precisa de &

int main ()
{
	setlocale (LC_ALL, "portuguese");

	int A [12];
	int B [12];
	int C [12];
	int I, J, AUX; 
	
	for (I=0; I<=11; ++I)
	{	printf("\t Informe o %d° valor: ", I+1);
		scanf("%d", &A[I]);	
	}
	
	ordena (A);

	for (I=0; I<=11; ++I)
	{	printf("\t \t \t Informe o %d° valor: ", I+1);
		scanf("%d", &B[I]);	
	}
	
	ordena (B);
	
	for (I=0; I<=11; ++I)
		C[I]=A[I]+B[I];

	ordena (C);
}

int ordena (int *v)
{	int AUX, I, J;

	for (I=0; I < 11; I++)
		for (J=I+1; J <= 11; J++)
		{	if (v[I] > v[J])
			{	AUX = v[I];
				v[I] = v[J];
				v[J] = AUX;		
			}
		}
	
	for (I=0; I<=11; ++I)
		printf ("\t \t \t \t \t \t   O %d° valor equivale a: %.2d \n", I+1, v[I]);
	
//	return C;
	
}
