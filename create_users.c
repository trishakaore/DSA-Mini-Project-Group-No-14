#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define UserNum 100 //number of users which will be added

int main()
{
    int i;
    printf("n\n"); //this is an instruction for main.c, in order to not read from the existing files
    srand(time(NULL));
    long rn;
    for (i = 0; i < UserNum; i++)
    {
        printf("add user\n");                          //this is an instruction for main, in order to add a new user
        rn = ((rand() % (1000000 - 1000 + 1)) + 1000); //generates random numbers from 1000 to 1000000 (both included)
                                                       //this number will be the balance of the new user
        printf("%ld\n", rn);
    }
    printf("exit\ny\ny\n"); //these are instructions for main, in order to exit main.c
                            //exit is for exiting, the first y is to confirm exit, the second y is to save the data generated
    return (0);
}