#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

//#define SENHA 12345	->	int

void alarme(void) 
{	int f = 0;
	
	for(f=100; f<=5000; f+=20) 
	{	Beep(3500, 1000);
		Sleep(10);
	}
} 

int main()
{	setlocale (LC_ALL, "");

	int indice = 0, i;
	char senha[5], verifica, SENHA[]="12345";

    for (i = 0; i < 5; i++)
    {
        indice = i;
        if (i == 0)
        {	printf ("Informe a senha de 5 digitos: ");		}
        if (i == 1)
        {	printf ("Informe a senha de 5 digitos: *");		}
        if (i == 2)
        {	printf ("Informe a senha de 5 digitos: **");		}
        if (i == 3)
        {	printf ("Informe a senha de 5 digitos: ***");		}
        if (i == 4)
        {	printf ("Informe a senha de 5 digitos: ****");		}
     
        verifica = getch();

        if (verifica == 13)
        	break;
        else
        	senha[i] = verifica;

        system("CLS");
    }

    printf ("\nSenha Digitada: ");

    for (i = 0; i <= indice; i++)
    	printf ("%c", senha[i]);
    
    printf ("\n\n");
    
    if (strcmp(senha, SENHA)!=0)
	{	printf ("\nSenha inválida!");
		alarme();
	}
	else
		printf ("\nSenha Ok!");
    
    getchar();
    return 0;
}
