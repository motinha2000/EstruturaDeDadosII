/*
1° PASSO - LER E PERCORRER QUALQUER ARQUIVO.
2° PASSO - VER FREQUÊNCIA DOS SIMBOLOS.
3° PASSO - MONTAR A ARVORE DE BAIXO PRA CIMA
MENOR FREQUÊNCIA -> MAIOR FREQUÊNCIA.
4° PASSO -  EXIBIR SIMBOLOS E SUAS FREQUÊNCIAS E MOSTRAR
*/
#define MAX_TAMANHO_PALAVRAS 100
#define CARACTERES 256

typedef struct Simbolo
{   
    char representacao;
    unsigned int frequencia;
    struct Simbolo *endereço;
}Simbolo;