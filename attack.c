
#include "block.h"
#include <time.h>

void attack()
{
    block_ptr t;
    t = trav; //note that trav is the global variable pointing to the last block
    int changed;

    srand(time(NULL));
    int rndnum = ((rand()) % 50) + 1;  //generates a random number from 1-50
    if (t != NULL)
    {
        if (t->block_index > 1)
        {
            t = t->prev;       //goes to the second last block in the block chain
            if (rndnum > t->block_index) //condition for attack-fail
            {
                printf("Attack failed\n");
                return;
            }
            while (t != NULL)     //comes into this loop only when attack is possible
            {
                if (t->block_index == rndnum)
                {
                    changed = (rand() % 500) + 1;

                    while (changed == t->nonce)
                    {
                        changed = (rand() % 500) + 1;
                    }
                    printf("Attack Successful\n");

                    t->nonce = changed;   //changes the nonce of the attacked block
                    break;
                }
                t = t->prev;  //continues the loop
            }
        }
        else
            printf("Only first block present - cannot be attacked\n");
    }
    else
        printf("no block formed to attack");
}