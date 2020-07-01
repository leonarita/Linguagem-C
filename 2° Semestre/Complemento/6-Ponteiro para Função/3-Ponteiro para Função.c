#include<stdio.h>
#include<assert.h>

int Quadrado (int x)
{
	return x*x;
}

int Dobro (int x)
{
	return 2*x;
}

int Abs (int x)
{
	return x<0? -x : x;
}

void ImprimeEspecial (int (* funcao) (int), int n)
{
	assert(funcao != NULL);
	printf ("<<<|%d|>>>\n", (*funcao)(n));
}

int main ()
{
	int (*f) (int);
	int valor;
	
	f = NULL;
	
	printf ("Introduza um valor inteiro: ");
	scanf ("%d", &valor);
	
	if (valor < 0)
		f = Abs;
	else
		if (valor <= 100)
			f = Quadrado;
		else
			f = Dobro;
	
	ImprimeEspecial(f, valor);
}
