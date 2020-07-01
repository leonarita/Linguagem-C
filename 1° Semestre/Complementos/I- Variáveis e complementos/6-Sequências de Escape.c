#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main (void)
{	setlocale(LC_ALL, "");

	printf ("\tSEQUÊNCIAS DE ESCAPE");					// \0 -> Fim da linha (comando nulo)
	sleep(2);
	printf ("\n\t\t\aAcorde!\a");						// \a -> Alarme sonoro do sistema
	sleep(2);
	printf ("\n\t\t\b\b\b\bMoveu 2 casas à esquerda");	// \b -> Move o cursor uma posição à esquerda
	sleep(2);
	printf ("\n\t\t\r\rVoltou");						// \r -> Move o cursor para o início da linha
	sleep(2);
	printf ("\n\t\t\"ASPASSS\"");						// \" -> printf reconhece as aspas
	sleep(2);
	printf ("\n\t\t\'APÓSTROFEE\'");					// \' -> printf reconhece as apóstrofe
	printf ("\n\n\n");
	
	//Usando a tabela ASC II
	int x=97;			//Na tabela, 97 corresponde ao "a"
	printf ("%c", x);	//Vai exibir o "a" por causa do %c
	
	//	if (x < 'a')
	
	getchar();
}
