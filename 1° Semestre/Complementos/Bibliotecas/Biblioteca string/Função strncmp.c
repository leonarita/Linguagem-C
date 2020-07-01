#include <stdio.h>
#include <string.h>		//necessário para strncmp;

int main (void)
{
  char str1[15] = "Curso de C";
  char str2[15] = "Curso de Java";
  int retorno;
  
  retorno = strncmp(str1, str2, 9);		//Também faz a comparação do conteúdo de duas strings, porém deve ser especificado o tamanho a ser comparado;
  
  printf("retorno = %d\n", retorno);
  
  return 0;
}

/*Possíveis valores de retorno:
	  0: conteúdo das strings são iguais
	< 0: conteúdo da string1 é menor do que string2
	> 0: conteúdo da string1 é maior do que string2		*/
