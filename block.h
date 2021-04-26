#ifndef MINIPROJ_BLOCK_H
#define MINIPROJ_BLOCK_H

typedef struct Block block;
typedef struct Transaction transaction;

struct Transaction {

};

struct Block {
    int block_index;
    transaction t_array[50];
    char prev_block_hash[30];
    int nonce;

};



#endif //MINIPROJ_BLOCK_H
