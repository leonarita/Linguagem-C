#include<stdio.h>
#include<locale.h>

int main()
{	setlocale (LC_ALL, "");
    int numero[5], i, acha, pesq;
    char resp;
    
    printf("\n\t\t\tPesquisa sequencial de n�meros\n\n");
    
    for (i=0;i<=4;i++)
    {	printf("Informe o %d� n�mero: ", i+1);
        fflush(stdin); 
		scanf("%d", &numero[i]);
    }

    resp='s';

    while(resp == 's' || resp == 'S')
    {	printf("\n\n\tEntre com o n�mero a ser pesquisado: ");
		fflush(stdin);
		scanf("%d", &pesq);
    	
		i=0;
        acha=0;

		while (i<=4 && acha==0)
        	if (pesq == numero[i])
				acha=1;
			else
 				i += 1;

		if (acha == 1)
			printf ("\n\n\t\t%d foi localizado na posi��o %d", pesq, i+1);
		else 
			printf ("\n\n\t\t%d n�o foi localizado!", pesq);
	
		printf ("\n\n\nDeseja continuar a pesquisa? [S]IM / [N]AO + <enter>");
		fflush(stdin);
		resp=getchar();
	}
	getch();
}
