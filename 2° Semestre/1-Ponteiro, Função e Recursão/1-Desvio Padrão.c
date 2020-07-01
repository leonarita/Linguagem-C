#include<stdio.h> 
#include<math.h>
#include<locale.h>

int main ()
{	setlocale (LC_ALL, "");
	int cont, i;
	float nota[15][2], mediaAluno[15], MArit=0, soma=0, dp;
	
	for (cont=0; cont<=14; cont++)
	{	for (i=0; i<=1; i++)
		{	printf ("Informe a %d° nota do %i° aluno: ", i+1, cont+1);
			scanf ("%f", &nota[cont][i]);
			fflush(stdin);
		}
		mediaAluno[cont] = (nota[cont][0]+nota[cont][1])/2;
		MArit += mediaAluno[cont];
	}

	MArit = (MArit/15);
	
	printf ("\n\n\t Média aritmética: %f", MArit);
	
	for (cont=0; cont<=14; cont++)
		printf ("\n\n Média do %d° aluno: %f", cont+1, mediaAluno[cont]);
	
	for (cont=0; cont<15; cont++)
		soma += pow((mediaAluno[cont] - MArit),2);
		
	dp = sqrt(soma/15);
	printf ("\n\nO Desvio Padrão é: %.2f", dp);
	
	getchar();
}
