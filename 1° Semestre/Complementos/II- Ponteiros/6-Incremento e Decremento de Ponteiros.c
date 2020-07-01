#include <stdio.h>  
#include <math.h> 
#include <locale.h>
 
main (void)  
{	setlocale (LC_ALL, "");

  double v[3]={1.1,2.2,3.3}, *pv=v,*pv2;  
  printf("O endereço do vetor v é %p\n",v);//hexadecimal  
  printf("O endereço do vetor v é %ld\n",(long int) v);//decimal  
  printf("O ponteiro *pv aponta para o endereço %p\n",pv);//hexadecimal  
  printf("O ponteiro *pv aponta para o endereço %ld\n",(long int) pv);//decimal  
  printf("O endereço de *pv é %ld\n",(long int) &pv);//decimal  
  printf("O valor apontado por *pv é %f\n",*pv);  
  pv++;  
  printf("O endereço de *pv é %ld\n",(long int) &pv);//decimal  
  printf("O ponteiro *pv aponta para o endereço %ld\n",(long int) pv);//decimal  
  printf("O valor apontado por *pv é %f\n",*pv);  
  printf("O ponteiro caminhou %ld bytes\n",sizeof(double));  
  pv2=pv+2;  
  printf("O valor apontado por *pv2 é %f\n",*pv2);  
  printf("A diferença entre pv2 e pv é %ld double\n",pv2-pv);  
  pv2--;  
  printf("O valor apontado por *pv2 é %f\n",*pv2);  
  if (pv2<pv) printf("pv2 está à esquerda de pv\n");  
  else printf("pv2 está à direita de pv\n");  
}
