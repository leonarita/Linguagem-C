#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

// 1)- Considerando o cadastro de uma agenda de endere�os, nomes, idade e telefones, defina a estrutura de registro apropriada, o diagrama de blocos e as codifica��es de um programa que efetuem as seguintes tarefas:

// a- o cadastramento das informa��es: nome, endere�o, idade e telefone.
// b- a pesquisa da idade.
// c- a classifica��o por ordem alfab�tica
// d- a altera��o de algum registro que tenha sido fornecido com erro.

// O programa em que est�o dever� ser projetado de tal forma que considere o uso de um menu de op��es, para que o usu�rio selecione a op��o desejada independentemente de uma ordem espec�fica, conforme layout abaixo:

// Programa Agenda

// 1.Cadastro e registros; 2.Pesquisa de registro; 3.Classifica��o alfab�tica; 4.Altera��o de registro; 5.Sair - Escolha uma op��o:
	
//Declara��o da struct	
struct CADASTRO_PESSOA
{	int idade;
	char telefone[20];
	char nome[20];
	char endereco[20];
};
struct CADASTRO_PESSOA peop[5];


int main () 
{	setlocale (LC_ALL, "Portuguese");
	int i, j, op;
	
	//Menu de op��es
	do
	{	printf ("\n\n\t\tMENU DE OP��ES \n\n\t1-Cadastro e registros \n\t2-Pesquisa de registro \n\t3-Classifica��o alfab�tica \n\t4-Altera��o de registro \n\t5-Sair\n\nInsira a op��o desejada: ");
		scanf ("%d", &op);
		fflush (stdin);
	
		switch (op)
		{
			//Os dados s�o cadastrados devidamente
			case 1:
				for (i=0; i<=4; i++)
				{	printf ("\n\n\n");
					fflush (stdin);
					printf ("\t Insira o nome da pessoa     : ");
					gets (peop[i].nome);
					
					fflush (stdin);
					printf ("\t Insira a idade da pessoa    : ");
					scanf ("%d", &peop[i].idade);
					
					fflush (stdin);
					printf ("\t Insira o telefone da pessoa : ");
					gets (peop[i].telefone);
					
					fflush (stdin);
					printf ("\t Insira o endere�o da pessoa : ");
					gets (peop[i].endereco);
					
					fflush (stdin);
				}
				printf ("\n\n\n\n\n\n\n");
				break;
			
			//O usu�rio informa um nome de um aluno j� cadastro para ser buscado
			char pesq[20];	
			case 2:
				printf ("Informe o nome do aluno que deseja buscar: ");
				gets (pesq);
				fflush (stdin);
				
				for (i=0; i<=4; i++)
					if ((strcmp (peop[i].nome, pesq))==0)
						printf ("\n\n\n\tRegistro N�mero %d\n\t\tNome: %s \n\t\tIdade: %d \n\t\tTelefone: %s \n\t\tEndere�o: %s", i+1, peop[i].nome, peop[i].idade, peop[i].telefone, peop[i].endereco);
				printf ("\n\n\n\n\n\n\n");
				break;
			
			//Realiza-se a ordena��o de struct por bubble sort
			case 3:	
				for (i=0; i<=3; i++)
					for (j=i+1; j<=4; j++)
						if ((strcmp(peop[i].nome, peop[j].nome))>0)
						{	struct CADASTRO_PESSOA aux;
							aux = peop[i];
							peop[i] = peop[j];
							peop[j] = aux;
						}
				printf ("\n\nRegistros ordenados: ");
				printf ("\n\t\t\t       Nome                      Telefone                  Endereco                  Idade");
				for (i=0; i<=4; i++)
				{	printf ("\n\t%d Aluno:               %s", i+1, peop[i].nome);
					for (j=strlen(peop[i].nome); j<=25; j++)
						printf (" ");
					printf ("%s", peop[i].telefone);
					for (j=strlen(peop[i].telefone); j<=25; j++)
						printf (" ");
					printf ("%s", peop[i].endereco);
					for (j=strlen(peop[i].endereco); j<=25; j++)
						printf (" ");
					printf ("%d", peop[i].idade);
				}
				printf ("\n\n\n\n\n\n\n");
				break;
			
			//A altera��o ser� realizada lendo o nome do registro a ser buscado, depois um la�o encontrar� essa posi��o para alter�-la devidamente
			case 4:
				printf ("\n\n\n\t\t\tInforme o nome do aluno cujo registro ser� alterado: ");
				gets (pesq);
				
				for (i=0; i<=4; i++)
					if ((strcmp (peop[i].nome, pesq))==0)
					{	printf ("\n\n\n");
						fflush (stdin);
						printf ("\t Insira o nome da pessoa     : ");
						gets (peop[i].nome);
						
						fflush (stdin);
						printf ("\t Insira a idade da pessoa    : ");
						scanf ("%d", &peop[i].idade);
						
						fflush (stdin);
						printf ("\t Insira o telefone da pessoa : ");
						gets (peop[i].telefone);
						
						fflush (stdin);
						printf ("\t Insira o endere�o da pessoa : ");
						gets (peop[i].endereco);
						
						fflush (stdin);
					}
					printf ("\n\n\n\n\n\n\n");
					break;
				
			case 5:
				printf ("\n\n\tAt� breve!");
				break;
				
			default:
				printf ("\n\n\t\tOp��o inv�lida! tente novamente.");
				printf ("\n\n\n\n\n\n\n");
				break;
			
			printf ("\n\n\n\n\n\n\n");
		}
	}
	while (op!=5);
            
    getch();
    return 0;
}
