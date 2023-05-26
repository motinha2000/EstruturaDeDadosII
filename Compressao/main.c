#include "compress.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{   
    char c;
    FILE *arquivo = fopen(argv[1], "r");
    printf("%s", argv[1]);

    if (arquivo == NULL) printf("\nErro ao abrir o arquivo.\n");
    else printf("\nTudo ok!\n");

    while( (c=fgetc(arquivo)) !=EOF)
        printf("%c", c);

    fclose(arquivo);
}