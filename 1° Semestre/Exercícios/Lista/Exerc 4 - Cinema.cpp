#include<stdio.h>
#include<conio.h>

int main () {
	
	int matriz[15][10] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	int Lin, Col, Val;
	int Inteiro =0;
	int Meio =0;
	int Valor=0;
	int IngressosVendidos;
	int resp;

	do
	{ 
    	printf ("Escolha a linha da cadeira: ");
    	scanf ("%d", &Lin);
	
  		printf ("Escolha a coluna da cadeira: ");
    	scanf ("%d", &Col);  
	
    	printf ("Digite 1 para ingresso inteiro ou 2 para meia entrada: ");
    	scanf ("%d", &Val);
    	
    	printf ("\n\nVoce selecionou a linha %d , a coluna %d e o ingresso %d ? \n", Lin, Col, Val);
    	
    	matriz[Lin][Col] = Val;
    	
    	if (Val== 1)
    		{ Inteiro +=1;
    		matriz[Lin][Col] = 1;
			}
		else
			{ Meio +=1;
			matriz[Lin][Col] = 2;
			}
   		
   		printf ("\n \n \n\t\t Digite 1 para continuar ou 2 para sair \n");
   		scanf ("%d", &resp);
 	}
 	while (resp==1);
	
	printf ("\n \n \n Quantidade de ingressos inteiros: %d \n", Inteiro);
	printf ("\n Quantidade de meia entrada: %d \n", Meio);
	
	IngressosVendidos = Inteiro + Meio;
	printf ("\n Quantidade de ingressos vendidos: %d \n", IngressosVendidos);
	
	float ValorTotalInteiro = Inteiro*15;
	float ValorTotalMeio = Meio*7.5;
	
	printf ("\n Valor total de ingressos inteiros: %f \n", ValorTotalInteiro);
	printf ("\n Valor total de ingressos meio: %f \n", ValorTotalMeio);


	getch ();
}
