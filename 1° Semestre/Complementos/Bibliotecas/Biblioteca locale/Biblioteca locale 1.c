#include <stdio.h>      /* printf */
#include <locale.h>     /* setlocale, LC_MONETARY, struct lconv, localeconv */

int main ()
{	setlocale (LC_ALL, "Portuguese");
	setlocale (LC_MONETARY,"UK");
	struct lconv *lc;
	lc=localeconv();
	printf ("Local Currency Symbol: %s\n",lc->currency_symbol);
	printf ("International Currency Symbol: %s\n",lc->int_curr_symbol);
	return 0;
}
