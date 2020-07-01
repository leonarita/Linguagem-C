#include <stdio.h>

int soma (int a, int b) 
{	return a + b;
}

int multiplica (int a, int b)
{	return a * b;
}

//� um tipo de dado ponteiro para fun��o int que aceita dois ints de par�metro 
typedef int (*Operacao) (int, int);

//Cria uma inst�ncia de Operacao que recebe o endere�o de mem�ria da fun��o soma
Operacao ponteiroParaSoma = &soma;

//Executa uma opera��o bin�ria sobre dois operandos
int opera (int a, int b, Operacao op) 
{
	return op(a,b);
}

int main() 
{
	printf("%d\n", ponteiroParaSoma(3, 4));
	printf("%d\n", opera(3, 4, soma));       //imprime 7
	printf("%d\n", opera(3, 4, multiplica)); //imprime 12
}
