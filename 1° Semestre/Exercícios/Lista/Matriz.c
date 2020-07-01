#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main ()
{	
	float matriz[5][5], somatot=0;
	int i, j;
	
	for (i=1; i<=4; i++)
	{	for (j=1; j<=4; j++)
		{	printf ("\n\n Digite o valor da matriz[%d][%d]: ", i, j);
			scanf ("%f", &matriz[i][j]);
			fflush(stdin);
			somatot+=matriz[i][j];
		}
	}
	
	printf ("\n\n        |  Coluna 1  |  Coluna 2  |  Coluna 3  |  Coluna 4  |");
	printf ("\n--------------------------------------------------------------");
	printf ("\nLinha 1 |    %.2f    |    %.2f    |    %.2f    |    %.2f    |", matriz[1][1], matriz[1][2], matriz[1][3], matriz[1][4]);
	printf ("\nLinha 2 |    %.2f    |    %.2f    |    %.2f    |    %.2f    |", matriz[2][1], matriz[2][2], matriz[2][3], matriz[2][4]);
	printf ("\nLinha 3 |    %.2f    |    %.2f    |    %.2f    |    %.2f    |", matriz[3][1], matriz[3][2], matriz[3][3], matriz[3][4]);
	printf ("\nLinha 4 |    %.2f    |    %.2f    |    %.2f    |    %.2f    |", matriz[4][1], matriz[4][2], matriz[4][3], matriz[4][4]);


	printf ("\n\n A soma dos valores da linha 4 vale: %f", matriz[4][1] + matriz [4][2] + matriz[4][3] + matriz [4][4]);
	printf ("\n\n A soma dos valores da coluna 3 vale: %f", matriz[1][3] + matriz [2][3] + matriz[3][3] + matriz [4][3]);
	printf ("\n\n A soma dos valores da diagonal principal vale: %f", matriz[1][1] + matriz[2][2] + matriz[3][3] + matriz [4][4]);
	printf ("\n\n A soma dos valores da diagonal secundaria vale: %f", matriz[1][4] + matriz [2][3] + matriz[3][2] + matriz [4][1]);
	printf ("\n\n A soma de todos os elementos da matriz vale: %f", somatot);
	getch();
}
