#include "compress.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exibe(int tam, Simbolo *h)
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
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (h[i].frequencia < h[j].frequencia)
            {
                Simbolo *aux = malloc(sizeof(Simbolo));
                *aux = h[i];
                h[i] = h[j];
                h[j] = *aux;
            }
        }
    }
}
Simbolo *arvore(int tam, Simbolo *h)
{
    /*
    aux->direita = NULL;
    aux->esquerda = NULL;
    */

    if (tam == 0)
    {
        // printf("\nTAM:%d", tam);
        Simbolo *aux = malloc(sizeof(Simbolo));
        return aux;
    }
    else if (tam == 1)
    {
        // printf("\nTAM:%d", tam);
        Simbolo *aux = malloc(sizeof(Simbolo));
        arvore(tam - 1, h);

    }
    else if (tam > 1)
    {
        // printf("\nTAM:%d", tam);
        Simbolo *aux = malloc(sizeof(Simbolo));
        Simbolo *m1 = malloc(sizeof(Simbolo));
        Simbolo *m2 = malloc(sizeof(Simbolo));
        memcpy(m1, &h[tam - 1], sizeof(Simbolo));
        memcpy(m2, &h[tam - 2], sizeof(Simbolo));

        if (m1->frequencia > m2->frequencia)
        {
            aux->representacao = malloc((strlen(m1->representacao) + strlen(m2->representacao) + 1) * sizeof(char));
            aux->representacao = strcat(aux->representacao, m1->representacao);
            aux->representacao = strcat(aux->representacao, m2->representacao);
            aux->frequencia = m1->frequencia + m2->frequencia;
            aux->direita = m1;
            aux->esquerda = m2;
        }
        else if (m2->frequencia > m1->frequencia)
        {
            aux->representacao = malloc((strlen(m1->representacao) + strlen(m2->representacao) + 1) * sizeof(char));
            aux->representacao = strcat(aux->representacao, m2->representacao);
            aux->representacao = strcat(aux->representacao, m1->representacao);
            aux->frequencia = m1->frequencia + m2->frequencia;
            aux->direita = m2;
            aux->esquerda = m1;
        }
        printf("\nPAI: %s-%d",aux->representacao,aux->frequencia);
        printf("\nFiMAIor: %s-%d.", aux->direita->representacao, aux->direita->frequencia);
        printf("\nFiMENor: %s-%d.", aux->esquerda->representacao, aux->esquerda->frequencia);
        ordenar(tam - 2, h);
        arvore(tam - 2, h);
    }
}