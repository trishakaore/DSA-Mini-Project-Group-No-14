#include "user.h"

void initHash()
{
    for (int i = 0; i < size; i++){
        userHash[i].ID = -1; 
        //initializing IDs to -1 allows for detection of nonexistent users           
    }
}

long makeID()
{
    //srand(time(NULL));  //preferably, this must be seeded in main.c instead of inside this function
    //assume close to 8,000 maximum potential users ==> 4-digit unique ID suffices
    //use rand to generate the number
    int whatever;
    long ID = rand();

    //loop to generate a 4 digit random number
    while (ID < 1000 || ID > 9999)
    {
        if (ID > 9999)
        {
            ID = ID % 10000;
        }

        else
        {
            whatever = rand() % 10;
            if (whatever == 0)
            {
                whatever += 1;
            }
            ID += (whatever * 1000);
        }
    }

    if (userHash[ID - 1000].ID == -1)       //if ID is available 
    {                                       //ID is stored at position ID-1000 in the array
        userHash[ID - 1000].ID = ID;        //so ID = 1500 will be stored at index 500
        return ID;
    }
    else                                   //if ID is taken, call makeID() recursively
    {
        makeID();
    }
}

//get and set date of user initiation
void setDate(long id)       
{
    int day, month, year;

    // `time_t` is an arithmetic time type
    time_t now;

    // Obtain current time
    // `time()` returns the current time of the system as a `time_t` value
    time(&now);

    // Convert to local time format and print to stdout

    // localtime converts a `time_t` value to calendar time and
    // returns a pointer to a `tm` structure with its members
    // filled with the corresponding values
    struct tm *local = localtime(&now);

    day = local->tm_mday;         // get day of month (1 to 31)
    month = local->tm_mon + 1;    // get month of year (0 to 11)
    year = local->tm_year + 1900; // get year since 1900

    (userHash[id - 1000]).join.dd = day;
    (userHash[id - 1000]).join.mm = month;
    (userHash[id - 1000]).join.yy = year;
}

//get and set time of user initiation
void setTime(long id)
{
    int hours, minutes, seconds, day, month, year;

    // `time_t` is an arithmetic time type
    time_t now;

    // Obtain current time
    // `time()` returns the current time of the system as a `time_t` value
    time(&now);

    // localtime converts a `time_t` value to calendar time and
    // returns a pointer to a `tm` structure with its members
    // filled with the corresponding values
    struct tm *local = localtime(&now);

    hours = local->tm_hour;  // get hours since midnight (0-23)
    minutes = local->tm_min; // get minutes passed after the hour (0-59)
    seconds = local->tm_sec; // get seconds passed after a minute (0-59)

    (userHash[id - 1000]).tim.hrs = hours;
    (userHash[id - 1000]).tim.min = minutes;
}

//put ID, date, time together to make an object of struct user and place it in userHash
void makeUser()
{
    long id = makeID();
    setDate(id);
    setTime(id);

    printf("Enter initial balance: ");
    scanf("%lf", &(userHash[id - 1000].balance)); 

    userHash[id-1000].transNum=0;

    for(int i=0;i<histsize;i++){        //initialize objects of transaction history array
        userHash[id-1000].history[i].amt = -1;
        userHash[id-1000].history[i].from = -1;
        userHash[id-1000].history[i].to = -1;
    }
    
    //print details of user just created
    printf("ID: %ld\n", id);
    printf("Balance: %.2lf\n", userHash[id - 1000].balance);
    printf("Date : %02d/%02d/%02d\n", userHash[id - 1000].join.dd, userHash[id - 1000].join.mm, userHash[id - 1000].join.yy);
    printf("Time : %02d:%02d\n", userHash[id - 1000].tim.hrs, userHash[id - 1000].tim.min);
}

void printUsers()
{
    int flag = 0;//to detect presence of users
    for (int i = 0; i < size - 1; i++)
    {
        if (userHash[i].ID != -1) //ID exists
        {
            printf("ID: %ld\n", userHash[i].ID);
            printf("Balance: %.2lf\n", userHash[i].balance);
            printf("Date : %02d/%02d/%02d\n", userHash[i].join.dd, userHash[i].join.mm, userHash[i].join.yy);
            printf("Time : %02d:%02d\n\n", userHash[i].tim.hrs, userHash[i].tim.min);
            if (flag == 0)
            {
                flag++;
            }
        }
    }
    if (flag == 0)
    {
        printf("No users present\n");
    }
}

void GetUserHash()// Make userHash from the data stored in user.txt
{
    initHash();     //initialize array IDs with -1
    FILE *f;
    user tmp;
    f = fopen("user.txt", "r");
    while (fread(&tmp, sizeof(user), 1, f))     //while !EOF, tmp reads each user into itself
        userHash[tmp.ID - 1000] = tmp;
    //printf("Read All into userHash\n");
    fclose(f);
}

void PutUserHash()//put data from userHash into user.txt for backup
{
    FILE *f;
    user tmp;
    f = fopen("user.txt", "w");

    for (int i = 0; i < size; i++)
    {
        tmp = userHash[i];
        if (tmp.ID != -1)       //if user with that ID exists
        {
            fwrite(&tmp, sizeof(user), 1, f);   //write user to file
        }
    }

    //printf("Put all into user.txt\n");
    fclose(f);
}
