#include "block.h"
#include <stdio.h>
#include <stdlib.h>

void initBlockchain(Blockchain *blockchain)
{
    blockchain->genesisBlock = NULL;
    blockchain->latestBlock = NULL;
}

Block *generateNextBlock(Blockchain *blockchain, float data)
{
    Block *newBlock;
    newBlock->index = 0;
    newBlock->previousBlock = NULL;
    newBlock->timestomp = 0;
    newBlock->data = data;
}

int addBlock(Blockchain *blockchain, Block *newblock)
{
}

char *calculateHash(int index, char *previousHash, unsigned long timestamp, float data)
{
}