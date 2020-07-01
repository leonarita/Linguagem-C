/*Samuel lima Santos*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<windows.h>
#include<time.h>


int main();
int apresentacao();
float total_combo_1(int quantidade);
float total_combo_2(int quantidade);
float total_combo_3(int quantidade);
float preco_total_final(float total_combo1, float total_combo2, float total_combo3);
float tabela_total();
char tabela_pagamento1();
char tabela_pagamento2();
char tabela_pagamento3();

int resposta = 0;
int escolha_combo = 0;
int escolha_pagamento = 0;

char combo1[] = "Combo Hambúrguer Duplo";
char combo2[] = "Combo Hambúrguer Simples";
char combo3[] = "Combo Misto Quente";

int code_combo1 = 1;
int code_combo2 = 2;
int code_combo3 = 3;

float preco_combo1 = 25.90;
float preco_combo2 = 18.50;
float preco_combo3 = 12.75;

float preco_total = 0.00;

int quantidade_combo1 = 0;
int quantidade_combo2 = 0;
int quantidade_combo3 = 0;

float total_combo1 = 0.00;
float total_combo2 = 0.00;
float total_combo3 = 0.00;

int code_pagamento1 = 1;
int code_pagamento2 = 2;
int code_pagamento3 = 3;

char pagamento1[] = "Cartão de Crédito/Débito";
char pagamento2[] = "Cheque";
char pagamento3[] = "Dinheiro";

float pago = 0.0;
float troco = 0.0;
float falta = 0.0;

char cartao[16];
int tamanho;
int i;

int pedido;
int pedido_numero = 0;

void textcolor (int iColor);


int main()
{
	setlocale(LC_ALL, "Portuguese");
	textcolor(15);
	tamanho = strlen(cartao);
	apresentacao();				
}


void textcolor (int iColor) 
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

int numero_pedido()
{
    srand (time (NULL)); 

    	for (pedido = 0; pedido <1; pedido++)
    	{        
        	pedido_numero= rand() % 10000;
    	}
}

int apresentacao()
{
	printf("\n\t  Bem-vindo ao Mickey & Donalds!");
		
		printf("\n\n\t  Pressione qualquer tecla..."); 
												
			getch();
								
				system("cls");
					
					tabela_combos();										
}

int tabela_combos()
{		
		do
		{
			printf("\n\t.________________________________________________.\n");
			printf("\t| Código |          Combo           |   Preço    |\n");
			printf("\t|________|__________________________|____________|\n"); 
			printf("\t|   %i    |  %s  |  R$ %.2f  |\n", code_combo1, combo1, preco_combo1); 
			printf("\t|________|__________________________|____________|\n"); 
			printf("\t|   %i    | %s |  R$ %.2f  |\n", code_combo2, combo2, preco_combo2); 
			printf("\t|________|__________________________|____________|\n"); 
			printf("\t|   %i    |    %s    |  R$ %.2f  |\n", code_combo3, combo3, preco_combo3); 
			printf("\t|________|__________________________|____________|\n"); 
			
			printf("\n\t Para voltar ao início, digite 4");
			
				printf("\n\n\t Escolha um combo: ");
					
					scanf("%i", &escolha_combo);
								
						system("cls");
		
		} while (escolha_combo <= 0 || escolha_combo >= 5);
						
							switch (escolha_combo)
								{
									case 1 : tabela_combo1();
										break;
									
									case 2 : tabela_combo2();
										break;
										
									case 3 : tabela_combo3();
										break;
									
									default : apresentacao();
										break;
								}
}

int tabela_combo1()
{	
	do
	{
		printf("\n \t.________________________________________________.\n");
		printf("\t|   Código   |         Combo          |   Preço  |\n");
		printf("\t|____________|________________________|__________|\n"); 
		printf("\t|     %i      | %s | R$ %.2f |\n", code_combo1, combo1, preco_combo1); 
		printf("\t|____________|________________________|__________|\n"); 
		printf("\t|               O que vem no lanche?             |\n");
		printf("\t|                                                |\n");
		printf("\t|    O lanche é composto por dois hambúrgueres   |\n");
		printf("\t|   de 250 gramas, queijo mussarela, salada de   |\n");
		printf("\t|   alface e tomate, picles e bacon. Acompanha   |\n");
		printf("\t|   batata frita grande e bebida.                |\n");
		printf("\t|________________________________________________|\n");
		
			printf("\n\n\t Deseja adicionar ao carrinho: Sim -> Digite 1");
			printf("  \n\t                               Não -> Digite 2");
			printf("\n\t Resposta: ");
					
							scanf("%i", &resposta);
							
								if (resposta != 1)
								{
									system("cls");
								}
							
	} while(resposta <= 0 || resposta >= 3);
					
					if (resposta == 1)
					{		
						printf("\n\n\t Digite quantos: ");
						
									scanf("%i", &quantidade_combo1);
									
										if(quantidade_combo1 <= 0)
										{
											quantidade_combo1 = quantidade_combo1 * (-1);
										}
									
											total_combo_1(quantidade_combo1);
											
												printf("\n\t Total parcial: R$ %.2f", total_combo1);
												
												printf("\n\n\t Pressione qualquer tecla..."); 
												
													getch();
								
														system("cls");
									
															continuar_compra();
					}
					else
					{
						tabela_combos();
					}							
}

float total_combo_1(int quantidade_combo1)
{
	total_combo1 = preco_combo1 * quantidade_combo1;
	
	
	return(total_combo1);
}

int tabela_combo2()
{
	do
	{
		printf("\n \t.__________________________________________________.\n");
		printf("\t|   Código   |           Combo          |   Preço  |\n");
		printf("\t|____________|__________________________|__________|\n"); 
		printf("\t|     %i      | %s | R$ %.2f |\n", code_combo2, combo2, preco_combo2); 
		printf("\t|____________|__________________________|__________|\n"); 
		printf("\t|                O que vem no lanche?              |\n");
		printf("\t|                                                  |\n");
		printf("\t|       O lanche é composto por um hambúrguer de   |\n");
		printf("\t|   150 gramas e queijo mussarela. É acompanhado   |\n");
		printf("\t|   de batata frita média e bebida.                |\n");
		printf("\t|__________________________________________________|\n");
		
			printf("\n\n\t Deseja adicionar ao carrinho: Sim -> Digite 1");
			printf("\n\t                               Não -> Digite 2");
			printf("\n\t Resposta: ");
					
							scanf("%i", &resposta);
							
								if (resposta != 1)
								{
									system("cls");
								}
							
	} while(resposta <= 0 || resposta >= 3);
					
					if (resposta == 1)
					{		
						printf("\n\n\t Digite quantos: ");
						
									scanf("%i", &quantidade_combo2);
									
										if(quantidade_combo2 <= 0)
										{
											quantidade_combo2 = quantidade_combo2 * (-1);
										}
									
											total_combo_2(quantidade_combo2);
											
												printf("\n\t Total parcial: R$ %.2f", total_combo2);
												
													printf("\n\n\t Pressione qualquer tecla...");
													
														getch();
								
															system("cls");
																												
																continuar_compra();
					}
					else
					{
						tabela_combos();
					}							
}

float total_combo_2(int quantidade_combo2)
{
	total_combo2 = preco_combo2 * quantidade_combo2;
	
	return(total_combo2);
}

int tabela_combo3()
{
	do
	{
		printf("\n \t.____________________________________________.\n");
		printf("\t|   Código   |        Combo       |   Preço  |\n");
		printf("\t|____________|____________________|__________|\n"); 
		printf("\t|     %i      | %s | R$ %.2f |\n", code_combo3, combo3, preco_combo3); 
		printf("\t|____________|____________________|__________|\n"); 
		printf("\t|             O que vem no lanche?           |\n");
		printf("\t|                                            |\n");
		printf("\t|       O lanche é composto por presunto e   |\n");
		printf("\t|   queijo mussarela. É acompanhado de uma   |\n");
		printf("\t|   bebida.                                  |\n");
		printf("\t|____________________________________________|\n");
	
			printf("\n\n\t Deseja adicionar ao carrinho: Sim -> Digite 1");
			printf("\n\t                               Não -> Digite 2");
			printf("\n\t Resposta: ");
					
							scanf("%i", &resposta);
							
								if (resposta != 1)
								{
									system("cls");
								}
							
	} while(resposta <= 0 || resposta >= 3);
					
					switch (resposta)
					{		
						case 1 : printf("\n\n\t Digite quantos: ");
						
									scanf("%i", &quantidade_combo3);
									 
									 	if(quantidade_combo3 <= 0)
										{
											quantidade_combo3 = quantidade_combo3 * (-1);
										}
									
											total_combo_3(quantidade_combo3);
											
												printf("\n\t Total parcial: R$ %.2f", total_combo3);
												
													printf("\n\n\t Pressione qualquer tecla...");
												
														getch();
									
															system("cls");
									 									 											
																continuar_compra();
							break;
					
						case 2 : tabela_combos();
							break;
					}							
}

float total_combo_3(int quantidade_combo3)
{
	total_combo3 = preco_combo3 * quantidade_combo3;
	
	return(total_combo3);
}

int continuar_compra()
{	
	do
	{
		printf("\n\n\t Deseja continuar comprando: Sim -> Digite 1");
		printf("  \n\t                             Não -> Digite 2");
		printf("\n\t Resposta: ");
						
			scanf("%i", &resposta);
								
				system("cls");
								
	} while(resposta <= 0 || resposta >= 3);
								
		if (resposta == 1)
		{
			system("cls");
										
				tabela_combos();
		}
		else
		{
			system("cls");
										
				tabela_total();
											
					getch();
												
						system("cls");
											
							tabela_pagamento();
		}
}

float preco_total_final(float total_combo1, float total_combo2, float total_combo3)
{
	preco_total = total_combo1 + total_combo2 + total_combo3;
	
	return(preco_total);
}

float tabela_total()
{
		preco_total_final(total_combo1, total_combo2, total_combo3);
		
			if(preco_total <= 10.00)
			{
				printf("\n\t .____________________________________.");
				printf("\n\t |  Total da compra:  |    R$ %.2f    |", preco_total);
				printf("\n\t |____________________|_______________|");
				
					printf("\n\n\t Pressione qualquer tecla...");
			}
			else
			{
				if(preco_total <= 100.00)
				{
					printf("\n\t .____________________________________.");
					printf("\n\t |  Total da compra:  |    R$ %.2f   |", preco_total);
					printf("\n\t |____________________|_______________|");
					
						printf("\n\n\t Pressione qualquer tecla...");
				}
				else
				{
					printf("\n\t .____________________________________.");
					printf("\n\t |  Total da compra:  |   R$ %.2f   |", preco_total);
					printf("\n\t |____________________|_______________|");
					
						printf("\n\n\t Pressione qualquer tecla...");
				}
			}
}	

float tabela_final()
{
	preco_total_final(total_combo1, total_combo2, total_combo3);
		
		if(preco_total <= 10.00)
		{
			printf("\n\t .____________________________________.");
			printf("\n\t |  Total da compra:  |    R$ %.2f    |", preco_total);
			printf("\n\t |____________________|_______________|");
				
		}
		else
		{
			if(preco_total <= 100.00)
			{
				printf("\n\t .____________________________________.");
				printf("\n\t |  Total da compra:  |    R$ %.2f   |", preco_total);
				printf("\n\t |____________________|_______________|");
					
			}
			else
			{
				printf("\n\t .____________________________________.");
				printf("\n\t |  Total da compra:  |   R$ %.2f   |", preco_total);
				printf("\n\t |____________________|_______________|");					
			}
		}
}

int tabela_pagamento()
{
	do
	{
		printf("\n\t.________________________________________.\n");
		printf("\t| Opção |       Forma de Pagamento       |\n");
		printf("\t|_______|________________________________|\n"); 
		printf("\t|   %i   |    %s    |\n", code_pagamento1, pagamento1); 
		printf("\t|_______|________________________________|\n"); 
		printf("\t|   %i   |             %s             |\n", code_pagamento2, pagamento2); 
		printf("\t|_______|________________________________|\n"); 
		printf("\t|   %i   |            %s            |\n", code_pagamento3, pagamento3); 
		printf("\t|_______|________________________________|\n");
						
			printf("\n\n\t Escolha uma forma de pagamento: ");
						
				scanf("%i", &escolha_pagamento);
									
					system("cls");
		
	} while (escolha_pagamento <=0 || escolha_pagamento >= 5);
						
		switch (escolha_pagamento)
		{
			case 1 : tabela_pagamento1();
				break;
									
			case 2 : tabela_pagamento2();
				break;
										
			case 3 : tabela_pagamento3();
				break;
									
			default : tabela_pagamento();
				break;
		}
}

char tabela_pagamento1()
{		
		printf("\n \t .______________________________.\n");
		printf("\t |      Forma de Pagamento      |\n");
		printf("\t |______________________________|\n");
		printf("\t |   %s   |\n", pagamento1); 
		printf("\t |______________________________|\n"); 
		
			tabela_final();
		
				printf("\n\n\t Digite o número do cartão (16 dígitos): ");
			
					scanf("%s", &cartao);
					
						if(cartao[16] != tamanho)
						{
							printf("\n\n\t Cartão inválido!");
							
								printf("\n\n\t Pressione qualquer tecla...");
								
									getch();
								
										setbuf(stdin, NULL);
														
											system("cls");
											
												tabela_pagamento();
						}
						else
						{	
							for(i=0; i<=strlen(cartao); i++)
							{
								if(cartao[i] <= 47 || cartao[i] >= 58 && cartao[i] != 48)
								{																					
										printf("\n\n\t Cartão inválido!");
										
											printf("\n\n\t Pressione qualquer tecla...");
										
												getch();
										
													setbuf(stdin, NULL);
														
														system("cls");
											
															tabela_pagamento();																			
								}
								else
								{
									if(i == 15)
									{
										numero_pedido();
								
											printf("\n\n\n\t Pedido de número #%i pago com ", pedido_numero);
											textcolor(5);
											printf("CARTÃO DE CRÉDITO/DÉBITO");
											textcolor(15);
										
												printf("\n\n\t Pressione qualquer tecla...");
									
													getch();
														
														system("cls");
																											
															agradecimento();	
									}
								}
							}
								
															
						}
}

char tabela_pagamento2()
{
	do
	{
		printf("\n \t .________________________.\n");
		printf("\t |   Forma de Pagamento   |\n");
		printf("\t |________________________|\n");
		printf("\t |         %s         |\n", pagamento2); 
		printf("\t |________________________|\n");
		
			tabela_final();
		
				printf("\n\n\t Confirmar -> 1");
				printf("  \n\n\t Escolher outro método de pagamento -> 2");
				printf("  \n\n\t Resposta: ");
				
					scanf("%i", &resposta);
					
						if(resposta == 1)
						{
							numero_pedido();
								
								printf("\n\n\n\t Pedido de número #%i pago com ", pedido_numero);
								textcolor(9);
								printf("CHEQUE");
								textcolor(15);
													
									printf("\n\n\t Pressione qualquer tecla..."); 
																
										getch();
																
												system("cls");
												
													agradecimento();
						}
						else
						{	
							if(resposta == 2)
							{
								system("cls");
								
									tabela_pagamento();
							}		
						}
											
							system("cls");
							
	} while (resposta <=0 || resposta >=3);
}

char tabela_pagamento3()
{
		printf("\n \t .________________________.\n");
		printf("\t |   Forma de Pagamento   |\n");
		printf("\t |________________________|\n");		
		printf("\t |        %s        |\n", pagamento3); 
		printf("\t |________________________|\n");
		
			tabela_final();
				
				printf("\n\n\t Quanto será pago: R$ ");
					
					scanf("%f", &pago);
					
						if (pago <= 0)
						{
							pago = pago * (-1);
						}
			
						troco = pago - preco_total;
			
							if (troco == 0.00 || troco >= 0.00)
							{
								printf("\n\t Troco: R$ %.2f", troco);
								
									numero_pedido();
								
										printf("\n\n\n\t Pedido de número #%i pago com ", pedido_numero);
										textcolor(10);
										printf("DINHEIRO");
										textcolor(15);
																		
											printf("\n\n\t Pressione qualquer tecla..."); 
											
												getch();
											
													system("cls");
																																	
														agradecimento();
							}
							else
							{
								falta = troco * (-1);
								
									printf("\n\t Valor pago insuficiente. Adicione R$ %.2f para completar o valor.", falta);
									
										printf("\n\n\t Pressione qualquer tecla...");
										
											getch();
										
												setbuf(stdin, NULL);
											
													system("cls");
																																			
														tabela_pagamento();
							}	
	return(0);
}

int agradecimento()
{
	printf("\n\n\t\t\t Seu pedido está sendo preparado!");
	printf("\n\n\t\t\t O Drive Thru do Mickey & Donalds agradece a preferência :) \n\n\n\n");
	
		comanda();
			
			registro();
			
				exit(0);
}

int comanda()
{
	FILE *file;
	file = fopen ("Comanda.txt", "a+");
	
	if(pedido_numero <= 10)
	{
		fprintf(file,"\n\t.______________.\n");
		fprintf(file,"\t|  Pedido #%i   |\n", pedido_numero);
		fprintf(file,"\t|______________|");
	}
	else
	{
		if(pedido_numero <= 100)
		{
			fprintf(file,"\n\t.______________.\n");
			fprintf(file,"\t| Pedido #%i   |\n", pedido_numero);
			fprintf(file,"\t|______________|");
		}
		else
		{
			if(pedido_numero <= 1000)
			{
				fprintf(file,"\n\t.______________.\n");
				fprintf(file,"\t| Pedido #%i  |\n", pedido_numero);
				fprintf(file,"\t|______________|");
			}
			else
			{
				if(pedido_numero <= 10000)
				{
					fprintf(file,"\n\t.______________.\n");
					fprintf(file,"\t| Pedido #%i |\n", pedido_numero);
					fprintf(file,"\t|______________|");
				}
			}
		}
	}
	
	fprintf(file, "__________________________________________.\n");
	fprintf(file, "\t| Código |          Combo             | Quantidade Pedida |\n");
	fprintf(file, "\t|________|____________________________|___________________|\n"); 
	
		if (total_combo1 != 0.0)
		{
			if(quantidade_combo1 <= 10)
			{
				fprintf(file, "\t|    %i   |   %s   |         %i         |\n", code_combo1, combo1, quantidade_combo1); 
				fprintf(file, "\t|________|____________________________|___________________|\n"); 
			}
			else
			{
				if(quantidade_combo1 <=100)
				{
					fprintf(file, "\t|    %i   |   %s   |         %i        |\n", code_combo1, combo1, quantidade_combo1); 
					fprintf(file, "\t|________|____________________________|___________________|\n"); 
				}
				else
				{
					fprintf(file, "\t|    %i   |   %s   |        %i        |\n", code_combo1, combo1, quantidade_combo1); 
					fprintf(file, "\t|________|____________________________|___________________|\n"); 
				}
			}
		}	
			if (total_combo2 != 0.0)
			{
				if(quantidade_combo2 <= 10)
				{
					fprintf(file, "\t|    %i   |  %s  |         %i         |\n", code_combo2, combo2, quantidade_combo2); 
					fprintf(file, "\t|________|____________________________|___________________|\n"); 
				}
				else
				{
					if(quantidade_combo2 <=100)
					{
						fprintf(file, "\t|    %i   |  %s  |         %i        |\n", code_combo2, combo2, quantidade_combo2); 
						fprintf(file, "\t|________|____________________________|___________________|\n"); 
					}
					else
					{
						fprintf(file, "\t|    %i   |  %s  |        %i        |\n", code_combo2, combo2, quantidade_combo2); 
						fprintf(file, "\t|________|____________________________|___________________|\n"); 
					}
				}
			}	
				if (total_combo3 != 0.0)
				{	
					if(quantidade_combo3 <= 10)
					{
						fprintf(file, "\t|    %i   |     %s     |         %i         |\n", code_combo3, combo3, quantidade_combo3); 
						fprintf(file, "\t|________|____________________________|___________________|\n"); 
					}
					else
					{
						if(quantidade_combo3 <=100)
						{
							fprintf(file, "\t|    %i   |     %s     |         %i        |\n", code_combo3, combo3, quantidade_combo3); 
							fprintf(file, "\t|________|____________________________|___________________|\n"); 	
						}
						else
						{
							fprintf(file, "\t|    %i   |     %s     |        %i        |\n", code_combo3, combo3, quantidade_combo3); 
							fprintf(file, "\t|________|____________________________|___________________|\n"); 		
						}						
					}
				}	
		
	fclose(file);
	return(0);
}

int registro()
{
	FILE *file;
	file = fopen ("Registro.txt", "a+");
	
	tamanho = strlen(cartao);
	
		if(pedido_numero <= 10)
	{
		fprintf(file,"\n\t.______________.\n");
		fprintf(file,"\t|  Pedido #%i   |\n", pedido_numero);
		fprintf(file,"\t|______________|");
	}
	else
	{
		if(pedido_numero <= 100)
		{
			fprintf(file,"\n\t.______________.\n");
			fprintf(file,"\t| Pedido #%i   |\n", pedido_numero);
			fprintf(file,"\t|______________|");
		}
		else
		{
			if(pedido_numero <= 1000)
			{
				fprintf(file,"\n\t.______________.\n");
				fprintf(file,"\t| Pedido #%i  |\n", pedido_numero);
				fprintf(file,"\t|______________|");
			}
			else
			{
				if(pedido_numero <= 10000)
				{
					fprintf(file,"\n\t.______________.\n");
					fprintf(file,"\t| Pedido #%i |\n", pedido_numero);
					fprintf(file,"\t|______________|");
				}
			}
		}
	}
		fprintf(file,"____________________________________________________________________________________.\n");
		fprintf(file,"\t| Código |          Combos          |   Preço Unitário   | Quantidade Pedida | Valor do Item Pedido |\n");
		fprintf(file,"\t|________|__________________________|____________________|___________________|______________________|\n"); 
		
		if(total_combo1 != 0.0)
		{
			if(total_combo1 <= 100 && quantidade_combo1 <= 10)
			{			
				fprintf(file,"\t|    %i   |  %s  |      R$ %.2f      |         %i         |       R$ %.2f       |\n", code_combo1, combo1, preco_combo1, quantidade_combo1, total_combo1); 
				fprintf(file,"\t|________|__________________________|____________________|___________________|______________________|\n"); 
			}
			
				if(total_combo1 <= 100 && quantidade_combo1 >= 10)
				{			
					fprintf(file,"\t|    %i   |  %s  |      R$ %.2f      |         %i        |       R$ %.2f       |\n", code_combo1, combo1, preco_combo1, quantidade_combo1, total_combo1); 
					fprintf(file,"\t|________|__________________________|____________________|___________________|______________________|\n"); 
				}
				
					if(total_combo1 >= 100 && quantidade_combo1 <= 10)
					{			
						fprintf(file,"\t|    %i   |  %s  |      R$ %.2f      |         %i         |       R$ %.2f      |\n", code_combo1, combo1, preco_combo1, quantidade_combo1, total_combo1); 
						fprintf(file,"\t|________|__________________________|____________________|___________________|______________________|\n"); 
					}
			
						if(total_combo1 >= 100 && quantidade_combo1 >= 10)
						{			
							fprintf(file,"\t|    %i   |  %s  |      R$ %.2f      |         %i        |       R$ %.2f      |\n", code_combo1, combo1, preco_combo1, quantidade_combo1, total_combo1); 
							fprintf(file,"\t|________|__________________________|____________________|___________________|______________________|\n"); 
						}
		}
		
		if(total_combo2 != 0.0)
		{
			if(total_combo2 <= 100 && quantidade_combo2 <= 10)
			{
				fprintf(file,"\t|    %i   | %s |      R$ %.2f      |         %i         |       R$ %.2f       |\n", code_combo2, combo2, preco_combo2, quantidade_combo2, total_combo2); 
				fprintf(file,"\t|________|__________________________|____________________|___________________|______________________|\n"); 
			}
				
				if(total_combo2 <= 100 && quantidade_combo2 >= 10)
				{
					fprintf(file,"\t|    %i   | %s |      R$ %.2f      |         %i         |       R$ %.2f       |\n", code_combo2, combo2, preco_combo2, quantidade_combo2, total_combo2); 
					fprintf(file,"\t|________|__________________________|____________________|___________________|______________________|\n"); 
				}
					
					if(total_combo2 >= 100 && quantidade_combo2 <= 10)
					{
						fprintf(file,"\t|    %i   | %s |      R$ %.2f      |         %i         |       R$ %.2f      |\n", code_combo2, combo2, preco_combo2, quantidade_combo2, total_combo2); 
						fprintf(file,"\t|________|__________________________|____________________|___________________|______________________|\n"); 
					}
					
						if(total_combo2 >= 100 && quantidade_combo2 >= 10)
						{
							fprintf(file,"\t|    %i   | %s |      R$ %.2f      |         %i        |       R$ %.2f      |\n", code_combo2, combo2, preco_combo2, quantidade_combo2, total_combo2); 
							fprintf(file,"\t|________|__________________________|____________________|___________________|______________________|\n"); 
						}
		}
			
		if(total_combo3 != 0.0)
		{
			if(total_combo3 <= 100 && quantidade_combo3 <= 10)
			{
				fprintf(file,"\t|    %i   |    %s    |      R$ %.2f      |         %i         |       R$ %.2f       |\n", code_combo3, combo3, preco_combo3, quantidade_combo3, total_combo3); 
				fprintf(file,"\t|________|__________________________|____________________|___________________|______________________|\n"); 
			}
					
				if(total_combo3 <= 100 && quantidade_combo3 >= 10)
				{
					fprintf(file,"\t|    %i   |    %s    |      R$ %.2f      |         %i         |       R$ %.2f       |\n", code_combo3, combo3, preco_combo3, quantidade_combo3, total_combo3); 
					fprintf(file,"\t|________|__________________________|____________________|___________________|______________________|\n"); 
				}
						
					if(total_combo3 >= 100 && quantidade_combo3 <= 10)
					{
						fprintf(file,"\t|    %i   |    %s    |      R$ %.2f      |         %i         |       R$ %.2f      |\n", code_combo3, combo3, preco_combo3, quantidade_combo3, total_combo3); 
						fprintf(file,"\t|________|__________________________|____________________|___________________|______________________|\n"); 
					}
							
						if(total_combo3 >= 100 && quantidade_combo3 >= 10)
						{
							fprintf(file,"\t|    %i   |    %s    |      R$ %.2f      |         %i        |       R$ %.2f      |\n", code_combo3, combo3, preco_combo3, quantidade_combo3, total_combo3); 
							fprintf(file,"\t|________|__________________________|____________________|___________________|______________________|\n"); 
						}
		}
		
		if (preco_total <= 100.00)
		{	
			fprintf(file,"\t|                                                           Total da Compra  |       R$ %.2f       |\n", preco_total); 
			fprintf(file,"\t|____________________________________________________________________________|______________________|\n");
		}
		else
		{
			fprintf(file,"\t|                                                           Total da Compra  |       R$ %.2f      |\n", preco_total); 
			fprintf(file,"\t|____________________________________________________________________________|______________________|\n");
		}
		
		switch (escolha_pagamento)
		{
			case 1: fprintf(file,"\t|                                                    Forma de pagamento  | %s |\n", pagamento1); 
					fprintf(file,"\t|________________________________________________________________________|__________________________|\n"); 
					fprintf(file,"\t|                                                          Número do cartão  |   ");
					
						   for(i=0; i<=strlen(cartao); i++)
							{
								if(i>=4 && i<=11)
								{
									fprintf(file,"*");
								}
								else
								{
									fprintf(file,"%c", cartao[i]);
								}
							}  
					
					fprintf(file," |\n"); 
					fprintf(file,"\t|____________________________________________________________________________|______________________|\n");	
				break;
				
			case 2: fprintf(file,"\t|                                                        Forma de pagamento  |        %s        |\n", pagamento2); 
					fprintf(file,"\t|____________________________________________________________________________|______________________|\n"); 						 
				break;
			
			case 3: fprintf(file,"\t|                                                        Forma de pagamento  |       %s       |\n", pagamento3); 
					fprintf(file,"\t|____________________________________________________________________________|______________________|\n"); 	
				break;					
		} 
		
		if(escolha_pagamento == 3)
		{
			if (pago <= 100.00)
			{
				fprintf(file,"\t|                                                                Valor pago  |       R$ %.2f       |\n", pago); 
				fprintf(file,"\t|____________________________________________________________________________|______________________|\n"); 
			}
			else
			{
				fprintf(file,"\t|                                                                Valor pago  |       R$ %.2f      |\n", pago); 
				fprintf(file,"\t|____________________________________________________________________________|______________________|\n"); 
			}
			
			if(troco <= 100.00 && troco >= 10.00)
			{
				fprintf(file,"\t|                                                                     Troco  |       R$ %.2f       |\n", troco); 
				fprintf(file,"\t|____________________________________________________________________________|______________________|\n"); 
			}
			else
			{
				if(troco <= 10.00)
				{
					fprintf(file,"\t|                                                                     Troco  |       R$ %.2f        |\n", troco); 
					fprintf(file,"\t|____________________________________________________________________________|______________________|\n"); 
				}
				else
				{
					fprintf(file,"\t|                                                                     Troco  |       R$ %.2f      |\n", troco); 
					fprintf(file,"\t|____________________________________________________________________________|______________________|\n"); 
				}
			}
		}
				
	fclose(file);
	return 0;
}
