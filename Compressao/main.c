#include "compress.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[ ])
{
    FILE *arquivo = fopen(argv[1], "r");
    printf("%s",argv[1]);
    if (arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo.\n");
        exit(1);
    }
    else printf("\nTUDO OK!");

    

    return 0;
}