#include "block.h"

//#include <stdio.h>

void update_trav(long int from_ID, long int to_ID, double amount)
{
    if (trav == NULL)
        trav = malloc(sizeof(block));
    trav->t_array[transactions].from = from_ID;
    trav->t_array[transactions].to = to_ID;
    trav->t_array[transactions].amt = amount;
    transactions++;

    if (transactions == 2)
        add_block();
    //printf("block number: %d\n", block_num);
}

void updateHistory(long int from_ID, long int to_ID, double amount, struct transact **head_ref)
{
    struct transact *next_transact = NULL;
    next_transact = (struct transact *)malloc(sizeof(struct transact));

    next_transact->to = to_ID;
    next_transact->from = from_ID;
    next_transact->amt = amount;
    next_transact->next = (*head_ref);
    (*head_ref) = next_transact;
}

void printHistory()
{
    long int from_ID;
    long int i;
    printf("enter user's ID whose transaction history is to be displayed : ");
    scanf("%ld", &from_ID);
    struct transact *temp = userHash[from_ID - 1000].history;

    while (temp != NULL)
    {
        printf("sent from UID : %ld\nreceived by UID : %ld\namount transferred : %lf\n", temp->from, temp->to, temp->amt);
        temp = temp->next;
    }
    printf("\n");
    for (i = 0; i < 9000; i++)
    {
        if (userHash[i].ID != -1)
        {
            struct transact *temp1 = userHash[i].history;
            while (temp1 != NULL)
            {
                if (temp1->to == from_ID)
                {
                    printf("sent from UID : %ld\nreceived by UID : %ld\namount transferred : %lf\n", temp1->from, temp1->to, temp1->amt);
                }
                temp1 = temp1->next;
            }
        }
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

                        updateHistory(from_ID, to_ID, amount, &userHash[from_ID - 1000].history);

                        update_trav(from_ID, to_ID, amount);

                        //printHistory(userHash[from_ID - 1000].history);

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