#include "compress.h"
#include <stdio.h>

void exibe(int cont, int *v,Simbolo *h)
{
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
}
