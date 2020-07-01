#include<stdio.h>
#include<locale.h>

int Recur (int a);

int main ()
{	setlocale(LC_ALL, "");
	int num;

	system ("TITLE Cálculo da soma dos n primeiros números elevados ao quadrado.");

	printf ("Informe o número de termos: ");
	scanf ("%d", &num);
	printf ("O resultado é %d", Recur(num));
}

int Recur (int a)
{	int b;
	if (a==0)
		return 0;
	else if (a>0)
		b = (a*a) + Recur (a-1);
	else if (a<0)
		b = (a*a) + Recur (a+1);
}
