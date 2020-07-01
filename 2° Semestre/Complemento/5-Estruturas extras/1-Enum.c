#include<stdio.h>
#include<locale.h>

enum dias	{	segunda=2, terca, quarta, quinta, sexta, sabado, domingo=1	};
//enum dias	{	segunda=2, terca=3, quarta=4, quinta=5, sexta=6, sabado=7, domingo=1	};

void main ()
{	setlocale (LC_ALL, "");

	int a, b;

	a = segunda;
	b = terca;
	
	a++;
	
	if (a==terca)
		printf ("Estamos na terça-feira!", a);
		
	a+=7;
	
	if (a==terca)
		printf ("Estamos na terça-feira!", a);
}
