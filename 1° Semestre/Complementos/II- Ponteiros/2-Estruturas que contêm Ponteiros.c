#include<stdio.h>
#include<conio.h>

int main ()
{
	struct horario
	{	int *pHora;
		int *pMinuto;
		int *pSegundo;
	};
	struct horario hoje;
	
	int hora=200;
	int minuto=300;
	int segundo=400;

	hoje.pHora = &hora;
	hoje.pMinuto = &minuto;
	hoje.pSegundo = &segundo;
	
	printf ("Hora: %i \n", *hoje.pHora);
	printf ("Minuto: %i \n", *hoje.pMinuto);
	printf ("Segundo: %i \n\n", *hoje.pSegundo);
	
	*hoje.pSegundo = 1000;				//Com asterisco lida com dados, sem asterisco lida com endere�o de mem�ria
	printf ("Segundo: %i \n", *hoje.pSegundo);
	
	getchar ();
	return 0;
}
