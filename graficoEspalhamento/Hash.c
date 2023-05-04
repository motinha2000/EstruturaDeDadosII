#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Hash.h"

void initHash(HashStruct *hashStruct)
{
    for (int i = 0; i < MAX; i++)
    {
        // chamando init de DoublyLinkedList para inicializar cada lista do vetor
        init(&(hashStruct->hashes[i]));
    }
    hashStruct->size = 0;
}

bool isHashEmpty(HashStruct *hashStruct)
{
    return hashStruct->size = 0;
}

int hash(char *key)
{
    int sum = 0;
    srand(time(NULL));
    // percorremos todos os caracteres da string passada
    for (int i = 0; key[i] != 0; i++)
    {   
        // acumulamos os códigos ascii de cada letra com um peso
        //sum += key[i] * (i + 1);
        sum += key[i] * (i + 1)*(rand()%1024);
    }
    return sum % MAX; // retorna o resto da divisão
}

int put(HashStruct *hashStruct, char *key, void *data, compare equal)
{
    if (!containsKey(hashStruct, key, equal))
    {
        // adiciona na fila que está na posição devolvida pela função hash
        int res = enqueue(&hashStruct->hashes[hash(key)], data);
        // incrementa a qtde de elementos baseado na quantidade inserida por enqueue
        hashStruct->size += res;
        return res;
    }
    return 0;
}

bool containsKey(HashStruct *hashStruct, char *key, compare equal)
{
    // calcula a posição
    int hashValue = hash(key);
    // busca na fila a posição da chave
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);
    return (pos != -1) ? true : false;
}

void *get(HashStruct *hashStruct, char *key, compare equal)
{
    // descobre em qual fila/lista está o dado
    int hashValue = hash(key);
    // first é nó sentinela, começamos do segundo nó
    Node *aux = hashStruct->hashes[hashValue].first->next;
    // procuramos o dado na lista
    while (aux != hashStruct->hashes[hashValue].first && !equal(aux->data, key))
        aux = aux->next;
    return aux->data;
}

void *removeKey(HashStruct *hashStruct, char *key, compare equal)
{
    int hashValue = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);
    void *result = removePos(&hashStruct->hashes[hashValue], pos);
    if (result != NULL)
        hashStruct->size--;
    return result;
}

void showHashStruct(HashStruct *hashStruct, printNode print)
{
    printf("\nThere are %d elements in the Hash\n\n", hashStruct->size);
    for (int i = 0; i < MAX; i++)
    {
        printf("Hash %d has %d elements: ", i, hashStruct->hashes[i].size);
        show(&hashStruct->hashes[i], print);
        printf("\n");
    }
}

void hashUm(HashStruct *hashStruct)
{
    FILE *imagem = fopen("Grafico.ppm", "w");
    FILE *arquivo = fopen("ListaDePalavrasPT.txt", "r");

    int contador_palavras = 0;
    char buffer[MAX_TAMANHO_PALAVRA];
    int maior, resto;
    resto = 0;
    maior = hashStruct->hashes[0].size;

    fprintf(imagem, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    srand(time(NULL)); // inicializa a semente do gerador de números aleatórios

    for (int i = 0; i < MAX; i++)
    {
        if (maior < hashStruct->hashes[i].size)
            maior = hashStruct->hashes[i].size;
    }
    resto = 256 % maior;
    // printf("%d\n", resto);
    // printf("%d", maior);

    int c = 0;
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            int r = 0;                                              // componente de cor vermelha
            int g = (hashStruct->hashes[i * j].size * 256) / maior; // componente de cor verde
            int b = 0;                                              // componente de cor azul
            fprintf(imagem, "%d %d %d ", r, g, b);                  // não esquecer do espaço!
        }
        fprintf(imagem, "\n");
    }
    fclose(imagem);
}

int hashDois(char *key)
{
    int sum = 0;
    // percorremos todos os caracteres da string passada
    for (int i = 0; key[i] != 0; i++)
    {
        // acumulamos os códigos ascii de cada letra com um peso
        sum += key[i] * (i + 1) * rand() % 4096;
    }
    return sum % MAX; // retorna o resto da divisão
}