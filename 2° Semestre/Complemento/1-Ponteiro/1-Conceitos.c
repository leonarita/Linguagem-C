#include <stdio.h>

//Nunca use um ponteiro que não foi inicializado.

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
    
    p++;		//Incrementa 1 int (4 bytes) no endereço de memória de p
    (*p)++;		//Incrementa o conteúdo da variável apontada por p
    *(p+15);	//Utiliza o ponteiro 15 posições a frente
    
    printf ("\n\nValor de num: %d\n",valor);
    printf ("Endereco para onde o ponteiro aponta: %p\n",p);
    printf ("Valor da variavel apontada: %d\n",*p);
    
    return(0);
}
