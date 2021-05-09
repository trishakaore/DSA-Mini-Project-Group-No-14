#include "user.c"
#include "time.h"

#define TranNum 2500

int main(){
    printf("y\n");
    FILE *f;
    user tmp;
    srand(time(NULL));
    user UIDArray[800];
    int i=0,n1,n2;
    double amt;
    f = fopen("user.txt","r");
    while(fread(&tmp, sizeof(user), 1, f)){
        //printf("%ld\n",tmp.ID);
        UIDArray[i] = tmp;
        i++;
    }

    for(int k=0;k<TranNum;k++){
        n1 = rand()%i;
        n2 = rand()%i;
        amt = (double)(rand()%500 + 1);

        printf("transaction\n");
        printf("%ld\n",UIDArray[n1].ID);
        printf("%ld\n",UIDArray[n2].ID);
        printf("%lf\n",amt);
    }

    printf("exit\n");
    printf("y\n");
    printf("y\n");
}