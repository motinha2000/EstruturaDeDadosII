#include "compress.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, cont;
    cont = i = 0;
    char ch;

    FILE *arquivo = fopen(argv[1], "r");

    if (arquivo == NULL)
        printf("\nErro ao abrir o arquivo.\n");

    while ((ch = fgetc(arquivo)) != EOF) // CONTAR CARACTER
        cont++;

    int *v = malloc(cont * sizeof(int));
    printf("\nChars: %d.", cont);

    fseek(arquivo, 0, SEEK_SET);//
    printf("\n");

    while ((ch = fgetc(arquivo)) != EOF && i < cont) // GUARDAR CARACTER COMO INT
    {
        v[i] = (int)ch;
        //printf("%c", (char)v[i]);
        i++;
    }
    Simbolo *h = malloc(cont * sizeof(Simbolo));
    for (int j = 0; j < cont; j++)
        h[j].frequencia = 0;

    for (int j = 0; j < cont; j++) // ATRIBUIR AO STRUCT
    {
        strcpy(h[j].representacao,(char)v[j]);
        for (int t = 0; t < cont; t++) // CALCULA FREQUENCIA
        {   
                strcpy(h[j].representacao,(char)v[j]);
                if (strcmp(h[j].representacao,(char)v[t])==0)
                h[j].frequencia++;
        }
    }

    for (int j = 0; j < cont; j++) // VERIFICAR REPETICOES E ANULAR O STRUCT
    {
        for (int t = 0; t < cont; t++)
        {
            if (j != t && h[j].representacao == h[t].representacao && h[j].frequencia != 0)
                h[t].frequencia = 0;
        }
    }

    exibe(cont,v,h);
    fclose(arquivo);
}