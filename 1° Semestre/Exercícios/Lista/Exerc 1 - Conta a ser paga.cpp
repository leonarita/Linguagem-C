#include<stdio.h>
#include<conio.h>

int main () {
	
	int V=0, i;
	int C[4], N[4];
		
	for (i=0; i<4; i++) 
	{
		printf ("\n Digite valor consumido:");
		scanf ("%d", &N[i]);
	
		C[i] = 7;
		V = N[i] - 10;
	
		if (V>0)
		{	if (V<20)
			{	C[i] = V + C[i];	}
			else
			{	C[i] = 20 + C[i];
				V = V - 20;
			
				if (V>=0)
				{	if (V<70)
					{	C[i] = 2*V + C[i];	}
					else
					{	C[i] = 140 + C[i];
						V = V - 70;
					
						if (V>0)
						{	C[i] = 5*V + C[i];	}
					}
				}
			}
		}	
	}
	
	for (i=0; i<4; i++)
	{	printf ("\n \n \n Valor consumido   Custo");
		printf ("\n %d --- %d \n", N[i], C[i]);		}
	
	getch ();
}
