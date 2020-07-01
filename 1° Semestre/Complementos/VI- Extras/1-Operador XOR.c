#include <stdio.h>

void encrypt(char *message)
{	char c;

	while (*message)
	{	*message = *message ^ 31;
		message++;
	}
}

int main()
{	char msg[80];

	while (fgets(msg, 80, stdin)) 
	{	encrypt(msg);
		printf("%s", msg);
	}
}
