/* Usando os operadores & e * */
#include<stdio.h>
#include<locale.h>

main()
{
	setlocale(LC_ALL, "Portuguese");
	int a; 
	int *aPtr;
	
	a = 7;
	aPtr = &a;
	
	printf("O endere�o de a � %p \n O valor de aPtr � %p\n\n", &a, aPtr);
			   
	printf("O valor de a � %d \n O valor apontado por aPtr � %d\n\n", a, *aPtr);
			   
	printf("Sabendo que * e & complementam-se mutuamente. \n\t &*aPtr = %p \n\t *&aPtr = %p\n", &*aPtr, *&aPtr);

	getch();

	return 0;
}
