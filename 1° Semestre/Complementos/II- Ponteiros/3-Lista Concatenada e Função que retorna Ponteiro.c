#include<stdio.h>
#include<conio.h>
#include<locale.h>

struct lista
{	int valor;
	struct lista *proximo;
}
m1, m2, m3;

struct lista *procurarValor (struct lista *pLista, int valor)
{	
	while (pLista!=(struct lista*)0)
	{	if (pLista->valor==valor)
			return pLista;
		else
			pLista=pLista->proximo;
	}
	return (struct lista*)0;
}

int main ()
{	setlocale (LC_ALL, "");
	struct lista *resultado, *gancho=&m1;
	int valor;

	m1.valor=5;
	m2.valor=10;
	m3.valor=15;
	
	m1.proximo=&m2;
	m2.proximo=&m3;
	m3.proximo=0;		//m3.proximo=(struct lista *)0;
	
	/*	OUTRAS FORMAS DE DECLARAÇÃO DE STRUCTS E INSERÇÃO DE DADOS

	1)	struct lista m1 = {5, &m2};
		struct lista m2 = {10, &m3};
		struct lista m3 = {15, 0};
		
	2)	struct lista m1 = {.valor=5,  .proximo=&m2};
		struct lista m2 = {.valor=10, .proximo=&m3};
		struct lista m3 = {.valor=15, .proximo=0};
	
	3) struct lista m[3] = { {5, &m2}, {10, &m3}, {15, 0} };	//vetor de structs
	*/
	
	printf ("Digite o valor da pesquisa: ");
	scanf ("%i", &valor);
	
	resultado=procurarValor(gancho, valor);
	
	if (resultado==(struct lista*)0)
		printf ("\n\nValor não encontrado...");
	else
		printf ("\n\nValor %i encontrado...", resultado->valor);

	printf ("\n\n\nElementos existentes: ");
	while (gancho!=0)
	{	printf ("%i ", gancho->valor);
		gancho = gancho->proximo;	}

	getchar();
	return 0;
}
