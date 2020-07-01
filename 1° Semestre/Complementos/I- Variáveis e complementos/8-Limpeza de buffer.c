#include<stdio.h>

//Serão apresentados 4 modos de limpar o buffer

void limparBuffer (void)
{	char c;
	while ((getchar()) != '\n' && c != EOF);
}

int main ()
{
	char a, b, c;

	a=getchar();

/*1)	fflush(stdin);			*/
/*2)	fflush(stdout);			*/
/*3)	setbuf(stdin, NULL);	*/
/*4)*/	limparBuffer();

	b=getchar();

/*1)	fflush(stdin);			*/
/*2)	fflush(stdout);			*/
/*3)	setbuf(stdin, NULL);	*/
/*4)*/	limparBuffer();

	c=getchar();

/*1)	fflush(stdin);			*/
/*2)	fflush(stdout);			*/
/*3)	setbuf(stdin, NULL);	*/
/*4)*/	limparBuffer();

	printf ("%c", a);
	printf ("%c", b);
	printf ("%c", c);

	return 0;
}
