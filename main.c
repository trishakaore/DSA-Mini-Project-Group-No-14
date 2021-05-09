#include "block.c"          // * 
#include "transaction.c"    // * 
#include "user.c"           // * all the necessary files which have functions and variables required
#include "attack.c"         // *
#include "hash.c"           // *
#include <ctype.h>        



int main()
{
    char buf,garb;
    int i;
    char choice[100] = {'\0'};             //this will be where the user's entered choice will be stored.
    system("clear");                       //clears screen.
    srand(time(NULL));

    //\e[0;92m changes text color to green.
    //\033[31m changes text color to red.
    //\033[0m changes text color to default color.

    printf("\n\e[0;92m                                                                BITCOIN\n");
    printf("                                                               ---------\n");
    printf("                                                      Project by group number 14\n\n");
    
    GetBackupVsFresh();                   //function which asks the user if they want to load previous data.


    scanf("%c", &buf);                    //stores '\n' (the enter key pressed by the user).
user_interface:                           //label which prints and the instructions and takes input from the user.
    printf("\033[0mPlease enter your choice to continue!\n\n");                                       // * instructions for user
    printf("\033[31mEnter \e[0;92m\"add user\"\033[31m to create a add user to the system\n");        // *
    printf("Enter \e[0;92m\"load users\"\033[31m to load users\n");                                   // *
    printf("Enter \e[0;92m\"transaction\"\033[31m to do a transaction\n");                            // *
    printf("Enter \e[0;92m\"transaction history\"\033[31m to display transcation history\n");         // *
    printf("Enter \e[0;92m\"block chain\"\033[31m to print the block chain\n");                       // *
    printf("Enter \e[0;92m\"attack\"\033[31m to attack a block\n");                                   // *
    printf("Enter \e[0;92m\"validate\"\033[31m to validate block chain\n");                           // *
    printf("Enter \e[0;92m\"clear\"\033[31m to clear screen\n");                                      // *
    printf("Enter \e[0;92m\"exit\"\033[31m to exit");                                                 // * end here
    printf("\033[0m\n\n");
    scanf("%[^\n]", choice);           //choice to be entered by the user without space or any other character following it.
    printf("\n");
    scanf("%c", &buf);                 //stores '\n' (the enter key pressed by the user).

    for (i = 0; i < 100, choice[i] != '\0';)        //loop to change every character of the choice enetered to lower case.
    {
        
        if (choice[i] >= 'A' && choice[i] <= 'Z')
            choice[i] = tolower(choice[i]);
        i++;
    }
    if (strcmp(choice, "add user") == 0)            //checks if user choice was "add user".
    {
        makeUser();                                 //function to add user.
        scanf("%c", &buf);                          //stores '\n' (the enter key pressed by the user).
        printf("\n\n");
        goto user_interface;                        //goes to label user_interface.
    }

    else if (strcmp(choice, "load users") == 0)     //checks if user choice was "load user".
    {
        printf("\n");                               
        printUsers();                               //function to load existing users.
        printf("\n\n");
        goto user_interface;                        //goes to label user_interface.
    }

    else if (strcmp(choice, "transaction") == 0)    //checks if user choice was "transaction".
    {
        transaction();                              //function to do a transaction.
        scanf("%c", &buf);                          //stores '\n' (the enter key pressed by the user).
        printf("\n\n");
        goto user_interface;                        //goes to label user_interface.
    }
    else if (strcmp(choice, "transaction history") == 0)  //checks if user choice was "transaction history".
    {
        printHistory();                             //function to print transaction history.
        scanf("%c", &buf);                          //stores '\n' (the enter key pressed by the user).
        printf("\n\n");
        goto user_interface;                         //goes to label user_interface.
    }
    else if (strcmp(choice, "block chain") == 0)     //checks if user choice was "block chain".
    {
        printBlockchain();                           //function to print block chain.     
        printf("\n\n");
        goto user_interface;                         //goes to label user_interface.
    }
    else if (strcmp(choice, "attack") == 0)          //checks if user choice was "attack".
    {
        attack();                                    //function to try to attack a block.
        printf("\n\n");
        goto user_interface;                         //goes to label user_interface.
    }
    else if (strcmp(choice, "validate") == 0)        //checks if user choice was "validate".
    {
        validate_block_chain();                      //function to check if the block chain is valid.
        printf("\n\n"); 
        goto user_interface;                         //goes to label user_interface.
    }
    else if (strcmp(choice, "clear") == 0)           //checks if user choice was "clear".
    {
        system("clear");
        goto user_interface;                         //goes to label user_interface.
    }
    else if (strcmp(choice, "exit") == 0)            //checks if user choice was "exit".
    {
        printf("Are you sure want to exit? (y/n) ");
        scanf("%c", &buf);
        scanf("%c", &garb);                          //stores '\n' (enter key pressed by the user).
        if (buf == 'y' || buf == 'Y')
        {   printf("Would you like to back up your data? (y/n): ");
            scanf("%c",&buf);
            if(buf=='y' || buf=='Y')                 //if condition is true, it backs up data.
            {
                PutUserHash();                       //function to back up user data.
                WriteBlocksToFile();                 //function to back up blocks.
            }
            system("clear");
            printf("\n\e[0;92m                                                             THANK YOU!\n\n");
            return (0);
        }
        else
        {
            //scanf("%c", &buf);
            printf("\n\n");
            goto user_interface;                    //goes to label user_interface.
        }
    }
    else                   //if the user enters a choice which is invalid, this part gets executed.
    {
        printf("\n\033[31m                                             invalid choice! Please enter a valid choice\n\n");
        goto user_interface;                        //goes to label user_interface.
    } 
}