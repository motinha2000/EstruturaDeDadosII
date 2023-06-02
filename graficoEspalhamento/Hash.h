#ifndef EstruturaDeDados_Hash_h
#define EstruturaDeDados_Hash_h
#include "ListaDup.h"
#define MAX 1024
#define WIDTH 32
#define HEIGHT 32
#define MAX_PALAVRAS 29859
#define MAX_TAMANHO_PALAVRA 100

typedef struct HashStruct {
    DoublyLinkedList hashes[MAX];
    int size;
}HashStruct;

void initHash(HashStruct *hashStruct);
bool isHashEmpty(HashStruct *hashStruct);
int hash(char *key);
int put(HashStruct *hashStruct, char *key, void *data, compare equal);
bool containsKey(HashStruct *hashStruct, char *key, compare equal);
void* get(HashStruct *hashStruct, char *key, compare equal);
void* removeKey(HashStruct *hashStruct, char *key, compare equal);
void showHashStruct(HashStruct *hashStruct, printNode print);
void hashUm(HashStruct *hashStruct);

#endif

//Usar o maior hashes[MAX] para descobrir a minha faixa de cor!