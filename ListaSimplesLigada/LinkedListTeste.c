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
    *aux = 1;
    enqueue(&lista, aux);
    

    return EXIT_SUCCESS;
}