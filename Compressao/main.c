#include "compress.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 11

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

    fseek(arquivo, 0, SEEK_SET);
    printf("\n");
    while ((ch = fgetc(arquivo)) != EOF && i < cont) // GUARDAR CARACTER COMO INT
    {
        v[i] = (int)ch;
        //printf("%c", (char)v[i]);
        i++;
    }
    SIMBOLO *h = malloc(cont * sizeof(SIMBOLO));
    for (int j = 0; j < cont; j++)
        h[j].frequencia = 0;

    for (int j = 0; j < cont; j++) // ATRIBUIR AO STRUCT
    {
        h[j].representacao = (char)v[j];
        for (int t = 0; t < cont; t++) // CALCULA FREQUENCIA
        {
            if (h[j].representacao == (char)v[t])
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

    for (int j = 0; j < cont; j++) // EXIBIÇÃO STRUCT NAO ANULADO
    {
        if (h[j].frequencia != 0)
        {
            if (h[j].representacao == (char)32)
            {
                printf("ESPAÇO(S) - ");
                printf("%d\n", h[j].frequencia);
            }
            else if (h[j].representacao == (char)10)
            {
                printf("QUEBRA(S) DE LINHA - ");
                printf("%d\n", h[j].frequencia);
            }
            else
            {
                printf("%c - ", h[j].representacao);
                printf("%d\n", h[j].frequencia);
            }
        }
    }
    fclose(arquivo);
}