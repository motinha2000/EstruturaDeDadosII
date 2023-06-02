#include "compress.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int c, cont;
    cont = c = 0;
    char ch;

    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL)
        printf("\nErro ao abrir o arquivo.\n");

    while ((ch = fgetc(arquivo)) != EOF)
        cont++;

    char *v = malloc(cont * sizeof(char));

    printf("\nChars: %d.", cont);
    printf("\n");

    fseek(arquivo, 0, SEEK_SET);
    while ((ch = fgetc(arquivo)) != EOF && c < cont) // GUARDAR TODOS CARACTERES
    {
        v[c] = ch;
        printf("%c", v[c]);
        c++;
    }

    int tam = elementosUnicos(cont, v);
    printf("\nElementos %d.\n", elementosUnicos(cont, v));

    Simbolo *h = malloc(tam * sizeof(Simbolo));
    iniciarStruct(tam, h);
    int prox = 0;
    for (int i = 0; i < cont; i++)
    {
        h[prox].representacao[0] = v[i];
        printf("\n")
        for (int p = 0; p < tam; p++) // SIMBOLO UNICO
        {
            if (h[prox].representacao[0] == h[p].representacao[0])
                break;
            else
            {
                for (int j = 0; j < cont; j++) // CONTAR FREQUENCIA
                {
                    if (h[prox].representacao[0] == v[j])
                        h[prox].frequencia++;
                }
                prox++;
            }
        }
    }

    exibe(tam, v, h);
    fclose(arquivo);
}