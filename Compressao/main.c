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
    char *vetorUnico = malloc(tam * sizeof(char));

    int prox = 0;
    for (int i = 0; i < cont; i++)
    {   
        for(int j=0;j<cont;j++)
        {
            if(v[i]!=v[i+1])
        }
    }

    Simbolo *h = malloc(tam * sizeof(Simbolo));
    for (int i = 0; i < tam; i++)
    {
        h[i].representacao = malloc(2 * sizeof(char));
        h[i].representacao[0] = vetorUnico[i];
        h[i].representacao[1] = '\0';
        h[i].frequencia = 0;
        h[i].direita = NULL;
        h[i].esquerda = NULL;
    }

    exibe(tam, v, h);
    fclose(arquivo);
}