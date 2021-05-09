#ifndef MINIPROJ_BLOCK_H
#define MINIPROJ_BLOCK_H

#include "user.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Block block;
typedef struct block_transact block_transact;
typedef struct Block *block_ptr;

int block_num = 1;      //global variable to count the number of blocks
int transactions = 0;   //global variable to count the number of transactions in the latest block
//set to zero for every new block and increment one by one

char hash[13];

struct block_transact
{
    long to;
    long from;
    double amt;
};

struct Block
{
    int block_index;
    block_transact t_array[50];
    char prev_block_hash[20];
    int nonce;
    block_ptr prev;
    block_ptr next;
};

block_ptr head, trav;    //pointers to head and the latest block of the block chain respectively

block_ptr Init_block_chain();     //initialises the block chain

void add_block(); //adds a block to the block-chain when the current block is full

void attack();   //attacks a random block (from 1-50) and changes its nonce

void validate_block_chain();   //checks the block-chain for any attacks and restores the original nonce

char *hashfunction(block_ptr);   //the hash-function used to calculate the hash-value of a block

void WriteBlocksToFile();   //writes and stores the block-chain in a retrievable manner in block.txt

void GetBlocksFromFile();  //retrieves the block-chain from bloc.txt and loads it, to perform further operations

#endif //MINIPROJ_BLOCK_H