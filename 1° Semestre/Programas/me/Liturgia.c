#include<stdio.h>
#include<locale.h>

void Credencia()
{	printf ("\t OFERTÓRIO \n");
	printf ("Pegar o cálice. \n");
	printf ("Pegar as âmbulas. \n");
	printf ("Pegar as galhetas. \n");
	printf ("Pegar o lavabo e o magistégio. \n\n");
	printf ("\t CONSAGRAÇÃO \n");
	printf ("Tocar o sino (duas vezes de 3 toques).");
}

int main ()
{	setlocale (LC_ALL, "");
	Credencia();
}
