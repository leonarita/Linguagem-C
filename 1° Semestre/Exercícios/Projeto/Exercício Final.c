#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>

#define N 5

float Intercambio(float a);

struct CAD_PRODUTO
{	int ID;
	char Nome[20];
	char Fabricante[20];
	char *PaisOrigem[20];
	float PrecoOrigem;
	float PrecoBrasil;
}; 
struct CAD_PRODUTO PRODUTO;
//Estrutura do tipo "CAD_PRODUTO" chamada prod
//A partir disso, é possível criar outras estruturas do tipo "CAD_PRODUTO", contendo as mesmas variáveis. Basta mudar o nome da estrutura

int opcao;

struct lconv *lc;		//Para símbolos monetários

int main()
{	system ("TITLE Vendas.inc");
	setlocale (LC_ALL, "");
	
	struct tm *Dados;	//Para data e hora
	time_t segundos;
	time (&segundos);
	Dados = localtime (&segundos);
	
	struct usuario
	{	char user[10];
		char password[7];
	};
	const struct usuario contas[N] = { {"Leo", "123456"}, {"Naoki", "a1b2c3"}, {"Steff", "meuamo"}, {"Narita", "000000"}, {"Luna", "auauau"} };
	
	int indice = 0;
	char senha[5], verifica, login[10], i, m;
	bool teste;
	
	do
	{	puts ("Login: ");
		gets (login);
		system("cls");
	
	    for (i = 0; i <= 5; i++)
	    {	indice = i;
	    	printf ("Login: %s \n", login);
	
			if (i == 0)
			{	printf ("Senha: ");
	    		verifica = getch();		}
	    	if (i == 1)
	        {	printf ("Senha: *");
	    		verifica = getch();		}
	        if (i == 2)
	        {	printf ("Senha: **");
	    		verifica = getch();		}
	        if (i == 3)
	        {	printf ("Senha: ***");
	    		verifica = getch();		}
	        if (i == 4)
	    	{	printf ("Senha: ****");
	    		verifica = getch();		}
	    	if (i==5)
	    	{	printf ("Senha: *****");
	    		verifica = getch();
	    		system("cls");
	    		printf ("Login: %s \n", login);
	    		printf ("Senha: ******");
	    		
	    		printf ("\n\n\tLoading");
				for (m=0; m<=2; m++)
				{	sleep(1);
					printf (".");
					fflush (stdout);
				}
			}
	    	     
	        if (verifica == 13)
	        	break;
	        else
	        	senha[i] = verifica;
	        if (i<5)
				system ("CLS");
	    }
	
		for (i=0; i<=N; i++)
		{	if (strcmp(login, contas[i].user)==0 && strcmp(senha, contas[i].password)==0)
			{	printf ("\n\n\t\tAcesso permitido!");
				getch();
				system ("cls");
				teste = true;
				break;	}
			
			if (i==N)
			{	if (strcmp(login, contas[i].user)!=0 || strcmp(senha, contas[i].password)!=0)
				{	printf ("\n\n\t\tAcesso negado!");
					getch();
					system("cls");	}
			}
		}
	} while (teste==false);
    
    do
    {    printf ("Bem-vindo, %s! \n\n", login);
	
		puts ("Insira o nome do produto: ");
		printf ("\t");
		gets (PRODUTO.Nome);
		fflush (stdin);
		
		printf ("\nGerando o ID do produto");
		for (i=0; i<3; i++)
		{	sleep (1);
			printf (".");
			fflush (stdout);
		}
		PRODUTO.ID = rand () % 1000;
		while (PRODUTO.ID<100)
			PRODUTO.ID = rand () % 1000;
		printf ("\n\tID do produto: %d", PRODUTO.ID);
	
		puts ("\n\nInsira o nome do fabricante: ");
		printf ("\t");
		gets (PRODUTO.Fabricante);
	
		printf("\nConsidere os seguintes códigos: \n\t1-EUA \n\t2-Alemanha \n\t3-Inglaterra \n\t4-Argentina \nInsira codigo do país de origem: ");
		scanf ("%d", &opcao);
		fflush (stdin);
	
		switch (opcao)
		{
			case 1:
				*PRODUTO.PaisOrigem = "EUA";
				setlocale (LC_MONETARY,"English");
				lc=localeconv();
				printf ("\nDigite o preço de origem em dólares: %s", lc->currency_symbol);
				scanf ("%f", &PRODUTO.PrecoOrigem);
				break;
			case 2:
				*PRODUTO.PaisOrigem = "Alemanha";
				setlocale (LC_MONETARY,"German");
				lc=localeconv();
				printf ("\n\nDigite o preço de origem em euro: %s", lc->currency_symbol);
				scanf ("%f", &PRODUTO.PrecoOrigem);
				break;
			case 3:
				*PRODUTO.PaisOrigem = "Inglaterra";
				setlocale (LC_MONETARY,"UK");
				lc=localeconv();
				printf ("\nDigite o preço de origem em libra: %s", lc->currency_symbol);
				scanf ("%f", &PRODUTO.PrecoOrigem);
				break;
			case 4:
				*PRODUTO.PaisOrigem = "Argentina";
				setlocale (LC_MONETARY,"Spanish_Arg");
				lc=localeconv();
				printf ("\nDigite o preço de origem em peso: %s", lc->currency_symbol);
				scanf ("%f", &PRODUTO.PrecoOrigem);
				break;
			default:
				printf ("\n\n\t\tComando inválido! Tente novamente...");
				sleep(1);
				system ("cls");
				break;
		}
	} while (opcao>4 || opcao<1);
	
	PRODUTO.PrecoBrasil = Intercambio(PRODUTO.PrecoOrigem);
	printf ("\nO preço no Brasil vale: R$%.2f", PRODUTO.PrecoBrasil);
	printf ("\n\n\n");
	
	printf ("Informações do dia");
	printf ("\n\tData: %d/%d/%d", Dados->tm_mday, Dados->tm_mon+1, Dados->tm_year+1900);
	printf ("\n\tHora: %d:%d:%d", Dados->tm_hour, Dados->tm_min, Dados->tm_sec);

	printf ("\n\n\n");
	printf ("\t\tImprimindo dados do arquivo feito");
	for (i=0; i<5; i++)
		{	sleep (1);
			printf (".");
			fflush (stdout);
		}
	printf ("\n\n\n\n\n");

	FILE *file;
	char frase[100];
	
	file = fopen ("Relatório.txt", "w");
		if(!file)
		{	printf ("Erro na abertura do arquivo");
			getchar();
			exit (1);	}
		fprintf (file, "Usuário: %s", login);
		fprintf (file, "\n\n\t\tDados sobre o produto");
		fprintf (file, "\nID: %d", PRODUTO.ID);
		fprintf (file, "\nNome: %s", PRODUTO.Nome);
		fprintf (file, "\nFabricante: %s", PRODUTO.Fabricante);
		fprintf (file, "\nPaís de origem: %s", *PRODUTO.PaisOrigem);
		fprintf (file, "\nPreço de origem: %s%.2f", lc->currency_symbol, PRODUTO.PrecoOrigem);
		fprintf (file, "\nPreço do Brasil: R$%.2f", PRODUTO.PrecoBrasil);
		fprintf (file, "\n\n\n");
		fprintf (file, "Informações do dia");
		fprintf (file, "\n\tData: %d/%d/%d", Dados->tm_mday, Dados->tm_mon+1, Dados->tm_year+1900);
		fprintf (file, "\n\tHora: %d:%d:%d", Dados->tm_hour, Dados->tm_min, Dados->tm_sec);
	fclose(file);

	file = fopen ("Relatório.txt", "r");
		if(!file)
		{	printf ("Erro na abertura do arquivo");
			getchar();
			exit (1);	}
		while (fgets(frase, 100, file) != NULL)
			printf ("%s", frase);
	fclose(file);
}

//O ".2" antes do "f" (float) indica que o número a ser exibido mostrará duas casas decimais

float Intercambio(float a)
{	if (opcao==1)
		return a * 3.9;
	else if (opcao==2)
		return a * 4.5;
	else if (opcao==3)
		return a * 4.9;
	else if (opcao==4)
		return a* 0.0881;
}
