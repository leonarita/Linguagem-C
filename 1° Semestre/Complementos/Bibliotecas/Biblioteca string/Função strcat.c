#include <stdio.h>
#include <string.h>//necessário para strcat
#include <conio.h>
int main (void)
{
  char str[10] = "Curso";
  strcat(str, " de C");
  //Concatena a string "de C" com o conteúdo da string str
  
  printf("str = %s\n", str);
  //Será exibido "curso de C"
  
  getch();
  return 0;
}
