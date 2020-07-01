#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

int main ()
{	setlocale (LC_ALL, "");
	int num, i, j=0, k=1;
	int bin[8];
	int aux;
	char a;

	for (i=0; i<=2000; i++)
	{	num = i;

		for (aux=7; aux>=0; aux--)
		{	bin[aux] = num%8;
	    	num = num/8;
		}
	
		printf ("\n\t\tNúmero %03d em octal = ", i);
		if (i == 0)
			printf ("       0");
		else
		{	for (aux=0; aux<8; aux++)
		    {	if (bin[aux]==0 && a=='a')
		    		printf (" ");
		    	else
				{	printf ("%d", bin[aux]);
					a = 'b';
				}
			}
		}
		
		a = 'a';
	}
	printf ("\n\n");
}
