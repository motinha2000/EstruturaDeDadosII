#ifndef Blockchain_h
#define Blockchain_h
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Block
{
    unsigned int index;
    char *previousHash;
    struct Block *previousBlock;
    unsigned long timestamp;
    float data;
    char *hash;
} Block;

typedef struct Blockchain
{
    Block *genesisBlock;
    Block *latestBlock;
} Blockchain;

void initBlockchain(Blockchain *blockchain);
char *calculateHash(int index, char *previousHash, unsigned long timestamp, float data);
Block *generateNextBlock(Blockchain *blockchain, float data);//cria o bloco
Block *getLatestBlock(Blockchain *blockchain);
bool isValidNewBlock(Block *newBlock, Block *previousBlock);
bool isBlockchainValid(Blockchain *blockchain);
int addBlock(Blockchain *blockchain, Block *newBlock);//adiciona o bloco na lista

#endif