#include<stdio.h>

int main()
{	int y, *p, x;

	y = 0;			// Atribui o valor 0 à variavel y –> y = 0
	
	p = &y;			// Atribui o endereco da variavel y ao ponteiro p
	printf ("x=%d	*p=%d	y=%d\n", x, *p, y);
	
	x = *p;			// Atribui o conteudo do endereco de p a x –> x = 0
	printf ("x=%d	*p=%d	y=%d\n", x, *p, y);
	
	x = 4;			// Atribui o valor 4 a x -> x = 4
	printf ("x=%d	*p=%d	y=%d\n", x, *p, y);
	
	(*p)++;			// Incrementa o conteudo apontado pelo ponteiro p -> y = 1
	printf ("x=%d	*p=%d	y=%d\n", x, *p, y);
	
	x--;			// Decrementa a variavel x -> x = 3
	printf ("x=%d	*p=%d	y=%d\n", x, *p, y);

	(*p) += x;		// Soma o valor de x ao valor da variavel apontada por p -> y = 4
	 
	printf ("x=%d	*p=%d	y=%d\n", x, *p, y);

	return(0);
} 

/*
OUTRAS OPERAÇÕES

	1) Igualar
		p1 = p2
		*p1 = *p2
	
	2) Incrementa bytes
		p1++
		p2--
		
	3) Incrementa conteudo da variável
		(*p)++
		
	4) Soma e subtração
		p = p+12
		p = p-1
		
	5) Alterar posição do ponteiro
		*(p+15)	->	avança 15 posições
	
	6) Comparação
		p1 == p2
		p1 != p2
		p1 < p2
		p1 > p2
		
	7) ??
		++*p	-> não altera nada
		*p++	-> mostra conteudo de endereço
*/
