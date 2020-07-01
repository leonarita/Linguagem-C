#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main ()
{	setlocale (LC_ALL, "");
	int num, i;
	int bin[8];
	int aux;

	for (i=0; i<=255; i++)
	{	num = i;

		for (aux=7; aux>=0; aux--)
		{	if (num%2 == 0)
	        	bin[aux] = 0;
	    	else
	        	bin[aux] = 1;
	    	num = num/2;
		}
	
		printf ("\n\t\tNúmero %03d em binário = ", i);
		for (aux=0; aux<8; aux++)
	    	printf ("%d", bin[aux]);
	}
	printf ("\n\n");
}
