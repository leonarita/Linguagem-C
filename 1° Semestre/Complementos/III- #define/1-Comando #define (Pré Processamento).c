#include<stdio.h>
#include<locale.h>

#define PI 3.14159
#define DOIS_PI 2*PI
#define AREA_CIRCULO(raio) raio*raio*PI	//� uma macro
#define NULO 0

#define SIM 100
#define NAO -100
//Diretivas de Pr� Processamento

double areaCirculo (double raio)
{	return raio * raio * PI;	}

int main ()
{	setlocale (LC_ALL, "");
	double r;
	int i=3;
	
	printf ("%f\n", PI);
	printf ("%f\n", DOIS_PI);
	printf ("\n\n\n");

	while (i!=NULO)	//Sem a linha 20, o i nunca atingir� zero
	{	printf ("Digite o raio do c�rculo: ");
		scanf ("%lf", &r);
		printf ("A �rea do c�rculo � %lf\n", areaCirculo(r)); 		//Vai chamar a fun��o areaCirculo
		printf ("A �rea do c�rculo � %lf\n", AREA_CIRCULO(r));		//Vai chamar a macro (no #define)
		
		if (areaCirculo(r)<=10)
			printf ("\n\t%i", NAO);
		else
			printf ("\n\t%i", SIM);
			
		printf ("\n\n\n");
		i--;
	}

	getchar();
}
