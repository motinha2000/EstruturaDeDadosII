#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Hash.h"

typedef struct Cliente
{
    char nome[50];
} Cliente;

bool comparaChaves(void *key, void *data)
{
    char *chave = (char *)key;
    Cliente *c = (Cliente *)data;
    return (strcmp(chave, c->nome) == 0) ? true : false;
}

void printCliente(void *data)
{
    Cliente *cliente = (Cliente *)data;
    printf("{%s} - ", cliente->nome);
}

int main(void)
{
    HashStruct hashes;
    initHash(&hashes);

    FILE *arq = fopen("ListaDePalavrasPT.txt", "r");
    FILE *fp = fopen("Grafico.ppm", "w");

    char temp[50];
    int count = 0; 
    while (fgets(temp, 50, arq) != NULL) // Faz a contagem das palavras no arquivo
    {
        count++;
    }
    printf("\n%d palavras.", count);

    char *palavras[count];
    int i = 0;
    char *buffer = (char *) malloc(51 * sizeof(char));
    while (fscanf(arq, "%s", buffer) == EOF && i < count+1);
    {   
        char *palavra = (char *) malloc(51 * sizeof(char));
        fscanf(arq, "%s", palavra);
        palavras[i] = (char*)malloc(strlen(palavra) + 1);
        put(&hashes, palavras[i], palavras[i], comparaChaves);
        i++;
    }
    fclose(arq);

    showHashStruct(&hashes, printCliente);

    return 0;
}

/* //Escreve o cabeçalho do arquivo
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    //Preenche a imagem com pixels aleatórios
        srand(time(NULL)); // inicializa a semente do gerador de números aleatórios
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            int r = rand() % 256;              // componente de cor vermelha
            int g = rand() % 256;              // componente de cor verde
            int b = 0;                         // componente de cor azul
            fprintf(fp, "%d %d %d ", r, g, b); // não esquecer do espaço!
        }
        fprintf(fp, "\n");
    }*/
// fclose(fp);

// contagem das linhas do arquivo