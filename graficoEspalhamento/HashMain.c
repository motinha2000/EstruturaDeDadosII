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
    Cliente *c = (Cliente *)malloc(sizeof(Cliente));
    char Linha[100];
    char palavras[100];
    char *result;
    char *dic;
    FILE *arq = fopen("ListaDePalavrasPT.txt", "rt");
    FILE *fp = fopen("Grafico.ppm", "w");

    //Escreve o cabeçalho do arquivo
    //fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    //Preenche a imagem com pixels aleatórios
    /* srand(time(NULL));//inicializa a semente do gerador de números aleatórios
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            int r = rand()%256;  // componente de cor vermelha
            int g = rand()%256;  // componente de cor verde
            int b = 0;  // componente de cor azul
            fprintf(fp,"%d %d %d ", r, g, b);//não esquecer do espaço!
        }
        fprintf(fp, "\n");
    } */

    //fclose(fp);

    int i=0; while(!feof(arq))
    {   
        result = fgets(Linha,100,arq);
        strcpy(dic,result);
        //printf("%s", result);
        put(&hashes,dic,c,comparaChaves);
        i++;
    }
    fclose(arq); 

    showHashStruct(&hashes, printCliente);

    return 0;
}