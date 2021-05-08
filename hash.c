#include <stdio.h>
#include"block.h"

char source[]="qwert5yui26opA0SD7FGHJKLz1xcvbn8mZ3XCVBNMQWE4RTYU9IOPasdfghjkl!@#$*^&";
//69

char* hashfunction(block_ptr B)
{
    char hash[12];
    hash[0]=source[((B->index)+(B->nonce)*3*(B->t_array[17].to))%69];
    hash[1]=source[((B->nonce)*(B->index)+21*(B->t_array[34].amt)+B->nonce)%69];
    hash[2]=source[((B->t_array[45].amt)*(B->index+B->nonce))%69];
    hash[3]=source[(B->nonce+B->index*13+4)%69];
    hash[4]=source[(B->t_array[25].to+B->nonce+3988+3*(B->index))%69];
    hash[5]=source[((B->nonce)*(B->t_array[3].amt)+3+(B->index+B->nonce))%69];
    hash[6]=source[((B->index+B->t_array[43].from)-478+B->nonce*2)%69];
    hash[7]=source[(B->nonce+B->index+9341)%69];
    hash[8]=source[(B->t_array[23].amt*3)%69];
    hash[9]=source[((B->nonce)+B->t_array[23].to+B->t_array[32].from)%69];
    hash[10]=source[((B->index)*(B->t_array[12].from)+B->nonce)%69];
    hash[11]=source[(B->nonce+(B->t_array[43].amt)*(B->t_array[23].from))%69];

    return hash;


}