#include <stdio.h>
#include <time.h>
#include <locale.h>

int main ()
{
	setlocale (LC_ALL, "");
	
	struct tm *data_hora_atual;					//ponteiro para struct que armazena data e hora
	time_t segundos;							//variável do tipo time_t para armazenar o tempo em segundos  
	time (&segundos);							//obtendo o tempo em segundos 
	data_hora_atual = localtime(&segundos);		//para converter de segundos para o tempo local, utilizamos a função localtime

	printf("Informações do dia");
	printf("\n\tHora .....: %d:%d:%d", data_hora_atual->tm_hour, data_hora_atual->tm_min, data_hora_atual->tm_sec);				//hora:minuto:segundo  
	printf("\n\tData .....: %d/%d/%d", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900);		  //dia/mês/ano	
}
