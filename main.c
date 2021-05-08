#include "user.h"

int main(){

    int n;
    scanf("%d",&n);

    srand(time(NULL));
    initHash();

    for(int i=0;i<n;i++)
        makeUser();

    for(int i=0; i<size-1; i++){
        if(userHash[i].ID!=-1){
            printf("ID: %ld\n", userHash[i].ID);
            printf("Balance: %lf\n",userHash[i].balance);
            printf("Date : %02d/%02d/%02d\n",userHash[i].join.dd,userHash[i].join.mm,userHash[i].join.yy);
            printf("Time : %02d:%02d\n",userHash[i].tim.hrs,userHash[i].tim.min);
            }
    }
}