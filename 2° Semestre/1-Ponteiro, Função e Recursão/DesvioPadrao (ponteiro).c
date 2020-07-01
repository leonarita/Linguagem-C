#include<stdio.h>
#include<math.h>
#include<locale.h>

#define N 3

float Desvio(float *Vetorzinho, int Consider, float Media);

main()
{	setlocale(LC_ALL, "Portuguese");

	float Notas[N];
	int Counter = 0;
	float Soma = 0;
	float Media;

	while(Counter < N)
	{	printf("%dª nota: ", (Counter + 1));
		scanf("%f", (Notas + Counter));
		Soma += *(Notas + Counter);
		Counter++;
		system("CLS");
	}

	Media = Soma/N;
	printf("%.2f", Media);
	printf("\n\nO desvio padrão é: %.2f\n\n", Desvio(Notas, N, Media));
}

float Desvio(float *Vetorzinho, int Consider, float Media)
{	float Helper;
	int Controller;
	float Summation = 0;

	while(Controller < N)
	{	Summation += ((*(Vetorzinho + Controller) - Media) * (*(Vetorzinho + Controller) - Media));
		Controller++;
		printf("%f\n", Summation);
	}
	return (sqrt(Summation/N));
}
