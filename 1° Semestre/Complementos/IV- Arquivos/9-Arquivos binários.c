#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct aluno_s
{	char nome[50];
    int idade;
    int matricula;
}
aluno_t;


size_t gravar_registro (FILE *pf, char *nome, int idade, int mat)
{	aluno_t a;

    strcpy (a.nome, nome);
    a.idade = idade;
    a.matricula = mat;

    return fwrite (&a, sizeof(aluno_t), 1, pf);
}


void ler_registro (FILE * pf, int mat)
{	aluno_t a;

    while (fread (&a, sizeof(aluno_t), 1, pf))
    {
        if (a.matricula == mat)
        {	printf( "Nome     : %s\n", a.nome );
            printf( "Idade    : %d\n", a.idade );
            printf( "Matricula: %d\n", a.matricula );
            printf( "\n" );
            break;
        }
    }
}


int main (int argc, char ** argv)
{
    FILE *arq = NULL;

    /* Abre arquivo para gravacao em modo binario... */
    arq = fopen( "registro.bin", "wb");

    if (!arq)
    {	fprintf( stderr, "Erro ao abrir arquivo para gravacao.\n");
        return EXIT_FAILURE;
    }

    /* Cadastra 5 alunos... */
    gravar_registro (arq, "Albert Einstein", 65, 1234);
    gravar_registro (arq, "Isaac Newton",    43, 3579);
    gravar_registro (arq, "Galileu Galilei", 80, 2468);
    gravar_registro (arq, "Michael Faraday", 77, 1000);
    gravar_registro (arq, "James Maxwell",   43, 5050);

    /* Fecha arquivo...*/
    fclose (arq);

    /* Abre arquivo para leitura em modo binario... */
    arq = fopen ("registro.bin", "rb");

    if (!arq)
    {   fprintf (stderr, "Erro ao abrir arquivo para leitura.\n");
        return EXIT_FAILURE;
    }

    /* Faz a leitura dos alunos pelo codigo de matricula  */
    ler_registro (arq, 1234);
    ler_registro (arq, 3579);
    ler_registro (arq, 2468);
    ler_registro (arq, 1000);
    ler_registro (arq, 5050);

    /* Fecha arquivo...*/
    fclose (arq);

    /* Sucesso */
    return EXIT_SUCCESS;
}
