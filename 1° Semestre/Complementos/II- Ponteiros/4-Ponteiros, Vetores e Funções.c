#include<stdio.h>
#include<conio.h>

int somarVetor (int vetor[], const int n)
{	int soma=0;
	int *ponteiro;
	int *const finalVetor=vetor+n;	//Vai apontar para o endereço de memória do vetor e adicionar n
	
	//Ponteiro vai apontar para o vetor enquanto não chegar ao finalVetor
	for (ponteiro=vetor; ponteiro<finalVetor; ++ponteiro)
		soma+=*ponteiro;
	return soma;
}

int main ()
{
	int vetor[10]={5,5,5,5,5,5,5,5,5,5};

	printf ("A soma dos membros do vetor = %i", somarVetor(vetor, 10));

	getchar();
	return 0;
}
