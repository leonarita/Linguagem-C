#include <stdio.h>
#include <math.h>
#include <locale.h> //necessário para usar setlocale

main (void)
{
  setlocale(LC_ALL,"");		//Permite o uso de acento no proprio teclado, sendo adotado o padrão do sistema operacional

  double x = 8.62;

  printf("Biblioteca math.h \n\n");

  printf("Valor aproximado para baixo de %f é %f\n",x, floor(x) );
  printf("Valor aproximado para cima de %f é %f\n", x, ceil(x));

  printf("\n\n");

  printf("Raiz quadrada de %f é %f\n",x,sqrt(x));
  printf("%.2lf ao quadrado é %.2f \n",x,pow(x,2));

  printf("\n\n");

  printf("Valor de  seno de %.2f = %.2f \n",x,sin(x));
  printf("Valor de  cosseno de %.2f = %.2f \n",x,cos(x));
  printf("Valor de  tangente de %.2f = %.2f \n",x,tan(x));

  printf("\n\n");

  printf("Logaritmo natural de %.2f = %.2f \n",x,log(x));
  printf("Logaritmo de %.2f  na base 10 = %.2f \n",x,log10(x));
  printf("Exponencial de %.2f = %e \n",x,exp(x));

  printf("\n\n");

  printf("O valor aproximado de pi é %e \n",M_PI);
  printf("O valor aproximado de pi/2 é %e \n",M_PI_2);
  printf("O valor aproximado de pi/4 é %e \n",M_PI_4);

  printf("\n\n");

  printf("O valor aproximado de raiz quadrada de 2 é %e \n",M_SQRT2);
  printf("O valor aproximado de raiz quadrada de meio é %e \n",M_SQRT1_2);

  printf("\n\n");

  printf("O valor aproximado do número de Euler é %e \n",M_E);
  printf("O valor aproximado de logaritmo de e na base 2 é %e \n",M_LOG2E);
  printf("O valor aproximado de logaritmo de e na base 10 é %e \n",M_LOG10E);
  printf("O valor aproximado de	logaritmo neperiano binário é %e \n",M_LN2);
  printf("O valor aproximado de logaritmo neperiano ou natural é %e \n",M_LN10);

  printf("\n\n");

  printf("O módulo de -3,2 é %f \n",fabs(-3.2));
  printf("O módulo de -3 é %d \n",abs(-3));
}
