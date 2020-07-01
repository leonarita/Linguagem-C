//	SENHA PARA 'MANEJAR GÔNDULA' E 'GERENCIAR USUÁRIOS'	:	abc123

#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include<wctype.h>
#include<windows.h>

/*	FUNCIONALIDADES

1)	Login através dos dados do arquivo

2)	Abastecer gôndulas, retirada de produtos vencidos, renovar preços dos produtos
		->	O abastecimento é empilhado a partir do critério da data de vencimento

3)	Caixa/Entrega de domícilos, onde o primeiro produto a ser processado será o primeiro a ser inserido na nota fiscal
		->	À medida que é processado, é entendido que o produto foi retirado da gôndula pelo cliente, sendo assim, desempilhado
		->	O pagamento pode ser realizado em cartão ou crédito
		->	As entregas de domicílio registram nome, endereço e estipulam o tempo de entrega

4)	Gerenciar usuário
		->	Visualiza dados cadastrados, permite realizar novo cadastro, buscar novo cadastro

*/

//BLOCO DE STRUCTS, VARIÁVEIS GLOBAIS, ARQUIVO E INTERFACE--------------------------------------------------------------------------------------------
FILE *file;

bool chave=false;

int tam=0;

typedef struct
{	char nome[50];
	char pront[11];
}
login;
login user, *cad;

typedef struct
{	int dVal, mVal, aVal;
}
produto;

typedef struct
{	int qFila;				//Quantidade de um determinado produto escolhido pelo cliente
	float pInd;				//É o resultado da quantidade de produtos no carrinho pelo seu valor por unidade
	produto pFila[5];		//Os produtos da fila
}
purchase;

typedef struct stack
{	produto prod[5];
	char descricao[50];
	float valor;
	char peso[10];
	int qntd;		//Quantidade de produtos na gôndola
}
pilha;
pilha arroz, feijao, sal, acucar, cafe, bolacha, farinha, biscoito, chocolate, vinagre;

typedef struct queue
{	pilha prod[10];
	float precoTot;
	purchase compra[10];
}
fila;
fila f;

typedef struct
{	char nome[40], endereco[50];	}
ent;
ent enc;

//Função que define as cores	->	recebe 0 a 15
void cor (int iColor) 
{	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
	bufferInfo.wAttributes &= 0x00F0;
	SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void tabela1 ()
{	cor(15);
	printf("\n\n\t .___________________________________________________________________________. \n");
	printf("    \t |  .____________________________________.                                   | \n");
	printf("    \t |  |                                    |                                   | \n");
	printf("    \t |  |                                    |                                   | \n");
	printf("    \t |  |____________________________________|                                   | \n");
	printf("    \t |                                                                           | \n");
	printf("    \t |  .________________________________.  ._________________________________.  | \n");
	printf("    \t |  |                                |  |                                 |  | \n");
	printf("    \t |  |                                |  |                                 |  | \n");	
	printf("    \t |  .________________________________.  ._________________________________.  | \n");
	printf("    \t |  .________________________________.  ._________________________________.  | \n");
	printf("    \t |  |                                |  |                                 |  | \n");
	printf("    \t |  |                                |  |                                 |  | \n");
	printf("    \t |  .________________________________.  ._________________________________.  | \n");
	printf("    \t |                ._____________________________________.    .______.        | \n");
	printf("    \t |                |                                     |    |      |        | \n");
	printf("    \t |                |                                     |    |      |        | \n");
	printf("    \t |                |_____________________________________|    |______|        | \n");
	printf("    \t |___________________________________________________________________________| \n");
}

void tabela2(int n)
{	cor(15);
	printf("\n\n\t .__________________________________________________________________________. \n");
	printf("    \t |                                                                          | \n");
	printf("    \t |                                                                          | \n");
	printf("    \t .__________________________________________________________________________. \n");
	printf("    \t |  .____________________.  .____________________.  .____________________.  | \n");
	printf("    \t |  |                    |  |                    |  |                    |  | \n");
	printf("    \t |  |                    |  |                    |  |                    |  | \n");	
	printf("    \t |  .____________________.  .____________________.  .____________________.  | \n");
	printf("    \t |  .____________________.  .____________________.  .____________________.  | \n");
	printf("    \t |  |                    |  |                    |  |                    |  | \n");
	printf("    \t |  |                    |  |                    |  |                    |  | \n");	
	printf("    \t |  .____________________.  .____________________.  .____________________.  | \n");
	printf("    \t |  .____________________.  .____________________.  .____________________.  | \n");
	printf("    \t |  |                    |  |                    |  |                    |  | \n");
	printf("    \t |  |                    |  |                    |  |                    |  | \n");	
	printf("    \t |  .____________________.  .____________________.  .____________________.  | \n");
	printf("    \t |  .____________________.  .____________________.  .____________________.  | \n");
	printf("    \t |  |                    |  |                    |  |                    |  | \n");
	printf("    \t |  |                    |  |                    |  |                    |  | \n");	
	printf("    \t |  .____________________.  .____________________.  .____________________.  | \n");
	printf("    \t |__________________________________________________________________________| \n");

if (n>1)
{	printf("    \t |                                 |                                        | \n");
	printf("    \t |_________________________________|                                        | \n");
	printf("    \t |                                 |                                        | \n");
	printf("    \t |_________________________________|________________________________________| \n");
	
	gotoxy(15, 23);
	cor(10); printf ("Informe opção: ");
	gotoxy(38, 20);
	cor(9); printf("(-1)- "); cor(4); printf("Cancelar");
}
	
	gotoxy (37, 4);
	cor(9); printf ("Catálogo de Produtos");
	gotoxy(14, 8);
	cor(9); printf("1-"); cor(14); printf("Arroz");
	gotoxy(38, 8);
	cor(9); printf("2-"); cor(14); printf("Feijão");
	gotoxy (62, 8);
	cor(9); printf("3-"); cor(14); printf("Sal");
	gotoxy(14, 12);
	cor(9); printf("4-"); cor(14); printf("Açúcar");
	gotoxy(38, 12);
	cor(9); printf("5-"); cor(14); printf("Café");
	gotoxy (62, 12);
	cor(9); printf("6-"); cor(14); printf("Bolacha");
	gotoxy(14, 16);
	cor(9); printf("7-"); cor(14); printf("Farinha");
	gotoxy(38, 16);
	cor(9); printf("8-"); cor(14); printf("Biscoito");
	gotoxy(62, 16);
	cor(9); printf("9-"); cor(14); printf("Chocolate");
	gotoxy(14, 20);
	cor(9); printf("10-"); cor(14); printf("Vinagre");
	
	if (n>2)
	{	gotoxy(62, 20);
		cor(9); printf("0- "); cor(10); printf("Prosseguir");	
	}
	cor(1);
}

void tabela3 ()
{	cor(15);
	printf("\n\n\t .___________________________________________________________________________. \n");
	printf("    \t |                                                                           | \n");
	printf("    \t |                                                                           | \n");
	printf("    \t .___________________________________________________________________________. \n");
	printf("    \t |  .________________________________.  ._________________________________.  | \n");
	printf("    \t |  |                                |  |                                 |  | \n");
	printf("    \t |  |                                |  |                                 |  | \n");	
	printf("    \t |  .________________________________.  ._________________________________.  | \n");
	printf("    \t |                ._____________________________________.    .______.        | \n");
	printf("    \t |                |                                     |    |      |        | \n");
	printf("    \t |                |                                     |    |      |        | \n");
	printf("    \t |                |_____________________________________|    |______|        | \n");
	printf("    \t |___________________________________________________________________________| \n");	
	printf("    \t |                                      |                                    | \n");
	printf("    \t |______________________________________|____________________________________|\n");
}

void tabela4()
{	cor(15);
		printf("\n\n\t .___________________________________________________________________________. \n");
		printf("    \t |  .________________________________________.                               | \n");
		printf("    \t |  |                                        |                               | \n");
		printf("    \t |  |                                        |                               | \n");
		printf("    \t |  |________________________________________|                               | \n");
		printf("    \t |                                                                           | \n");
		printf("    \t |  ._________________________.  .________________________________________.  | \n");
		printf("    \t |  |                         |  |                                        |  | \n");
		printf("    \t |  |                         |  |                                        |  | \n");	
		printf("    \t |  |_________________________|  |________________________________________|  | \n");
		printf("    \t |  ._________________________.  .________________________________________.  | \n");
		printf("    \t |  |                         |  |                                        |  | \n");
		printf("    \t |  |                         |  |                                        |  | \n");
		printf("    \t |  |_________________________|  |________________________________________|  | \n");
		printf("    \t |                ._________________________________________.                | \n");
		printf("    \t |                |                                         |                | \n");
		printf("    \t |                |                                         |                | \n");
		printf("    \t |                |_________________________________________|                | \n");
		printf("    \t |___________________________________________________________________________| \n");	 
}

void tabelaErro()
{	cor(15);
	printf("\n\n    \t                  ._____________________________________.                      \n");
	printf("    \t                  |                                     |                      \n");
	printf("    \t                  |                                     |                      \n");
	printf("    \t                  |_____________________________________|                      \n");
}

void input (char res[], int n)
{	int i, j=strlen(res);
	
	for (i=j; i<=n; i++)
		strcat(res, " ");
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------


//BLOCO DE FUNÇÃO I : BUSCA BINÁRIA --------------------------------------------------------------------------------------------------------------------------
void busca (login X[], int inicio, int fim, login A)
{	int i;
	for (i=inicio; i<=fim; i++)
		if (strcmp(X[i].nome, A.nome)==0 && strcmp(X[i].pront, A.pront)==0)
		{	chave=true;
		}
}

void BuscaBin (login X[], int inicio, int fim, login A)
{	int meio;

	if (chave==false)
	{	if (inicio<fim)
		{	meio = (inicio+fim)/2;
			BuscaBin (X, inicio, meio, A);
			BuscaBin (X, meio+1, fim, A);
			if (chave==false)
				busca (X, inicio, meio, A);
			if (chave==false)
				busca (X, meio+1, fim, A);
		}
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------


//BLOCO DE FUNÇÃO II : ORDENAÇÃO ------------------------------------------------------------------------------------------------------------------------------
void swap (login *a, login *b)
{	login aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

int particao (login X[], int p, int r)
{	int i, j;
	char pivo[50];
	strcpy (pivo, X[(p+r)/2].nome);
	i=p-1;
	j=r+1;
	
	while (i<j)
	{
		do {	j = j - 1;	}
		while (strcmp(X[j].nome, pivo)>0);
		
		do	{	i = i + 1;	}
		while (strcmp(X[i].nome, pivo)<0);
		
		if (i<j)
			swap (&X[i], &X[j]);
	}
	return j;
}

void quick (login X[], int p, int r)
{
	int q;
	
	if (p<r)
	{	q = particao (X, p, r);
		quick (X, p, q);
		quick (X, q+1, r);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------


//BLOCO DE FUNÇÃO III : MANIPULAÇÃO DE ARQUIVOS DO LOGIN -------------------------------------------------------------------------------------------------
void atualizarArquivo ()
{	remove ("usuarios.dat");
	
	if(!(file = fopen ("usuarios.dat", "w+")))
	{	system("CLS");
	
		tabelaErro();
				
		gotoxy (30, 4);
		cor(4);
		printf ("Arquivo usuarios.dat inexistente!");
		cor(15);
		printf ("\n\n\n\n\n");
		getchar();
		exit (1);
	}
	
	int i;
	
	for (i=0; i<tam; i++)
	{	fputs (cad[i].nome, file);
		fprintf (file, "\0");
		fputs (cad[i].pront, file);
		fprintf (file, "\0");
	}
	
	fclose (file);
}

void TransfereDados ()
{	file = fopen ("usuarios.dat", "r+");

	if(!file)
	{	system("CLS");
	
		tabelaErro();
				
		gotoxy (30, 4);
		cor(4);
		printf ("Arquivo usuarios.dat inexistente!");
		cor(15);
		printf ("\n\n\n\n\n");
		getchar();
		exit (1);
	}

	int i=0, j=0;
	char a[50];
	
	while (fgets(a, 50, file) != NULL)
	{	fflush (stdin);
	
		if (j%2==0)
		{	strcpy (cad[i].nome, a);
			fflush (stdin);
		}
		else if (j%2!=0)
		{	strcpy (cad[i].pront, a);
			fflush (stdin);
		}
		
		j++;
		
		fflush (stdin);
		
		if (j==2)
		{	i++;
			j = 0;
			
			tam++;
			cad = (login *) realloc (cad, (tam+1)*sizeof(login));
			
			if (cad == NULL)
			{	system ("CLS");
	
				tabelaErro();
						
				gotoxy (33, 3);
				cor(4);
				printf("Erro de alocação de memória");
				gotoxy (35, 4);
				printf("realloc devolveu NULL!");
				cor(7);
				printf ("\n\n\n\n\n\n\n\n\n");
				exit(1);
			}
		}
		fflush (stdin);	
	}
	
	fclose (file);
}
//-----------------------------------------------------------------------------------------------------------------------------------------


//BLOCO DE FUNÇÃO IV : MANIPULAÇÃO DE PILHAS ---------------------------------------------------------------------------------------------
void armazenarDados (pilha *X, char nome[])
{	remove (nome);
	file = fopen (nome, "w+");
	
	if(file==NULL)
	{	system("CLS");
	
		tabelaErro();
				
		gotoxy (30, 4);
		cor(4);
		printf ("Arquivo %s inexistente!", nome);
		cor(15);
		getchar();
		exit (1);
	}
	
	int i;
	
	for (i=0; i<X->qntd; i++)
	{	fprintf (file, "%d", X->prod[i].dVal);
		fprintf (file, "\n");
		fprintf (file, "%d", X->prod[i].mVal);
		fprintf (file, "\n");
		fprintf (file, "%d", X->prod[i].aVal);
		fprintf (file, "\n");
	}
	
	fclose (file);
}

void abreDados (pilha *X, char nome[])
{	file = fopen (nome, "r+");

	int i=0, j=0;
	char a[50];
	
	while (fgets(a, 50, file) != NULL)
	{	fflush (stdin);
	
		if (j==0)
		{	X->prod[i].dVal = atoi(a);
		}
		else if (j==1)
		{	X->prod[i].mVal = atoi(a);
		}
		else if (j==2)
		{	X->prod[i].aVal = atoi(a);
		}
		
		j++;
		fflush (stdin);
		
		if (j==3)
		{	i++;
			j = 0;
		}
		fflush (stdin);	
	}
	
	X->qntd = i;
		
	fclose (file);
}

void at (pilha *X, char nome[])
{	
	struct tm *date;
	time_t segundos;
	time (&segundos);
	date = localtime (&segundos);
	
	int m=0;
	
	int i=0, j, n=0;

	for (i=0; i<X->qntd-1; i++)
	{	if (date->tm_year+1900>X->prod[i].aVal)
		{	for (j=i+1; j<X->qntd-1; j++)
				X->prod[j-1] = X->prod[j];
			i=0;
			X->qntd--;
			m++;
		}
		
		else if (date->tm_year+1900==X->prod[i].aVal && date->tm_mon+1>X->prod[i].mVal)
		{	for (j=i+1; j<X->qntd-1; j++)
				X->prod[j-1] = X->prod[j];
			i=0;
			X->qntd--;
			m++;
		}
		
		else if ((date->tm_year+1900==X->prod[i].aVal && date->tm_mon+1==X->prod[i].mVal && date->tm_mday>X->prod[i].dVal))
		{	for (j=i+1; j<X->qntd-1; j++)
				X->prod[j-1] = X->prod[j];
			i=0;
			X->qntd--;
			m++;
		}
	}
	
	if (date->tm_year+1900>X->prod[X->qntd-1].aVal || (date->tm_year+1900==X->prod[X->qntd-1].aVal && date->tm_mon+1>X->prod[X->qntd-1].mVal) || 
	(date->tm_year+1900==X->prod[X->qntd-1].aVal && date->tm_mon+1==X->prod[X->qntd-1].mVal && date->tm_mday>X->prod[X->qntd-1].dVal))
	{
		produto A;
		A.aVal = ' ';
		A.dVal = ' ';
		A.mVal = ' ';
		X->prod[X->qntd-1] = A;
		n=1;
		X->qntd--;
		m++;
	}
	
	if (m>0)
	{	system ("CLS");
		tabelaErro();	
		gotoxy (33, 3);
		cor(4);
		if (m>1)
			printf("Foram removidos %d", m);
		else
			printf("Foi removido %d", m);
		gotoxy (35, 4);
		printf("produtos %s!", nome);
		cor(15);
		getch();
		system ("CLS");
	}
	
	armazenarDados (X, nome);
}

void empilhar (pilha *X, char nome[])
{	produto N;
	int i=0, j;
	
	struct tm *date;
	time_t segundos;
	time (&segundos);
	date = localtime (&segundos);
	
	if (X->qntd == 5)
	{	gotoxy(15, 25);
		cor(4); printf ("Gôndola cheia!!");
		getch();
		return;
	}
	else if (X->qntd == 0)
	{	gotoxy(15, 25);
		cor(4); printf ("Gôndola Vazia!");
	}

	gotoxy(55, 23);
	cor(10); printf ("Data de validade");	cor(11);
	gotoxy(46, 25);
	printf ("Dia: ");
	gotoxy(56, 25);
	printf ("Mês: ");
	gotoxy(66, 25);
	printf ("Ano: ");
	
	cor(7); 
	do	
	{	gotoxy(51, 25);	
		fflush(stdin);
	}
	while (!(scanf ("%d", &N.dVal)));
	
	do
	{	gotoxy(61, 25);
		fflush(stdin);
	}
	while (!(scanf ("%d", &N.mVal)));
	
	do
	{	gotoxy(71, 25);	
		fflush(stdin);
	}
	while (!(scanf ("%d", &N.aVal)));
	
	if ((N.mVal==1 && N.dVal > 31) || (N.mVal==2 && N.dVal > 29) ||(N.mVal==3 && N.dVal > 31) || (N.mVal==4 && N.dVal > 30) || (N.mVal==5 && N.dVal > 31) || 
		(N.mVal==6 && N.dVal > 30) || (N.mVal==7 && N.dVal > 31) || (N.mVal==8 && N.dVal > 31) || (N.mVal==9 && N.dVal > 30) || (N.mVal==10 && N.dVal > 31) || 
		(N.mVal==11 && N.dVal > 30) || (N.mVal==12 && N.dVal > 31) || (N.aVal%4==0 && N.aVal%400!=0 && N.mVal == 2 && N.dVal>28) || 
		(N.aVal%4==0 && N.aVal%400==0 && N.mVal == 2 && N.dVal>28) || (N.aVal%4!=0 && N.mVal == 2 && N.dVal>28) || (N.dVal <1) || (N.mVal<1) || (N.mVal>12) || (N.dVal>31))
	{
		gotoxy(15, 25);
		cor(4); printf ("Data de validade inválida!");
		getch();
		return;
	}
	
	if (date->tm_year+1900>N.aVal || (date->tm_year+1900==N.aVal && date->tm_mon+1>N.mVal) || (date->tm_year+1900==N.aVal && date->tm_mon+1==N.mVal && date->tm_mday>N.dVal))
	{	gotoxy(15, 25);
		cor(4); printf ("Data de validade expirada!");
		getch();
		return;
	}
	
	pilha aux;
	aux.qntd=0;
			
	X->qntd++;
	
	while (X->prod[i].aVal>N.aVal && i<X->qntd)
	{	i++;
	}
	
	while (X->prod[i].aVal==N.aVal && X->prod[i].mVal>N.mVal && i<X->qntd)
	{	i++;
	}
	
	while (X->prod[i].aVal==N.aVal && X->prod[i].mVal==N.mVal && X->prod[i].dVal>N.dVal && i<X->qntd)
	{	i++;
	}
	
	for (j=X->qntd-1; j>=i; j--)
	{	aux.prod[aux.qntd] = X->prod[j];
		aux.qntd++;
	}
	
	X->prod[i] = N;
	i++;
	
	for (j=aux.qntd-1; j>=0; j--)
	{	X->prod[i] = aux.prod[j];
		i++;
	}

	armazenarDados (X, nome);
}
//------------------------------------------------------------------------------------------------------------------------------


//BLOCO DE FUNÇÃO V : MANIPULAÇÃO DOS PREÇOS -----------------------------------------------------------------------------------
void atualizarValor ()
{	remove("precos.txt");

	file = fopen ("precos.txt", "w+");
	
	if(ferror(file))
	{	system("CLS");
	
		tabelaErro();
				
		gotoxy (30, 4);
		cor(4);
		printf ("Arquivo preços.dat inexistente!");
		cor(15);
		getchar();
		exit (1);
	}
	
	fprintf (file, "%.2f", arroz.valor);
	putc ('\n', file);
	fprintf (file, "%.2f", feijao.valor);
	putc ('\n', file);
	fprintf (file, "%.2f", cafe.valor);
	putc ('\n', file);
	fprintf (file, "%.2f", acucar.valor);
	putc ('\n', file);
	fprintf (file, "%.2f", sal.valor);
	putc ('\n', file);
	fprintf (file, "%.2f", farinha.valor);
	putc ('\n', file);
	fprintf (file, "%.2f", biscoito.valor);
	putc ('\n', file);
	fprintf (file, "%.2f", bolacha.valor);
	putc ('\n', file);
	fprintf (file, "%.2f", chocolate.valor);
	putc ('\n', file);
	fprintf (file, "%.2f", vinagre.valor);
	putc ('\n', file);
	fclose(file);
}

void atribuiPrecos()
{	
	if((file = fopen ("precos.txt", "r+"))==NULL)
	{	system("CLS");
	
		tabelaErro();
				
		gotoxy (30, 4);
		cor(4);
		printf ("Arquivo preços.dat inexistente!");
		cor(15);
		getchar();
		exit (1);
	}

	int j=0;
	char a[50];
	
	while (fgets(a, 50, file) != NULL)
	{	fflush (stdin);
	
		if (j==0)
		{	arroz.valor = (float) atof(a);
			fflush (stdin);
		}
		else if (j==1)
		{	feijao.valor = (float) atof(a);
			fflush (stdin);
		}
		else if (j==2)
		{	cafe.valor = (float) atof(a);
			fflush (stdin);
		}
		else if (j==3)
		{	acucar.valor = (float) atof(a);
			fflush (stdin);
		}
		else if (j==4)
		{	sal.valor = (float) atof(a);
			fflush (stdin);
		}
		else if (j==5)
		{	farinha.valor = (float) atof(a);
			fflush (stdin);
		}
		else if (j==6)
		{	biscoito.valor = (float) atof(a);
			fflush (stdin);
		}
		else if (j==7)
		{	bolacha.valor = (float) atof(a);
			fflush (stdin);
		}
		else if (j==8)
		{	chocolate.valor = (float) atof(a);
			fflush (stdin);
		}
		else if (j==9)
		{	vinagre.valor = (float) atof(a);
			fflush (stdin);
		}
		
		j++;
	}
	
	fclose (file);
}

void trocarValor (pilha *X)
{	cor(12); 
	gotoxy(46, 24);
	printf ("Atenção: para separar casas decimais,");
	gotoxy(47, 25);
	printf (" use virgula! (não ponto)");
	
	do
	{	cor(10);
		gotoxy(11, 25);
		printf ("Insira o novo valor: R$");
		cor(7);
		fflush (stdin);
	}
	while (!(scanf ("%f", &X->valor)));
	
	if (X->valor<0)
	{	cor(15);
			
		printf  ("\n    \t                  |                                     |                      \n");
		printf("    \t                  |                                     |                      \n");
		printf("    \t                  |_____________________________________|                      \n");
		
		gotoxy (34,28);
		cor(15); printf ("Não foi possível alterar!");
		getch();
		atribuiPrecos();
		return;
	}
	
	fflush (stdin);
	atualizarValor ();
}
//---------------------------------------------------------------------------------------------------------------------------------


//BLOCO DE FUNÇÃO VI : MANIPULAÇÃO DE FILA -----------------------------------------------------------------------------------------
void cancelar (pilha *X, purchase *Y, char nome[])
{	pilha aux;

	int i;
	
	for (i=0; i<Y->qFila; i++)
		aux.prod[i] = Y->pFila[i];

	i=Y->qFila-1;

	do
	{	X->prod[X->qntd] = aux.prod[i];
		X->qntd++;
		i--;
	}
	while (i!=-1);
	
	armazenarDados (X, nome);
}

void removerGondola (pilha *X, int qd)
{
	X->qntd -= qd;
}

void addFila (pilha *X, purchase *Y, char nome[], char p[], int q)
{	int QTDE;

	do
	{	gotoxy(46, 23);
		cor(13); printf ("Insira a quantidade desse produto: ");
		fflush (stdin);
		cor(7);
	}
	while (!(scanf ("%d", &QTDE)));
	
	if (QTDE < 1)
	{	return;
	}
	
	if (QTDE > X->qntd)
	{	gotoxy(55, 25);
		cor(4); printf ("Estoque insuficiente!");
		getch();
		return;
	}
	
	int z, w=X->qntd-1;
	
	for (z=Y->qFila; z < Y->qFila + QTDE; z++)
	{	Y->pFila[z] = X->prod[w];
		w--;
	}
	
	Y->pInd =  (float) QTDE * X->valor;
	f.precoTot+= Y->pInd;

//sprintf -> transforma int/float em string

	char g[30], h[30], i[30], j[30], k[30], l[30], m[30];
	sprintf (g, "%d", q);
	input (g, 2);
	strcpy (h, p);
	input (h, 10);
	strcpy (i, X->peso);
	input (i, 4);
	strcpy (j, X->descricao);
	input (j, 10);
	sprintf (k, "%.2f", X->valor);
	input (k, 6);
	sprintf (l, "%d", QTDE);
	input (l, 5);
	sprintf (m, "%.2f", Y->pInd);
	input (m, 10);
	
	file = fopen (nome, "a+");
	fprintf (file, "\t | %s |  %s | %s | %18s  |        R$%s |     %s |        R$%s |			\n", g, h, i, j, k, l, m);
	fprintf (file, "\t |_____|______________|_______|_____________________|__________________|____________|______________________|			\n");
	fclose (file);
	
	Y->qFila += QTDE;
	
	removerGondola(X, QTDE);
	armazenarDados (X, p);
	abreDados (X, p);
}

void pegarData ()
{	struct tm *Dados;
	time_t segundos;
	time (&segundos);
	Dados = localtime (&segundos);
	
	f.precoTot = 0.00;
	
	remove ("data.txt");
	file = fopen ("data.txt", "a+");
	fprintf (file, "NF_%d-%d-%d_%d-%d-%d.txt\0", Dados->tm_mday, Dados->tm_mon+1, Dados->tm_year+1900, Dados->tm_hour, Dados->tm_min, Dados->tm_sec);
	fclose(file);
}

void pegarDataEnt ()
{	struct tm *Dados;
	time_t segundos;
	time (&segundos);
	Dados = localtime (&segundos);
	
	f.precoTot = 0.00;
	
	remove ("data.txt");
	file = fopen ("data.txt", "a+");
	fprintf (file, "NFEnt_%d-%d-%d_%d-%d-%d.txt\0", Dados->tm_mday, Dados->tm_mon+1, Dados->tm_year+1900, Dados->tm_hour, Dados->tm_min, Dados->tm_sec);
	fclose(file);
}
//---------------------------------------------------------------------------------------------------------------------------------


//MENUS -----------------------------------------------------------------------------------------------------------------------------
bool getsenha (char passwd[], int a)
{	char senha[6], verifica, i, indice, m;
	system ("CLS");
		
	for (i = 0; i <= 5; i++)
	{	indice = i;
	
		cor(15);
		tabela1();
		
		gotoxy (60,5);
		cor(13);
		printf ("Seja bem vindo,");
		gotoxy (51, 6);
		printf ("%s", user.nome);
		cor(10);
		gotoxy (20,5);
		printf ("MENU DE OPÇÕES");
		
		gotoxy (16, 10);
		cor(9);	printf ("1-");	cor(14);	printf ("Manejar Gôndolas");
		gotoxy (16, 14);
		cor(9);	printf ("2-");	cor(14);	printf ("Caixa/PDV");
		gotoxy (52, 10);
		cor(9);	printf ("3-");	cor(14);	printf ("Entregas em domicilio");
		gotoxy (52, 14);
		cor(9);	printf ("4-");	cor(14);	printf ("Gerenciar usuários");
		gotoxy (14, 18);
		cor(9);	printf ("0-");	cor(4);		printf ("Sair");
		gotoxy (30, 18);
		cor(9);	printf ("Informe a opção desejada: ");
		cor(15);
		gotoxy (72, 18);
		printf ("%d", a);
		fflush (stdin);
		
		printf("\n\n\n    \t                                      |                                      | \n");
		printf("    \t                                      |                                      | \n");
		printf("    \t                                      |______________________________________| \n");
		printf("    \t                                      |                                      | \n");
		printf("    \t                                      |                                      | \n");
		printf("    \t                                      |______________________________________| \n");
		
		gotoxy (50,22);
		
    	cor(13);
    					
		cor(9);
		printf ("Senha: ");
	
		if (i == 0)
		{	verifica = getch();		}
    	if (i == 1)	
		{	cor(15);
			printf("*");
	    	verifica = getch();		}
	    if (i == 2)
	    {	cor(15);
			printf("**");
	  		verifica = getch();		}
 	    if (i == 3)
	    {	cor(15);
			printf("***");
    		verifica = getch();		}
        if (i == 4)
	    {	cor(15);
			printf("****");
    		verifica = getch();		}
    	if (i==5)
	    {	cor(9);
	   		cor(15);
			printf("*****");
    		verifica = getch();
			cor(9);	;
	    	system("cls");
	   		cor(13);
	   				   		
	   		cor(15);
	   		tabela1();
		
			gotoxy (60,5);
			cor(13);
			printf ("Seja bem vindo,");
			gotoxy (51 , 6);
			printf ("%s", user.nome);
			cor(10);
			gotoxy (20,5);
			printf ("MENU DE OPÇÕES");
			
			gotoxy (16, 10);
			cor(9);	printf ("1-");	cor(14);	printf ("Manejar Gôndolas");
			gotoxy (16, 14);
			cor(9);	printf ("2-");	cor(14);	printf ("Caixa/PDV");
			gotoxy (52, 10);
			cor(9);	printf ("3-");	cor(14);	printf ("Entregas em domicilio");
			gotoxy (52, 14);
			cor(9);	printf ("4-");	cor(14);	printf ("Gerenciar usuários");
			gotoxy (14, 18);
			cor(9);	printf ("0-");	cor(4);		printf ("Sair");
			gotoxy (30, 18);
			cor(9);	printf ("Informe a opção desejada: ");
			cor(15);
			gotoxy (72, 18);
			printf ("%d", a);
			fflush (stdin);
			
			printf("\n\n\n    \t                                      |                                      | \n");
			printf("    \t                                      |                                      | \n");
			printf("    \t                                      |______________________________________| \n");
			printf("    \t                                      |                                      | \n");
			printf("    \t                                      |                                      | \n");
			printf("    \t                                      |______________________________________| \n");
			
			gotoxy (50,22);
			
	    	cor(13);
	    					
			cor(9);
			printf ("Senha: ");
    		cor(15);
			printf("******");
		}
		    	     
        if (verifica == 13)
        	break;
	    else
        	senha[i] = verifica;
	    if (i<5)
			system ("CLS");
	}
	   
	gotoxy (50,25);
	cor(6);
	printf ("Loading");
	for (m=0; m<=3; m++)
	{	sleep(1);
		printf (".");
		fflush (stdout);
	}
	cor(15);
		
	if (strcmp(senha, passwd)==0)
	{	gotoxy (50,25);
		cor(10);
		printf ("Acesso permitido!");
		cor(15);
		getchar();
		system ("CLS");
		return true;
	}
	else
	{	gotoxy (50,25);
		cor(4);
		printf ("Senha incorreta!");
		cor(15);
		getchar();
		return false;
	}
}

void getNF (char NF[], int q)
{	remove ("data.txt");

	struct tm *Dados;
	time_t segundos;
	time (&segundos);
	Dados = localtime (&segundos);
	
	int i, op;
	char a[25];
	bool chave=false;

	do
	{	do
		{	system ("CLS");
			tabela2(3);
			gotoxy(35, 23);
			cor(7);
			fflush (stdin);
		}
		while (!(scanf ("%d", &op)));
		
		if (op==1)
		{	if (f.prod[0].qntd==0)
			{	gotoxy(15, 25);
				cor(4); printf ("Estoque vazio!");
				getch();
				continue;
			}
			addFila (&f.prod[0], &f.compra[0], NF, "arroz", 1);
		}
		else if (op==2)
		{	if (f.prod[1].qntd==0)
			{	gotoxy(15, 25);
				cor(4); printf ("Estoque vazio!");
				getch();
				continue;
			}
			addFila (&f.prod[1], &f.compra[1], NF, "feijao", 2);
		}
		else if (op==3)
		{	if (f.prod[2].qntd==0)
			{	gotoxy(15, 25);
				cor(4); printf ("Estoque vazio!");
				getch();
				continue;
			}
			addFila (&f.prod[2], &f.compra[2], NF, "sal", 3);
		}
		else if (op==4)
		{	if (f.prod[3].qntd==0)
			{	gotoxy(15, 25);
				cor(4); printf ("Estoque vazio!");
				getch();
				continue;
			}
			addFila (&f.prod[3], &f.compra[3], NF, "acucar", 4);
		}
		else if (op==5)
		{	if (f.prod[4].qntd==0)
			{	gotoxy(15, 25);
				cor(4); printf ("Estoque vazio!");
				getch();
				continue;
			}
			addFila (&f.prod[4], &f.compra[4], NF, "cafe", 5);
		}
		else if (op==6)
		{	if (f.prod[5].qntd==0)
			{	gotoxy(15, 25);
				cor(4); printf ("Estoque vazio!");
				getch();
				continue;
			}
			addFila (&f.prod[5], &f.compra[5], NF, "bolacha", 6);
		}
		else if (op==7)
		{	if (f.prod[6].qntd==0)
			{	gotoxy(15, 25);
				cor(4); printf ("Estoque vazio!");
				getch();
				continue;
			}
			addFila (&f.prod[6], &f.compra[6], NF, "farinha", 7);
		}
		else if (op==8)
		{	if (f.prod[7].qntd==0)
			{	gotoxy(15, 25);
				cor(4); printf ("Estoque vazio!");
				getch();
				continue;
			}
			addFila (&f.prod[7], &f.compra[7], NF, "biscoito", 8);
		}
		else if (op==9)
		{	if (f.prod[8].qntd==0)
			{	gotoxy(15, 25);
				cor(4); printf ("Estoque vazio!");
				getch();
				continue;
			}
			addFila (&f.prod[8], &f.compra[8], NF, "chocolate", 9);
		}
		else if (op==10)
		{	if (f.prod[9].qntd==0)
			{	gotoxy(15, 25);
				cor(4); printf ("Estoque vazio!");
				getch();
				continue;
			}
			addFila (&f.prod[9], &f.compra[9], NF, "vinagre", 10);
		}
		else if (op==0)
		{
			if (f.precoTot <=0)
			{	remove (NF);
				return;
			}
			
			int pag;
			
			int b=0;
			float val, troco;
			char cart[20], senha[6];
			
			do
			{	do
				{	system ("CLS");
					tabela3();
					gotoxy (37, 4);
					cor(10); printf ("Valor final: R$%.2f", f.precoTot);
					
					gotoxy(15, 8);  
					cor(9); printf ("1-"); cor(14); printf ("Pagamento em dinheiro");
					gotoxy(51, 8);
					cor(9); printf ("2-"); cor(14); printf ("Pagamento em cartão");
					
					gotoxy(12, 12);
					cor(9); printf ("0-"); cor(4); printf ("Voltar");
					
					gotoxy (30, 12);
					cor(9);	printf ("Informe a opção desejada: ");
					cor(7);
					gotoxy (72, 12);
					fflush (stdin);
				}
				while (!(scanf ("%d", &pag)));
				
				if (pag==1)
				{	b=0;
					
					do
					{	system ("CLS");
						tabela3();
						gotoxy (37, 4);
						cor(10); printf ("Valor final: R$%.2f", f.precoTot);
						
						gotoxy(15, 8);  
						cor(9); printf ("1-"); cor(14); printf ("Pagamento em dinheiro");
						gotoxy(51, 8);
						cor(9); printf ("2-"); cor(14); printf ("Pagamento em cartão");
						
						gotoxy(12, 12);
						cor(9); printf ("0-"); cor(4); printf ("Voltar");
						
						gotoxy (30, 12);
						cor(9);	printf ("Informe a opção desejada: ");
						cor(7);
						gotoxy (72, 12);
						printf ("%d", pag);
						fflush (stdin);
						
						cor(11);
						gotoxy(15, 15);
						printf ("Insira o valor recebido: R$"); cor(7);
					}
					while (!(scanf ("%f", &val)));
					
					if (val<f.precoTot)
					{	gotoxy(51, 15);
						cor(4); printf ("Saldo insuficiente");
						getch();
					}
					else
					{	troco = val-f.precoTot; 
						gotoxy(51, 15);
						cor(11); printf ("Troco: R$%.2f", troco);
						b=1;
						chave=true;
					}
				}
				
				else if (pag==2)
				{	system ("CLS");
					tabela3();
					gotoxy (37, 4);
					cor(10); printf ("Valor final: R$%.2f", f.precoTot);
					
					gotoxy(15, 8);  
					cor(9); printf ("1-"); cor(14); printf ("Pagamento em dinheiro");
					gotoxy(51, 8);
					cor(9); printf ("2-"); cor(14); printf ("Pagamento em cartão");
						
					gotoxy(12, 12);
					cor(9); printf ("0-"); cor(4); printf ("Voltar");
						
					gotoxy (30, 12);
					cor(9);	printf ("Informe a opção desejada: ");
					cor(7);
					gotoxy (72, 12);
					printf ("%d", pag);
					fflush (stdin);
					
					cor(11);
					gotoxy(15, 15);
					fflush (stdin);
					printf ("Insira o cartão: ");
					cor(7);
					fgets (cart, 20, stdin);
					fflush (stdin);
					
					int i, verifica, indice, m;
					
					system ("cls");
					
					for (i = 0; i <= 5; i++)
				    {	indice = i;
				    	
				    	system ("CLS");
						tabela3();
						gotoxy (37, 4);
						cor(10); printf ("Valor final: R$%.2f", f.precoTot);
						
						gotoxy(15, 8);  
						cor(9); printf ("1-"); cor(14); printf ("Pagamento em dinheiro");
						gotoxy(51, 8);
						cor(9); printf ("2-"); cor(14); printf ("Pagamento em cartão");
							
						gotoxy(12, 12);
						cor(9); printf ("0-"); cor(4); printf ("Voltar");
							
						gotoxy (30, 12);
						cor(9);	printf ("Informe a opção desejada: ");
						cor(7);
						gotoxy (72, 12);
						printf ("%d", pag);
						fflush (stdin);
						
						cor(11);
						gotoxy(15, 15);
						fflush (stdin);
						printf ("Insira o cartão: ");
						cor(7);
						printf ("%s", cart);
						
						gotoxy(51, 15);
						cor(11);
						printf ("Senha: ");
						cor(7);
				
						if (i == 0)
						{	verifica = getch();		}
				    	if (i == 1)
				        {	printf("*");
				    		verifica = getch();		}
				        if (i == 2)
				        {	printf("**");
				    		verifica = getch();		}
				        if (i == 3)
				        {	printf("***");
				    		verifica = getch();		}
				        if (i == 4)
				    	{	printf("****");
				    		verifica = getch();		}
				    	if (i==5)
				    	{	printf("*****");
				    		verifica = getch();
							cor(9);	;
				    		system ("CLS");
				    		
							tabela3();
							gotoxy (37, 4);
							cor(10); printf ("Valor final: R$%.2f", f.precoTot);
							
							gotoxy(15, 8);  
							cor(9); printf ("1-"); cor(14); printf ("Pagamento em dinheiro");
							gotoxy(51, 8);
							cor(9); printf ("2-"); cor(14); printf ("Pagamento em cartão");
								
							gotoxy(12, 12);
							cor(9); printf ("0-"); cor(4); printf ("Voltar");
								
							gotoxy (30, 12);
							cor(9);	printf ("Informe a opção desejada: ");
							cor(7);
							gotoxy (72, 12);
							printf ("%d", pag);
							fflush (stdin);
							
							cor(11);
							gotoxy(15, 15);
							fflush (stdin);
							printf ("Insira o cartão: ");
							cor(7);
							printf ("%s", cart);
							
							gotoxy(51, 15);
							cor(11);
							printf ("Senha: ");
							cor(7);
							printf("******");
							cor(9);
						}
				    	     
				        if (verifica == 13)
				        	break;
				        else
				        	senha[i] = verifica;
				        if (i<5)
							system ("CLS");
				    }
				    
				    cor(15);
					printf("\n\n    \t                  |                                     |                        \n");
					printf("    \t                  |                                     |                      \n");
					printf("    \t                  |_____________________________________|                      \n");
						    
					gotoxy (41, 18);
				    cor(6);
				    printf ("Loading");
					for (m=0; m<=3; m++)
					{	sleep(1);
						printf (".");
						fflush (stdout);
					}
					  
					gotoxy (35, 18); 
					cor(10); printf ("Transação permitida!");
					b=1;
					chave=true;
				}
				else if (pag==0)
					break;
			}
			while (b!=1);
			
			getch();

			
			if (pag==0)
				continue;
			
			cor(8);
			char z[30];
			sprintf (z, "%.2f", f.precoTot);
			input (z, 10);
			file = fopen (NF, "a+");
			fprintf (file, "\t |                                                                 Total da Compra  |        R$%s |			\n", z);
			fprintf (file, "\t |__________________________________________________________________________________|______________________|			\n");
			
			if (pag==1)
			{	char d[30], e[30];
				sprintf (d, "%.2f", val);
				sprintf (e, "%.2f", troco);
				input (d, 10);
				input (e, 10);
			
				fprintf (file, "\t |                                                              Forma de pagamento  |       Dinheiro       |			\n");
				fprintf (file, "\t |__________________________________________________________________________________|______________________|			\n");
				fprintf (file, "\t |                                                                      Valor pago  |        R$%s |			\n", d);
				fprintf (file, "\t |__________________________________________________________________________________|______________________|			\n");
				fprintf (file, "\t |                                                                           Troco  |        R$%s |			\n", e);
				fprintf (file, "\t |__________________________________________________________________________________|______________________|			\n");
			}
			else
			{	char f[30];
				strcpy (f, cart);
				
				f[strlen(f)-1]=32;
				
				int j = strlen(f)/2;
				for (i=0; i<=j; i++)
					f[i] = 42;
				
				input (f, 13);
				fprintf (file, "\t |                                                              Forma de pagamento  |       Cartão         |			\n");
				fprintf (file, "\t |__________________________________________________________________________________|______________________|			\n");
				fprintf (file, "\t |                                                                Número do cartão  |       %s |			\n", f);
				fprintf (file, "\t |__________________________________________________________________________________|______________________|			\n");
			}
			 
			fprintf (file, "\t |   	Data: %02d/%02d/%d	       Hora: %02d:%02d:%02d             Caixa #1	    |							\n", Dados->tm_mday, Dados->tm_mon+1, Dados->tm_year+1900, Dados->tm_hour, Dados->tm_min, Dados->tm_sec);
			fprintf (file, "\t |__________________________________________________________________________________|									\n");
			
			fclose(file);
			
			system("cls");
			
			file = fopen (NF, "r+");
			system("COLOR E0");
			while(fgets(a, 25, file)!=NULL)
				printf ("%s", a);
			fclose(file);
			
			getch();
			system("COLOR 0F");
			
			if (q==1)
			{	int temp;
				do
				{	temp = (rand()%100) + Dados->tm_sec;
				}
				while (temp<5 || temp>120);
				
				system ("CLS");
				
				tabela4();
				gotoxy (20, 5);
				cor(4); printf ("Cadastro de pedido");
				gotoxy(15,10);
				cor(1); printf ("Nome do cliente: ");
				gotoxy(15,14);
				cor(1); printf ("Endereço do cliente: ");
				cor(7);
				
				gotoxy(43, 10);
				printf ("%s", enc.nome);
				gotoxy(43, 14);
				printf ("%s", enc.endereco);
				gotoxy (30, 18);
				cor(6);
				printf ("Tempo previsto: %d minutos", temp);
				
				getch();
			}
			return;
		}
		else if (op<0 && op==-1)
		{	remove (NF);
		
			if (f.compra[0].qFila>0)
				cancelar (&f.prod[0], &f.compra[0], "arroz");
			if (f.compra[1].qFila>0)
				cancelar (&f.prod[1], &f.compra[1], "feijao");
			if (f.compra[2].qFila>0)
				cancelar (&f.prod[2], &f.compra[2], "sal");
			if (f.compra[3].qFila>0)
				cancelar (&f.prod[3], &f.compra[3], "acucar");
			if (f.compra[4].qFila>0)
				cancelar (&f.prod[4], &f.compra[4], "cafe");
			if (f.compra[5].qFila>0)
				cancelar (&f.prod[5], &f.compra[5], "bolacha");
			if (f.compra[6].qFila>0)
				cancelar (&f.prod[6], &f.compra[6], "farinha");
			if (f.compra[7].qFila>0)
				cancelar (&f.prod[7], &f.compra[7], "biscoito");
			if (f.compra[8].qFila>0)
				cancelar (&f.prod[8], &f.compra[8], "chocolate");
			if (f.compra[9].qFila>0)
				cancelar (&f.prod[9], &f.compra[9], "vinagre");
			return;
		}					
		else
		{	cor(15);
			printf("\n\n\n    \t                  |                                     |                      \n");
			printf("    \t                  |_____________________________________|                      \n");
			
			gotoxy (37, 27);
			printf ("Comando inválido!");
			getch();
		}
	}
	while (chave==false);
}

void gerenciarUsuario ()
{	int op;

	cad = (login *) malloc (sizeof(login));
	TransfereDados();

	system ("TITLE Sistema Gerenciador de Supermercado: Gerenciar usuários");

	do
	{	do
		{	system ("CLS");
			cor(15);
			tabela1();
			
			gotoxy (17,5);
			cor(10);
			printf ("GERENCIAR USUÁRIOS \n");
			gotoxy (15, 10);
			cor(9);	printf ("1-");	cor(14);	printf ("Visualizar usuarios.dat");
			gotoxy (15, 14);
			cor(9);	printf ("2-");	cor(14);	printf ("Cadastrar usuário");
			gotoxy (52, 10);
			cor(9);	printf ("3-");	cor(14);	printf ("Buscar usuário no sistema");
			gotoxy (52, 14);
			cor(9);	printf ("4-");	cor(14);	printf ("Quantidade de registros");
			gotoxy (14, 18);
			cor(9);	printf ("0-");	cor(4);	printf ("Retornar");
		
			gotoxy (30, 18);
			cor(9);	printf ("Informe a opção desejada: ");	cor(7);
			
			gotoxy (72, 18);
			fflush (stdin);
		}
		while (!(scanf ("%d", &op)));
			
		if (op==1)
		{	int i;
			system("CLS");
			cor(15); 
			for (i=0; i<tam; i++)
			{	fflush (stdin);
				printf ("\n\n\t\tNome %i: %s \t\tProntuário %i: %s", (i+1), cad[i].nome, (i+1), cad[i].pront);
				fflush (stdin);
			}
		}
			
		else if (op==2)
		{	system ("CLS");
			tabela4(); 
			cor(4); gotoxy (20, 5);
			printf ("Cadastro de usuário");
			cor(1);
			gotoxy(15,10);
			printf ("Nome do usuário: ");
			gotoxy(15,14);
			printf ("Prontuário do usuário: ");
			
			cor(7);
			fflush (stdin);
			gotoxy(45, 10);
			fgets (cad[tam].nome, 50, stdin);		//gets(cad[tam].nome);
			fflush (stdin);
			gotoxy(45, 14);
			fgets (cad[tam].pront, 11, stdin);		//gets(cad[tam].pront);
			fflush (stdin);
			
			if (strlen(cad[tam].nome)<2 || strlen(cad[tam].pront)<2)
				continue;
			
			int m; 
			for (m=0; user.nome[m]!='\0'; m++)
				cad[tam].nome[m] = toupper (cad[tam].nome[m]);
			for (m=0; user.pront[m]!='\0'; m++)
				cad[tam].pront[m] = toupper (cad[tam].pront[m]);
			
			tam++;
			cad = (login *) realloc (cad, (tam+1)*sizeof(login));
			
			if (cad == NULL)
			{	system ("CLS");
	
				tabelaErro();
						
				gotoxy (33, 3);
				cor(4);
				printf("Erro de alocação de memória");
				gotoxy (35, 4);
				printf("realloc devolveu NULL!");
				cor(7);
				printf ("\n\n\n\n\n\n\n\n\n");
				exit(1);
			}
			
			fflush (stdin);
			quick (cad, 0, tam-1);
			atualizarArquivo ();
			fflush (stdin);
		}
		
		else if (op==3)
		{	chave=false;
		
			login b;
			
			system ("CLS");
			tabela4();
			cor(4); gotoxy (20, 5);
			printf ("Cadastro de usuário");
			cor(1);
			gotoxy(15,10);
			printf ("Nome do usuário: ");
			gotoxy(15,14);
			printf ("Prontuário do usuário: ");
			
			cor(7);
			fflush (stdin);
			gotoxy(50, 10);
			fgets (b.nome, 50, stdin);
			fflush (stdin);
			gotoxy(50, 14);
			fgets (b.pront, 11, stdin);
			fflush (stdin);
			
			int m; 
			for (m=0; user.nome[m]!='\0'; m++)
				b.nome[m] = toupper (b.nome[m]);
			for (m=0; user.pront[m]!='\0'; m++)
				b.pront[m] = toupper (b.pront[m]);
			
			BuscaBin (cad, 0, tam-1, b);
			
			if (chave==true)
			{	gotoxy (30, 18);
				cor(10); printf ("Usuário cadastrado!");
			}
			else
			{	gotoxy (30, 18);
				cor(4); printf ("Usuário não cadastrado!");
			}
		}
		
		else if (op==4)
		{	cor(15);
			printf("\n\n    \t                                      |                                      | \n");
			printf("    \t                                      |                                      | \n");
			printf("    \t                                      |______________________________________| \n");
			
			gotoxy (50,22);
			cor(3); printf ("Há %d cadastros no sistema!", tam);
		}
		
		else if (op==0)
		{	int i;
			int j=tam;
	
			for (i=0; i<j-1; i++)
			{	cad = (login *) realloc (cad, (tam-1)*sizeof(login));
				tam--;
						
				if (cad == NULL)
				{	system ("CLS");
			
					tabelaErro();
									
					gotoxy (33, 3);
					cor(4);
					printf("Erro de alocação de memória");
					gotoxy (35, 4);
					printf("realloc devolveu NULL!");
					cor(7);
					printf ("\n\n\n\n\n\n\n\n\n");
					exit(1);
				}
			}
			free (cad);
			tam=0;
			return;
		}
		
		else
		{	cor(15);
			printf("\n\n    \t                  |                                     |                      \n");
			printf("    \t                  |_____________________________________|                      \n");
			
			gotoxy (37, 21);
			cor(4); printf ("Comando inválido!");
		}
		
		getch();
		system ("cls");
	}
	while (op!=0);
}

void manejar ()
{	int op1, op2;
	system ("TITLE Sistema Gerenciador de Supermercado: Manejar Gôndolas");
	
	if (arroz.qntd!=0)
		at (&arroz, "arroz");
	if (feijao.qntd!=0)
		at (&feijao, "feijao");
	if (sal.qntd!=0)
		at (&sal, "sal");
	if (acucar.qntd!=0)
		at (&acucar, "acucar");
	if (cafe.qntd!=0)
		at (&cafe, "cafe");
	if (bolacha.qntd!=0)
		at (&bolacha, "bolacha");
	if (farinha.qntd!=0)
		at (&farinha, "farinha");
	if (biscoito.qntd!=0)
		at (&biscoito, "biscoito");
	if (chocolate.qntd!=0)
		at (&chocolate, "chocolate");
	if (vinagre.qntd!=0)
		at (&vinagre, "vinagre");
	
	do
	{	do
		{	system ("CLS");
			tabela1();
			gotoxy (17,5);
			cor(10); printf ("MANEJAR GÔNDOLAS \n");
			gotoxy (15, 10);
			cor(9); printf ("1- "); cor(14); printf ("Abastecer Gôndolas");
			gotoxy (15, 14);
			cor(9); printf ("2- "); cor(14); printf ("Visualizar abastecimento");
			gotoxy (52, 10);
			cor(9); printf ("3- "); cor(14); printf ("Alterar preços");
			gotoxy (52, 14);
			cor(9); printf ("4- "); cor(14); printf ("Visualizar preços");
			gotoxy (14, 18);
			cor(9); printf ("0- "); cor(4); printf ("Retornar");
			gotoxy (30, 18);
			cor(9);	printf ("Informe a opção desejada: ");
			cor(7);
			
			gotoxy (72, 18);
			fflush (stdin);
		}
		while (!(scanf ("%d", &op1)));
		
		if (op1==1)
		{	do
			{	system ("CLS");
				tabela2(2);
				cor(7);
				gotoxy(35, 23);
				fflush (stdin);
			}
			while (!(scanf ("%d", &op2)));

			if (op2==1)
				empilhar (&arroz, "arroz");
			else if (op2==2)
				empilhar (&feijao, "feijao");
			else if (op2==3)
				empilhar (&sal, "sal");
			else if (op2==4)
				empilhar (&acucar, "acucar");
			else if (op2==5)
				empilhar (&cafe, "cafe");
			else if (op2==6)
				empilhar (&bolacha, "bolacha");
			else if (op2==7)
				empilhar (&farinha, "farinha");
			else if (op2==8)
				empilhar (&biscoito, "biscoito");
			else if (op2==9)
				empilhar (&chocolate, "chocolate");
			else if (op2==10)
				empilhar (&vinagre, "vinagre");
			else if (op2==-1 && op2<0)
				continue;
			else
			{	cor(4);
				printf ("\n\t\tComando inválido!");
			}
				
			fflush (stdin);
		}
		
		else if (op1==2)
		{	system ("CLS");
			tabela2(1);
			cor(11);
			gotoxy(27, 8);
			printf ("%d un", arroz.qntd);
			gotoxy(52, 8);
			printf ("%d un", feijao.qntd);
			gotoxy (75, 8);
			printf ("%d un", sal.qntd);
			gotoxy(27, 12);
			printf ("%d un", acucar.qntd);
			gotoxy(52, 12);
			printf ("%d un", cafe.qntd);
			gotoxy (75, 12);
			printf ("%d un", bolacha.qntd);
			gotoxy(27, 16);
			printf ("%d un", farinha.qntd);
			gotoxy(52, 16);
			printf ("%d un", biscoito.qntd);
			gotoxy(75, 16);
			printf ("%d un", chocolate.qntd);
			gotoxy(27, 20);
			printf ("%d un", vinagre.qntd);
			getch();
			
			fflush (stdin);
		}
		
		else if (op1==3)
		{	do
			{	system ("CLS");
				tabela2(2);
				gotoxy(35, 23);
				cor(7);
				fflush (stdin);
			}
			while (!(scanf ("%d", &op2)));
			
			if (op2==1)
				trocarValor (&arroz);
			else if (op2==2)
				trocarValor (&feijao);
			else if (op2==3)
				trocarValor (&sal);
			else if (op2==4)
				trocarValor (&acucar);
			else if (op2==5)
				trocarValor (&cafe);
			else if (op2==6)
				trocarValor (&bolacha);
			else if (op2==7)
				trocarValor (&farinha);
			else if (op2==8)
				trocarValor (&biscoito);
			else if (op2==9)
				trocarValor (&chocolate);
			else if (op2==10)
				trocarValor (&vinagre);
			else if (op2==-1 && op2<0)
				continue;
			else
			{	cor(4);
				printf ("\n\t\tComando inválido!");
			}
				
			fflush (stdin);
		}
		
		else if (op1==4)
		{	system ("CLS");
			tabela2(1);
			cor(10);
			gotoxy(25, 8);
			printf ("R$%.2f", arroz.valor);
			gotoxy(50, 8);
			printf ("R$%.2f", feijao.valor);
			gotoxy (74, 8);
			printf ("R$%.2f", sal.valor);
			gotoxy(25, 12);
			printf ("R$%.2f", acucar.valor);
			gotoxy(50, 12);
			printf ("R$%.2f", cafe.valor);
			gotoxy (74, 12);
			printf ("R$%.2f", bolacha.valor);
			gotoxy(25, 16);
			printf ("R$%.2f", farinha.valor);
			gotoxy(50, 16);
			printf ("R$%.2f", biscoito.valor);
			gotoxy(74, 16);
			printf ("R$%.2f", chocolate.valor);
			gotoxy(25, 20);
			printf ("R$%.2f", vinagre.valor);
			getch();
			
			fflush (stdin);
		}
		
		else if (op1==0)
			return;
		
		else
		{	cor(15);
			printf("\n\n    \t                  |                                     |                      \n");
			printf("    \t                  |_____________________________________|                      \n");
			
			cor(4);
			gotoxy (37, 21);
			printf ("Comando inválido!");
			getch();
		}
		
		fflush (stdin);
	}
	while (op1!=0);
}

void Caixa()
{	int op;
	system ("TITLE Sistema Gerenciador de Supermercado : Caixa/PDV");

	char NF[30];
	
	pegarData();
	
	char a[30];
	file = fopen ("data.txt", "r+");
	while(fgets(a, 30, file)!='\0')
		strcpy(NF, a);
	fclose(file);
	file = fopen(NF, "w");
	fprintf (file, "\t ._______________.																							\n");
	fprintf (file, "\t |  NOTA FISCAL  |																							\n");
	fprintf (file, "\t |_______________|_________________________________________________________________________________________.			\n");
	fprintf (file, "\t | Cod |   Produto    | Peso  |     Descricao       |  Preço Unitário  | Quantidade | Valor do Item Pedido |			\n");
	fprintf (file, "\t |_____|______________|_______|_____________________|__________________|____________|______________________|			\n");
	fclose(file);

	getNF (NF, 0);
}

void Entregas ()
{
	system ("TITLE Sistema Gerenciador de Supermercado : Entregas em Domicílios");
	
	system ("CLS");
	
	char NF[35];
	
	int op;
	tabela4();
	gotoxy (20, 5);
	cor(4); printf ("Cadastro de pedido");
	gotoxy(15,10);
	cor(1); printf ("Nome do cliente: ");
	gotoxy(15,14);
	cor(1); printf ("Endereço do cliente: ");
	cor(7);
	
	char t[50], u[60];
	
	fflush (stdin);
	gotoxy(43, 10);
	fgets (t, 25, stdin);
	
	fflush (stdin);
	gotoxy(43, 14);
	fgets (u, 30, stdin);
		
	t[strlen(t)-1] = '\0';
	u[strlen(u)-1] = '\0';
	
	pegarDataEnt();
	
	char a[35];
	file = fopen ("data.txt", "r+");
	while(fgets(a, 35, file)!='\0')
		strcpy(NF, a);
	fclose(file);

	strcpy (enc.nome, t);
	strcpy (enc.endereco, u);
	
	int r, s, w=0, i=0;
	r = strlen(t);
	s = strlen(u);
	
	input (t, 35);
	input (u, 38);

	file = fopen(NF, "w");
	fprintf (file, "\t ._______________.																							\n");
	fprintf (file, "\t |  NOTA FISCAL  |																							\n");
	fprintf (file, "\t |_______________|_________________________________________________________________________________________.			\n");
	fprintf (file, "\t |	Nome: %20s  |	Endereço: %20s  |			\n", t, u);
	fprintf (file, "\t |__________________________________________________|______________________________________________________|			\n");
	fprintf (file, "\t | Cod |   Produto    | Peso  |     Descricao       |  Preço Unitário  | Quantidade | Valor do Item Pedido |			\n");
	fprintf (file, "\t |_____|______________|_______|_____________________|__________________|____________|______________________|			\n");
	fclose(file);
	
	getNF (NF, 1);
}

//Função que leva às funções principais do sistema
void menu ()
{	int op, i;
	bool ok;
	int j=tam;
	
	for (i=0; i<j-1; i++)
	{	cad = (login *) realloc (cad, (tam-1)*sizeof(login));
		tam--;
				
		if (cad == NULL)
		{	system ("CLS");
	
			tabelaErro();
							
			gotoxy (33, 3);
			cor(4);
			printf("Erro de alocação de memória");
			gotoxy (35, 4);
			printf("realloc devolveu NULL!");
			cor(7);
			printf ("\n\n\n\n\n\n\n\n\n");
			exit(1);
		}
	}
	free (cad);
	tam=0;
	
	struct tm *data_hora_atual;					//ponteiro para struct que armazena data e hora
	time_t segundos;							//variável do tipo time_t para armazenar o tempo em segundos  
	time (&segundos);							//obtendo o tempo em segundos 
	data_hora_atual = localtime(&segundos);		//para converter de segundos para o tempo local, utilizamos a função localtime
	
	file = fopen ("Controle de Usuário.txt", "a+");
	
	for (i=0; user.nome[i+1]!='\0'; i++)
		fputc (user.nome[i], file);
		
	fprintf (file, " (");
		
	for (i=0; user.pront[i+1]!='\0'; i++)
		fputc (user.pront[i], file);
		
	fprintf (file, ")");
	
	fprintf(file, "\n\tLogin  : %d/%d/%d ", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900);
	fprintf(file, "%d:%d:%d ", data_hora_atual->tm_hour, data_hora_atual->tm_min, data_hora_atual->tm_sec);
	
	fclose(file);

	do
	{	//Atribuindo os produtos na struct fila
		f.prod[0] = arroz;
		f.prod[1] = feijao;
		f.prod[2] = sal;
		f.prod[3] = acucar;
		f.prod[4] = cafe;
		f.prod[5] = bolacha;
		f.prod[6] = farinha;
		f.prod[7] = biscoito;
		f.prod[8] = chocolate;
		f.prod[9] = vinagre;

		system ("TITLE Sistema Gerenciador de Supermercado");
	
		do
		{	system ("CLS");
			
			tabela1();
			
			gotoxy (60,5);
			cor(13);
			printf ("Seja bem vindo,");
			gotoxy (51, 6);
			printf ("%s", user.nome);
			cor(10);
			gotoxy (20,5);
			printf ("MENU DE OPÇÕES");
			
			gotoxy (16, 10);
			cor(9);	printf ("1-");	cor(14);	printf ("Manejar Gôndolas");
			gotoxy (16, 14);
			cor(9);	printf ("2-");	cor(14);	printf ("Caixa/PDV");
			gotoxy (52, 10);
			cor(9);	printf ("3-");	cor(14);	printf ("Entregas em domicilio");
			gotoxy (52, 14);
			cor(9);	printf ("4-");	cor(14);	printf ("Gerenciar usuários");
			gotoxy (14, 18);
			cor(9);	printf ("0-");	cor(4);		printf ("Sair");
			gotoxy (30, 18);
			cor(9);	printf ("Informe a opção desejada: ");
			cor(7);
			gotoxy (72, 18);
			fflush (stdin);
		}
		while (!(scanf ("%d", &op)));
		
		if (op==1)
		{	ok = getsenha ("abc123", 1);
			if (ok == true)
				manejar();
		}
		
		else if (op==2 || op==3)
		{	if (op==2)
				Caixa();
			
			else if (op==3)
				Entregas();
			
			arroz = f.prod[0];
			feijao = f.prod[1];
			sal = f.prod[2];
			acucar = f.prod[3];
			cafe = f.prod[4];
			bolacha = f.prod[5];
			farinha = f.prod[6];
			biscoito = f.prod[7];
			chocolate = f.prod[8];
			vinagre = f.prod[9];
			
			for (i=0; i<=9; i++)
			{	f.compra[i].qFila = 0;
				f.compra[i].pInd = 0.00;
			}
			f.precoTot = 0.00;
		}
		
		else if (op==4)
		{	ok = getsenha ("abc123", 4);
			if (ok == true)
				gerenciarUsuario();
		}
		
		else if (op==0)
		{	cor(15);
			printf("\n\n    \t                  |                                     |                      \n");
			printf("    \t                  |_____________________________________|                      \n");
			
			cor(10);
			gotoxy (37, 21);
			printf ("Logoff realizado!");
			printf ("\n\n\n\n\n\n\n\n\n");
			cor(7);
			
			time_t segundos;
			time (&segundos);
			data_hora_atual = localtime(&segundos);	
			
			file = fopen ("Controle de Usuário.txt", "a+");
			
			fprintf(file, "\n\tLogout : %d/%d/%d ", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900);
			fprintf(file, "%d:%d:%d \n\n", data_hora_atual->tm_hour, data_hora_atual->tm_min, data_hora_atual->tm_sec);
			
			fclose (file);
			
			int i;
			
			exit(0);
		}
		
		else
		{	cor(15);
			printf("\n\n    \t                  |                                     |                      \n");
			printf("    \t                  |_____________________________________|                      \n");
			
			cor(4);
			gotoxy (37, 21);
			printf ("Comando inválido!");
			getch();
		}
		
		//getchar();
		fflush (stdin);
	}
	while (op!=0);
}

int main ()
{	setlocale (LC_ALL, "");

	strcpy (arroz.peso, "5 KG");
	strcpy (feijao.peso, "1 KG");
	strcpy (cafe.peso, "100 G");
	strcpy (acucar.peso, "200 G");
	strcpy (sal.peso, "200 G");
	strcpy (farinha.peso, "400 G");
	strcpy (biscoito.peso, "750 G");
	strcpy (bolacha.peso, "500 G");
	strcpy (chocolate.peso, "500 G");
	strcpy (vinagre.peso, "1 L");
	
	strcpy (arroz.descricao, 		"Arroz integral");
	strcpy (feijao.descricao, 		"Feijão carioca");
	strcpy (cafe.descricao, 		"Café em pó");
	strcpy (acucar.descricao,		"Açúcar refinado");
	strcpy (sal.descricao, 			"Sal iodado");
	strcpy (farinha.descricao, 		"Farinha de trigo");
	strcpy (biscoito.descricao, 	"Biscoito de leite");
	strcpy (bolacha.descricao, 		"Bolacha recheada");
	strcpy (chocolate.descricao, 	"Barra de chocolate");
	strcpy (vinagre.descricao, 		"Vinagre de maçã");
	
	abreDados (&arroz, "arroz");
	abreDados (&feijao, "feijao");
	abreDados (&sal, "sal");
	abreDados (&acucar, "acucar");
	abreDados (&cafe, "cafe");
	abreDados (&bolacha, "bolacha");
	abreDados (&farinha, "farinha");
	abreDados (&biscoito, "biscoito");
	abreDados (&chocolate, "chocolate");
	abreDados (&vinagre, "vinagre");
	
	atribuiPrecos();

	cad = (login *) malloc (sizeof(login));
	TransfereDados();
	
	int i=0;

	if (cad == NULL)
	{	system ("CLS");
		tabelaErro();
		gotoxy (33, 3);
		cor(4);
		printf("Erro de alocação de memória");
		gotoxy (35, 4);
		printf("malloc devolveu NULL!");
		cor(7);
		printf ("\n\n\n\n\n\n\n\n\n");
		exit(1);
	}
	
	int m, n=0;

	do
	{	system ("TITLE Sistema Gerenciador de Supermercado: Login");
		
		tabela4();
		gotoxy (25, 5);
	
		gotoxy (25, 5);
		cor(13);
		puts("LOGIN DO SISTEMA");
		cor(15);	
		gotoxy (15,10);
		cor(9);
		puts ("Nome do usuário ");
		gotoxy (15,14);
		puts ("Prontuário do usuário ");
		cor(15);
		
		cor(7);
		fflush (stdin);
		gotoxy(45, 10);
		fgets (user.nome, 50, stdin);
		fflush (stdin);
		
		gotoxy(45, 14);
		fgets (user.pront, 11, stdin);
		fflush (stdin);
		
		for (m=0; user.nome[m]!='\0'; m++)
			user.nome[m] = toupper (user.nome[m]);
		for (m=0; user.pront[m]!='\0'; m++)
			user.pront[m] = toupper (user.pront[m]);
		
		gotoxy (34, 16);
		cor(6);
		printf ("\n\n\t\t\t\tLoading");
		for (m=0; m<=2; m++)
		{	sleep(1);
			printf (".");
			fflush (stdout);
		}
		
		char a[50];
		m=0;
		
		BuscaBin (cad, 0, tam-1, user);
		
		if (chave==true)
		{	gotoxy (34, 16);
			cor(15);
			printf("\n\n\t\t\t  |");
			cor(10);
			printf ("     Acesso permitido!");
			cor(7);
			getchar();
			menu();
		}
		else
		{	gotoxy (34, 15);
		//	system("COLOR 40");
			cor(12);
			printf ("\n\n\t\t\t\t         Acesso negado! \n\t\t\t\tUsuário e/ou prontuário inválido!\n\n");
		}
		i++;
		
		if (i==3)
		{	cor(4);
			printf ("\n\n\n\t\t\t\tLogin incorreto 3 tentativas seguidas.\n\t\t\t\t\tDesligando o sistema...\n\n");
			cor(15);
			break;
		}
		getchar();
		//system("COLOR 0F");
		system ("CLS");
		fflush (stdin);
	}
	while (i!=3);
}
