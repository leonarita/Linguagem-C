#include <stdio.h>
#include <string.h>//necessário para strlen
#include <conio.h>
int main (void)
{
  char str[5] = "Curso";
  int tamanho;
  
  tamanho = strlen(str);	//Determina o tamanho de uma string.
  
  printf("O tamanho da string %s vale %d\n", str, tamanho);
  
  getch();
  return 0;
}
