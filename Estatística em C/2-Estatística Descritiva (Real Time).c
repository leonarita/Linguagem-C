#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<stdlib.h>

void CalcularAmplitude (float *vetor);
float CalcularMedia (float *vetor);
float CalcularVariancia (float *vetor, float media);
float CalcularDesvioPadrao (float variancia);
float CalcularCoeficienteVariacao (float media, float desvioPadrao);

int tamanho = 0;

int main ()
{
	setlocale (LC_ALL, "");
	
	float *valores = (float *) malloc (sizeof(float));
	float dado;
	int i;
	
	float media, variancia, desvioPadrao;
	
	do
	{
		do
		{	printf("\n\n\n\nInforme um valor (ou digite zero para sair): ");
			fflush(stdin);
		}
		while (!scanf("%f", &dado));
		
		if (dado == 0)
			break;
		else
		{
			valores[tamanho] = dado;
			tamanho++;
			valores = (float *) realloc (valores, (tamanho+1) * sizeof(float));
		}
		
		system("CLS");
		
		printf ("\n\nValores: ");
		for (i=0; i<tamanho; i++)
			printf("%f ", valores[i]);
	
		CalcularAmplitude(valores);
	
		media = CalcularMedia(valores);
		printf("\n\nA média aritmética entre os valores é de %.2f", media);
	
		variancia = CalcularVariancia(valores, media);
		printf("\n\nA variância entre os valores é de %.2f", variancia);
		
		desvioPadrao = CalcularDesvioPadrao(variancia);
		printf("\n\nO desvio padrão entre os valores é de %.2f", desvioPadrao);
		
		printf("\n\nO coeficiente de variação entre os valores é de %.2f", CalcularCoeficienteVariacao(media, desvioPadrao));
	
	}
	while (dado != 0);
	
	free(valores);
	
	getch();
	return 0;
}

void CalcularAmplitude (float *vetor)
{
	float maior=vetor[0], menor=vetor[0];
	int i;
	
	for (i=1; i<tamanho; i++)
	{
		if (vetor[i] > maior)
			maior = vetor[i];
		if (vetor[i] < menor)
			menor = vetor[i];
	}
	
	printf("\n\nMaior valor: %.2f, menor valor: %.2f \nAmplitude: %.2f", maior, menor, (maior - menor));
}

float CalcularMedia (float *vetor)
{
	float resultado=0;
	int i;
	
	for (i=0; i<tamanho; i++)
		resultado += vetor[i];
	
	return resultado/tamanho;
}

float CalcularVariancia (float *vetor, float media)
{
	float resultado=0;
	int i;
	
	for (i=0; i<tamanho; i++)
		resultado += pow((vetor[i] - media), 2);
		
	return resultado/tamanho;
}

float CalcularDesvioPadrao (float variancia)
{
	return sqrt(variancia);
}

float CalcularCoeficienteVariacao (float media, float desvioPadrao)
{
	return (100 * desvioPadrao)/media;
}
