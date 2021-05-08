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
#define size 9000

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

struct transact
{
    long to;
    long from;
    double amt;
    transact *next;
};

struct user
{
    long ID;
    double balance;
    transact *history;
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
void updateHistory(long int from_ID, long int to_ID, double amount, struct transact **head_ref);
void update_trav(long int from_ID, long int to_ID, double amount);
void printUsers();

#endif
