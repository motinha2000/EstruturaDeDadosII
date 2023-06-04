#include "compress.h"
#include <stdio.h>
#include <stdlib.h>

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
        // printf("%c", v[c]);
        c++;
    }

    int tam = elementosUnicos(cont, v);
    printf("Elemento(s) %d.\n", tam);

    Simbolo *h = malloc(tam * sizeof(Simbolo));
    iniciarStruct(tam, h);
    folhas(tam, cont, v, h);
    exibe(tam, v, h);printf("\n");
    ordenar(tam, h);
    exibe(tam, v, h);
    //Simbolo *compress = arvore(tam,h);
    fclose(arquivo);
}