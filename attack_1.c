//#include <stdio.h>
#include "block.h"
//#include <stdbool.h>
#include <time.h>

void attack()
{
    block_ptr t;
    t = trav;    //note that trav is the global variable pointing to the last block
    //int prev_nonce;
    int changed;

    srand(time(NULL));
    int rndnum=((rand())%50)+1;
    //t=t->next;
    while(t != NULL)
    {
        if(t->block_index == rndnum)
        {
            //prev_nonce = t->nonce;
            changed = (rand()%500)+1;

            while (changed == t->nonce) {
                changed = (rand() % 500) + 1;
            }

            t->nonce = changed;
            break;
        }
     t=t->prev;
    }

    if(t == NULL)
    {
        printf("Attack failed\n");
    }

}
