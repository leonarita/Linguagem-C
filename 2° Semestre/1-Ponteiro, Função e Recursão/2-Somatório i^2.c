#include<stdio.h>
#include<locale.h>

int Recur (int a);

int main ()
{	setlocale(LC_ALL, "");
	int num;

	system ("TITLE C�lculo da soma dos n primeiros n�meros elevados ao quadrado.");

	printf ("Informe o n�mero de termos: ");
	scanf ("%d", &num);
	printf ("O resultado � %d", Recur(num));
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
