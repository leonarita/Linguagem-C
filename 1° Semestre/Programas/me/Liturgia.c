#include<stdio.h>
#include<locale.h>

void Credencia()
{	printf ("\t OFERT�RIO \n");
	printf ("Pegar o c�lice. \n");
	printf ("Pegar as �mbulas. \n");
	printf ("Pegar as galhetas. \n");
	printf ("Pegar o lavabo e o magist�gio. \n\n");
	printf ("\t CONSAGRA��O \n");
	printf ("Tocar o sino (duas vezes de 3 toques).");
}

int main ()
{	setlocale (LC_ALL, "");
	Credencia();
}
