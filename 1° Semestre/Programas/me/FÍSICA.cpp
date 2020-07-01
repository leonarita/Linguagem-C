//Programa de auxilio de fisica

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int opcao1, opcao2, opcao3, resp;
//---------------------------------------------

int main () 
{
 
	printf("\n \t \t Topicos da Fisica disponiveis: \n");
	printf("\n 1. Mecanica \n");
    printf("\n 2. Termologia \n");
    printf("\n 3. Eletrica \n");
    printf("\n 4. Optica \n");
    printf("\n 5. Ondulatoria \n");    
	printf("\n 6. Fisica Moderna \n");
		
	printf("\n \n \n Digite o conteudo a ser abordado: \t");
    scanf("%d", &opcao1);
    	
    if(opcao1<1 || opcao1>6)
	   	printf("\n \n \n \n \n Codigo invalido. Tente Novamente! \n \n");
    
    switch(opcao1) 
  
	{
		case 1:
			system("cls");
	       	printf("\t \t MECANICA \n");
	    	   	
    	   	printf ("\n A Mecanica e o ramo da fisica que estuda os movimentos. \n");
	       	
			printf("\n Divisoes da Mecanica: \n");
  	   	 	printf("\n 10. Cinematica \n");
   			printf("\n 20. Dinamica \n");
			printf("\n 30. Estatica \n");
  				
  			printf ("\n \n \n Digite a divisao desejada: \t");
 			scanf ("%d", &opcao2);
  			
  			switch(opcao2)
  				
  			{
				case 10:
					system("cls");
		      		printf("\t \t CINEMATICA \n");
	
			       	printf ("\n A Cinematica e o campo que descreve os movimentos. \n");
	       	
					printf("\n Divisoes da Mecanica: \n");
		      		printf("\n 100. Movimento Uniforme (MU) \n");
    				printf("\n 200. Movimento Uniformemente Variado (MUV) \n");
  					printf("\n 300. Queda Livre \n");
  	   		 		printf("\n 400. Lancamento Vertical \n");
   					printf("\n 500. Lancamento Horizontal \n");
  					printf("\n 600. Lancamento Obliquo \n");
  					printf("\n 700. Movimento Circular Uniforme (MCU) \n");  		
			  
					printf ("\n \n \n Digite o assunto a ser trabalhado: \t");
	  				scanf ("%d", &opcao3);		
	  				
	  				int a, vf, vi, Sf, Si, tf, ti;
  					
  					switch(opcao3)
  					
  					{
  						case 100:
  							system("cls");
  							printf("\t \t MOVIMENTO UNIFORME (MU) \n");
  						 							
	  						printf ("\n O movimento uniforme analisa os movimentos cuja velocidade e constante. \n");
 							printf ("\n Formula principal: v = (S-S0)/(t-t0) \n");
 							printf ("\n Formula derivada da formula acima, considerando o tempo inicial zero: S = S0 + v*t \n");
  						
  							printf ("\n \n \n \n \n Faca voce mesmo um teste escolhendo os valores! \n");
  						
  							printf ("\n Insira a velocidade: ");
  							scanf ("%d", &vf);
  							
  							printf ("\n Insira a posicao inicial: ");
  							scanf ("%d", &Si);  							
							printf ("\n Insira o tempo final: ");
  							scanf ("%d", &tf);
  						
  							Sf = Si + vf*tf;
  						
  							printf ("\n A posicao final e %d \n", Sf);  						
  							system ("pause");
  							break;
  				
  						case 200:				
						    system("cls");
  							printf("\t \t MOVIMENTO UNIFORMEMENTE VARIADO (MUV) \n");
 							
	  						printf ("\n O movimento uniformemente variado analisa os movimentos cuja aceleracao e constante, ou seja, sofre variacoes de velocidade. \n");
 							printf ("\n Formula principal: a = (v-v0)/(t-t0) \n");
 							printf ("\n Formula derivada da formula acima, considerando o tempo inicial zero: v = v0 + a*t \n");
  						
  							printf ("\n \n \n \n \n Faca voce mesmo um teste escolhendo os valores! \n");
  						
  							printf ("\n Insira a aceleracao: ");
  							scanf ("%d", &a);
  							
  							printf ("\n Insira a velocidade inicial: ");
  							scanf ("%d", &vi);  							
							printf ("\n Insira o tempo final: ");
  							scanf ("%d", &tf);
  							
  							vf = vi + a*tf;
  						
  							printf ("\n A velocidade final e %d \n", vf);  						
  							system ("pause");
  							
  							printf ("\n \n \n \n");
  							
  							printf ("\n Provenientes desse conceito, surgiram mais duas formulas que auxiliam o estudo do MUV:");
  							printf ("\n Equacao horaria do espaco: Sf = Si + vi*t + (a*t*t)/2");
  							printf ("\n Equacao de Torricelli: vf*vf = vi*vi + 2*a*(Sf-Si)");
  							
  							printf ("\n \n \n \n");
  							
  							printf ("\n Deseja testar a Equacao horaria do espaco?");
  							printf ("\n \t 1- Sim");
  							printf ("\n \t 2- Nao");
  							printf ("\n \n \n Resposta: ");
  							scanf ("%d", &resp);
  							
  							printf ("\n \n \n \n");
  							
  							if (resp==1)
  								{	printf ("\n Insira a aceleracao: ");
  									scanf ("%d", &a);							
  									printf ("\n Insira a velocidade inicial: ");
  									scanf ("%d", &vi);  	
									printf ("\n Insira o espaco inicial: ");
  									scanf ("%d", &Si);						
									printf ("\n Insira o tempo final: ");
  									scanf ("%d", &tf);
  									
  									Sf = Si + vi*tf + (a*tf*tf)/2;
  									
  									printf ("\n O espaco final e: %d \n \n ", Sf);
  									
  									system ("pause");
  								}
  							break;
	
  						case 300:
 							system("cls");
 							printf("\t \t QUEDA LIVRE \n");
  							system ("pause");
  							break;
  					
		  				case 400:
							system("cls");
  							printf("\t \t LANCAMENTO VERTICAL \n");  					
  							system ("pause");
  							break;

  						case 500:
							system("cls");
  							printf("\t \t LANCAMENTO HORIZONTAL \n");
  							system ("pause");
  							break;

  						case 600:
							system("cls");
  							printf("\t \t LANCAMENTO OBLIQUO \n");
  							system ("pause");
  							break;
  					
  						case 700:
							system("cls");
  							printf("\t \t MOVIMENTO CIRCULAR UNIFORME (MCU) \n"); 
  							system ("pause");
  							break;
	      			}
	       				
		       	case 20:
					system("cls");
	    	   		printf("\t \t DINAMICA \n");
	       			break;
	       		
      	 		case 30:
					system("cls");
	      			printf("\t \t MECANICA \n");
  					break;
					}
			break;
				
		case 2:
			system("cls");
       		printf("\t \t TERMOLOGIA \n");
			break;
	       	
		case 3:
		 	system("cls");
     		printf("\t \t ELETRICA \n");
    	 	break;
		 
		case 4:
			system("cls");
	   		printf("\t \t OPTICA \n");
	   		break;
	      	
		case 5:
	 		system("cls");
  	   		printf("\t \t ONDULATORIA \n");
  	   		break;
		
		case 6:
			system("cls");
     		printf("\t \t FISICA MODERNA \n");
	      	break;
	       	
	}
		    
	
	getch();
}
