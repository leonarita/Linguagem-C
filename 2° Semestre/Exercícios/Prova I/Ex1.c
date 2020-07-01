#include<stdio.h>
#include<locale.h>

float potencia (float taxa, float meses)
{	if (meses==0)
		return 1;
	else
		return taxa*potencia(taxa, meses-1);
}

int main ()
{	setlocale (LC_ALL, "");
	float capital, taxa, meses;
	
	printf ("Informe o capital: R$");
	scanf ("%f", &capital);
	printf ("Informe a taxa de juros (em porcentagem): ");
	scanf ("%f", &taxa);
	taxa=1+(taxa/100);
	printf ("Informe o tempo (em meses): ");
	scanf ("%f", &meses);
	
	printf ("\n\n\n\n\tConsiderando o capital de %.2f aplicado a uma taxa de %f ao mês durante %.0f meses", capital, taxa, meses);
	taxa = potencia (taxa, meses);
	printf ("\n\n\n\n\tO valor do juros compostos é R$%f", capital*taxa);
}
