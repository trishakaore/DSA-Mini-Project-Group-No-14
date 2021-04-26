typedef struct user user;
typedef struct date date;
typedef struct transact transact;
typedef struct time time;

struct user{
    long ID;
    double balance;
    transact* history;
    date join;
    time tim;
};

struct date{
    int dd;
    int mm;
    int yy;
};

struct time{
    int hrs;
    int min;
};

struct transact{
    long to;
    long from;
    double amt;
    transact* next;
};

user makeUser(double bal);
    long makeID();
    void setDate(user);
    void setTime(user);

void transaction(user, user, double);




