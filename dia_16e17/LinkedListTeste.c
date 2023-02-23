#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"

int main()
{   
    log_set_level(LOG_TRACE); // INICIALIZA A FUNÇÃO DE LOGS

    // Criação da lista ligada
    LinkedList lista;

    init(&lista);

    return EXIT_SUCCESS;
}