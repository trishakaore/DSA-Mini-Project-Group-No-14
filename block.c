#include "block.h"
//#include "validate.c"

void validate_block_chain()
{
    block_ptr traverse = trav;
    if (traverse != NULL)
    {
        while (traverse->prev != NULL)
        {
            //calc hash value using traverse.prev values and compare it with prevhash of traverse
            char *hashvalue = hashfunction(traverse->prev);
            //hashvalue=hashfunction(traverse->prev);
            //strcpy(hashvalue,hashfunction(traverse->prev));

            if (/*they're not equal*/ strcmp(traverse->prev_block_hash, hashvalue) != 0)
            {
                printf("%d block was attacked\n", traverse->prev->block_index);     //testing purpose
                //block_ptr temp=traverse;

                for (int i = 1; i <= 500; i++)
                {
                    traverse->prev->nonce = i;
                    hashvalue = hashfunction(traverse->prev);
                    //calc hash val again and check if it matches
                    if (/*it matches*/ strcmp(traverse->prev_block_hash, hashvalue) == 0)
                    {
                        printf("%d block has been repaired!\n", traverse->prev->block_index);    //testing purpose
                        //trav->prev->nonce is that value
                        break;
                    }
                }
            }

            traverse = traverse->prev;
        }
        printf("The block chain has been validated!\n");   //testing purpose
    }
    else
        printf("No block-chain present\n");
}

block_ptr Init_block_chain()
{

    head = malloc(sizeof(block));
    head->prev = NULL;
    head->next = NULL;
    head->block_index = 1;
    strcpy(head->prev_block_hash, "0");
    head->nonce = (rand() % 500) + 1;

    //trav = malloc(sizeof(block));
    trav = head;
    transactions = 0;

    return head; //why global head?
}

void add_block() //always validate before add?  //after transaction has been called, if transactions == 50, then add_block
{
    validate_block_chain();
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

    strcpy(trav->prev_block_hash, hash_value); // hafta do this using hash

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
