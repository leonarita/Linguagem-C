#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

typedef struct sNo
{	int N;
	struct sNo *Prox;
}
NO;

void Inic (NO** Pilha)
{	*Pilha = NULL;	}

void Push (NO** Pilha, int Num)
{	NO* Tmp;
	
	Tmp = (NO *) malloc (sizeof(NO));
	
	if (Tmp == NULL)
		return;
	Tmp->Prox = *Pilha;
	*Pilha=Tmp;
}

int Empty (NO* Pilha)
{	return (Pilha==NULL);	}

void Pop (NO** Pilha)
{	NO *Tmp = *Pilha;
	
	if (Empty(*Pilha))
		return;
	
	*Pilha = (*Pilha)->Prox;
	free (Tmp);
}

void Print (NO* Pilha)
{
	if (Empty(Pilha))
		return;
	printf ("%d \n", Pilha->N);
	Print (Pilha->Prox);
}

int Top (NO *Pilha)
{
	if (Empty(Pilha))
		return -1;
	return Pilha->N;
}

int main ()
{	setlocale (LC_ALL, "");

	NO* P;
	
	Inic (&P);
	printf ("%s está vazia\n", Empty(P)?"":"Não");
	Print (P);
	puts ("Push: 10");
	Push (&P, 10);
	puts ("Push: 20");
	Push (&P, 20);
	puts ("Push: 30");
	Push (&P, 30);
	printf ("%s está vazia\n", Empty(P)?"":"Não");
	Print (P);
	puts ("Pop: ");
	Pop (&P);
	Print (P);
	puts ("Pop: ");
	Pop (&P);
	Print (P);
	puts ("Pop: ");
	Pop (&P);
	Print (P);
	printf ("%s está vazia\n", Empty(P)?"":"Não");
}
