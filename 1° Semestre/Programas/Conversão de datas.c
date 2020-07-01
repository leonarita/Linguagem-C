#include<stdio.h>
#include<math.h>

int main ()
{	int dataBR, dataEUA, i, d, m, a, j;

	printf ("Digite a data brasileira: ");
	scanf ("%d", &dataBR);
	
	for (i=1000000; i<=31000000; i=i+1000000)
	{	if (dataBR<i+1000000 && dataBR>i-1000000)
		{	d=i;
			break;
		}
	}
	printf ("\n\n\tDia: %d", d);
	
	for (i=10000; i<=120000; i=i+10000)
	{	if (dataBR-d<i+10000 && dataBR-d>i-10000)
		{	m=i;
			break;
		}
	}
	printf ("\n\tMes: %d", m);
	
	a = dataBR - d - m;
	
	printf ("\n\tAno: %d", a);
	
	d /= 100;
	m *= 100;
	
	dataEUA = d + a + m;
	
	printf ("\n\n\t\t\tData americana: %d", dataEUA);
}
