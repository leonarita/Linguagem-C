#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>

struct dicionario
{	char palavra[20];
	char definicao[50];
};

bool compararStrings (const char palavra1[], const char palavra2[])
{	int i=0;

	while (palavra1[i]==palavra2[i] && palavra1[i]!='\0' && palavra2[i]!='\0')
		i++;
		
	if (palavra1[i]=='\0' && palavra2[i]=='\0')
		return true;
	else
		return false;
}

int procurarStrings (const struct dicionario lingua[], const char procurar[], const int numDePalavras)
{	bool compararStrings (const char palavra1[], const char palavra2[]);
	int i=0;
	
	while (i<numDePalavras)
	{	if (compararStrings(procurar, lingua[i].palavra))
			return i;
		else
			++i;
	}
	return -1;
}

int main (void)
{	setlocale(LC_ALL, "");
	int procurarStrings (const struct dicionario lingua[], const char procurar[], const int numDePalavras);
	const int NUMERODEDEFINICOES=7;
	char palavra[7]={'\0'};
	int resultadoPesquisa;
	
	const struct dicionario portugues [7] =
	{	{"Pao", "Comida de farinha"},
		{"Mortadela", "Comida de carne"},
		{"Feijao", "Comida brasileira"},
		{"Tropeiro", "Tipo de feijão"},
		{"Queijo", "Comida mineira"},
		{"Macarronada", "Tipico de vó"},
		{"Pizza", "Tipico da Itália"}	};
		
	printf ("Digite uma palavra: ");
	scanf ("%s", palavra);
	
	resultadoPesquisa = procurarStrings (portugues, palavra, NUMERODEDEFINICOES);
	
	if (resultadoPesquisa!=-1)
		printf ("%s \n", portugues[resultadoPesquisa].definicao);
	else
		printf ("Palavra não encontrada.");
}
