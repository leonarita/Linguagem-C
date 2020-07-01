#include <stdio.h>
#include<locale.h>

void teste (void);
int VariavelGlobal=2;

int main ()
{	setlocale (LC_ALL, "");
	printf ("Testando a diferença entre variáveis automática e estática e global");
	printf ("\n");
	teste();
	teste();
	teste();
}

void teste (void)	//Testar diferença entre variáveis automática e estática
{
	int VariavelLocalAutomatica=2;
	VariavelLocalAutomatica*=2;
	printf ("\n\tVariável Local Automática = %d", VariavelLocalAutomatica);	//Cada vez cria uma variável diferente
	
	static int VariavelLocalEstatica=2;
	VariavelLocalEstatica*=2;
	printf ("\n\t\tVariável Local Estática = %d", VariavelLocalEstatica);	//Cada vez que é chamada, é modificada
	
	VariavelGlobal*=2;
	printf ("\n\t\t\tVariável Global = %d", VariavelGlobal);	//A variável global se comporta como uma variável estática
	
	printf ("\n");
}
