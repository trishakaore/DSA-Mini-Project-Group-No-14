#include "block.c"
#include "transaction.c"
#include "user.c"
#include "attack_1.c"
#include "hash.c"
#include <ctype.h>



int main()
{
    char buf,garb;
    int i;
    char choice[100] = {'\0'};
    system("clear");
    srand(time(NULL));

    printf("\n\e[0;92m                                                                BITCOIN\n");
    printf("                                                               ---------\n");
    printf("                                                      Project by group number 14\n\n");
    
    GetBackupVsFresh();


    scanf("%c", &buf);
user_interface:
    printf("\033[0mPlease enter your choice to continue!\n\n");
    printf("\033[31mEnter \e[0;92m\"add user\"\033[31m to create a add user to the system\n");
    printf("Enter \e[0;92m\"load users\"\033[31m to load users\n");
    printf("Enter \e[0;92m\"transaction\"\033[31m to do a transaction\n");
    printf("Enter \e[0;92m\"transaction history\"\033[31m to display transcation history\n");
    printf("Enter \e[0;92m\"block chain\"\033[31m to print the block chain\n");
    printf("Enter \e[0;92m\"attack\"\033[31m to attack a block\n");
    printf("Enter \e[0;92m\"validate\"\033[31m to validate block chain\n");
    printf("Enter \e[0;92m\"clear\"\033[31m to clear screen\n");
    printf("Enter \e[0;92m\"exit\"\033[31m to exit");
    printf("\033[0m\n\n");
    scanf("%[^\n]", choice);
    printf("\n");
    scanf("%c", &buf);

    for (i = 0; i < 100, choice[i] != '\0';)
    {
        
        if (choice[i] >= 'A' && choice[i] <= 'Z')
            choice[i] = tolower(choice[i]);
        i++;
    }
    if (strcmp(choice, "add user") == 0)
    {
        makeUser();
        scanf("%c", &buf);
        printf("\n\n");
        goto user_interface;
    }

    else if (strcmp(choice, "load users") == 0)
    {
        printf("\n");
        printUsers();
        printf("\n\n");
        goto user_interface;
    }

    else if (strcmp(choice, "transaction") == 0)
    {
        transaction();
        scanf("%c", &buf);
        printf("\n\n");
        goto user_interface;
    }
    else if (strcmp(choice, "transaction history") == 0)
    {
        printHistory();
        scanf("%c", &buf);
        printf("\n\n");
        goto user_interface;
    }
    else if (strcmp(choice, "block chain") == 0)
    {
        printBlockchain();
        printf("\n\n");
        goto user_interface;
    }
    else if (strcmp(choice, "attack") == 0)
    {
        attack();
        printf("\n\n");
        goto user_interface;
    }
    else if (strcmp(choice, "validate") == 0)
    {
        validate_block_chain();
        printf("\n\n");
        goto user_interface;
    }
    else if (strcmp(choice, "clear") == 0)
    {
        system("clear");
        goto user_interface;
    }
    else if (strcmp(choice, "exit") == 0)
    {
        printf("Are you sure want to exit? (y/n) ");
        scanf("%c", &buf);
        scanf("%c", &garb);
        if (buf == 'y' || buf == 'Y')
        {   printf("Would you like to back up your data? (y/n): ");
            scanf("%c",&buf);
            if(buf=='y' || buf=='Y'){
                PutUserHash();
                WriteBlocksToFile();
            }
            system("clear");
            printf("\n\e[0;92m                                                             THANK YOU!\n\n");
            return (0);
        }
        else
        {
            //scanf("%c", &buf);
            printf("\n\n");
            goto user_interface;
        }
    }
    else
    {
        printf("\n\033[31m                                             invalid choice! Please enter a valid choice\n\n");
        goto user_interface;
    }
}