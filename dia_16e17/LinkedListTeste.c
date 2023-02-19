#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"

int main()
{   
    int aux = 123;
    // INICIALIZA A FUNÇÃO DE LOGS
    log_set_level(LOG_TRACE);

    // Criação da lista ligada
    LinkedList lista;

    init(&lista);
    isEmpty(&lista);
    enqueue(&lista, &aux);

    return EXIT_SUCCESS;
}