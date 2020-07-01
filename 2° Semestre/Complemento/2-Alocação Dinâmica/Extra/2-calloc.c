#include<stdio.h>
#include<stdlib.h>

//malloc() -> Aloca mem�ria, sujeitando a sujeira no teclado e n�o garantindo que inicia-se as posi��es com 0
//free()   -> Desaloca a mem�ria ante do fim do programa, n�o alterando o valor do ponteiro (no final do programa a mem�ria ser� desalocada naturalmente)
//calloc() -> Aloca mem�ria sem gerar sujeita no teclado e iniciando as posi��es com zero

int main ()
{
	int *p;
	p = (int *) calloc(5, sizeof(int));
	
	int i;
	for (i=0; i<5; i++)
	//	printf ("Endereco de p%i = %p \t Valor de p%i = %i \n", i, (p+1), i, *(p+1));
		printf ("Endereco de p%i = %p \t Valor de p%i = %i \n", i, &p[i], i, *(p+1));
	
	printf ("\n\n%i", *p);
	
	*p=20;
	printf ("\n\n%i", *p);

	*(p+1)=10;
	printf ("\n\n%i", *p);
	printf ("\n%i", *(p+1));
	printf ("\n%i", p[1]);		//Ponteiro � um vetor

	return 0;
}
