#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

// 1)- Considerando o cadastro de uma agenda de endereços, nomes, idade e telefones, defina a estrutura de registro apropriada, o diagrama de blocos e as codificações de um programa que efetuem as seguintes tarefas:

// a- o cadastramento das informações: nome, endereço, idade e telefone.
// b- a pesquisa da idade.
// c- a classificação por ordem alfabética
// d- a alteração de algum registro que tenha sido fornecido com erro.

// O programa em que estão deverá ser projetado de tal forma que considere o uso de um menu de opções, para que o usuário selecione a opção desejada independentemente de uma ordem específica, conforme layout abaixo:

// Programa Agenda

// 1.Cadastro e registros; 2.Pesquisa de registro; 3.Classificação alfabética; 4.Alteração de registro; 5.Sair - Escolha uma opção:
	
//Declaração da struct	
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
	
	//Menu de opções
	do
	{	printf ("\n\n\t\tMENU DE OPÇÕES \n\n\t1-Cadastro e registros \n\t2-Pesquisa de registro \n\t3-Classificação alfabética \n\t4-Alteração de registro \n\t5-Sair\n\nInsira a opção desejada: ");
		scanf ("%d", &op);
		fflush (stdin);
	
		switch (op)
		{
			//Os dados são cadastrados devidamente
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
					printf ("\t Insira o endereço da pessoa : ");
					gets (peop[i].endereco);
					
					fflush (stdin);
				}
				printf ("\n\n\n\n\n\n\n");
				break;
			
			//O usuário informa um nome de um aluno já cadastro para ser buscado
			char pesq[20];	
			case 2:
				printf ("Informe o nome do aluno que deseja buscar: ");
				gets (pesq);
				fflush (stdin);
				
				for (i=0; i<=4; i++)
					if ((strcmp (peop[i].nome, pesq))==0)
						printf ("\n\n\n\tRegistro Número %d\n\t\tNome: %s \n\t\tIdade: %d \n\t\tTelefone: %s \n\t\tEndereço: %s", i+1, peop[i].nome, peop[i].idade, peop[i].telefone, peop[i].endereco);
				printf ("\n\n\n\n\n\n\n");
				break;
			
			//Realiza-se a ordenação de struct por bubble sort
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
			
			//A alteração será realizada lendo o nome do registro a ser buscado, depois um laço encontrará essa posição para alterá-la devidamente
			case 4:
				printf ("\n\n\n\t\t\tInforme o nome do aluno cujo registro será alterado: ");
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
						printf ("\t Insira o endereço da pessoa : ");
						gets (peop[i].endereco);
						
						fflush (stdin);
					}
					printf ("\n\n\n\n\n\n\n");
					break;
				
			case 5:
				printf ("\n\n\tAté breve!");
				break;
				
			default:
				printf ("\n\n\t\tOpção inválida! tente novamente.");
				printf ("\n\n\n\n\n\n\n");
				break;
			
			printf ("\n\n\n\n\n\n\n");
		}
	}
	while (op!=5);
            
    getch();
    return 0;
}
