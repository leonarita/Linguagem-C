#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, time, localtime, strftime */
#include <locale.h>     /* struct lconv, setlocale, localeconv */

int main ()
{
	time_t rawtime;
	struct tm *timeinfo;
	char buffer[80];
	int twice=0;
	struct lconv * lc;

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	do
	{	printf ("Locale is: %s\n", setlocale (LC_ALL,NULL));
		strftime (buffer,80,"%c",timeinfo);
		printf ("Date is: %s\n",buffer);
		lc = localeconv ();
    	printf ("Currency symbol is: %s\n-\n",lc->currency_symbol);
		setlocale (LC_ALL,"");
 	} while (!twice++);
 	
 /*	
	printf ("\n\n\n");
	printf ("\n%s", lc->decimal_point);
	printf ("\n%s", lc->thousands_sep);
	printf ("\n%s", lc->grouping);
	printf ("\n%s", lc->int_curr_symbol);
	printf ("\n%s", lc->currency_symbol);
	printf ("\n%s", lc->mon_decimal_point);
	printf ("\n%s", lc->mon_thousands_sep);
	printf ("\n%s", lc->mon_grouping);
	printf ("\n%s", lc->positive_sign);
	printf ("\n%s", lc->negative_sign);
	printf ("\n%s", lc->int_frac_digits);
	printf ("\n%s", lc->p_sep_by_space);
	printf ("\n%s", lc->p_cs_precedes);
	printf ("\n%s", lc->n_cs_precedes);
	printf ("\n%s", lc->n_sep_by_space);
	printf ("\n%s", lc->p_sign_posn);
	printf ("\n%s", lc->n_sign_posn); 	*/

	return 0;
}
