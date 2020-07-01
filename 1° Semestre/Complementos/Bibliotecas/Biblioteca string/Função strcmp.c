#include <stdio.h>
#include <string.h>	//necess�rio para strcmp

int main (void)
{
  char str1[4] = "abc";
  char str2[4] = "abd";
  int retorno;
  
  retorno = strcmp(str1, str2);			//Compara o conte�do de duas strings;
  
  printf("retorno = %d\n", retorno);	//mostra o retorno da fun��o strcmp  
  
  return 0;
}

/*Poss�veis valores de retorno:
	  0: conte�do das strings s�o iguais
	< 0: conte�do da string1 � menor do que string2
	> 0: conte�do da string1 � maior do que string2		*/
