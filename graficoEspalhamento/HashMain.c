#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Hash.h"

#define WIDTH 256
#define HEIGHT 256

typedef struct Cliente
{
    char nome[50];
    char email[50];
} Cliente;

bool comparaChaves(void *key, void *data)
{
    char *chave = (char *)key;
    Cliente *c = (Cliente *)data;
    return (strcmp(chave, c->email) == 0) ? true : false;
}

void printCliente(void *data)
{
    Cliente *cliente = (Cliente *)data;
    printf("{%s,%s} - ", cliente->nome, cliente->email);
}

int main(void)
{
    HashStruct hashes;
    initHash(&hashes);
    char Linha[100];
    char *result;
    int i, j;
    FILE *arq = fopen("ListaDePalavrasPT.txt", "rt");
    FILE *fp = fopen("Grafico.ppm", "w");

    //Escreve o cabeçalho do arquivo
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    //Preenche a imagem com pixels aleatórios
    srand(time(NULL));//inicializa a semente do gerador de números aleatórios
    for (i = 0; i < HEIGHT; i++){
        for (j = 0; j < WIDTH; j++){
            int r = rand() % 256;  // componente de cor vermelha
            int g = rand() % 256;  // componente de cor verde
            int b = rand() % 256;  // componente de cor azul
            fprintf(fp,"%d %d %d ", r, g, b);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    /* i=0; while(!feof(arq))
    {
        result = fgets(Linha,100,arq);
        if(result)
        printf("Linha %d : %s", i, Linha);
        i++;
    }
    fclose(arq); */

    return 0;
}