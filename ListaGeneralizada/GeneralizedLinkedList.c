#include "GeneralizedLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int addAtom(Node **list, int atom)
{
    Node *no = (Node *)malloc(sizeof(Node));
    if (no == NULL)
        printf("Memoria insuficiente para a operacao!");
    no->type = 0;
    no->atomList.atom = atom;
    no->tail = NULL;
    if (*list == NULL)
        *list = no;
    else
    {
        Node *aux;
        for (aux = *list; aux->tail != NULL; aux = aux->tail);
        aux->tail = no;
    }
}

void showGeneralizedList(Node *list)
{
    Node *aux;
    for (aux; aux->tail != NULL; aux = aux->tail)
    {
        printf("\n%d", aux->atomList.atom);
    }
}