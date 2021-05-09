#include "block.h"


void update_trav(long int from_ID, long int to_ID, double amount)
{
    if (trav == NULL)
        trav = malloc(sizeof(block));
    trav->t_array[transactions].from = from_ID;
    trav->t_array[transactions].to = to_ID;
    trav->t_array[transactions].amt = amount;
    transactions++;

    if (transactions == 50)
        add_block();
}

void updateHistory(long int from_ID, long int to_ID, double amount)
{
    
    userHash[from_ID-1000].history[userHash[from_ID-1000].transNum].to = to_ID;
    userHash[from_ID-1000].history[userHash[from_ID-1000].transNum].from = from_ID;
    userHash[from_ID-1000].history[userHash[from_ID-1000].transNum].amt = amount;
    userHash[from_ID-1000].transNum++;

    userHash[to_ID-1000].history[userHash[to_ID-1000].transNum].to = to_ID;
    userHash[to_ID-1000].history[userHash[to_ID-1000].transNum].from = from_ID;
    userHash[to_ID-1000].history[userHash[to_ID-1000].transNum].amt = amount;
    userHash[to_ID-1000].transNum++;


}

void printHistory()
{
    long int from_ID;
    long int i;
    printf("enter user's ID whose transaction history is to be displayed : ");
    scanf("%ld", &from_ID);
    
    if(userHash[from_ID-1000].ID == -1){
        printf("Invalid UID!\n");
        return;
    }
    printf("transNum: %d\n", userHash[from_ID-1000].transNum);
    
    for(int k= 0; k< userHash[from_ID-1000].transNum;k++){
        printf("From: %ld\n", userHash[from_ID-1000].history[k].from);
        printf("To: %ld\n", userHash[from_ID-1000].history[k].to);
        printf("Amount: %.2lf\n", userHash[from_ID-1000].history[k].amt);
        printf("\n");

    }
}

void transaction()
{
    long int to_ID, from_ID;
    double amount;
    printf("enter SENDER's UID : ");
    scanf("%ld", &from_ID);
    printf("enter RECEIVER's UID : ");
    scanf("%ld", &to_ID);
    printf("enter amount to be transferred : ");
    scanf("%lf", &amount);
    if (amount > 0)
    {
        if (from_ID >= 1000 && from_ID <= 9999 && to_ID >= 1000 && to_ID <= 9999)
        {
            if (userHash[to_ID - 1000].ID == to_ID && userHash[from_ID - 1000].ID == from_ID)
            {
                if (to_ID != from_ID)
                {
                    if (userHash[from_ID - 1000].balance >= amount)
                    {
                        userHash[to_ID - 1000].balance += amount;
                        userHash[from_ID - 1000].balance -= amount;

                        updateHistory(from_ID, to_ID, amount);

                        update_trav(from_ID, to_ID, amount);


                        printf("\nSuccessfully transferred!\n");
                    }
                    else
                        printf("Transaction Failed! - Invalid Amount\n");
                }
                else
                    printf("Transaction Failed! - SENDER's UID cannot be the same as RECEIVER's UID\n");
            }
            else
                printf("Transaction Failed! - Invalid UID\n");
        }
        else
            printf("Transaction Failed! - Invalid UID\n");
    }
    else
        printf("Anount cannot be 0 - Transaction Failed\n");
}