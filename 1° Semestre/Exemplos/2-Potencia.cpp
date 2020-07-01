#include <stdio.h>
#include <conio.h>

double potencia (int base, int expoente)
{	if(expoente == 0)
		return (double) 1;
	else
		return (double) (base * potencia(base, expoente-1));
}

int main ()
{	int base, expoente;
	double resultado;

	printf ("Digite a base: ");
	scanf ("%d", &base);

	printf ("Digite o expoente: ");
	scanf ("%d", &expoente);

	resultado = potencia(base,expoente);

	printf("%d elevado a %d = %lf", base, expoente,resultado);
	getch();
}
