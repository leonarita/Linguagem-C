#include<stdio.h>
#include<conio.h>

int main () {
	
	int matriz1[3][3], matriz2[3][3], matriz3[3][3];
	float Det;
	
	printf ("\t\tMATRIZ 1 \n");
	for (int i=1; i<=3; i++)
	{	for (int j=1; j<=3; j++)
		{ 	printf ("Insira o valor %d, %d da matriz1: ", i, j);
			scanf ("%d", &matriz1[i][j]);	}
	}
	printf ("\n\n\n");
	
	printf ("\t\tMATRIZ 2 \n");
	for (int i=1; i<=3; i++)
	{	for (int j=1; j<=3; j++)
		{ 	printf ("Insira o valor %d, %d da matriz2: ", i, j);
			scanf ("%d", &matriz2[i][j]);	}
	}
	
	for (int i=1; i<=3; i++)
	{	for (int j=1; j<=3; j++)
		{	if (matriz1[i][j] > matriz2[i][j])
				matriz3[i][j] = matriz1[i][j];	
			else
				matriz3[i][j] = matriz2[i][j];	
		}
	}
	
	printf ("\n\n\n\t\tMATRIZ 1");
	printf ("\n\n        |  Coluna 1  |  Coluna 2  |  Coluna 3  |");
	printf ("\n--------------------------------------------------------------");
	printf ("\nLinha 1 |     %d     |     %d     |     %d     |", matriz1[1][1], matriz1[1][2], matriz1[1][3]);
	printf ("\nLinha 2 |     %d     |     %d     |     %d     |", matriz1[2][1], matriz1[2][2], matriz1[2][3]);
	printf ("\nLinha 3 |     %d     |     %d     |     %d     |", matriz1[3][1], matriz1[3][2], matriz1[3][3]);

	printf ("\n\n\n\t\tMATRIZ 2");
	printf ("\n\n        |  Coluna 1  |  Coluna 2  |  Coluna 3  |");
	printf ("\n--------------------------------------------------------------");
	printf ("\nLinha 1 |     %d     |     %d     |     %d     |", matriz2[1][1], matriz2[1][2], matriz2[1][3]);
	printf ("\nLinha 2 |     %d     |     %d     |     %d     |", matriz2[2][1], matriz2[2][2], matriz2[2][3]);
	printf ("\nLinha 3 |     %d     |     %d     |     %d     |", matriz2[3][1], matriz2[3][2], matriz2[3][3]);	 

	printf ("\n\n\n\t\tMATRIZ 3");
	printf ("\n\n        |  Coluna 1  |  Coluna 2  |  Coluna 3  |");
	printf ("\n--------------------------------------------------------------");
	printf ("\nLinha 1 |     %d     |     %d     |     %d     |", matriz3[1][1], matriz3[1][2], matriz3[1][3]);
	printf ("\nLinha 2 |     %d     |     %d     |     %d     |", matriz3[2][1], matriz3[2][2], matriz3[2][3]);
	printf ("\nLinha 3 |     %d     |     %d     |     %d     |", matriz3[3][1], matriz3[3][2], matriz3[3][3]);
	
	printf ("\n \n \n");
	
	Det = (matriz3[0][0] * matriz3[1][1] * matriz3[2][2]) + (matriz3[0][1] * matriz3[1][2] * matriz3[2][0]) + (matriz3[0][2] * matriz3[1][0] * matriz3[2][1]) - (matriz3[0][2] * matriz3[1][1] * matriz3[2][0]) - (matriz3[2][1] * matriz3[1][2] * matriz3[0][0]) - (matriz3[2][2] * matriz3[0][1] * matriz3[1][0]);
	printf ("O determinante vale: %.2f", Det);
	
	getch();
}
