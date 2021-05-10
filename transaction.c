#include "block.h"     //header file which contains function add_block() and includes header file user.h.
                       //user.h contains functions update_trav(long int,long int, double), updateHistory(long int, long int, double),
                       //printHistory(), and transaction().
                       //both block.h and user.h contain structures which help in making and updating transactions and blocks.


void update_trav(long int from_ID, long int to_ID, double amount)   //function to update transaction details in the current block which is being pointed to by trav.
{
    if (trav == NULL)                                               //condition will be true if trav is not pointing to a block of memory
        trav = malloc(sizeof(block));                               //in that case we allocate memory (if the statement is true).
    trav->t_array[transactions].from = from_ID;                     //updates the SENDER's UID of the transaction in the current block.
    trav->t_array[transactions].to = to_ID;                         //updates the RECEIVER's UID of the transaction in the current block.
    trav->t_array[transactions].amt = amount;                       //updates the amount transacted during the transaction in the current block.
    transactions++;

    if (transactions == 50)                                         //number of transactions a block can store is 50, so if 50 transactions are done
        add_block();                                                //the condition is true and we add a new block. this add_block fuction creates a new block. 
}

void updateHistory(long int from_ID, long int to_ID, double amount)                 //function to update both the SENDER's and RECEIVER's transaction history.
{
    
    userHash[from_ID-1000].history[userHash[from_ID-1000].transNum].to = to_ID;     //updates the RECIEVER's UID in SENDER's transaction history.
    userHash[from_ID-1000].history[userHash[from_ID-1000].transNum].from = from_ID; //updates the SENDER's UID in SENDER's transaction history.
    userHash[from_ID-1000].history[userHash[from_ID-1000].transNum].amt = amount;   //updates the amount transferred in SENDER's transaction history.
    userHash[from_ID-1000].transNum++;                                              //increases the number of transactions of the SENDER by 1.

    userHash[to_ID-1000].history[userHash[to_ID-1000].transNum].to = to_ID;         //updates the RECIEVER's UID in RECEIVER's transaction history.
    userHash[to_ID-1000].history[userHash[to_ID-1000].transNum].from = from_ID;     //updates the SENDER's UID in RECEIVER's transaction history.
    userHash[to_ID-1000].history[userHash[to_ID-1000].transNum].amt = amount;       //updates the amount transferred in RECEIVER's transaction history.
    userHash[to_ID-1000].transNum++;                                                //increases the number of transactions of the RECIEVER by 1.


}

void printHistory()                                                                    //function to print transaction history of a user. in the transaction history, the user can be both the SENDER or the RECEIVER.
{
    long int from_ID;
    long int i;
    printf("enter user's ID whose transaction history is to be displayed : ");
    scanf("%ld", &from_ID);
    
    if(userHash[from_ID-1000].ID == -1)                                                  //checks if the UID entered by the user exists or not, condition is true is the UID does not exist.
    {
        printf("Invalid UID!\n");
        return;
    }
    printf("total number of transactions : %d\n", userHash[from_ID-1000].transNum);    //prints the number of transactions of the user whose UID has been entered by the user.
    
    for(int k= 0; k< userHash[from_ID-1000].transNum;k++)
    {
        printf("From: %ld\n", userHash[from_ID-1000].history[k].from);                   //prints SENDER's ID in the (k+1)th transaction.
        printf("To: %ld\n", userHash[from_ID-1000].history[k].to);                       //prints RECIEVER's ID in the (k+1)th transaction.
        printf("Amount: %.2lf\n", userHash[from_ID-1000].history[k].amt);                //prints amount transferred in the (k+1)th transaction.
        printf("\n");

    }
}

void transaction()                                                                               //function to perform a transaction.
{
    long int to_ID, from_ID;
    double amount;
    printf("enter SENDER's UID : ");
    scanf("%ld", &from_ID);
    printf("enter RECEIVER's UID : ");
    scanf("%ld", &to_ID);
    printf("enter amount to be transferred : ");
    scanf("%lf", &amount);
    if (amount > 0)                                                                              //checks if the amount of transferred is greater than 0, if not, goes to the else statement instead.
    {
        if (from_ID >= 1000 && from_ID <= 9999 && to_ID >= 1000 && to_ID <= 9999)                //checks if the UID is in the range of UID's, if not, goes to the else statement instead.
        {
            if (userHash[to_ID - 1000].ID == to_ID && userHash[from_ID - 1000].ID == from_ID)    //checks if both the SENDER's UID and the RECEIVER's UID exist, if not, goes to the else statement instead.
            {
                if (to_ID != from_ID)                                                            //checks if the SENDER's and the RECEIVER's UID's are different, if not, goes to the else statement instead.
                {
                    if (userHash[from_ID - 1000].balance >= amount)                              //chcks if the SENDER's balance is more than or equal the amount that needs to be transfered, if not, goes to the else statement instead.
                    {
                        userHash[to_ID - 1000].balance += amount;                                //amount added to RECEIVER's balance.
                        userHash[from_ID - 1000].balance -= amount;                              //amount removed from SENDER's balance.

                        updateHistory(from_ID, to_ID, amount);                                   //function to update history.

                        update_trav(from_ID, to_ID, amount);                                     //function to update the current block's contents.


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
        printf("Transaction Failed! - Amount cannot be 0\n");
}
