#include <stdio.h>
#include <conio.h>
#include <string.h>  // arquivo de cabe�alho para trabalhar com strings
#include <locale.h>

void main()
{	setlocale (LC_ALL, "");
	char Nome[30];  // declara uma string que poder� armazenar at� 29 caracteres !! 
	strcpy(Nome, "Jose da Silva");  // atribui "Jose da Silva" para a vari�vel Nome
	printf("O funcion�rio %s foi tranferido", Nome);  // no lugar de %s aparecer� o conte�do da vari�vel Nome  
	getch();
}
