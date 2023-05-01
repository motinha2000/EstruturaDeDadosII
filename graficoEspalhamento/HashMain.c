#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

typedef struct Cliente
{
    char nome[MAX_TAMANHO_PALAVRA];
} Cliente;

bool comparaChaves(void *key, void *data)
{
    char *chave = (char *)key;
    char *c = (char *)data;
    return (strcmp(chave, c) == 0) ? true : false;
}

void printCliente(void *data)
{
    Cliente *cliente = (Cliente *)data;
    printf("{%s} - ", cliente->nome);
}

int main()
{
    HashStruct hashes;
    initHash(&hashes);

    int contador_palavras = 0;
    char buffer[MAX_TAMANHO_PALAVRA];
    FILE *arquivo = fopen("ListaDePalavrasPT.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Lê palavras linha por linha até o fim do arquivo
    while (fscanf(arquivo, "%s", buffer) != EOF && contador_palavras < MAX_PALAVRAS)
    {
        char *palavra = malloc(MAX_TAMANHO_PALAVRA * sizeof(char));
        strcpy(palavra, buffer);
        // printf("%p\n",&palavra);
        put(&hashes, palavra, palavra, comparaChaves);
        contador_palavras++;
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Imprime as palavras lidas
    /* for (int i = 0; i < contador_palavras; i++)
    {
        printf("%s\n", palavras[i]);
    } */

    hashUm(&hashes);
    // showHashStruct(&hashes, printCliente);

    return 0;
}