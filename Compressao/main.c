#include "compress.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) //
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
    Simbolo *aux = malloc(tam * sizeof(Simbolo));
    iniciarStruct(tam, h);
    iniciarStruct(tam, aux);
    folhas(tam, cont, v, h);
    folhas(tam, cont, v, aux);
    ordenar(tam, h);
    ordenar(tam, aux);
    exibe(tam, h);printf("\n");
    arvore(tam, h);
    // printf("REPRESENTACAO: '%s' - FREQUENCIA:%d",
    // h[0].direita->direita->esquerda->direita->representacao,
    // h[0].direita->direita->esquerda->direita->frequencia);
    //exibe(tam, aux);printf("\n");
    huffman(tam, h, aux);
    fclose(arquivo);
}