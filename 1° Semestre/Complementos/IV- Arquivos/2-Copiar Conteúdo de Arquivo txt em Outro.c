#include<stdio.h>

void copiarConteudo (FILE *file1, FILE *file2)
{	char leitor[1000];
	
	while (fgets(leitor, 1000, file1)!=NULL)
		fputs (leitor, file2);
}

int main ()
{	

/*	FILE *file1 = fopen ("Arquivo 1.txt", "w");
		if(!file1)		//if (file==NULL)
		{	printf ("Erro na abertura do arquivo");
			getchar();
			return (1);		}
		fprintf (file1, "Pão com mortadela \nHot Dog \nStrogonoff\n");
	fclose(file1);																			*/
	
	
	FILE *file1 = fopen ("Arquivo 1.txt", "r");
		if(!file1)		//if (file==NULL)
		{	printf ("Erro na abertura do arquivo");
			getchar();
			return (1);		}

	FILE *file2 = fopen ("Arquivo 2.txt", "w");
		copiarConteudo (file1, file2);
	
	fclose(file1);
	fclose(file2);
	return 0;
}
