#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main ()
{	double a=0.9, *b=&a, **c=&b;
	printf ("%f, %p, %p \n", a, b, c);       //Valor de a  ,  endere�o de mem�ria de a  ,  endere�o de mem�ria de b
	printf ("%p, %p, %p \n", &a, &b, &c);    //Endere�os de mem�ria de a, b e c
	printf ("%f, %p, %f \n", *b, *c, **c);   //Valor de a  ,  endere�o de mem�ria de a  ,  valor de c
	
	//printf ("%p", *c);	->	vai imprimir que o ponteiro c vai exibir o conteudo do ponteiro b, que � o endere�o de mem�ria de a
	//printf ("%p", **c);	->	vai imprimir que o ponteiro c vai exibir o conteudo daquilo que o ponteiro b est� apontando
	
	getchar ();
}
