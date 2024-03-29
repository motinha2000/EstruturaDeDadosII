#ifndef DataStructure_GeneralizedLinkedList_h
#define DataStructure_GeneralizedLinkedList_h
#include <stdbool.h>

typedef struct Node
{
    int type; // 0 atomo e 1 lista
    union
    {
        int atom;
        struct Node *list;
    } atomList;
    struct Node *tail;
} Node;

int addAtom(Node **list, int data);
int addList(Node **list, Node **subList);
Node *head(Node *list);
Node *tail(Node *list);
void showGeneralizedList(Node *list);
int depth(Node *list);

#endif