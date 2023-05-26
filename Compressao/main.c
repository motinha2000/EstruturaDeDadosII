#include "compress.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //char c;
    int i;
    char ch;
    i=0;
    Simbolo h[7];

    FILE *arquivo = fopen(argv[1], "r");

    if (arquivo == NULL) printf("\nErro ao abrir o arquivo.\n");

    while ((ch = fgetc(arquivo)) != EOF)//PERCORRER O ARQUIVO E EXIBIR OS CARACTERES ENCONTRADOS
    {
        if (ch != 32 && ch != 10)//IGNORAR ESPAÇOS E QUEBRAS DE LINHA
            printf("%c", ch);
    }
    fseek(arquivo,0,SEEK_SET);//MUDAR O PONTEIRO PRO COMEÇO DO ARQUIVO NOVAMENTE
    while ((ch = fgetc(arquivo)) != EOF && i<7)//PERCORRER O ARQUIVO E RESPEITAR O LIMITE DO VETOR DE STRUCT
    {
        if (ch != 32 && ch != 10){//IGNORAR ESPAÇOS E QUEBRAS DE LINHA
            h[i].representacao=ch;//ATRIBUIR VALOR ENCONTRADO AO STRUCT
            i++;//AVANÇAR POSIÇÃO NO STRUCT
        }
    }

    printf("\n");

    for(int j=0;j<7;j++)//EXIBIR OS CARACTERES PELO STRUCT
        printf("%c",h[j].representacao);

    fclose(arquivo);
}