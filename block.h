#ifndef MINIPROJ_BLOCK_H
#define MINIPROJ_BLOCK_H

#include "user.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct Block block;
typedef struct block_transact block_transact;
typedef struct Block* block_ptr;


int block_num = 1;
int transactions = 0; 
 //set to zero for every new block and increment one by one

struct block_transact{
    long to;
    long from;
    double amt;
};


struct Block {
    int block_index;
    block_transact t_array[50];
    char prev_block_hash[30];
    int nonce;
    block_ptr prev;
    block_ptr next;
};


block_ptr head, trav;

//block_ptr block_array = NULL;


block_ptr Init_block_chain();

block_ptr make_block();

void add_block();

void attack();



#endif //MINIPROJ_BLOCK_H