#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<time.h>
#include <stdlib.h>

//EUUUU TEEEE AMOOOOOOOOO

void op1 ()
{	printf ("\n\t\t\tIntrodu��o (E/S)");
	printf ("\n\n\tEu n�o sou de dar printf sobre minha vida, mas � incr�vel como voc� deu um scanf em minha vida toda e me conhece t�o bem. Voc� � tudo pra mim, amor <3");
}

void op2 ()
{	printf ("\n\t\t\tCondi��es");
	printf ("\n\n\n\tEssa condi��o diz muito a respeito de mim: ");
	printf ("\n\n\n\n\t\tif (Stefany est� comigo)\n\t\t\tEu estou feliz!!!!!! :) \n\t\telse \n\t\t\tEu estou triste :'(");
	printf ("\n\n\n\nMe ajuda a cumprir esse if, por favor. Fique comigo pra sempre, amor!");
}

void op3 ()
{	printf ("\n\t\t\tLoops");
	printf ("\n\n\n\tEsse loop diz muito a respeito de mim: ");
	printf ("\n\n\n\n\t\tfor (i=0; i<=infinito; i++) \n\t\t\tEu sempre te amarei, amor");
	printf ("\n\n\n\nEu faria todo esse loop novamente s� para te ver feliz, amor!");
}

void op4 ()
{	printf ("\n\t\t\tVetores (arraial)");
	printf ("\n\n\n\tMeu cora��o � dividido em compartimentos assim como o vetor, e voc� ocupa todos esses compartimentos: ");
	printf ("\n\n\n\n\t\tvetor_cora��o[atrio_dir, atrio_esq, ventriculo_dir, ventriculo_esq] = {'Stefany', 'Meu amor', 'Meu nen�', 'Voc� mesma!!'}");
	printf ("\n\n\n\nVoc� sempre � a dona de todos os lugares desse vetor, amor!");
}

void op5 ()
{	printf ("\n\t\tFun��o");
	printf ("\n\n\n\tA fun��o Leonardo:");
	printf ("\n\n\n\n\t\tvoid Leonardo (meu_amor)\n\t\t{\tprintf ('A fun��o dessa fun��o � amar para todo sempre o amor da minha vida Stefany <3 <3 <3');\n\t\t}");
}

void op6 ()
{	printf ("\n\t\t\tPonteiro");
	printf ("\n\n\n\tint *MeuAmor, SeuCoracao = amorInfinito; \n\t*MeuAmor = &SeuCoracao; \n\n\tMeuAmor aponta para o seu cora��o e percebe quanto amor h� nele. Voc� � tudo pra mim, amor <3");
}

void op7 ()
{
	FILE *file;
	file = fopen ("Para o amor da minha vida.txt", "w");
	
	if (!file)
	{	printf ("Erro na abertura do arquivo");
		getchar();
		exit (1);	}
	
	fprintf (file, "PARAB�����NS, AMOOOOOR <3 \n\n\tAmor, parab�ns pelo seu dia! \nObrigado pela sua linda ess�ncia que percorre o meu eu e me encanta por completo. \nVoc� � tudo para mim, amor. \nSei que h� 19 anos atr�s voc� nasceu pra mim. \nObrigado por tanto, por tudo, principalmente por existir e pelo seu amor que � infinito. \nVoc� � meu amor, meu nen�, minha vida, meu tudo. \nTinhamu, amor. \nQue esse seja apenas o primeiro anivers�rio seu comigo de muitos!!");
	fclose (file);
	printf ("\n\n\n\tPressione enter at� o essa tela fechar e abra o arquivo gerado...");
}

void op8 ()
{	printf ("\n\t\tBibliografia");
	printf ("\n\n\n\tLivro 1: A arte de amar");
	printf ("\n\tLivro 2: Demonstrando algebricamente que Leonardo ama mais do que Stefany");
	printf ("\n\tLivro 3: Algoritmo do amor");
	printf ("\n\tLivro 4: Introdu��o � Linguagem C ainda vai casar comigo simm");
	printf ("\n\tLivro 5: Linguagem C++ Eu = Amor");
}

int main ()
{	setlocale (LC_ALL, "");
	int op;

	system ("TITLE Linguagem C de Casa Comigo");
	printf ("\t\t\tSeja bem-vindo � esse programa!");
	printf ("\n\nConsidere as op��es abaixo: \n\t1-Introdu��o (E/S) \n\t2-Condi��es \n\t3-Loops \n\t4-Vetores (arraial) \n\t5-Fun��es \n\t6-Ponteiros \n\t7-Arquivos \n\t8-Bibliografia");
	printf ("\n\nQual op��o voc� deseja? ");
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

	printf ("Informa��es do dia mais especial da vida do meu nen�!!!!!!!!!!!!! <3");
	printf ("\n\tData: %d/%d/%d", Dados->tm_mday, Dados->tm_mon+1, Dados->tm_year+1900);
	printf ("\n\tHora: %d:%d:%d", Dados->tm_hour, Dados->tm_min, Dados->tm_sec);
	printf ("\n\n");
}
