#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"

void init(LinkedList *list){
    log_info("Inicializando a lista");
    log_trace("init ->");
    list->first = NULL;
    list->size = 0;
    log_debug("list->first: %p", list->first);
    log_debug("list->size: %d", list->size);
    log_trace("init <-");
}

int enqueue(LinkedList *list, void *data){
   log_info("Adicionando elemento a lista");
   log_trace("init ->");
   if(list == NULL){
        log_error("Parametro invalido");
        log_debug("list: %p", list);
        return 1;
   }
   
}

void* dequeue(LinkedList *list){
    return NULL;
}

void* first(LinkedList *list){
    return NULL;
}

void* last(LinkedList *list){
    return NULL;
}

int push(LinkedList *list, void *data){
    return 0;
}

void* pop(LinkedList *list){
    return NULL;
}

void* top(LinkedList *list){
    return NULL;
}

bool isEmpty(LinkedList *list){
    log_info("Verificando se a lista esta vazia");
    log_trace("isEmpty ->");
    if(list == NULL){
        log_error("Parâmetro inválido");
        log_debug("list: %p", list);
        return true;
    }
    log_debug("list->size: %d", list->size);
    log_trace("isEmpty <-");
    if(list->size == 0){
        return true;
    } else {
        return false;
    }
}

int indexOf(LinkedList *list, void *data, compare equal){
    return 0;
}

void *getPos(LinkedList *list, int pos){
    return NULL;
}

Node* getNodeByPos(LinkedList *list, int pos){
    return NULL;
}

int add(LinkedList *list, int pos, void *data){
    return 0;
}

int addAll(LinkedList *listDest, int pos, LinkedList *listSource){
    return 0;
}

void* removePos(LinkedList *list, int pos){
    return NULL;
}

bool removeData(LinkedList *list, void *data, compare equal){
    return NULL;
}
