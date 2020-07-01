/*Funções para conversão de caracteres maiúsculos e minúsculos:
			tolower
		Converte o caracter em minúsculo
		
			toupper
		Converte caracter minúsculo em maiúsculo.
	
  Funções para manipulação de caracteres
		
			isalnum
		Verifica se o caracter é alfanumérico
		
			isalpha
		Verificar se o caracter é uma letra do alfabeto
		
			iscntrl
		Verificar se o caracter é um caracter de controle
		
			isdigit
		Verificar se o caracter é um digito decimal
		
			isgraph
		Verifica se o caracter tem representação gráfica
		
			islower
		Verifica se o caracter é minúsculo
		
			isprint
		Verifica se o caracter é imprimível.
		
			ispunct
		Verifica se o caracter é um ponto
		
			isspace
		Verificar se o caracter é um espaço em branco
		
			isupper
		Verifica se o caracter é uma letra maiúscula
		
			isxdigit
		Verifica se o caracter é um dígito hexadecimal	*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>			//biblioteca para as funções isalpha, isdigit, toupper, tolower
int main(void)
{
  char letra;
  char op;
  
  printf("Digite uma letra do alfabeto: ");
  scanf("%c",&letra);
  
  //isalpha verifica se é uma letra do alfabeto
  if (isalpha(letra))
  {
    printf("\nVoce digitou a letra %c \n\n",letra);
    
    //toupper transforma em maiuscula
    letra = toupper(letra);
    printf("Maiuscula: %c \n\n",letra);
    
    //tolower transforma em minuscula
    letra = tolower(letra);
    printf("Minuscula: %c \n\n",letra);
  }
  else
  {
    printf("Voce nao digitou uma letra!!!\n");
  }
  
  printf("\nInforme um numero de 0 a 9: ");
  fflush(stdin);
  scanf("%c",&op);
  
  //isdigit verifica se o caracater recebido é um dígito
  if(isdigit(op))
  {
    printf("Digito: %c \n\n",op);
  }
  else
    printf("Voce nao digitou um numero!!!\n\n");
  
  system("pause");
  return 0;
}
