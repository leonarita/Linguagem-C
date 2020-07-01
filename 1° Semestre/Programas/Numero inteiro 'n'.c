#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>

//O numero n elevado ao quadrado é a soma dos n primeiros numeros impares
//2 ao quadrado = 		1 + 3 	= 4
//3 ao quadrado = 	1 + 3 + 5   = 9
//4 ao quadrado = 1 + 3 + 5 + 7 = 16

#define PI 3.14159265

int main (void)
{	setlocale (LC_ALL, "");
	int num, potencia, i, impar=1, resp=1, b, cifra1, cifra2, c, d;
	
	printf ("Digite o número inteiro: ");
	scanf ("%d", &num);

	double x= (double) num;	//Casting: usa um tipo de variável entre parenteses na frente da operação para adaptar o resultado ao esperado
	
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
		
	//Pré e pós Incremento : ++i	=	i++
	//Pré e pós Decremento : --i	=	i--
		
	if (potencia!=num*num)
	{	printf ("\n\n\t\tERROR 404");
		return 0;	}
		
	printf ("\nCalculando Número ao Quadrado...");
	printf ("\n\t%d ao quadrado = %d", num, potencia);
	
	printf ("\n\nVerificando se a potencia e o número são pares ou ímpares");	//Operador resto %
	if (num%2==0)
		printf ("\n\t%d : numero par.", num);
	else
		printf ("\n\t%d : numero ímpar.", num);
		
	if (potencia%2==0)
		printf ("\n\t%d : numero par.", potencia);
	else
		printf ("\n\t%d : numero ímpar.", potencia);
		
	printf ("\n\nOperacoes Aritmeticas Basicas entre potencia e número");
	printf ("\n\tpotencia + número = %d + %d = %d", potencia, num, potencia+num);
	printf ("\n\tpotencia - número = %d - %d = %d", potencia, num, potencia-num);
	printf ("\n\tpotencia * número = %d * %d = %d", potencia, num, potencia*num);
	if (num==0)
		printf ("\n\tpotencia / número = 0 / 0 = Indeterminado");
	else
		printf ("\n\tpotencia / número = %d / %d = %d", potencia, num, potencia/num);
		
	printf ("\n\nRelação as operações básicas");
	potencia+num > potencia-num ?	printf ("\n\tSoma > Subtração") 	   	 :  printf ("\n\tSubtração > Soma");
	potencia+num > potencia*num ?	printf ("\n\tSoma > Multiplicação")		 :  printf ("\n\tMultiplicação > Soma");
	if (num!=0)
		potencia+num > potencia/num ?	printf ("\n\tSoma > Divisão") 			 :  printf ("\n\tDivisão > Soma");
	potencia-num > potencia*num ?	printf ("\n\tSubtração > Multiplicação") :  printf ("\n\tMultiplicação > Subtração");
	if (num!=0)
	{	potencia-num > potencia/num ?	printf ("\n\tSubtração > Divisão") 		 :  printf ("\n\tDivisão > Subtração");
		potencia*num > potencia/num ?	printf ("\n\tMultiplicação > Divisão")	 :  printf ("\n\tDivisão > Multiplicação");	}
	//Tal condição é verdadeira?	Caso seja verdadeira, faça...	ou	 Caso seja falsa, faça...
	//É possível atribuir valores também para indicar a veracidade da condição

	printf ("\n\nCalculando número fatorial");
	if (num>0)
	{	for (b=num; b>=1; --b)
			resp*=b;
		printf ("\n\tNúmero fatorial = %d! = %d", num, resp);	}
	else if (num==0)
		printf ("\n\tNúmero fatorial = 0! = 1");
	else
		printf ("\n\tErro: Fatorial de número negativo é indefinido...");
	printf ("\nObs: Fatorial é definido apenas para números posivos e zero.");
	
	printf ("\n\nInvertendo o número e a potência");
	printf ("\n\tNúmero invertido: ");
	c=num;
	if (c<0)
		c=c*(-1);
	if (num<0)
		printf ("-");
	while (c!=0)
	{	cifra1=c%10;
		printf ("%i", cifra1);
		c/=10;	}
	printf ("\n\tPotência invertida: ");
	d=potencia;
	while (d!=0)
	{	cifra2=d%10;
		printf ("%i", cifra2);
		d/=10;
	}
		
	//Usando a biblioteca math.h
	printf("\n\nFunções Trigonométricas");
    double seno, cosseno, tangente;
	seno = sin(x*PI/180);
	cosseno = cos(x*PI/180);
	tangente = tan(x*PI/180);
	printf("\n\tValor de seno de %.0f° = %.2lf", x, seno);
	printf("\n\tValor de cosseno de %.0f° = %.2lf", x, cosseno);
	printf("\n\tValor de tangente de %.0f° = %.2lf", x, tangente);
	
	//Usando a biblioteca math.h
	printf("\n\nFunções Trigonométricas Inversas");
    double arcoseno, arcocosseno, arcotangente;
	arcoseno = asin(x*180/PI);
	arcocosseno = acos(x*180/PI);
	arcotangente = atan(x*180/PI);
	printf("\n\tValor de arcoseno de %.0f° = %.2lf", x, arcoseno);
	printf("\n\tValor de arcocosseno de %.0f° = %.2lf", x, arcocosseno);
	printf("\n\tValor de arcotangente de %.0f° = %.2lf", x, arcotangente);
	
	//Usando a biblioteca math.h
	printf("\n\nFunções Exponenciais");
	double exponencialx, exponencial2, exponenciale;
	exponencialx = exp(x);
	printf("\n\tValor exponencial de %.0f = %.2lf", x, exponencialx);
	exponencial2 = exp2(x);
	printf("\n\tValor exponencial de 2 elevado a %.0f = %.2lf", x, exponencial2);
	exponenciale = expm1(x);
	printf("\n\tValor exponencial de e elevado a %.0f = %.2lf", x, exponenciale);

	//Usando a biblioteca math.h
	printf("\n\nFunções Logarítmicas");
	double logaritmo_natural, logaritmo_base10, logaritmo_natural2, logaritmo_binario;
	logaritmo_natural = log(x);
	printf("\n\tLogaritmo natural de %.0f = %.2lf", x, logaritmo_natural);
	logaritmo_base10 = log10(x);
	printf("\n\tLogaritmo de %.2f na base 10 = %.2lf", x, logaritmo_base10);
	logaritmo_binario = log2(x);
	printf("\n\tLogaritmo binário de %.0f = %.2lf", x, logaritmo_binario);
	logaritmo_natural2 = log1p(x);
	printf("\n\tLogaritmo natural de %.0f+1 = %.2lf", x, logaritmo_natural2);
	
	//Usando a biblioteca math.h
	printf("\n\nFunções Gama");
	double fgama, flgama, errof, errofc;
	fgama = tgamma(x);
	printf("\n\tA função gama de %.0f = %.2lf", x, fgama);
	flgama = lgamma(x);
	printf("\n\tA função logarítmica gama de %.0f = %.2lf", x, flgama);
	errof = erf(x);
	printf("\n\tO valor retornado da função de erro para %.0f = %.2lf", x, errof);
	errofc = erfc(x);
	printf("\n\tA função de erro complementar de %.0f é equivalente a: = %.2lf", x, errofc);	


	sleep (3);		//A função sleep programa uma pausa que, nesse caso, é de 3 segundos
	
	printf ("\n\n\n----------------------------------------------------------------");
	int a;	
	printf ("\n\n\nConsidere as opções a seguir: \n\t1-Sim \n\t0-Não");
	printf ("\nDeseja testar a função rand? ");
	scanf ("%d", &a);
	
	//Esse programa testa as condições true ou falsa sem indicá-las na condição
	if (a!=1 && a!=0)
		printf ("\n\t\t\t\tComando inválido...");
	else if (a)
	{	printf ("\n\t\t\t\tProsseguindo...");
		sleep(3);
		int j;
		printf("\n\nGerando 10 valores aleatórios: \n");
		for (j=0; j<10; j++)
			printf("%d ", rand() % 100);	//Função rand (randômico) para gerar 10 números aleatórios entre zero e 100
		getchar();	}
	else
		printf ("\n\t\t\t\tFinalizando comandos...");
	printf ("\n\n\n\n");
	
	getch();
}
