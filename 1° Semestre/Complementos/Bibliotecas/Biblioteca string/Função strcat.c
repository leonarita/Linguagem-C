#include <stdio.h>
#include <string.h>//necess�rio para strcat
#include <conio.h>
int main (void)
{
  char str[10] = "Curso";
  strcat(str, " de C");
  //Concatena a string "de C" com o conte�do da string str
  
  printf("str = %s\n", str);
  //Ser� exibido "curso de C"
  
  getch();
  return 0;
}
