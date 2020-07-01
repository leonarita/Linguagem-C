#include<stdio.h>

int Quadrado (int x)
{
	return x*x;
}

int Dobro (int x)
{
	return 2*x;
}

int Cubo (int x)
{
	return Quadrado(x) * x;
}

void ImprimeEspecial (int (* funcao) (int), int n)
{
	printf ("<<<|%d|>>>\n", (*funcao)(n));
}

int main ()
{
	int (*f) (int);
	
	f = Quadrado;
	ImprimeEspecial(f, 3);
	
	f = Dobro;
	ImprimeEspecial(f, 10);
	
	f = Cubo;
	ImprimeEspecial(f, 5);
}
