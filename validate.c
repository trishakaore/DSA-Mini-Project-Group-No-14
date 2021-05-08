#include "user.h"
#include "block.h"

void validate_block_chain()
{
    block_ptr traverse = trav;

    while (traverse->prev != NULL) {
        //calc hash value using traverse.prev values and compare it with prevhash of traverse

        if (/*they're not equal*/) {
            for (int i = 1; i <= 500; i++) {
                //calc hash val again and check if it matches
                if (/*it matches*/ ) {
                    //trav->prev->nonce is that value
                }
            }
        }

        traverse = traverse->prev;
    }
}