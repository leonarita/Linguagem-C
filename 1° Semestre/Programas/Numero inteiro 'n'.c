#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>

//O numero n elevado ao quadrado � a soma dos n primeiros numeros impares
//2 ao quadrado = 		1 + 3 	= 4
//3 ao quadrado = 	1 + 3 + 5   = 9
//4 ao quadrado = 1 + 3 + 5 + 7 = 16

#define PI 3.14159265

int main (void)
{	setlocale (LC_ALL, "");
	int num, potencia, i, impar=1, resp=1, b, cifra1, cifra2, c, d;
	
	printf ("Digite o n�mero inteiro: ");
	scanf ("%d", &num);

	double x= (double) num;	//Casting: usa um tipo de vari�vel entre parenteses na frente da opera��o para adaptar o resultado ao esperado
	
	if (num>0)
	{	for (i=1; i<=num; i++)
		{	potencia+=impar;
			impar=impar+2;	}	}
	else if (num<0)
	{	for (i=-1; num<=i; i--)
		{	potencia+=impar;
			impar=impar+2;	}	}
	else if (num==0)
		potencia=0;
		
	//Pr� e p�s Incremento : ++i	=	i++
	//Pr� e p�s Decremento : --i	=	i--
		
	if (potencia!=num*num)
	{	printf ("\n\n\t\tERROR 404");
		return 0;	}
		
	printf ("\nCalculando N�mero ao Quadrado...");
	printf ("\n\t%d ao quadrado = %d", num, potencia);
	
	printf ("\n\nVerificando se a potencia e o n�mero s�o pares ou �mpares");	//Operador resto %
	if (num%2==0)
		printf ("\n\t%d : numero par.", num);
	else
		printf ("\n\t%d : numero �mpar.", num);
		
	if (potencia%2==0)
		printf ("\n\t%d : numero par.", potencia);
	else
		printf ("\n\t%d : numero �mpar.", potencia);
		
	printf ("\n\nOperacoes Aritmeticas Basicas entre potencia e n�mero");
	printf ("\n\tpotencia + n�mero = %d + %d = %d", potencia, num, potencia+num);
	printf ("\n\tpotencia - n�mero = %d - %d = %d", potencia, num, potencia-num);
	printf ("\n\tpotencia * n�mero = %d * %d = %d", potencia, num, potencia*num);
	if (num==0)
		printf ("\n\tpotencia / n�mero = 0 / 0 = Indeterminado");
	else
		printf ("\n\tpotencia / n�mero = %d / %d = %d", potencia, num, potencia/num);
		
	printf ("\n\nRela��o as opera��es b�sicas");
	potencia+num > potencia-num ?	printf ("\n\tSoma > Subtra��o") 	   	 :  printf ("\n\tSubtra��o > Soma");
	potencia+num > potencia*num ?	printf ("\n\tSoma > Multiplica��o")		 :  printf ("\n\tMultiplica��o > Soma");
	if (num!=0)
		potencia+num > potencia/num ?	printf ("\n\tSoma > Divis�o") 			 :  printf ("\n\tDivis�o > Soma");
	potencia-num > potencia*num ?	printf ("\n\tSubtra��o > Multiplica��o") :  printf ("\n\tMultiplica��o > Subtra��o");
	if (num!=0)
	{	potencia-num > potencia/num ?	printf ("\n\tSubtra��o > Divis�o") 		 :  printf ("\n\tDivis�o > Subtra��o");
		potencia*num > potencia/num ?	printf ("\n\tMultiplica��o > Divis�o")	 :  printf ("\n\tDivis�o > Multiplica��o");	}
	//Tal condi��o � verdadeira?	Caso seja verdadeira, fa�a...	ou	 Caso seja falsa, fa�a...
	//� poss�vel atribuir valores tamb�m para indicar a veracidade da condi��o

	printf ("\n\nCalculando n�mero fatorial");
	if (num>0)
	{	for (b=num; b>=1; --b)
			resp*=b;
		printf ("\n\tN�mero fatorial = %d! = %d", num, resp);	}
	else if (num==0)
		printf ("\n\tN�mero fatorial = 0! = 1");
	else
		printf ("\n\tErro: Fatorial de n�mero negativo � indefinido...");
	printf ("\nObs: Fatorial � definido apenas para n�meros posivos e zero.");
	
	printf ("\n\nInvertendo o n�mero e a pot�ncia");
	printf ("\n\tN�mero invertido: ");
	c=num;
	if (c<0)
		c=c*(-1);
	if (num<0)
		printf ("-");
	while (c!=0)
	{	cifra1=c%10;
		printf ("%i", cifra1);
		c/=10;	}
	printf ("\n\tPot�ncia invertida: ");
	d=potencia;
	while (d!=0)
	{	cifra2=d%10;
		printf ("%i", cifra2);
		d/=10;
	}
		
	//Usando a biblioteca math.h
	printf("\n\nFun��es Trigonom�tricas");
    double seno, cosseno, tangente;
	seno = sin(x*PI/180);
	cosseno = cos(x*PI/180);
	tangente = tan(x*PI/180);
	printf("\n\tValor de seno de %.0f� = %.2lf", x, seno);
	printf("\n\tValor de cosseno de %.0f� = %.2lf", x, cosseno);
	printf("\n\tValor de tangente de %.0f� = %.2lf", x, tangente);
	
	//Usando a biblioteca math.h
	printf("\n\nFun��es Trigonom�tricas Inversas");
    double arcoseno, arcocosseno, arcotangente;
	arcoseno = asin(x*180/PI);
	arcocosseno = acos(x*180/PI);
	arcotangente = atan(x*180/PI);
	printf("\n\tValor de arcoseno de %.0f� = %.2lf", x, arcoseno);
	printf("\n\tValor de arcocosseno de %.0f� = %.2lf", x, arcocosseno);
	printf("\n\tValor de arcotangente de %.0f� = %.2lf", x, arcotangente);
	
	//Usando a biblioteca math.h
	printf("\n\nFun��es Exponenciais");
	double exponencialx, exponencial2, exponenciale;
	exponencialx = exp(x);
	printf("\n\tValor exponencial de %.0f = %.2lf", x, exponencialx);
	exponencial2 = exp2(x);
	printf("\n\tValor exponencial de 2 elevado a %.0f = %.2lf", x, exponencial2);
	exponenciale = expm1(x);
	printf("\n\tValor exponencial de e elevado a %.0f = %.2lf", x, exponenciale);

	//Usando a biblioteca math.h
	printf("\n\nFun��es Logar�tmicas");
	double logaritmo_natural, logaritmo_base10, logaritmo_natural2, logaritmo_binario;
	logaritmo_natural = log(x);
	printf("\n\tLogaritmo natural de %.0f = %.2lf", x, logaritmo_natural);
	logaritmo_base10 = log10(x);
	printf("\n\tLogaritmo de %.2f na base 10 = %.2lf", x, logaritmo_base10);
	logaritmo_binario = log2(x);
	printf("\n\tLogaritmo bin�rio de %.0f = %.2lf", x, logaritmo_binario);
	logaritmo_natural2 = log1p(x);
	printf("\n\tLogaritmo natural de %.0f+1 = %.2lf", x, logaritmo_natural2);
	
	//Usando a biblioteca math.h
	printf("\n\nFun��es Gama");
	double fgama, flgama, errof, errofc;
	fgama = tgamma(x);
	printf("\n\tA fun��o gama de %.0f = %.2lf", x, fgama);
	flgama = lgamma(x);
	printf("\n\tA fun��o logar�tmica gama de %.0f = %.2lf", x, flgama);
	errof = erf(x);
	printf("\n\tO valor retornado da fun��o de erro para %.0f = %.2lf", x, errof);
	errofc = erfc(x);
	printf("\n\tA fun��o de erro complementar de %.0f � equivalente a: = %.2lf", x, errofc);	


	sleep (3);		//A fun��o sleep programa uma pausa que, nesse caso, � de 3 segundos
	
	printf ("\n\n\n----------------------------------------------------------------");
	int a;	
	printf ("\n\n\nConsidere as op��es a seguir: \n\t1-Sim \n\t0-N�o");
	printf ("\nDeseja testar a fun��o rand? ");
	scanf ("%d", &a);
	
	//Esse programa testa as condi��es true ou falsa sem indic�-las na condi��o
	if (a!=1 && a!=0)
		printf ("\n\t\t\t\tComando inv�lido...");
	else if (a)
	{	printf ("\n\t\t\t\tProsseguindo...");
		sleep(3);
		int j;
		printf("\n\nGerando 10 valores aleat�rios: \n");
		for (j=0; j<10; j++)
			printf("%d ", rand() % 100);	//Fun��o rand (rand�mico) para gerar 10 n�meros aleat�rios entre zero e 100
		getchar();	}
	else
		printf ("\n\t\t\t\tFinalizando comandos...");
	printf ("\n\n\n\n");
	
	getch();
}
