#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Naokinho (void);
void Luninha (void);
void Luninha_Naokinho (void);

int opcao;
//-------------------------------------------------------------------------------------------------------------------------------//
int main ()
{
    setlocale(LC_ALL,"Portuguese");
    printf ("\n Naokinho ou Luninha? \n");
    printf ("\n 7789. Naokinho? \n");
    printf ("\n 1933. Luninha? \n");
    printf ("\n 2000. Luninha e Naokinho? \n");

    printf("\n \t O que deseja, amigo? \n \t");
    scanf("%d",&opcao);
//----------------------------------------------------------------------------------------------------------------------------------//
	switch(opcao) 
	{
		case 7789:
	       	system("cls");
	       	printf("\t Olha o Naokinhooooooo \n");
	       	printf ("\n \n");
	       	Naokinho();
	    	break;		
		
		case 1933:
	       	system("cls");
	       	printf("\t Olha a Luninha, genteeeeeeeeeeee \n");
	       	printf ("\n \n");
	       	Luninha();
	    	break;		
	    	
	    case 2000:
	       	system("cls");
	       	printf("\t Olha a Luninha eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee o Naokinhooo <3 \n");
	       	printf ("\n \n");
	       	Luninha_Naokinho();
	    	break;
	}
	getchar();
	return 0; 
}
 
void Naokinho(void)
{	printf("Escolheu a opção %d aaaaaaaaaaaaaaaaaaaaaaaaaa \n",opcao);
	printf("\n O Naoki é lindooooooooo \n");	}

void Luninha (void)
{	printf("Escolheu  a opção %d aaaaaaaaaaaaaaaaaaaaaaaa \n",opcao);
	printf("\n A Luninha é lindaaaaaaaaaaa \n");	}

void Luninha_Naokinho (void)
{	printf ("Escolheu a opção %d aaaaaaaaaaaaaaaaaaaaaa \n", opcao);
	printf ("\n O Naokinho é lindo, e a Luninha também \n");	}
