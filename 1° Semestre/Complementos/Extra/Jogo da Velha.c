#include <stdio.h>
#include <stdlib.h>

#define DIM 3

int main()
{	printf("Exibindo um determinado tabuleiro do jogo da velha!\n");
	
	char velha[DIM][DIM] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	int i=0, j=0;

	//inserindo valores dentro da tabela
	velha[0][0] = 'X';
	velha[1][1] = 'X';
	velha[0][2] = '0';
	velha[2][2] = '0';

	for(i=0; i<DIM; i++)		//DE 0 A 2
	{	for(j=0; j<DIM; j++)		//DE 0 A 2
			printf("%c%c", velha[i][j], j==DIM-1?' ':'|');	//CASO J FOR 1, ELE VAI DAR ESPAÇO BRANCO; CASO CONTRÁRIO, IMPRIMIRÁ |

		if (i!=DIM-1)
			printf("\n------\n");
	}
	return 0;
}
