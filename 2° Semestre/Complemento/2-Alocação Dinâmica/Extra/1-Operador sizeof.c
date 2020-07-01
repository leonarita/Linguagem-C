#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main ()
{	setlocale (LC_ALL, "");

	int x;		//Cada int ocupa 4 bytes de mem�ria
	double y;	//Cada double ocupe 8 bytes de mem�ria

	printf ("Bytes de int x: %li\n", sizeof(x));
	printf ("Bytes de double y: %li\n", sizeof(y));
	//Exibe a quantidade de mem�ria, em bits, utilizados para armazenar a vari�vel

	printf ("\n\n");
	printf ("Bytes de short: %li\n", sizeof(short));
	printf ("Bytes de double: %li\n", sizeof(double));
	
	int vetor[10];

	printf ("\n\n");
	printf ("Bytes do vetor de 10 posi��es: %li\n", sizeof(vetor));		//4 bytes (int) * 10 (espa�o do vetor) = 40
	printf ("Bytes do vetor de 10 posi��es: %li\n", vetor);				//Mostra o endere�o de mem�ria do vetor

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
