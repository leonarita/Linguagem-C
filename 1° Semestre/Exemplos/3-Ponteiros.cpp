#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main ()
{	double a=0.9, *b=&a, **c=&b;
	printf ("%f, %p, %p \n", a, b, c);       //Valor de a  ,  endereço de memória de a  ,  endereço de memória de b
	printf ("%p, %p, %p \n", &a, &b, &c);    //Endereços de memória de a, b e c
	printf ("%f, %p, %f \n", *b, *c, **c);   //Valor de a  ,  endereço de memória de a  ,  valor de c
	
	//printf ("%p", *c);	->	vai imprimir que o ponteiro c vai exibir o conteudo do ponteiro b, que é o endereço de memória de a
	//printf ("%p", **c);	->	vai imprimir que o ponteiro c vai exibir o conteudo daquilo que o ponteiro b está apontando
	
	getchar ();
}
