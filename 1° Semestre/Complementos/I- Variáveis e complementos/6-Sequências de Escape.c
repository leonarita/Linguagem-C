#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main (void)
{	setlocale(LC_ALL, "");

	printf ("\tSEQU�NCIAS DE ESCAPE");					// \0 -> Fim da linha (comando nulo)
	sleep(2);
	printf ("\n\t\t\aAcorde!\a");						// \a -> Alarme sonoro do sistema
	sleep(2);
	printf ("\n\t\t\b\b\b\bMoveu 2 casas � esquerda");	// \b -> Move o cursor uma posi��o � esquerda
	sleep(2);
	printf ("\n\t\t\r\rVoltou");						// \r -> Move o cursor para o in�cio da linha
	sleep(2);
	printf ("\n\t\t\"ASPASSS\"");						// \" -> printf reconhece as aspas
	sleep(2);
	printf ("\n\t\t\'AP�STROFEE\'");					// \' -> printf reconhece as ap�strofe
	printf ("\n\n\n");
	
	//Usando a tabela ASC II
	int x=97;			//Na tabela, 97 corresponde ao "a"
	printf ("%c", x);	//Vai exibir o "a" por causa do %c
	
	//	if (x < 'a')
	
	getchar();
}
