#include "block.h"

void GetBackupVsFresh()
{

    printf("Do you want to restore data from backup files? (y/n): ");
    char k;
    scanf("%c", &k);

    if (k == 'y')
    {
        GetUserHash();
        GetBlocksFromFile();

        block_num = trav->block_index;

        int i = 0;
        while (trav->t_array[i].amt != 0) {
            i++;
        }
        transactions = i;
    }
    else
    {
        initHash();
        Init_block_chain();
    }
}

void printBlockchain()
{
    block_ptr t_print;
    int i;
    t_print = head;
    for (i = 1; i < trav->block_index; i++)
    {
        printf("block index = %d\n", t_print->block_index);
        printf("previous block hash = %s\n", t_print->prev_block_hash);
        printf("nonce = %d\n", t_print->nonce);
        printf("          |\n");
        printf("          v\n");
        t_print = t_print->next;
    }
}

void validate_block_chain()
{
    block_ptr traverse = trav;
    if (traverse != NULL)
    {
        while (traverse->prev != NULL)
        {
            //calc hash value using traverse.prev values and compare it with prevhash of traverse
            char *hashvalue = hashfunction(traverse->prev);
            
            if (/*they're not equal*/ strcmp(traverse->prev_block_hash, hashvalue) != 0)
            {
                printf("%d block was attacked\n", traverse->prev->block_index); //testing purpose
                
                for (int i = 1; i <= 500; i++)
                {
                    traverse->prev->nonce = i; //sjjsjjsj
                    hashvalue = hashfunction(traverse->prev);
                    //calc hash val again and check if it matches
                    if (/*it matches*/ strcmp(traverse->prev_block_hash, hashvalue) == 0)
                    {
                        printf("%d block has been repaired!\n", traverse->prev->block_index); //testing purpose
                        //trav->prev->nonce is that value
                        break;
                    }
                }
            }

            traverse = traverse->prev;
        }
        printf("The block chain has been validated!\n"); //testing purpose
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

    for (int i = 0; i < 50; i++)
    {
        head->t_array[i].to = 0;
        head->t_array[i].from = 0;
        head->t_array[i].amt = 0;
    }

    trav = head;
    transactions = 0;

    return head; 
}

void add_block() //always validate before add  //after transaction has been called, if transactions == 50, then add_block
{
    validate_block_chain();
    block_num++;
    transactions = 0; 

    block_ptr tmp = malloc(sizeof(block));

    for (int i = 0; i < 50; i++)
    {
        tmp->t_array[i].to = 0;
        tmp->t_array[i].from = 0;
        tmp->t_array[i].amt = 0;
    }

    tmp->block_index = block_num;
    tmp->nonce = (rand() % 500) + 1;
    trav->next = tmp;
    tmp->next = NULL;
    //must calc. the hash value of trav and store it in hash_value[30]

    tmp->prev = trav;
    trav = tmp;
    char *hash_value = hashfunction(trav->prev);

    strcpy(trav->prev_block_hash, hash_value); // have to do this using hash
    
}

void WriteBlocksToFile()
{
    FILE *f;
    f = fopen("block.txt", "w");
    block tmp;
    block_ptr go;
    go = head;
    while (go)
    {
        tmp = *go;
        fwrite(&tmp, sizeof(block), 1, f);
        go = go->next;
    }
    //printf("Put chain into block.txt\n");
    fclose(f);
}

void GetBlocksFromFile()
{
    Init_block_chain();
    FILE *f;
    f = fopen("block.txt", "r");
    block tmp;
    fread(&tmp, sizeof(block), 1, f);
    *head = tmp;
    while (fread(&tmp, sizeof(block), 1, f))
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