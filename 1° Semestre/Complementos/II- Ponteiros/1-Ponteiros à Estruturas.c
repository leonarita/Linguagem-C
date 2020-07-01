#include<stdio.h>
#include<conio.h>

int main ()
{
	struct horario
	{	int hora;
		int minuto;
		int segundo;
	};
	struct horario agora, *depois;
	depois=&agora;
	
	depois->hora=20;
	depois->minuto=80;
	depois->segundo=50;
	
/*Pode ser utilizado da seguinte forma também:
	(*depois).hora=20;		//Uso do parênteses é por causa da precedência de sinais -> Naturalmente o ponto tem precedência o ponteiro
	(*depois).minuto=20;
	(*depois).segundo=20;	
//Exemplo: Multiplicação e divisão têm precedencia à soma e subtração	*/

	int somatorio=100;
	struct horario antes;
	antes.hora = somatorio * depois->segundo;
	antes.minuto = agora.hora - depois->minuto;
	antes.segundo = depois->minuto + depois->segundo;

	printf ("Agora: %i:%i:%i", agora.hora, agora.minuto, agora.segundo);
	printf ("\nAntes: %i:%i:%i", antes.hora, antes.minuto, antes.segundo);
	
	getchar();
	return 0;
}
