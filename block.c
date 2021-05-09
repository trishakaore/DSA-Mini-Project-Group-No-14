#include "block.h"

block_ptr Init_block_chain()
{

    head = malloc(sizeof(block));
    head->prev = NULL;
    head->next = NULL;
    head->block_index = 1;
    strcpy (head->prev_block_hash, "0");
    head->nonce = (rand() % 500) + 1;

    //trav = malloc(sizeof(block));
    trav = head;
    transactions = 0;

    return head;  //why global head?
}

void add_block()    //always validate before add?  //after transaction has been called, if transactions == 50, then add_block
{
    block_num++;
    transactions = 0; //check

    //block_ptr tmp;
    char hash_value[30];

    block_ptr tmp = malloc(sizeof(block));

    tmp->block_index = block_num;
    tmp->nonce = (rand() % 500) + 1;
    trav->next = tmp;
    tmp->next = NULL;
    //must calc. the hash value of trav and store it in hash_value[30]

    //strcpy(tmp->prev_block_hash, trav->prev_block_hash);

    tmp->prev = trav;
    trav = tmp;


    strcpy(trav->prev_block_hash, hash_value);   // hafta do this using hash

    //free(tmp);

//    trav->next = tmp;
//    //must calc. the hash value of trav and store it in hash_value[30]
//
//    trav = tmp;
//
//    trav->next = NULL;
//    trav->nonce = (rand() % 500) + 1;
//    trav->block_index = block_num;
//    strcpy(trav->prev_block_hash, hash_value);   // hafta do this using hash

}   

void WriteBlocksToFile(){
    FILE *f;
    f = fopen("block.txt","w");
    block tmp;
    block_ptr go;
    go = head;
    while(go){
        tmp=*go;
        fwrite(&tmp,sizeof(block),1,f);
        go = go->next;
    }
    //printf("Put chain into block.txt\n");
    fclose(f);
}

void GetBlocksFromFile(){
    Init_block_chain();
    FILE *f;
    f = fopen("block.txt","r");
    block tmp;
    fread(&tmp,sizeof(block),1,f);
    *head=tmp;
    while(fread(&tmp,sizeof(block),1,f)){
        block_ptr temptr = malloc(sizeof(block));
        *temptr = tmp;
        trav->next = temptr;
        temptr->next = NULL;
        temptr->prev = trav;
        trav = temptr;
    }

    //printf("blockchain ready\n");
    fclose(f);
}

void GetBackupVsFresh(){

    printf("Do you want to restore data from backup files? (y/n): ");
    char k;
    scanf("%c",&k);
    
    if(k=='y'){
        GetUserHash();
        GetBlocksFromFile();
    }
    else{
        initHash();
        Init_block_chain();
    }
}