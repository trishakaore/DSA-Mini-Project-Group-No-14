#include <stdio.h>
#include"block.h"

char source[]="qwert5yui26opA0SD7FGHJKLz1xcvbn8mZ3XCVBNMQWE4RTYU9IOPasdfghjkl!@#$*^&+-";
//71

char* hashfunction(block_ptr B)
{
    char hash[12];
    hash[0]=source[((B->block_index)+(B->nonce)*3*(B->t_array[17].to))%71];
    hash[1]=source[((B->nonce)*(B->block_index)+21*(int)(B->t_array[34].amt)+B->nonce)%71];
    hash[2]=source[((int)(B->t_array[45].amt)*(B->block_index+B->nonce))%71];
    hash[3]=source[(B->nonce+B->block_index*13+4)%71];
    hash[4]=source[(B->t_array[25].to+B->nonce+3988+3*(B->block_index))%71];
    hash[5]=source[((B->nonce)*(int)(B->t_array[3].amt)+3+(B->block_index+B->nonce))%71];
    hash[6]=source[((B->block_index+B->t_array[43].from)-478+B->nonce*2)%71];
    hash[7]=source[(B->nonce+B->block_index+9341)%71];
    hash[8]=source[((int)B->t_array[23].amt*3+(int)B->t_array[5].amt)%71];
    hash[9]=source[((B->nonce)+B->t_array[23].to+B->t_array[32].from)%71];
    hash[10]=source[((B->block_index)*(B->t_array[12].from)+B->nonce)%71];
    hash[11]=source[(B->nonce+((int)B->t_array[43].amt)*(B->t_array[23].from))%71];

    return hash;


}