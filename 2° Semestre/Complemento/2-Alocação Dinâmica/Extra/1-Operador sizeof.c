#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main ()
{	setlocale (LC_ALL, "");

	int x;		//Cada int ocupa 4 bytes de memória
	double y;	//Cada double ocupe 8 bytes de memória

	printf ("Bytes de int x: %li\n", sizeof(x));
	printf ("Bytes de double y: %li\n", sizeof(y));
	//Exibe a quantidade de memória, em bits, utilizados para armazenar a variável

	printf ("\n\n");
	printf ("Bytes de short: %li\n", sizeof(short));
	printf ("Bytes de double: %li\n", sizeof(double));
	
	int vetor[10];

	printf ("\n\n");
	printf ("Bytes do vetor de 10 posições: %li\n", sizeof(vetor));		//4 bytes (int) * 10 (espaço do vetor) = 40
	printf ("Bytes do vetor de 10 posições: %li\n", vetor);				//Mostra o endereço de memória do vetor

	struct x
	{	int a;
		int b;
		int c;
	};
	struct x estrutura1;

	printf ("\n\n");
	printf ("Bytes da estrutura: %li\n", sizeof(estrutura1));
	//4 (bytes por int) * 3 (ints) = 12
	
	struct y
	{	int a;
		double b;
		int c;
	};
	struct y estrutura2;

	printf ("\n\n");
	printf ("Bytes da estrutura: %i\n", sizeof(estrutura2));
	//4 (bytes por int) * 2 (ints) + 8 (bytes por double) = 16
	//Mas mostra 24 (?)

	return 0;
}
