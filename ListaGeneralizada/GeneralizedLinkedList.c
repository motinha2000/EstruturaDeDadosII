#include "GeneralizedLinkedList.h"

int addAtom(Node **list, int atom)
{
    Node *no;
    no->type=0;
    no->atomList.atom=atom;
    no->(*tail)=NULL;

}