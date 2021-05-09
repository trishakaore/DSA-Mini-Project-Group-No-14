#include "block.h"

void GetBackupVsFresh()   //to load a previous database or start a fresh one
{

    printf("Do you want to restore data from backup files? (y/n): ");
    char k;
    scanf("%c", &k);

    if (k == 'y')
    {
        GetUserHash();   //to retrieve the user database
        GetBlocksFromFile();   //to retrieve the block-chain

        block_num = trav->block_index;   //reset the block_num

        int i = 0;
        //to reset value of transactions
        while (trav->t_array[i].amt != 0) {
            i++;
        }
        transactions = i;
    }
    else
    {
        initHash();  //starts a fresh user database
        Init_block_chain();   //starts a fresh block-chain
    }
}

void printBlockchain()  //to print the block-chain
{
    block_ptr t_print;
    int i;
    t_print = head;
    for (i = 1; i < trav->block_index; i++)    //traverse through the block-chain and print relevant info
    {
        printf("block index = %d\n", t_print->block_index);
        printf("previous block hash = %s\n", t_print->prev_block_hash);
        printf("nonce = %d\n", t_print->nonce);
        printf("          |\n");
        printf("          v\n");
        t_print = t_print->next;
    }
    printf(" CURRENT (INCOMPLETE BLOCK)\n");
}

void validate_block_chain()  //checks the block-chain for any attacks and restores the original nonce
{
    block_ptr traverse = trav;
    if (traverse != NULL)
    {
        while (traverse->prev != NULL)
        {
            //calc hash value using traverse.prev values and compare it with prevhashvalue of traverse
            char *hashvalue = hashfunction(traverse->prev);
            
            if (/*they're not equal==>attacked*/ strcmp(traverse->prev_block_hash, hashvalue) != 0)
            {
                printf("block number %d was attacked\n", traverse->prev->block_index); //testing purpose
                
                for (int i = 1; i <= 500; i++) //to find the correct nonce
                {
                    traverse->prev->nonce = i;
                    hashvalue = hashfunction(traverse->prev);
                    //calc hash val again and check if it matches
                    if (/*it matches*/ strcmp(traverse->prev_block_hash, hashvalue) == 0)
                    {
                        printf("block number %d has been repaired!\n", traverse->prev->block_index); //testing purpose
                        //trav->prev->nonce is that value
                        break;
                    }
                }
            }

            traverse = traverse->prev;
        }
        printf("\nThe block chain has been validated!\n"); //testing purpose
    }
    else
        printf("No block-chain present\n");
}

block_ptr Init_block_chain()  //to initialise a block-chain
{

    head = malloc(sizeof(block));   //head
    head->prev = NULL;
    head->next = NULL;
    head->block_index = 1;
    strcpy(head->prev_block_hash, "0");
    head->nonce = (rand() % 500) + 1;   //generate a nonce

    for (int i = 0; i < 50; i++)   //initialise the transaction array in the block
    {
        head->t_array[i].to = 0;
        head->t_array[i].from = 0;
        head->t_array[i].amt = 0;
    }

    trav = head;      //since there's only one block
    transactions = 0;

    return head; 
}

void add_block() //always validate before add  //after transaction has been called, if transactions == 50, then add_block
{
    validate_block_chain();
    block_num++;
    transactions = 0; 

    block_ptr tmp = malloc(sizeof(block));

    for (int i = 0; i < 50; i++)   //initialise the transaction array
    {
        tmp->t_array[i].to = 0;
        tmp->t_array[i].from = 0;
        tmp->t_array[i].amt = 0;
    }

    tmp->block_index = block_num;                   //assigning values
    tmp->nonce = (rand() % 500) + 1;
    trav->next = tmp;
    tmp->next = NULL;
    //must calc. the hash value of trav and store it in hash_value[30]

    tmp->prev = trav;      //insertion at the end of the chain
    trav = tmp;
    char *hash_value = hashfunction(trav->prev);

    strcpy(trav->prev_block_hash, hash_value); //storing the prevhashvalue
    
}

void WriteBlocksToFile()   //writes and stores the block-chain in a retrievable manner in block.txt
{
    FILE *f;
    f = fopen("block.txt", "w");
    block tmp;
    block_ptr go;
    go = head;
    while (go)   //writing the blocks one by one
    {
        tmp = *go;
        fwrite(&tmp, sizeof(block), 1, f);
        go = go->next;
    }
    //printf("Put chain into block.txt\n");
    fclose(f);
}

void GetBlocksFromFile()    //retrieves the block-chain from bloc.txt and loads it, to perform further operations
{
    Init_block_chain();   //initialises a block-chain
    FILE *f;
    f = fopen("block.txt", "r");
    block tmp;

    //reads into head
    fread(&tmp, sizeof(block), 1, f);
    *head = tmp;
    while (fread(&tmp, sizeof(block), 1, f))  //reads blocks from the file and forms a linked list
    {
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