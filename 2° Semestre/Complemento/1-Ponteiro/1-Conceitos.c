#include <stdio.h>

//Nunca use um ponteiro que n�o foi inicializado.

int main ()
{	int num, valor, *p;
	
	num=55;
	p=&num;     /* Pega o endereco de num */
    valor=*p;   /* Valor e igualado a num indiretamente */

	printf ("\n\nValor inicial de num: %d\n",valor);
    printf ("Endereco para onde o ponteiro aponta: %p\n",p);
    printf ("Valor da variavel apontada: %d\n",*p);
    
    *p=100; /* Muda o valor de num de uma maneira indireta */

    printf ("\nValor final de num: %d\n",num);
    
    p++;		//Incrementa 1 int (4 bytes) no endere�o de mem�ria de p
    (*p)++;		//Incrementa o conte�do da vari�vel apontada por p
    *(p+15);	//Utiliza o ponteiro 15 posi��es a frente
    
    printf ("\n\nValor de num: %d\n",valor);
    printf ("Endereco para onde o ponteiro aponta: %p\n",p);
    printf ("Valor da variavel apontada: %d\n",*p);
    
    return(0);
}
