#include "compress.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 11

int main(int argc, char *argv[])
{
    int i, cont;
    cont = i = 0;
    char ch;

    FILE *arquivo = fopen(argv[1], "r");

    if (arquivo == NULL)
        printf("\nErro ao abrir o arquivo.\n");

    while ((ch = fgetc(arquivo)) != EOF) // PERCORRER O ARQUIVO E RESPEITAR O TAMANHO DO VETOR DE STRUCT
        cont++;
    int *v = malloc(cont * sizeof(int));
    printf("\nChar's: %d.", cont);

    fseek(arquivo, 0, SEEK_SET); // MUDAR O PONTEIRO PRO COMEÇO DO ARQUIVO NOVAMENTE
    printf("\n");
    while ((ch = fgetc(arquivo)) != EOF && i < cont) // PERCORRER O ARQUIVO E RESPEITAR O TAMANHO DO VETOR DE STRUCT
    {
        v[i] = (int)ch;
        printf("%c", (char)v[i]);
        i++;
    }
    //SIMBOLO *h = malloc(cont*sizeof(SIMBOLO));
    SIMBOLO *h = malloc(cont*sizeof(SIMBOLO));
    for (int j = 0; j < cont; j++)
        h[j].frequencia=0;
    printf("\n");
    fseek(arquivo, 0, SEEK_SET); // MUDAR O PONTEIRO PRO COMEÇO DO ARQUIVO NOVAMENTE
    for (int j = 0; j < cont; j++)
    {   
        if(h[j].representacao==(char)v[j])
            h[j].frequencia++;
        else 
            h[j].representacao = (char)v[j]; // ATRIBUIR VALOR ENCONTRADO AO STRUCT
    }   

    for (int j = 0; j < cont; j++)
        printf("%d", h[j].frequencia);

    fclose(arquivo);
}