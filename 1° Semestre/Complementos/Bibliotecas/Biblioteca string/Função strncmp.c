#include <stdio.h>
#include <string.h>		//necess�rio para strncmp;

int main (void)
{
  char str1[15] = "Curso de C";
  char str2[15] = "Curso de Java";
  int retorno;
  
  retorno = strncmp(str1, str2, 9);		//Tamb�m faz a compara��o do conte�do de duas strings, por�m deve ser especificado o tamanho a ser comparado;
  
  printf("retorno = %d\n", retorno);
  
  return 0;
}

/*Poss�veis valores de retorno:
	  0: conte�do das strings s�o iguais
	< 0: conte�do da string1 � menor do que string2
	> 0: conte�do da string1 � maior do que string2		*/
