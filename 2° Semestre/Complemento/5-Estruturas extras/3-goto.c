#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

void main ()
{	setlocale (LC_ALL, "");

	int n, i;
	
	printf ("\n\n\t\tInsira um número inteiro: ");
	scanf ("%d", &n);
	
	for (i=1; i<=10; i++)
	{	if (n==i)
			goto salta1;
		else if (n*i==50)
			goto salta2;
	}
	
	puts ("\n\t\tNenhuma condição se verficou!");
	goto end;

salta1:
	puts ("\n\t\tn: Valor entre 1 e 10");
	goto end;

salta2:
	puts ("\n\t\tn*i: Produto múltiplo de 50");
	goto end;

end:
	exit(0);
}
