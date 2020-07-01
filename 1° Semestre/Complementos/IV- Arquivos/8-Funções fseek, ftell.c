#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fp = fopen( "arquivo.bin", "r" );
    fseek( fp, 0L, SEEK_END );
    long tam = ftell(fp);
    fclose(fp);
    printf("Tamanho total do arquivo: %ld bytes\n", tam );
    return 0;
}
