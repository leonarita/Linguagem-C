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
	
/*Pode ser utilizado da seguinte forma tamb�m:
	(*depois).hora=20;		//Uso do par�nteses � por causa da preced�ncia de sinais -> Naturalmente o ponto tem preced�ncia o ponteiro
	(*depois).minuto=20;
	(*depois).segundo=20;	
//Exemplo: Multiplica��o e divis�o t�m precedencia � soma e subtra��o	*/

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
