#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include <windows.h>

void gotoxy(int x, int y);

void cor (int iColor); 

int calcula_triangulo(int a, int b, int c);

char gravacao(char a, char b, char c);

char cadastro();

	int valor_a = 0;
	int valor_b = 0;
	int valor_c = 0;
	int resposta = 0;
	char nome[50];
	char email[50];
	char telefone[50];
	
	

void cor (int iColor) 
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

char cadastro()
{
	
	
		printf("\n\t Insira seu nome para cadastro: ");
			
			gets(nome);
		
		printf("\n\t Insira seu e-mail: ");
		
			gets(email);
		
		printf("\n\t Insira seu numero de telefone: ");
		
			gets(telefone);
			
				
					
					
					
				
			
					system("cls");
	return 0;
}

int tabela()
{
	printf("\n\n\t .____________________________________________________________________________. \n");
	printf("    \t |  ._________________________________________.  ._________________________.  | \n");
	printf("    \t |  |                                         |  |                         |  | \n");
	printf("    \t |  |           ");
	
		cor(10); //muda a cor do título para verde
		
	printf("FORMANDO TRIÂNGULOS");
	
		cor(15); //volta a cor para o branco
	
	printf("           |  |                         |  | \n");
	printf("    \t |  |_________________________________________|  |                         |  | \n");
	printf("    \t |                                               |                         |  | \n");
	printf("    \t |  .__________________________.  .___________.  |                         |  | \n");
	printf("    \t |  |                          |  |           |  |                         |  | \n");
	printf("    \t |  |  Valor do primeiro lado  |  |           |  |                         |  | \n");	
	printf("    \t |  |__________________________|  |___________|  |                         |  | \n");
	printf("    \t |  .__________________________.  .___________.  |                         |  | \n");
	printf("    \t |  |                          |  |           |  |                         |  | \n");
	printf("    \t |  |  Valor do primeiro lado  |  |           |  |                         |  | \n");
	printf("    \t |  |__________________________|  |___________|  |                         |  | \n");
	printf("    \t |  .__________________________.  .___________.  |                         |  | \n");
	printf("    \t |  |                          |  |           |  |                         |  | \n");
	printf("    \t |  |  Valor do primeiro lado  |  |           |  |                         |  | \n");
	printf("    \t |  |__________________________|  |___________|  |                         |  | \n");
	printf("    \t |  ._________________________________________.  |                         |  | \n");
	printf("    \t |  |                                         |  |                         |  | \n");
	printf("    \t |  |  Lado A:      Lado B:      Lado C:      |  |                         |  | \n");
	printf("    \t |  |_________________________________________|  |                         |  | \n");
	printf("    \t |                                               |_________________________|  | \n");
	printf("    \t |____________________________________________________________________________| \n");	 
}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int lado_a()
{
	gotoxy(45, 10);  //posiciona o cursor no local de inserção de dados
	
		scanf("%i", &valor_a);
		
			gotoxy(43, 10); //posiciona novamente no mesmo local, para "apagar" da tela
			
				printf("           ");

					gotoxy(23, 22); //posiciona o cursor no local onde deve aparecer o valor digitado
	
						printf("%i", valor_a);
					
	return 0;
}

int lado_b()
{
	gotoxy(45, 14); //posiciona o cursor no local de inserção de dados
	
		scanf("%i", &valor_b);
		
			gotoxy(43, 14); //posiciona novamente no mesmo local, para "apagar" da tela
			
				printf("           ");
				
					gotoxy(36, 22); //posiciona o cursor no local onde deve aparecer o valor digitado
	
						printf("%i", valor_b);
	
	return 0;
}

int lado_c()
{
	gotoxy(45, 18); //posiciona o cursor no local de inserção de dados
	
		scanf("%i", &valor_c);
		
			gotoxy(43, 18); //posiciona novamente no mesmo local, para "apagar" da tela
			
				printf("           ");
				
					gotoxy(49, 22); //posiciona o cursor no local onde deve aparecer o valor digitado
	
						printf("%i", valor_c);
	
	return 0;
}

int calcula_triangulo(int a, int b, int c)
{	
	if( a < b + c && b < a + c && c < a + b ) //compara os lados para verificar se a condição para ser um triângulo foi respeitada
	{
		if( a == b && b == c )
		{
			equilatero();
		}
		else
		{
			if( a == b || a == c || b == c )
			{
				isosceles();
			}
			else
			{
				escaleno();
			}
		}
	}
	else
	{
			system("cls");
			
				printf("\n Não é um triângulo!");
				
					repetir();
	}
}

int repetir()
{			
	printf("\n\n Deseja inserir novos valores?  1 -> SIM");
					printf("  \n                                2 -> NÃO");
					printf("  \n Resposta: ");
					
						scanf("%i", &resposta);
										
							switch(resposta)
							{
								case 1 : system("cls");
								
											main();
									break;
									
								case 2 : exit (0);
									break;
								
								default : system("cls");
												
											repetir();
									break;				
							}
	return 0;
}

int equilatero()
{
	gotoxy(57, 11);
	
		printf("|            *            |");
		
	gotoxy(57, 12);	
	
		printf("|           * *           |");
	
	gotoxy(57, 13);	
		
		printf("|          *   *          |");
		
	gotoxy(57, 14);
	
		printf("|         *     *         |");
		
	gotoxy(57, 15);	
	
		printf("|        * * * * *        |");
		
	gotoxy(60, 17);	
	
		printf("Triângulo Equilátero");
}

int isosceles()
{
	gotoxy(57, 11);
	
		printf("|            *            |");
		
	gotoxy(57, 12);	
	
		printf("|          *   *          |");
		
	gotoxy(57, 13);	
	
		printf("|        *       *        |");
	
	gotoxy(57, 14);
	
		printf("|      *           *      |");
		
	gotoxy(57, 15);	
	
		printf("|    * * * * * * * * *    |");
	
	gotoxy(60, 17);	
	
		printf("Triângulo Isósceles.");
}

int escaleno()
{
	gotoxy(57, 11);
	
		printf("|          *              |");
		
	gotoxy(57, 12);
	
		printf("|         *  *            |");
		
	gotoxy(57, 13);
	
		printf("|        *     *          |");
		
	gotoxy(57, 14);
	
		printf("|       *        *        |");
	
	gotoxy(57, 15);
	
		printf("|      * * * * * * *      |");
		
	gotoxy(62, 17);	
	
		printf("Triângulo Escaleno");
}

char le_arquivo()
{
	
}

int main()
{
	FILE *file;
	file = fopen ("Ficha_cadastro.txt", "w+");
	
	setlocale(LC_ALL, "Portuguese");
	
		cor(15); //muda a cor para branco
		
			cadastro();
	
			tabela();
				
				lado_a();
				
					lado_b();
					
						lado_c();
						
							calcula_triangulo(valor_a, valor_b, valor_c);
							
								getch();
								
	fprintf(file, "\n\n\t Nome do usuário: %s ", nome);
						
	fprintf(file, "\n\n\t E-mail do usuário: %s ", email);
						
	fprintf(file, "\n\n\t Telefone do usuário: %s", telefone);
	
	if( valor_a == valor_b && valor_b == valor_c )
		{
			fprintf(file, "\n\n\t Triângulo: Equilátero.");
		}
		else
		{
			if( valor_a == valor_b || valor_a == valor_c || valor_b == valor_c )
			{
				fprintf(file, "\n\n\t Triângulo: Isósceles.");
			}
			else
			{
				fprintf(file, "\n\n\t Triângulo: Escaleno.");
			}
		}
		
	fclose(file);
	
	file = fopen ("Ficha_cadastro.txt", "w+");
																		
	fgets(nome, 50, file);
		
		printf("\n\n\n\n\n\n\n\n\n\n\t Nome do usuário: %s", nome);
		
	fgets(email, 50, file);
	
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t E-mail do usuário: %s", email);
		
	fgets(telefone, 50, file);
	
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t Telefone do usuário: %s", telefone);
		
		fclose(file);	
		
	getch();
		
		system("cls");
									
		repetir();
	
										
									
	getch();
}
