#include <stdio.h>

int soma (int a, int b) 
{	return a + b;
}

int multiplica (int a, int b)
{	return a * b;
}

//É um tipo de dado ponteiro para função int que aceita dois ints de parâmetro 
typedef int (*Operacao) (int, int);

//Cria uma instância de Operacao que recebe o endereço de memória da função soma
Operacao ponteiroParaSoma = &soma;

//Executa uma operação binária sobre dois operandos
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
