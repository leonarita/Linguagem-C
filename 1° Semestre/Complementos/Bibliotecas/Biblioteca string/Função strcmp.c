#include <stdio.h>
#include <string.h>	//necessário para strcmp

int main (void)
{
  char str1[4] = "abc";
  char str2[4] = "abd";
  int retorno;
  
  retorno = strcmp(str1, str2);			//Compara o conteúdo de duas strings;
  
  printf("retorno = %d\n", retorno);	//mostra o retorno da função strcmp  
  
  return 0;
}

/*Possíveis valores de retorno:
	  0: conteúdo das strings são iguais
	< 0: conteúdo da string1 é menor do que string2
	> 0: conteúdo da string1 é maior do que string2		*/
