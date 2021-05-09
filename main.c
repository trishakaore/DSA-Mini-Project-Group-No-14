#include "block.c"
#include "transaction.c"
#include "user.c"
#include "attack_1.c"
//#include "validate.c"
#include "hash.c"
#include <ctype.h>

/*void GetBackupVsFresh()
{

    printf("Do you want to restore data from backup files? (y/n): ");
    char k;
    scanf("%c", &k);

    if (k == 'y')
    {
        GetUserHash();
        GetBlocksFromFile();
    }
    else
    {
        initHash();
        Init_block_chain();
    }
}*/

int main()
{
    char buf;
    //char hash[13]; //test
    int i;
    char choice[100] = {'\0'};
    system("clear");
    srand(time(NULL));
    //initHash();
    //Init_block_chain();
    printf("\n\e[0;92m                                                                BITCOIN\n");
    printf("                                                               ---------\n");
    printf("                                                      Project by group number 14\n\n");
    GetBackupVsFresh();
    scanf("%c", &buf);
user_interface:
    printf("\033[0mPlease enter your choice to continue!\n\n");
    printf("\033[31mEnter \"add user\" to create a add user to the system\n");
    printf("Enter \"load users\" to load users\n");
    printf("Enter \"transaction\" to do a transaction\n");
    printf("Enter \"transaction history\" to display transcation history\n");
    printf("Enter \"block chain\" to print the block chain\n");
    printf("Enter \"attack\" to attack a block\n");
    printf("Enter \"validate\" to validate block chain\n");
    printf("Enter \"clear\" to clear screen\n");
    printf("Enter \"exit\" to exit");
    printf("\033[0m\n\n");
    scanf("%[^\n]", choice);
    scanf("%c", &buf);

    for (i = 0; i < 100, choice[i] != '\0';)
    {
        /*if (choice[i] == '\n')
        {
            choice[i] = '\0';
        }
        else*/
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
        //scanf("%c", &buf);
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
        //scanf("%c", &buf);
        printf("\n\n");
        goto user_interface;
    }
    else if (strcmp(choice, "validate") == 0)
    {
        validate_block_chain();
        //scanf("%c", &buf);
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
        if (buf == 'y' || buf == 'Y')
        {
            system("clear");
            PutUserHash();
            WriteBlocksToFile();
            printf("\n\e[0;92m                                                             THANK YOU!\n\n");
            return (0);
        }
        else
        {
            scanf("%c", &buf);
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