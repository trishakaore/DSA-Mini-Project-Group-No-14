
#include "block.h"
#include <time.h>

void attack()
{
    block_ptr t;
    t = trav; //note that trav is the global variable pointing to the last block
    int changed;

    srand(time(NULL));
    int rndnum = ((rand()) % 50) + 1;
    if (t != NULL)
    {
        if (t->block_index > 1)
        {
            t = t->prev;
            if (rndnum > t->block_index)
            {
                printf("Attack failed\n");
                return;
            }
            while (t != NULL)
            {
                if (t->block_index == rndnum)
                {
                    changed = (rand() % 500) + 1;

                    while (changed == t->nonce)
                    {
                        changed = (rand() % 500) + 1;
                    }
                    printf("Attack Successful\n");

                    t->nonce = changed;
                    break;
                }
                t = t->prev;
            }
        }
        else
            printf("Only first block present - cannot be attacked\n");
    }
    else
        printf("no block formed to attack");
}