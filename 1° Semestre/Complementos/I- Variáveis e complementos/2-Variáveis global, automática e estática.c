#include <stdio.h>
#include<locale.h>

void teste (void);
int VariavelGlobal=2;

int main ()
{	setlocale (LC_ALL, "");
	printf ("Testando a diferen�a entre vari�veis autom�tica e est�tica e global");
	printf ("\n");
	teste();
	teste();
	teste();
}

void teste (void)	//Testar diferen�a entre vari�veis autom�tica e est�tica
{
	int VariavelLocalAutomatica=2;
	VariavelLocalAutomatica*=2;
	printf ("\n\tVari�vel Local Autom�tica = %d", VariavelLocalAutomatica);	//Cada vez cria uma vari�vel diferente
	
	static int VariavelLocalEstatica=2;
	VariavelLocalEstatica*=2;
	printf ("\n\t\tVari�vel Local Est�tica = %d", VariavelLocalEstatica);	//Cada vez que � chamada, � modificada
	
	VariavelGlobal*=2;
	printf ("\n\t\t\tVari�vel Global = %d", VariavelGlobal);	//A vari�vel global se comporta como uma vari�vel est�tica
	
	printf ("\n");
}
