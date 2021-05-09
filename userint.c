#include "block.c"
#include "transaction.c"
#include "user.c"
#include "attack_1.c"

int main()
{
    char buf;
    int choice, j;
    system("clear");
    srand(time(NULL));
    initHash();
    printf("\n\e[0;92m                                                                BITCOIN\n");
    printf("                                                               ---------\n");
    printf("                                                      Project by group number 14\n\n");
user_interface:
    printf("\033[0mPlease enter a number to continue!\n\n");
    printf("\033[31menter 1 to create a add user to the system\n");
    printf("enter 2 to load users\n");
    printf("enter 3 to do a transaction\n");
    printf("enter 4 to display transcation history\n");
    printf("enter 5 to attack a block\n");
    printf("enter 6 to validate block chain\n");
    printf("enter 7 to clear screen\n");
    printf("enter 8 to exit");
    printf("\033[0m\n\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        makeUser();
        printf("\n\n");
        goto user_interface;
    }

    else if (choice == 2)
    {
        printUsers();
        printf("\n\n");
        goto user_interface;
    }

    else if (choice == 3)
    {
        transaction();
        printf("\n\n");
        goto user_interface;
    }
    else if (choice == 4)
    {
        printHistory();
        printf("\n\n");
        goto user_interface;
    }
    else if (choice == 5)
    {
        attack();
        printf("\n\n");
        goto user_interface;
    }
    else if (choice == 6)
    {
        //validate_block_chain();
        goto user_interface;
    }
    else if (choice == 7)
    {
        system("clear");
        goto user_interface;
    }
    else if (choice == 8)
    {
        system("clear");
        printf("\n\e[0;92m                                                             THANK YOU!\n\n");
        return (0);
    }
    else
    {
        printf("\n\033[31m                                             invalid choice! Please enter a valid choice\n\n");
        goto user_interface;
    }
}