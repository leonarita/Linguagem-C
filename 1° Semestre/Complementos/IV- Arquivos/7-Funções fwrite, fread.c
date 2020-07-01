#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

int main()
{
	FILE *pf;
	float pi = 3.1415;
	float pilido;
	
	setlocale(LC_ALL, "Portuguese");
	
	if((pf = fopen("arquivo.bin", "wb")) == NULL)
	{	printf("Erro na abertura do arquivo");
		exit(1);
	}
	
	if(fwrite(&pi, sizeof(float), 1, pf) != 1)
		printf("Erro na escrita do arquivo");
	
	fclose(pf);
	
	
	if((pf = fopen("arquivo.bin", "rb")) == NULL)
	{	printf("Erro na abertura do arquivo");
		exit(1);
	}
	
	if(fread(&pilido, sizeof(float), 1, pf) != 1)
		printf("Erro na leitura do arquivo");

	printf("\nO valor de PI, lido do arquivo é: %f", pilido);
	fclose(pf);
}
