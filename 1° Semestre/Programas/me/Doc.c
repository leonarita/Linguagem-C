#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<time.h>
#include <stdlib.h>

//EUUUU TEEEE AMOOOOOOOOO

void op1 ()
{	printf ("\n\t\t\tIntrodução (E/S)");
	printf ("\n\n\tEu não sou de dar printf sobre minha vida, mas é incrível como você deu um scanf em minha vida toda e me conhece tão bem. Você é tudo pra mim, amor <3");
}

void op2 ()
{	printf ("\n\t\t\tCondições");
	printf ("\n\n\n\tEssa condição diz muito a respeito de mim: ");
	printf ("\n\n\n\n\t\tif (Stefany está comigo)\n\t\t\tEu estou feliz!!!!!! :) \n\t\telse \n\t\t\tEu estou triste :'(");
	printf ("\n\n\n\nMe ajuda a cumprir esse if, por favor. Fique comigo pra sempre, amor!");
}

void op3 ()
{	printf ("\n\t\t\tLoops");
	printf ("\n\n\n\tEsse loop diz muito a respeito de mim: ");
	printf ("\n\n\n\n\t\tfor (i=0; i<=infinito; i++) \n\t\t\tEu sempre te amarei, amor");
	printf ("\n\n\n\nEu faria todo esse loop novamente só para te ver feliz, amor!");
}

void op4 ()
{	printf ("\n\t\t\tVetores (arraial)");
	printf ("\n\n\n\tMeu coração é dividido em compartimentos assim como o vetor, e você ocupa todos esses compartimentos: ");
	printf ("\n\n\n\n\t\tvetor_coração[atrio_dir, atrio_esq, ventriculo_dir, ventriculo_esq] = {'Stefany', 'Meu amor', 'Meu nenê', 'Você mesma!!'}");
	printf ("\n\n\n\nVocê sempre é a dona de todos os lugares desse vetor, amor!");
}

void op5 ()
{	printf ("\n\t\tFunção");
	printf ("\n\n\n\tA função Leonardo:");
	printf ("\n\n\n\n\t\tvoid Leonardo (meu_amor)\n\t\t{\tprintf ('A função dessa função é amar para todo sempre o amor da minha vida Stefany <3 <3 <3');\n\t\t}");
}

void op6 ()
{	printf ("\n\t\t\tPonteiro");
	printf ("\n\n\n\tint *MeuAmor, SeuCoracao = amorInfinito; \n\t*MeuAmor = &SeuCoracao; \n\n\tMeuAmor aponta para o seu coração e percebe quanto amor há nele. Você é tudo pra mim, amor <3");
}

void op7 ()
{
	FILE *file;
	file = fopen ("Para o amor da minha vida.txt", "w");
	
	if (!file)
	{	printf ("Erro na abertura do arquivo");
		getchar();
		exit (1);	}
	
	fprintf (file, "PARABÉÉÉÉÉNS, AMOOOOOR <3 \n\n\tAmor, parabéns pelo seu dia! \nObrigado pela sua linda essência que percorre o meu eu e me encanta por completo. \nVocê é tudo para mim, amor. \nSei que há 19 anos atrás você nasceu pra mim. \nObrigado por tanto, por tudo, principalmente por existir e pelo seu amor que é infinito. \nVocê é meu amor, meu nenê, minha vida, meu tudo. \nTinhamu, amor. \nQue esse seja apenas o primeiro aniversário seu comigo de muitos!!");
	fclose (file);
	printf ("\n\n\n\tPressione enter até o essa tela fechar e abra o arquivo gerado...");
}

void op8 ()
{	printf ("\n\t\tBibliografia");
	printf ("\n\n\n\tLivro 1: A arte de amar");
	printf ("\n\tLivro 2: Demonstrando algebricamente que Leonardo ama mais do que Stefany");
	printf ("\n\tLivro 3: Algoritmo do amor");
	printf ("\n\tLivro 4: Introdução à Linguagem C ainda vai casar comigo simm");
	printf ("\n\tLivro 5: Linguagem C++ Eu = Amor");
}

int main ()
{	setlocale (LC_ALL, "");
	int op;

	system ("TITLE Linguagem C de Casa Comigo");
	printf ("\t\t\tSeja bem-vindo à esse programa!");
	printf ("\n\nConsidere as opções abaixo: \n\t1-Introdução (E/S) \n\t2-Condições \n\t3-Loops \n\t4-Vetores (arraial) \n\t5-Funções \n\t6-Ponteiros \n\t7-Arquivos \n\t8-Bibliografia");
	printf ("\n\nQual opção você deseja? ");
	scanf ("%d", &op);
	system ("CLS");
	
	switch (op)
	{	case 1:
			op1();
			break;
		case 2:
			op2();
			break;
		case 3:
			op3();
			break;
		case 4:
			op4();
			break;
		case 5:
			op5();
			break;
		case 6:
			op6();
			break;
		case 7:
			op7();
			break;
		case 8:
			op8();
			break;
	}
	printf ("\n\n\n\t\t\tEU TE AMO PRA CARALHO, AMOR <3 <3 <3 \n\n\n\n");
	
	struct tm *Dados;	//Para data e hora
	time_t segundos;
	time (&segundos);
	Dados = localtime (&segundos);

	printf ("Informações do dia mais especial da vida do meu nenê!!!!!!!!!!!!! <3");
	printf ("\n\tData: %d/%d/%d", Dados->tm_mday, Dados->tm_mon+1, Dados->tm_year+1900);
	printf ("\n\tHora: %d:%d:%d", Dados->tm_hour, Dados->tm_min, Dados->tm_sec);
	printf ("\n\n");
}
