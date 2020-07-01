#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main ()
{
	int x, y, i;
	POINT cursor;
	GetCursorPos(&cursor);
	
	x=cursor.x;
	y=cursor.y;
	
	for (i=1; i<4; i++)
	{	sleep (5);
		GetCursorPos(&cursor);
		x=cursor.x;
		y=cursor.y;
		SetCursorPos (x + (rand() % 5 - 2) * (rand() % 23 / 39 + 7), y + (rand() % 5 - 2) * (rand() % 23 / 39 + 7)+200000);
		//Beep(3500, 1000);
	}
	
	return 0;
	printf ("FEITO!");
}
