#include "compress.h"
#include <stdio.h>
#include <stdlib.h>

void exibe(int tam, char *v,Simbolo *h)
{
    for (int j = 0; j < tam; j++) // EXIBIÇÃO STRUCT NAO ANULADO
    {
            if (h[j].representacao[0] == (char)32)
            {
                printf("ESPAÇO(S) - ");
                printf("%d\n", h[j].frequencia);
            }
            else if (h[j].representacao[0] == (char)10)
            {
                printf("QUEBRA(S) DE LINHA - ");
                printf("%d\n", h[j].frequencia);
            }
            else
            {
                printf("%c - ", h[j].representacao[0]);
                printf("%d\n", h[j].frequencia);
            }
    }
}

int elementosUnicos(int cont, char *v)
{   
    int e = 0;
    for (int z = 0; z < cont; z++)
    {
        int repetido = 0; 
        for (int x = z + 1; x < cont; x++)
        {
            if (v[z] == v[x] && !repetido)
            {
                e++;
                repetido = 1;
            }
        }
    }
    return cont - e;
}

void iniciarStruct(int tam, Simbolo *h)
{
    for (int i = 0; i < tam; i++)
    {
        h[i].representacao = malloc(2 * sizeof(char));
        h[i].representacao[0] = '\0';
        h[i].representacao[1] = '\0';
        h[i].frequencia = 0;
        h[i].direita = NULL;
        h[i].esquerda = NULL;
    }
}