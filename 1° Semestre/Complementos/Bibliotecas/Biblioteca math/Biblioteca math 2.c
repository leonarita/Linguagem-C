#include <stdio.h>
#include <math.h>
#include <locale.h> //necess�rio para usar setlocale

main (void)
{
  setlocale(LC_ALL,"");		//Permite o uso de acento no proprio teclado, sendo adotado o padr�o do sistema operacional

  double x = 8.62;

  printf("Biblioteca math.h \n\n");

  printf("Valor aproximado para baixo de %f � %f\n",x, floor(x) );
  printf("Valor aproximado para cima de %f � %f\n", x, ceil(x));

  printf("\n\n");

  printf("Raiz quadrada de %f � %f\n",x,sqrt(x));
  printf("%.2lf ao quadrado � %.2f \n",x,pow(x,2));

  printf("\n\n");

  printf("Valor de  seno de %.2f = %.2f \n",x,sin(x));
  printf("Valor de  cosseno de %.2f = %.2f \n",x,cos(x));
  printf("Valor de  tangente de %.2f = %.2f \n",x,tan(x));

  printf("\n\n");

  printf("Logaritmo natural de %.2f = %.2f \n",x,log(x));
  printf("Logaritmo de %.2f  na base 10 = %.2f \n",x,log10(x));
  printf("Exponencial de %.2f = %e \n",x,exp(x));

  printf("\n\n");

  printf("O valor aproximado de pi � %e \n",M_PI);
  printf("O valor aproximado de pi/2 � %e \n",M_PI_2);
  printf("O valor aproximado de pi/4 � %e \n",M_PI_4);

  printf("\n\n");

  printf("O valor aproximado de raiz quadrada de 2 � %e \n",M_SQRT2);
  printf("O valor aproximado de raiz quadrada de meio � %e \n",M_SQRT1_2);

  printf("\n\n");

  printf("O valor aproximado do n�mero de Euler � %e \n",M_E);
  printf("O valor aproximado de logaritmo de e na base 2 � %e \n",M_LOG2E);
  printf("O valor aproximado de logaritmo de e na base 10 � %e \n",M_LOG10E);
  printf("O valor aproximado de	logaritmo neperiano bin�rio � %e \n",M_LN2);
  printf("O valor aproximado de logaritmo neperiano ou natural � %e \n",M_LN10);

  printf("\n\n");

  printf("O m�dulo de -3,2 � %f \n",fabs(-3.2));
  printf("O m�dulo de -3 � %d \n",abs(-3));
}
