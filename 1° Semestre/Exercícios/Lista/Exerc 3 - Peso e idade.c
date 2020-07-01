#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

float media1(float N1, int N2)
{	if (N2 == 0)
		return 0;
	float result1;
	result1=N1/N2;
	return(result1);
}

float media2(float M1, int M2)
{	if (M2 == 0)
		return 0;
	float result2;
	result2=M1/M2;
	return(result2);
}

float media3(float O1, int O2)
{	if (O2 == 0)
		return 0;
	float result3;
	result3=O1/O2;
	return(result3);
}

float media4(float P1, int P2)
{	if (P2 == 0)
		return 0;
	float result4;
	result4=P1/P2;
	return(result4);
}

float media0(float S1, int S2)
{	if (S2 == 0)
		return 0;
	float result0;
	result0=S1/S2;
	return(result0);
}

int main ()
{	
	int num, i=1, idade, cat1=0, cat2=0, cat3=0, cat4=0, cat0=0;
	float peso=0, soma1=0, soma2=0, soma3=0, soma4=0, soma0=0;
	float result1, result2, result3, result4, result0;
	
	printf ("\t Digite o numero de pessoas: ");
	scanf ("%d", &num);
	fflush(stdin);
	
	do
	{	printf ("\n \n \t %d Pessoa", i);
		printf ("\n Digite a idade: ");
		scanf ("%d", &idade);
		fflush (stdin);
		
		printf ("\n Digite o peso: ");
		scanf ("%f", &peso);
		fflush (stdin);
		i++;
		
		if (idade<=10)
		{	cat1++;
			soma1+=peso; }
		if (idade>11 && idade<=20)
		{	cat2++;
			soma2+=peso; }
		if (idade>21 && idade<=30)
		{	cat3++;
			soma3+=peso; }
		if (idade>30)
		{	cat4++;
			soma4+=peso; }
		if (idade==0)
		{	cat0++;
			soma0+=peso; }
	} 
	while  (i<=num);
	printf ("\n \n");
	
	result0 = media0(soma0,cat0);
	printf ("\n Media de peso das pessoas com 0 anos: %f", result4);
	
	result1 = media1(soma1,cat1);
	printf ("\n Media de peso das pessoas de ate 10 anos: %f", result1);
	
	result2 = media2(soma2,cat2);
	printf ("\n Media de peso das pessoas entre 11 e 20 anos: %f", result2);
	
	result3 = media3(soma3,cat3);
	printf ("\n Media de peso das pessoas entre 21 e 30 anos: %f", result3);
	
	result4 = media4(soma4,cat4);
	printf ("\n Media de peso das pessoas maiores de 30 anos: %f", result4);
	
}
