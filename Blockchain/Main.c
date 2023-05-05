#include "block.h"
#include <stdio.h>
#include <stdlib.h>
//github.com/amosnier/sha-2/
void main(void)
{
    Blockchain ethereum;
    initBlockchain(&ethereum);
    generateNextBlock(&ethereum,80.0);
}