#ifndef MINIPROJ_USER_H
#define MINIPROJ_USER_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct user user;
typedef struct datee datee;
typedef struct transact transact;
typedef struct timee timee;

#define size 9000  //max number of users
#define histsize 100  //max number of transactions per user

struct datee
{
    int dd;
    int mm;
    int yy;
};

struct timee
{
    int hrs;
    int min;
};

//datee and timee store user creation date and time

struct transact 
{
    long to;
    long from;
    double amt;
};

struct user
{
    long ID;
    double balance;
    int transNum;                   //stores number of transactions done by user
    transact history[histsize];     //stores user transaction history
    datee join;
    timee tim;
};

user userHash[size];                

void initHash();                    

void makeUser();
long makeID();
void setDate(long);
void setTime(long);

void transaction();
void printHistory();
void updateHistory(long int from_ID, long int to_ID, double amount);
void update_trav(long int from_ID, long int to_ID, double amount);
void printUsers();

void GetUserHash();
void PutUserHash();

#endif
