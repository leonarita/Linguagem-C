#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>

struct horario
{	int horas;
	int minutos;
	int segundos;
};

int main (void)
{	setlocale(LC_ALL, "");

	void receberHorario (struct horario lista[5]);	//Declarei a fun��o teste dentro da fun��o principal
	void printHorario (struct horario lista[5]);
	struct horario listaHorario[5];
	
	receberHorario (listaHorario);
	printHorario (listaHorario);
	
	return 0;
}

void receberHorario (struct horario lista[5])
{	int i;
	for (i=0; i<5; ++i)
	{	printf ("Digite o %i hor�rio (hh:mm:ss): ", i+1);
		scanf ("%i:%i:%i", &lista[i].horas, &lista[i].minutos, &lista[i].segundos);
	}
}

void printHorario (struct horario lista[5])
{	int i;
	for (i=0; i<5; ++i)
	{	printf ("O %i� hor�rio �: %i:%i:%i\n\n", i+1, lista[i].horas, lista[i].minutos, lista[i].segundos);	}
}
