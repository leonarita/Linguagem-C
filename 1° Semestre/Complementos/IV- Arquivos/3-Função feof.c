#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	FILE *p;
	char c, str[30], frase[80] = "Este é um arquivo chamado: ";
	int i;
	
	printf("\n\n Entre com um nome para o arquivo:\n");
	gets(str);
	
	if (!(p = fopen(str, "w")))
	{
		printf("Erro! Impossível abir o arquivo!\n");
		exit(1);
	}
	
	strcat(frase, str);
	for (i=0; frase[i]; i++)
		putc(frase[i], p);
	fclose(p);
	
	p = fopen(str, "r");
	c = getc(p);
	while (!feof(p))
	{
		printf("%c", c);
		c = getc(p);
	}
	fclose(p);
}
