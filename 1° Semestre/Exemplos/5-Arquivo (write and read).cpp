#include <stdio.h>
#include <stdlib.h>

int main()
{	FILE *fp;
	char string[100], c;
	int i;

//Criação do arquivo!!
	fp = fopen ("arquivo.txt", "w");

	if(!fp)
	{	printf ("Erro na abertura do arquivo");
		exit(0);	
	}

	printf ("Entre com a string a ser gravada no arquivo: ");
	gets (string);

	//Grava a string no arquivo caractere por caractere
	for(i=0; string[i]; i++)
		putc (string[i], fp);
	
	//Exibe a string na tela caractere por caractere
	for(i=0; string[i]; i++)
		putc (string[i], stdout);
	
	//Exibe a string na tela caractere por caractere
	while (string[i] != '\0')
	{	fputc (string[i], stdout);
		i++;
	}
		
	putc ('a', stdout);
	fputc ('b', stdout);
	
	fclose(fp);

//Leitura do arquivo!!
	fp = fopen("arquivo.txt", "r");

	if(!fp)
	{	printf("Erro na abertura do arquivo");
		exit(0);	
	}

	//Imprime a string lida na tela caractere por caractere
	while((c = getc(fp) ) != EOF)
		printf("%c", c);
		
	//Conta o tamanho da string
	while ((string[i]=fgetc(fp))!=EOF)
		i++;

	fclose(fp);
	
	return 0;
}
