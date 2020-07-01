#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

typedef struct sPessoa
{	int Idade;
	char Nome[20+1];
	struct sPessoa *Prox;
}
PESSOA;

typedef PESSOA* FILA;

void Inic (FILA* Fila)
{	*Fila = NULL;	}

void Inserir (FILA* Fila, int Idade, char* Nome)
{
	if (*Fila == NULL)
	{	*Fila = (FILA) malloc (sizeof(PESSOA));
		
		if (*Fila == NULL)
			return;
		
		(*Fila)->Idade = Idade;
		strcpy ((*Fila)->Nome, Nome);
		(**Fila).Prox=NULL;
	}
	else
		Inserir (& (**Fila).Prox, Idade, Nome);
}

void Apagar (FILA* Fila)
{	PESSOA *Tmp = *Fila;

	if (*Fila==NULL)
		return;
	
	*Fila = (*Fila)->Prox;
	free (Tmp);
}

void Listar (FILA Fila)
{	if (Fila == NULL)
		return;
	printf ("%d %s \n", Fila->Idade, Fila->Nome);
	Listar (Fila->Prox);
}

int main ()
{	setlocale (LC_ALL, "");

	FILA F;
	
	Inic (&F);
	puts ("Iniciar: ");
	Listar (F);
	puts ("Inserir: ");
	Inserir (&F, 10, "Tiago");
	Inserir (&F, 20, "Luisa");
	Inserir (&F, 30, "Ana");
	puts ("Listar 3");
	Listar (F);
	Apagar (&F);
	puts ("Listar 2");
	Listar (F);
	Apagar (&F);
	puts ("Listar 1");
	Listar (F);
	Apagar (&F);
	puts ("Listar Nada");
	Listar (F);
	Apagar (&F);
	puts ("Listar Nada");
	Listar (F);
}
