#include<stdio.h>
#include<locale.h>

long int fatorial (int num)
{	if (num==1)
		return (long int) 1;
	else
		return (long int) num * fatorial (num-1);
}

int main ()
{
	setlocale (LC_ALL, "");
	
	int n, p;
	long int P, A, C;
	
	printf ("Digite n: ");
	scanf ("%d", &n);
	
	printf ("Digite p: ");
	scanf ("%d", &p);

	P = (long int) fatorial(n);
	A = (long int) (fatorial(n)) / (fatorial(n-p));
	C = (long int) (fatorial(n)) / (fatorial(p) * fatorial(n-p));
	
	printf ("\n\n Permutação de n: \n\t A ordem importa \n\t\t P%d = %ld", n, P);					//Número de elementos é igual ao número de tracinhos
	printf ("\n\n Arranjo de n, p: \n\t A ordem importa \n\t\t A%d,%d = %ld", n, p, A);			//Número de elementos não é igual ao número de tracinhos
	printf ("\n\n Combinação de n, p: \n\t A ordem não importa \n\t\t C%d,%d = %ld", n, p, C);
}
