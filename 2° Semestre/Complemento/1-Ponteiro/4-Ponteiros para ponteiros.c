#include <stdio.h>

int main ()
{	float fpi = 3.1415;
    float *pf;		//Ponteiro que vai apontar para um dado do tipo float
	float **ppf;	//Ponteiro que vai apontar para um dado do tipo ponteiro float

    pf = &fpi;	/* pf armazena o endereco de fpi */
    ppf = &pf;	/* ppf armazena o endereco de pf */

    printf("%f\n", **ppf);	/* Imprime o valor de fpi */
    printf("%f", *pf);		/* Tambem imprime o valor de fpi */
    
    fpi = 2;	//Altera o conteudo no endere�o de mem�ria de fpi, e os ponteiros lhe apontar�o (in)diretamente
    
    printf("\n\n\n%f\n", **ppf);	/* Imprime o valor de fpi */
    printf("%f", *pf);		/* Tambem imprime o valor de fpi */
    
    return(0);
}

