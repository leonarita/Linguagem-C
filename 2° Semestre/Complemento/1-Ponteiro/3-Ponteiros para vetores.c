#include <stdio.h>

int main () 
{	int matrx [10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *p;
	p = matrx;
   
	printf ("O terceiro elemento do vetor e: %d",p[2]);
	return(0);
}

/*
  int vetor[10];
  int *ponteiro, i;
  ponteiro = &i;

	 as operacoes a seguir sao invalidas 
  vetor = vetor + 2;     ERRADO: vetor nao � variavel 
  vetor++;               ERRADO: vetor n�o � variavel 
  vetor = ponteiro;      ERRADO: vetor n�o � variavel 

	as operacoes abaixo sao validas 
  ponteiro = vetor;       CERTO: ponteiro � variavel 
  ponteiro = vetor+2;     CERTO: ponteiro � variavel 
*/
