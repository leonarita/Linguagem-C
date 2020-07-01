#include <stdio.h>
#include <conio.h>
#include <string.h>  // arquivo de cabeçalho para trabalhar com strings
#include <locale.h>

void main()
{	setlocale (LC_ALL, "");
	char Nome[30];  // declara uma string que poderá armazenar até 29 caracteres !! 
	strcpy(Nome, "Jose da Silva");  // atribui "Jose da Silva" para a variável Nome
	printf("O funcionário %s foi tranferido", Nome);  // no lugar de %s aparecerá o conteúdo da variável Nome  
	getch();
}
