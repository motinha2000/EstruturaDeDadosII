#include "GeneralizedLinkedList.h"
#include <stdlib.h>

int main()
{
    Node *listageneralizada = NULL;

    addAtom(&listageneralizada, 7);
    addAtom(&listageneralizada, 7);
    addAtom(&listageneralizada, 7);
    addAtom(&listageneralizada, 7);
    addAtom(&listageneralizada, 7);
    addAtom(&listageneralizada, 7);
    showGeneralizedList(listageneralizada);
}