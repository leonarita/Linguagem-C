#include<stdio.h>
#include<windows.h>

void cor (int iColor) 
{	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
	bufferInfo.wAttributes &= 0x00F0;
	SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

int main ()
{	//cor(0);
	printf ("\n\t0-Preto*");
	cor(1);
	printf ("\n\t1-Azul");
	cor(2);
	printf ("\n\t2-Verde");
	cor(3);
	printf ("\n\t3-Verde-água");
	cor(4);
	printf ("\n\t4-Vermelho");
	cor(5);
	printf ("\n\t5-Roxo");
	cor(6);
	printf ("\n\t6-Amarelo");
	cor(7);
	printf ("\n\t7-Branco");
	cor(8);
	printf ("\n\t8-Cinza");
	cor(9);
	printf ("\n\t9-Azul claro");
	cor(10);
	printf ("\n\t10-Verde claro");
	cor(11);
	printf ("\n\t11-Verde-água claro");
	cor(12);
	printf ("\n\t12-Vermelho claro");
	cor(13);
	printf ("\n\t13-Lilás");
	cor(14);
	printf ("\n\t14-Amarelo claro");
	cor(15);
	printf ("\n\t15-Branco brilhante");
}
