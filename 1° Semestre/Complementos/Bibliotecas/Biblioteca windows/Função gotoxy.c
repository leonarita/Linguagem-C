#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x, int y)
{	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

main() 
{	int col= 40; 
	int lin= 12;
	
	system("cls");

	while (1)
	{	gotoxy (col,lin);
		putch(219);
		
		switch (toupper(getch())) 
		{	case 'N': if( lin>1 ) lin--; break;
			case 'S': if( lin<24 ) lin++; break;
			case 'L': if( col<80 ) col++; break;
			case 'O': if( col>1 ) col--; break;
			case 'F': exit(1);
		}
	}
} 
