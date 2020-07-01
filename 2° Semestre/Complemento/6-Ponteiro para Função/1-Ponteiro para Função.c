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
	ImprimeEspecial(Quadrado, 3);
	ImprimeEspecial(Dobro, 10);
	ImprimeEspecial(Cubo, 5);
}
