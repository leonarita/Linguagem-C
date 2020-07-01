#include <stdio.h>
#include <stdlib.h>

int main () 
{	char c;
	char i;
	int j, a, b;

	printf("Usando char\n");

	i = 32;
	do
	{	j = i;
		for (;i<=j+5; i++)
		{	printf ("\t Pos %03d: char %c", i, i);
			if (i==127)
				break;
		}
		printf ("\n");
	}
	while (i!=127);

	printf("\n\nUsando int\n");
    	
    a = 32;
	do
	{	b = a;
		for (;a<=b+5; a++)
		{	printf ("\t Pos %03d: char %c", a, a);
			if (a==127)
				break;
		}
		printf ("\n");
	}
	while (a!=127);

	printf ("\n\n");
	system ("pause");
	return 0;
}
