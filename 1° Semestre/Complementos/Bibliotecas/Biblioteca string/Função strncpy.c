#include <stdio.h>
#include <string.h>//necessário para strncpy
#include <conio.h>
int main (void)
{
  char str1[8] = "Curso C";
  char str2[5];
  
  strncpy(str2, str1, 5);	//Realiza a cópia do conteúdo de uma variável a outra, porém deve ser especificado o tamanho a ser copiado.
  
  str2[5] = '\0';
  printf("str2 = %s\n", str2);
  
  getch();
  return 0;
}
