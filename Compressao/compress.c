#include "compress.h"
#include <stdio.h>
#include <stdlib.h>

void exibe(int tam, char *v, Simbolo *h)
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

void folhas(int tam, int cont, char *v, Simbolo *h)
{
    int prox = 0;
    for (int i = 0; i < cont; i++)
    {
        h[prox].representacao[0] = v[i];
        for (int p = 0; p < tam;) // SIMBOLO UNICO
        {
            if (h[prox].representacao[0] == h[p].representacao[0] && p != prox)
                break;
            else if (h[prox].representacao[0] != h[p].representacao[0] && p != prox)
                p++;
            else
            {
                for (int j = 0; j < cont; j++) // CONTAR FREQUENCIA
                {
                    if (h[prox].representacao[0] == v[j])
                        h[prox].frequencia++;
                }
                prox++;
                break;
            }
        }
        if (prox == tam)
            break;
    }   
}

void ordenar(int tam, Simbolo *h)
{
    for(int i=0;i<tam;i++)
    {   Simbolo *aux;
        for(int j=0;j<tam;j++)
        {

        }
    }
}