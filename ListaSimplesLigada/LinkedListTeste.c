#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"

int main()
{   
    FILE *file = fopen("program.log","w");
	
	log_set_level(LOG_INFO);
	log_add_fp(file, LOG_TRACE);

    LinkedList lista; // Criação da lista ligada
    init(&lista); // INICIA A LISTA COM PONTEIRO null E SIZE 0

    int *aux = (int *)malloc(sizeof(int));
    *aux = 777;
    enqueue(&lista, aux);

    char *auxS = (char *)malloc(sizeof(char));
    *auxS = 'C';
    enqueue(&lista, auxS);

    int *numero = malloc(sizeof(int));
    numero = (int*)dequeue(&lista);
    printf("%d removido\n", *numero);

    char *caracter = malloc(sizeof(char));
    caracter = (char*)dequeue(&lista);
    printf("%c removido\n", *caracter);


    

    return EXIT_SUCCESS;
}