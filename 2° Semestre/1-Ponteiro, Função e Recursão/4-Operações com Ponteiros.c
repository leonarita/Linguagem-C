#include<stdio.h>
#include<string.h>
#include<locale.h>

void incremento ()
{	//Um ponteiro para o tipo xyz avança sempre sizeof(xyz) bytes por unidade de incremento
	
	int x=5, *px=&x;
	float y=5.0, *py=&y;
	
	printf ("int x = 5, *px = &x;\nfloat y = 5.0, *py = &y;\n\n");
	
	printf ("\tx = %d \t\t(long) px = %ld \n", x, (long)px);
	printf ("\tx+1 = %d \t(long) (px+1) = %ld \n\n", x+1, (long) (px+1));	//O ponteiro desloca 4 bytes (1 int)
	
	printf ("\ty = %f \t(long) py = %ld \n", y, (long)py);
	printf ("\ty+1 = %f \t(long) (py+1) = %ld \n", y+1, (long) (py+1));		//O ponteiro desloca 4 bytes (1 int)
	
	int *ptr;
	ptr++;
	ptr = ptr + 2;
	ptr += 4;		//Se ptr apontar para um float, avança 4*4 = 16 bytes
}


void decremento ()
{	//Um ponteiro para o tipo xyz recua sempre sizeof(xyz) bytes por unidade de incremento

	char s[100];
	char *ptr = s;	//Aponta para o primeiro caractere de s

	printf ("Introduza uma string: ");
	gets (s);
	fflush (stdin);
	
	if (*ptr=='\0')	//Se a string estiver vazia
		return;		//Retorne 0
	
	//Imprimir a string normalmente
	printf ("\n\t");
	while (*ptr!='\0')
		putchar (*ptr++);
	
	//Imprimir a mensagem ao contrário
	printf ("\n\t");
	ptr--;	//Por causa do '/0'
	
	while (ptr>=s)
		putchar (*ptr--);
}


int string_length (char *s)
{	char *ptr = s;

	while (*s!='\0')
		s++;
	
	return (int) (s - ptr);
}


void diferenca ()
{	//A diferença entre dois ponteiros para elementos do mesmo tipo permite saber quantos elementos há entre um endereço e outro

	char s[100];
	char *ptr = s;	//Aponta para o primeiro caractere de s

	printf ("Introduza uma string: ");
	gets (s);
	fflush (stdin);
	printf ("\n\t%d\n", string_length(s));
}

void teste ()
{	printf ("\n\nchar s[20]='Ola'; \n\n\tResponda se as seguinte operações são válidas:\n");
	printf ("\n\n\t\ts='Ole';");
	sleep (2);
	printf ("\t//Erro de compilação: Devia usar strcpy");
	sleep (1);
	printf ("\n\n\t\ts++;");
	sleep (2);
	printf ("\t\t//Erro: Não podemos alterar o s");
	sleep (1);
	printf ("\n\n\t\ts+1;");
	sleep (2);
	printf ("\t\t//Ok: Não estamos alterando o s");
	sleep (1);
	printf ("\n\n\t\t*s;");
	sleep (2);
	printf ("\t\t//Ok");
	sleep (1);
	printf ("\n\n\t\ts=s-2;");
	sleep (2);
	printf ("\t\t//Erro: Não podemos alterar o s");
	sleep (1);
	printf ("\n\n\t\ts>s-2;");
	sleep (2);
	printf ("\t\t//Ok");
	sleep (1);
	printf ("\n\n\t\ts+1-s;");
	sleep (2);
	printf ("\t\t//Ok");
	sleep (1);
	printf ("\n\n");
}

int main ()
{	setlocale (LC_ALL, "");
	int op;
	printf ("Considere as opções abaixo: \n\t 1- Incremento \n\t 2- Decremento \n\t 3- Diferença \n\t10- Teste \n\nQual você deseja escolher? ");
	scanf ("%d", &op);
	printf ("\n\n\n");
	fflush (stdin);
	
	switch (op)
	{
		case 1:
			incremento();
			break;
		case 2:
			decremento();
			break;
		case 3:
			diferenca();
			break;
		case 10:
			teste();
			break;
	}
}
