#include<stdio.h>
#include<stdlib.h>

int main ()
{	FILE *file;
	char c;

//	fp = fopen ("exemplo.bin","wb"); -> Binário

	file = fopen ("teste.txt", "w");
	fprintf (file, "10 20 30");
	fclose(file);

	file = fopen ("teste.txt", "r");

	int x, y, z;
	fscanf (file, "%i %i %i", &x, &y, &z);		//	fscanf (file, "...", variável);	 ->  Limita, pois deve estar corretamente formatado
	printf ("%i %i %i", x, y, z);
		
/*	while (!feof(file))
	{
		fscanf(file, "%c", &c);
		printf("%c", c);
	}
*/
	while((c = getc(file)) != EOF)
		printf("%c", c);
		
/*	char frase[100];
	while (fgets(frase, 100, file)!=NULL)
		printf ("%s", frase);				*/		
		
	fclose(file);
}
