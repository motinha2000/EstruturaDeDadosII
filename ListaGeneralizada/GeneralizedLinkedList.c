#include "GeneralizedLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int addAtom(Node **list, int data)
{
    Node *no = (Node *)malloc(sizeof(Node));
    if (no == NULL)
        return -1;
    no->type = 0;
    no->atomList.atom = data;
    no->tail = NULL;
    if (*list == NULL)
        *list = no;
    else
    {
        Node *aux = NULL;
        for (aux = *list; aux->tail != NULL; aux = aux->tail)
            ;
        aux->tail = no;
    }
}

void showGeneralizedList(Node *list)
{   printf("( ");
    Node *aux = NULL;
    for (aux = list; aux != NULL; aux = aux->tail)
    {
        if (aux->type == 0)
        {
            printf("%d ", aux->atomList.atom);
        }
        else
        {
            showGeneralizedList(aux->atomList.list);
        }
    }
    printf(")");
}