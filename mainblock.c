#include "transaction.c"
#include "block.c"

int main(){
    srand(time(NULL));
    Init_block_chain();

    //int n;
    //scanf("%d",&n);

    //srand(time(NULL));
    initHash();

    for(int i=0;i<2;i++)
        makeUser();

    for(int i=0; i<size-1; i++){
        if(userHash[i].ID!=-1){
            printf("ID: %ld\n", userHash[i].ID);
            printf("Balance: %lf\n",userHash[i].balance);
            printf("Date : %02d/%02d/%02d\n",userHash[i].join.dd,userHash[i].join.mm,userHash[i].join.yy);
            printf("Time : %02d:%02d\n",userHash[i].tim.hrs,userHash[i].tim.min);
            }
    }

    for(int i=0;i<5;i++){
        transaction();
    }

    printf("block number: %d\n",block_num);
}