#include<stdio.h>
#include<locale.h>

struct Est
{	char c;
	int n;
	float x;
};


union Uni
{	char c;
	int n;
	float x;
};

void main ()
{	setlocale (LC_ALL, "");

	//register int contador;
	//printf ("\n\n\tDimensão do Registro: %d", sizeof(contador));

	printf ("\n\tDimensão da Estrutura: %d", sizeof(struct Est));
	printf ("\n\tDimensão da União: %d", sizeof(union Uni));
	
	union Uni uniao;
	
	uniao.x = 12345.6;
	puts ("\n\n\tValores iniciais");
	printf ("\t\t '%c' %d %7.2f", uniao.c, uniao.n, uniao.x);
	
	printf ("\n\n\tAlterando apenas o int");
	uniao.n = 2500;
	printf ("\n\t\t '%c' %d %7.2f", uniao.c, uniao.n, uniao.x);
}
