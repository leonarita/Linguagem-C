#include<stdio.h>
#include<math.h>
#include<locale.h>

/*	* p=3,  q=11, e=7		->	d=3							* p=3,  q=3,  e=3		->	d=3
	* p=5,  q=11, e=3		->	d=27						* p=5,  q=5,  e=7		->	d=7
	* p=7,  q=11, e=13		->	d=33						* p=47, q=53, e=59		->	d=1419
*/

int main ()
{	setlocale (LC_ALL, "");

	int p, q, e, fi, d;
	int result1, result2, result3;
	
	//Coletando o par de números primos
	printf ("\n\tDigite o número primo p: ");
	scanf ("%d", &p);
	
	printf ("\tDigite o número primo q: ");
	scanf ("%d", &q);
	
	//Coletando a chave pública
	printf ("\tDigite a chave pública e: ");
	scanf ("%d", &e);
	
	//Calculando o fi
	fi = (q-1)*(p-1);
	
	result1 = (fi - floor(fi/e)*e);
	result2 = (fi - floor(fi/e)*1);
	
	while (result1!=1)
	{	result3 = (e - floor(e/result1)*result1);
		result2 = (1 - floor(e/result1)*result2);
		
		result1 = result3;
	}
	
	d = result2;
	
	if (d<=0)
	{	while (d<=0)
			d += fi;
	}
	else if (d>0 && d-fi>0)
	{	while (d>0 && d-fi>0)
		{	d -= fi;
		}
	}
	
	printf ("\n\n\n\t\t\tAs chaves privadas são %d", d);
}
