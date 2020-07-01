/*Fun��es para convers�o de caracteres mai�sculos e min�sculos:
			tolower
		Converte o caracter em min�sculo
		
			toupper
		Converte caracter min�sculo em mai�sculo.
	
  Fun��es para manipula��o de caracteres
		
			isalnum
		Verifica se o caracter � alfanum�rico
		
			isalpha
		Verificar se o caracter � uma letra do alfabeto
		
			iscntrl
		Verificar se o caracter � um caracter de controle
		
			isdigit
		Verificar se o caracter � um digito decimal
		
			isgraph
		Verifica se o caracter tem representa��o gr�fica
		
			islower
		Verifica se o caracter � min�sculo
		
			isprint
		Verifica se o caracter � imprim�vel.
		
			ispunct
		Verifica se o caracter � um ponto
		
			isspace
		Verificar se o caracter � um espa�o em branco
		
			isupper
		Verifica se o caracter � uma letra mai�scula
		
			isxdigit
		Verifica se o caracter � um d�gito hexadecimal	*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>			//biblioteca para as fun��es isalpha, isdigit, toupper, tolower
int main(void)
{
  char letra;
  char op;
  
  printf("Digite uma letra do alfabeto: ");
  scanf("%c",&letra);
  
  //isalpha verifica se � uma letra do alfabeto
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
  
  //isdigit verifica se o caracater recebido � um d�gito
  if(isdigit(op))
  {
    printf("Digito: %c \n\n",op);
  }
  else
    printf("Voce nao digitou um numero!!!\n\n");
  
  system("pause");
  return 0;
}
