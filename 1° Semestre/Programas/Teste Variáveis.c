#include<stdio.h>
#include<locale.h>
#include<time.h>

#define SOMA(a, b) (a + b)

int soma(int a, int b)
{	return(a + b);	}

int main ()
{	setlocale (LC_ALL, "");

	int op, i=1, j=1, v[10];
	
	for ( i=1, j=1; i<=10, j<=10; i++, j++)
		printf ("\ni + j = %d + %d = %d", i, j, (i+j));
		
	printf ("\n\nEndereço de memória do vetor v[] : %d = %d", v, &v);		//sizeof(vetor) = 40 bytes
	
	printf ("\n\nEndereço de memóra da função soma: %d\n\n\n\n", soma);		//sizeof(soma) = 1 byte

	j=1;
	for (i=1; i<=10; i++)
	{	printf ("\n\ti + j = %02d + %02d = %02d", i, j, (i+j));
		if (i==10 && j==10)
			break;
		if (i==10)
		{	i=0;
			j++;
			printf("\n");
		}
	}
}
