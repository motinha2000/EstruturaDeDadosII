#include "GeneralizedLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int addAtom(Node **list, int atom)
{
    Node *no = (Node *)malloc(sizeof(Node));
    if (no == NULL)
        printf("Memoria insuficiente para a operacao!");
    else
    {
        (*list)->next = *no;
        no->type = 0;
        no->atomList.atom=atom;
        no->next=NULL;
        printf("Tudo certo!");
    }
}

void showGeneralizedList(Node *list)
{
    while(list->next!=NULL){
        printf("\n%d",list->atomList.atom);
    }
}