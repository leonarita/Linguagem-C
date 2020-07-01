#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int *p, i;
	
	p = (int *) malloc (5 * sizeof(int));
	
	for (i=0; i<=4; i++)
		p[i] = i+1;
	
	for (i=0; i<=4; i++)
		printf("%d ", p[i]);
	
	free(p);
	printf("\n");
		
	for (i=0; i<=4; i++)
		printf("%d ", p[i]);
}
