#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<locale.h>

/*	Leonardo
	1234
	1234
	BD
	abc
*/

int n, i;

struct cliente
{	char nome[20];
	char cpf[11];
	char conta[6];
	char agencia[6];
	char senha[6];       
	float saldo;
}
usuario[20];


cadastrarCliente ()
{	int i=1;

    printf ("\n\t\t===== CADASTRO DE CLIENTES ===== \n");   
 
    printf ("\nQuantos clientes deseja cadastrar? ");
    scanf ("%d", &n);

	for (i=1; i<=n; i++)
    {	puts ("");

	    printf ("\n*-- NOME--* ");
	    scanf ("%s", &usuario[i].nome);  

	    printf ("\n*--CPF--* ");
	    scanf ("%s", &usuario[i].cpf);

	    printf ("\n*--AGENCIA--* ");
	    scanf ("%s", &usuario[i].agencia);

	    printf ("\n*--NUMERO DA CONTA--* ");
	    scanf ("%s", &usuario[i].conta);

	    printf ("\n*--SENHA--* ");
	    scanf ("%s", &usuario[i].senha);   

	    usuario[i].saldo = 0;
    }

    printf ("\n\n*-- operacao realizada com sucesso !!!--*");
    getch();
} 
    

deposito ()
{	int a,b,c,x;
    float dep;
    char agn[6], conta[6], senha[6];
    
    printf ("\n\t\t===== DEPOSITO ===== \n"); 
    
    printf ("\n*--DIGITE A SUA AGENCIA--* ");
    scanf ("%s", &agn);

    printf ("\n*--NUMERO DA CONTA--* ");
    scanf ("%s", &conta);
    
    for (i=1; i<=n; i++)
    {	a = strcmp (agn, usuario[i].agencia);
        b = strcmp (conta, usuario[i].conta);
        
        if ((a == 0) && (b == 0))
        {	x=1;
        
        	printf ("\n CLIENTE : %s", usuario[i].nome) ;
        	printf ("\n CPF : %s", usuario[i].cpf) ;

        	printf ("\n\n*--QUANTIDADE DO DEPOSITO--*");
        	scanf ("%f", &dep) ;
        	
			if (dep >= 0)
        		usuario[i].saldo = usuario[i].saldo + dep;
        	else
        	{ 	printf ("\n\a *-- erro: O DEPOSITO TEM QUE SER POSITIVO --* ");
    	    	break;
        	}
        }
    }
    
    if(x!=1)
    	printf ("\n\a\a *-- erro: DADOS INCORRETOS ! --*");
    	
    printf ("\n\n*-- aguarde... --*");
	getch();
}

    
consultaSaldo ()
{	char agn[6], conta[6], senha[6];
    int a,b,c,x;  
    
	printf ("\n\t\t===== SALDO =====\n"); 
    
    printf ("\n*--DIGITE A SUA AGENCIA--* ");
    scanf ("%s", &agn); 

    printf ("\n*--NUMERO DA CONTA--* ");
    scanf ("%s", &conta);

    printf ("\n *--DIGITE A SUA SENHA--* ");
    scanf ("%s", &senha); 

    for (i=1; i<=n; i++)
    {	a = strcmp(agn,usuario[i].agencia);
        b = strcmp(conta,usuario[i].conta);
        c = strcmp(senha,usuario[i].senha);
        
		if ((a == 0) && (b == 0)  && (c == 0))
        {	x=1;
        	printf ("\n CLIENTE : %s", usuario[i].nome) ;
        	printf ("\n CPF : %s", usuario[i].cpf) ;
        	printf ("\n\n *--SEU SALDO E : %f reais --*", usuario[i].saldo) ;        
        }
    }
    
    if (x != 1)
    	printf ("\n\a\a *-- erro: DADOS INCORRETOS ! --*");
    
    printf ("\n\n*-- aguarde... --*");
    getch();
}


transfere ()
{	char agn[6], conta[6], senha[6],agn2[6],conta2[6];
    int a, b, c, d, e, j, x, l; 
    float val;
    
	printf ("\n\t\t ===== TRANSFERENCIA ===== \n"); 
    
    printf ("\n*--DIGITE A SUA AGENCIA--* ");
    scanf ("%s", &agn); 
   
    printf ("\n*--NUMERO DA CONTA--* ");
    scanf ("%s", &conta);

    printf ("\n *--DIGITE A SUA SENHA--*: ");
    scanf ("%s", &senha);
    
    for (i=1; i<=n; i++)
    {	a = strcmp(agn,usuario[i].agencia);
        b = strcmp(conta,usuario[i].conta);
        c = strcmp(senha,usuario[i].senha);
        
        if ((a == 0) && (b == 0)  && (c == 0))
        {	l=1;
        	
			printf ("\n CLIENTE : %s", usuario[i].nome) ; 
        	printf ("\n CPF : %s", usuario[i].cpf) ;
        }
        
    	if (l != 1)
		{	printf ("\a\a*-- erro: DADOS INCORRETOS ! --*");
    		printf ("\n\n aguarde...");
      		getch();
      		system ("cls");
      		main();
      	}
    }
    
    printf ("\n*--DIGITE A AGENCIA DO BENEFICIADO--* ");
    scanf ("%s", &agn2);

    printf ("\n*--NUMERO DA CONTA DO BENEFICIADO--* ");
    scanf ("%s", &conta2);
    
    for (j=1; j<=n; j++)
    {	d = strcmp(agn2,usuario[j].agencia);
        e = strcmp(conta2,usuario[j].conta);
        
		if  ((d == 0) && (e == 0))
        {	printf ("\n *--CLIENTE BENEFICIADO--* %s", usuario[j].nome) ; 
                
            printf ("\n*--VALOR DA TRANSFERENCIA--*");
            scanf ("%f", &val);
                        
            for (i=1; i<=n; i++)
            {	if (usuario[i].saldo >= val)
                {	x=1;
                    usuario[j].saldo = usuario[j].saldo + val;
                    usuario[i].saldo = usuario[i].saldo - val;                    
                }
                else 
                	x=0;
            }
            if (x != 0)
				printf ("\a\a *-- erro: SALDO INSUFICIENTE! --*");       
        }
    }
    
	printf ("\n\n*-- aguarde... --*");  
	getch();      
}


saque ()
{ 	int a,b,c,x;
    float saq;
	char agn[6], conta[6], senha[6];
    
    printf ("\n\t\t===== SAQUE ===== \n"); 
    
    printf ("\n*--DIGITE A SUA AGENCIA--* ");
    scanf ("%s", &agn);

    printf ("\n*--NUMERO DA CONTA--* ");
    scanf ("%s", &conta);
    
    for (i=1; i<=n; i++)
    {   a = strcmp(agn,usuario[i].agencia);
        b = strcmp(conta,usuario[i].conta);

        if ((a == 0) && (b == 0))
        {   printf ("\n CLIENTE : %s", usuario[i].nome);
			printf ("\n CPF : %s", usuario[i].cpf);

	        printf ("\n\n*--VALOR DA RETIRADA--*");
	        scanf ("%f", &saq);
	        
	        if ((saq > 0) && (saq <= usuario[i].saldo) )
	        {	x=1;
	        	usuario[i].saldo = usuario[i].saldo - saq;	
			}
        }
    }
     
    if (x != 1)
    	printf ("\n\a\a*-- erro: SALDO INSUFICIENTE ! --*");
    printf ("\n\n*-- aguarde... --*");
    getch(); 
}


menu ()
{	printf ("Considere as seguintes opções...\n");
	puts ("");
	puts ("1 - NOVO CLIENTE") ;
	puts ("2 - DEPOSITO") ;
	puts ("3 - CONSULTA SALDO") ;
	puts ("4 - TRANSFERENCIA") ;
	puts ("5 - RETIRADA");    
	puts ("6 - Sair");  
	puts ("\n\nSelecione a opcao desejada: ");
}
     
     
main()
{	setlocale (LC_ALL, "");
	int op;
	
	menu ();
	scanf ("%d", &op);
	
	switch (op)
	{	case 1:
		    system ("cls") ;
		    cadastrarCliente ();
		    system ("cls");
		    main();
		    
	    case 2:
		    system ("cls") ;
		    deposito (); 
		    system ("cls");
		    main();
		    
	    case 3:
		    system ("cls") ;
		    consultaSaldo ();
		    system ("cls");
		    main();
		    
	    case 4:
		    system ("cls") ;
		    transfere();
		    system ("cls");
		    main();         

	    case 5:
		    system ("cls") ;
		    saque (); 
		    system ("cls");
		    main();
		    
	    case 6:  
	    	exit (1);       
	}
	
	getch();
} 
