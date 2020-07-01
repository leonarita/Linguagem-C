#include <stdio.h>
#include <locale.h>

main() 
{	setlocale(LC_ALL, "Portuguese");

	float x = 0.0;
	float y = 0.0;
	char op;

	printf("\n Expressão? ");
	scanf("%f %c %f", &x, &op, &y);

	switch( op ) 
	{	case '+': printf("\n valor = %.2f", x+y); break;
		case '-': printf("\n valor = %.2f", x-y); break;
		case '*': printf("\n valor = %.2f", x*y); break;
		case '/': printf("\n valor = %.2f", x/y); break;
		default : printf("\n Operador inválido: %c",op);
	}
	
	/*	int a=1;
		printf ("%d", a++);		-> 1
		printf ("%d", a);		-> 2
		printf ("%d", ++a);		-> 3
		printf ("%d", a+=2);	-> 5
		printf ("%d", a);		-> 5
	*/
}
