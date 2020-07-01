#include<stdio.h>
#include<locale.h>

int A (int m, int n);

int main ()
{	setlocale(LC_ALL, "");
	int resp;
	system ("TITLE Função de Ackermann");

	resp = A(3,2);
	printf ("O valor retornado é: %d", resp);
}

int A (int m, int n)
{	if (m==0)
		return n+1;
	else if (m>0 && n==0)
		return A (m-1, 1);
	else if (m>0 && n>0)
		return A (m-1, A(m, n-1));
}
