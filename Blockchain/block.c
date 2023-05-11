#include "block.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sha-256.h"

void initBlockchain(Blockchain *blockchain)
{
    Block *genesisBlock = (Block *)malloc(sizeof(Block));
    genesisBlock->index = 0;
    genesisBlock->previousHash = "0";
    genesisBlock->previousBlock = NULL;
    genesisBlock->timestamp = time(NULL);
    genesisBlock->data = 1000000;
    // calcula o hash do genesis block
    genesisBlock->hash = calculateHash(genesisBlock->index, genesisBlock->previousHash, genesisBlock->timestamp, genesisBlock->data);
    blockchain->genesisBlock = genesisBlock;
    blockchain->latestBlock = genesisBlock;
}

static void hash_to_string(char string[65], const uint8_t hash[32])
{
    size_t i;
    for (i = 0; i < 32; i++)
    {
        // montar uma string com 64 caracteres hexadecimais
        string += sprintf(string, "%02x", hash[i]); // 02x hexadecimal em 2 caracteres
    }
}

char *calculateBlockHash(Block *block)
{
    return calculateHash(block->index, block->previousHash, block->timestamp, block->data);
}

char *calculateHash(int index, char *previousHash, unsigned long timestamp, float data)
{
    if (previousBlock->index + 1 != newBlock->index)
    {
        return false;
    }
    else if (previousBlock->hash != newBlock->previousHash)
    {
        return false;
    }
    else if (strcmp(calculateBlockHash(newBlock), newBlock->hash) != 0)
    {
        return false;
    }

    return true;
}

Block *generateNextBlock(Blockchain *blockchain, float data)
{
    // pegamos uma referência ao último bloco da lista
    Block *previousBlock = getLatestBlock(blockchain);
    Block *newBlock = (Block *)malloc(sizeof(Block));
    newBlock->data = data;
    newBlock->previousHash = previousBlock->hash;
    newBlock->index = previousBlock->index + 1;
         //pegamos a data e hora atual
        ewBlock->timestamp = time(NULL);
         //calculamos o hash do novo bloco
        newBlock->hash = calculateBlockHash(newBlock);
    return newBlock;
}

Block *getLatestBlock(Blockchain *blockchain)
{
    return blockchain->latestBlock;
}

bool isValidNewBlock(Block *newBlock, Block *previousBlock)
{
    if (previousBlock->index + 1 != newBlock->index)
    {

        return false;
    }
    else if (previousBlock->hash != newBlock->previousHash)
    {

        return false;
    }
    else if (strcmp(calculateBlockHash(newBlock), newBlock->hash) != 0)
    {

        return false;
    }

    return true;
}

bool isBlockchainValid(Blockchain *blockchain)
{
    Block *aux = getLatestBlock(blockchain);

    while (aux != blockchain->genesisBlock)
    {

        if (!isValidNewBlock(aux, aux->previousBlock))

            return false;

        aux = aux->previousBlock;
    }

    return true;
}

int addBlock(Blockchain *blockchain, Block *newblock)
{
}
