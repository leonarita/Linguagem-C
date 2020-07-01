#include <stdio.h>  
#include <math.h> 
#include <locale.h>
 
main (void)  
{	setlocale (LC_ALL, "");

  double v[3]={1.1,2.2,3.3}, *pv=v,*pv2;  
  printf("O endere�o do vetor v � %p\n",v);//hexadecimal  
  printf("O endere�o do vetor v � %ld\n",(long int) v);//decimal  
  printf("O ponteiro *pv aponta para o endere�o %p\n",pv);//hexadecimal  
  printf("O ponteiro *pv aponta para o endere�o %ld\n",(long int) pv);//decimal  
  printf("O endere�o de *pv � %ld\n",(long int) &pv);//decimal  
  printf("O valor apontado por *pv � %f\n",*pv);  
  pv++;  
  printf("O endere�o de *pv � %ld\n",(long int) &pv);//decimal  
  printf("O ponteiro *pv aponta para o endere�o %ld\n",(long int) pv);//decimal  
  printf("O valor apontado por *pv � %f\n",*pv);  
  printf("O ponteiro caminhou %ld bytes\n",sizeof(double));  
  pv2=pv+2;  
  printf("O valor apontado por *pv2 � %f\n",*pv2);  
  printf("A diferen�a entre pv2 e pv � %ld double\n",pv2-pv);  
  pv2--;  
  printf("O valor apontado por *pv2 � %f\n",*pv2);  
  if (pv2<pv) printf("pv2 est� � esquerda de pv\n");  
  else printf("pv2 est� � direita de pv\n");  
}
