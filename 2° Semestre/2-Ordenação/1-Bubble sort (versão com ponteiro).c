#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b);
void bubbleSort(int *v, int n);

int main()
{	int tam,i,*v;
	
	printf("Tamanho do vetor: ");
	scanf("%d", &tam);
	
	v = (int*) malloc(tam*sizeof(int));
	
	for (i=0; i<tam; i++)
	{	printf("Valor %i: ",i+1);
		scanf("%d", &v[i]);
	}
	
	bubbleSort (v, tam-1);

//	system ("CLS");
	printf("Valores Ordenados:\n\n");
	for (i=0; i<tam; i++)
		printf("v[%d] = %3.d \n",i,v[i]);
	return 0; 
} 

void swap(int *a, int *b)
{	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int *v, int n)
{	int i;

	if (n < 1)
		return;
	
	for (i=0; i<n; i++)
		if (v[i] > v[i+1])
			swap(&v[i], &v[i+1]);
	bubbleSort(v, n-1);
} 
