#include<stdio.h>

int main ()
{
	char x[10], c;
	int i=0;
	
/*	x[0]=getchar();
	printf ("%c", x[0]);	*/
	
	while ((x[i]=getchar()) != '\n' && i<8);	//algo � digitado e vai na vari�vel x[i]
		i++;
	
	x[i]='\0';
	printf ("%s", x);
	
	while ((c=getchar()) != '\n');	//algo � digitado e vai ser armazenado na vari�vel x[i]
		putchar(c);					//Replica o que foi digitado na tela
	
	return 0;
}
