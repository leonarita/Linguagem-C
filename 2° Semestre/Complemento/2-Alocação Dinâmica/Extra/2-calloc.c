#include<stdio.h>
#include<stdlib.h>

//malloc() -> Aloca memória, sujeitando a sujeira no teclado e não garantindo que inicia-se as posições com 0
//free()   -> Desaloca a memória ante do fim do programa, não alterando o valor do ponteiro (no final do programa a memória será desalocada naturalmente)
//calloc() -> Aloca memória sem gerar sujeita no teclado e iniciando as posições com zero

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
	printf ("\n%i", p[1]);		//Ponteiro é um vetor

	return 0;
}
