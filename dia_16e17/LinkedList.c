#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"

void init(LinkedList *list)
{
    log_info("Inicializando a lista");
    log_trace("INIT ->");
    list->first = NULL;
    list->size = 0;
    log_debug("list->first: %p", list->first);
    log_debug("list->size: %d", list->size);
    log_trace("INIT <-");
}

int enqueue(LinkedList *list, void *data)
{
    log_info("Adicionando elemento a lista");
    log_trace("ENQUEUE ->");

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) // caso não há espaço suficiente na RAM ele retorna valor negativo
        return -1;
    newNode->data = data;
    newNode->next = NULL;
    if(isEmpty(list)) //se a lista estiver vazia
        list->first = newNode; //novo nó e primeiro
    else {
        Node *aux = list->first; //aux aponta para o primeiro
        while(aux->next != NULL) //enquanto não for o último nó
            aux = aux->next; //aux avança para o nó seguinte
        aux->next = newNode; //último nó aponta para o novo nó
    }
    list->size++;
    return 1;
    log_trace("ENQUEUE <-");
}

void *dequeue(LinkedList *list)
{
    return NULL;
}

void *first(LinkedList *list)
{
    return NULL;
}

void *last(LinkedList *list)
{
    return NULL;
}

int push(LinkedList *list, void *data)
{
    return 0;
}

void *pop(LinkedList *list)
{
    return NULL;
}

void *top(LinkedList *list)
{
    return NULL;
}

bool isEmpty(LinkedList *list)
{
    log_info("Verificando se a lista esta vazia");
    log_trace("ISEMPTY ->");
    if (list == NULL)
    {
        log_error("Parâmetro inválido");
        log_debug("list: %p", list);
        return true;
    }
    log_debug("list->size: %d", list->size);
    log_trace("ISEMPTY <-");
    if (list->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int indexOf(LinkedList *list, void *data, compare equal)
{
    return 0;
}

void *getPos(LinkedList *list, int pos)
{
    return NULL;
}

Node *getNodeByPos(LinkedList *list, int pos)
{
    return NULL;
}

int add(LinkedList *list, int pos, void *data)
{
    return 0;
}

int addAll(LinkedList *listDest, int pos, LinkedList *listSource)
{
    return 0;
}

void *removePos(LinkedList *list, int pos)
{
    return NULL;
}

bool removeData(LinkedList *list, void *data, compare equal)
{
    return NULL;
}
