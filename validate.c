//when added to add_block remove printf() statement

#include "user.h"
#include "block.h"


void validate_block_chain()
{
    block_ptr traverse = trav;

    while (traverse->prev != NULL)
    {
        //calc hash value using traverse.prev values and compare it with prevhash of traverse
        char *hashvalue = hashfunction(traverse->prev);
        //hashvalue=hashfunction(traverse->prev);
        //strcpy(hashvalue,hashfunction(traverse->prev));

        if (/*they're not equal*/ strcmp(traverse->prev_block_hash, hashvalue) != 0)
        {
            printf("%d block was attacked\n", traverse->prev->block_index);
            //block_ptr temp=traverse;

            for (int i = 1; i <= 500; i++)
            {
                traverse->prev->nonce = i;
                hashvalue = hashfunction(traverse->prev);
                //calc hash val again and check if it matches
                if (/*it matches*/ strcmp(traverse->prev_block_hash, hashvalue) == 0)
                {
                    printf("%d block has been repaired!\n", traverse->prev->block_index);
                    //trav->prev->nonce is that value
                    break;
                }
            }
        }

        traverse = traverse->prev;
    }
    printf("The block chain has been validated!\n");
}
