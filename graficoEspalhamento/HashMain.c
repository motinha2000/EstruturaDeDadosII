#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

typedef struct Cliente {
    char nome[50];
    char email[50];
}Cliente;

bool comparaChaves(void *key, void *data) {
    char *chave = (char*)key;
    Cliente *c = (Cliente*)data;
    return (strcmp (chave, c->email) == 0)?true:false;
}

void printCliente(void *data) {
    Cliente *cliente = (Cliente*)data;
    printf("{%s,%s} - ", cliente->nome, cliente->email);
}

int main() {
    HashStruct hashes;
    initHash(&hashes);  
    char Linha[100];
    char *result;
    int i;

    FILE *arq;
    FILE *imagem;

    arq = fopen("ListaDePalavrasPT.txt", "rt");
    if(arq==NULL)
        printf("Problemas na CRIACAO do arquivo\n");
    
    i=1;
    while(!feof(arq))
    {
        result = fgets(Linha,100,arq);
        if(result)
        printf("Linha %d : %s", i, Linha);
        i++;
    }
    fclose(arq);

    return 0;
}