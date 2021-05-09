#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define UserNum 100

int main()
{
        int i,n;
        printf("n\n");
        //scanf("%d", &n);
        srand(time(NULL));
        long rn;
        for (i = 0; i < UserNum; i++)
        {
                printf("add user\n");
                rn = ((rand() % (1000000 - 1000 + 1)) + 1000);
                printf("%ld\n", rn);
        }
        printf("exit\ny\ny\n");
        return (0);
}