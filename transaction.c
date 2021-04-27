#include "user.h"
#include "block.h"
#include <stdio.h>

void update_trav(long int from_ID, long int to_ID, double amount)
{
    trav->t_array[transactions].from = from_ID;
    trav->t_array[transactions].to = to_ID;
    trav->t_array[transactions].amt = amount;
    transactions++;
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

void printHistory(transact *l1)
{
    struct transact *temp = l1;

    while (temp != NULL)
    {
        printf("from UID : %ld\nto UID : %ld\namount transferred : %lf\n",temp->from,temp->to,temp->amt);
        temp=temp->next;
    }
}

void transaction()
{
    long int to_ID, from_ID;
    double amount;
    printf("to-from-amount to be transferred ");
    scanf("%ld %ld %lf", &to_ID, &from_ID, &amount);

    if (userHash[to_ID - 1000].ID == to_ID && userHash[from_ID - 1000].ID == from_ID)
    {
        if (userHash[from_ID - 1000].balance >= amount)
        {
            userHash[to_ID - 1000].balance += amount;
            userHash[from_ID - 1000].balance -= amount;

            updateHistory(from_ID, to_ID, amount, &userHash[from_ID - 1000].history);

            update_trav(from_ID, to_ID, amount);

            printHistory(userHash[from_ID - 1000].history);
        }
        else
            printf("Transaction Failed! - Invalid Amount\n");
    }
    else
        printf("Transaction Failed! - Invalid UID\n");
}