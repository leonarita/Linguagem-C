//Tópicos 5 e 6 com erros ao compilar

//null terminator -> \0

#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdbool.h>

//string é o conjunto de caracteres

void concatenarStrings (char string1[], int t1,  char string2[], int t2, char string3[]);
int tamanhoString (char string[]);
void  alfabetico (char variavel);
_Bool stringsIguais (char s1[], char s2[]);

int main (void)
{	setlocale(LC_ALL, "");

	printf ("1) DEFINIÇÃO DE STRINGS");
	printf ("\n\tÉ o conjunto de caracteres.");
	printf ("\n\t\tExemplo: ");

	char teste[] = {'B', 'r', 'a', 's', 'i', 'l'};
	//char teste[6] = {'B', 'r', 'a', 's', 'i', 'l'};
	//char teste[7] = {"Brasil};
	//char teste[] = {"Brasil"};
	//char teste[] = "Brasil";
	
	//Caractere nulo: '\0' -> Ocupa um espaço
	
	int i;

	for (i=0; i<6; i++)
		printf("%c", teste[i]);
	printf ("\n\t\tExemplo: %s", teste);
	printf("\n\n\n");
	
//-------------------------------------------------------------------------------
	
	printf ("2) CONCATENAR STRINGS");
	printf ("\n\tExemplo: ");
	
	char palavra1[] = {'p', 'ã', 'o', ' '};
	char palavra2[] = {'m', 'o', 'r', 't', 'a', 'd', 'e', 'l', 'a'};
	char novaPalavra[13];
	
	concatenarStrings (palavra1, 4,  palavra2, 9, novaPalavra);
	
	for (i=0; i<13; i++)
		printf("%c", novaPalavra[i]);
	printf("\n\n\n");
	
//-------------------------------------------------------------------------------
	
	printf ("3) CONTAR CARACTERES DE UMA STRING");
	printf ("\n\tOs caracteres de uma string é a quantidade de algarismos somados ao caractere nulo.");
	
	char stringUsuario[20];
	
	printf ("\n\n\tExemplo: Digite uma palavra(string): ");
	scanf ("%s", &stringUsuario);
	
	int num = tamanhoString (stringUsuario);
	
	printf ("\t\tA string %s possui %i caracteres.", stringUsuario, num);
	printf("\n\n\n");
	
//-------------------------------------------------------------------------------

	printf ("4) VERIFICAR CARACTERES ALFABETICOS");
	printf ("\n\n\tExemplo: ");
	
	char nome[20];
	i=0;
	
	printf ("Digite uma palavra: ");
	scanf ("%s", nome);
	
	while (nome[i]!='\0')
	{	alfabetico (nome[i]);
		++i;	}
	printf("\n\n\n");

//-------------------------------------------------------------------------------

//CUIDADO!

/*	char nome[20], sobrenome[20];
	printf ("Insira seu nome e seu sobrenome: );
	scanf ("%s%s", &nome, &sobrenome);
	printf ("\n\n%s%s", nome, sobrenome);
*/

//-------------------------------------------------------------------------------

	printf ("5) OBTER STRING DO USUÁRIO");
	printf ("\n\n\tExemplo: ");
	
	char linha[100];
	char *caractere;
	i=0;
	
	do
	{	*caractere = getchar ();	//Getchar vai na linha de comando e pega uma caractere
		linha[i]=caractere;
		++i;
	} while (caractere!='\n');
	
	linha[i-1]='\0';

	printf ("%s", linha);
	printf("\n\n\n");
	
//-------------------------------------------------------------------------------

	printf ("6) VERIFICAR IGUALDADE ENTRE DUAS STRINGS");
	printf ("\n\n\tExemplo: ");
	
	if (stringsIguais("casa", "casa"))
		printf ("São iguais.");
	else
		printf ("Não são iguais");
	printf("\n\n\n");

	return 0;
}
//FIM DA FUNÇÃO MAIN
//-------------------------------------------------------------------------------

void concatenarStrings (char string1[], int t1,  char string2[], int t2, char string3[])
{	int i, j;

	for (i=0; i<t1; ++i)
		string3[i]=string1[i];
	for (j=0; j<t2; ++j)
		string3[j+t1]=string2[j];
}

int tamanhoString (char string[])
{	int numCaracteres=0;

	while (string[numCaracteres] != '\0')
		++numCaracteres;
	++numCaracteres;		//Adicionar o caractere nulo	
	return numCaracteres;
}

void  alfabetico (char variavel)
{
	if ((variavel >='a' && variavel<='z') || (variavel >='A' && variavel<='Z'))
		printf ("\n\t%c é uma letra.", variavel);
	else
		printf ("\n\t%c não é uma letra.", variavel);
}

bool stringsIguais (char s1[], char s2[])
{	int i=0;

	while (s1[i]=s2[i] && s1[i]!='\0' && s2[i]!='\0')
		++i;
		
	if (s1[i]=='\0' && s2[i]=='\0')
		return 1;	//Verdadeiro -> As duas strings são iguais
	else
		return 0;	//Falso -> As duas strings não são iguais
}
