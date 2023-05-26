#include "compress.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //char c;
    int i;
    char ch;
    i=0;
    Simbolo h[7];

    FILE *arquivo = fopen(argv[1], "r");

    if (arquivo == NULL) printf("\nErro ao abrir o arquivo.\n");

    while ((ch = fgetc(arquivo)) != EOF)
    {
        if (ch != 32 && ch != 10)
            printf("%c", ch);
    }
    fseek(arquivo,0,SEEK_SET);
    while ((ch = fgetc(arquivo)) != EOF && i<7)
    {
        if (ch != 32 && ch != 10){
            h[i].representacao=ch;
            i++;
        }
    }

    printf("\n");

    for(int j=0;j<7;j++)
        printf("%c",h[j].representacao);

    fclose(arquivo);
}