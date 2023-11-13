#include <stdio.h>
#define MAX_LEN 20

struct date {
    int year;
    int month;
    int day;
};

struct client_info1 {
    int no;
    char name[MAX_LEN];
    double pamount;
    struct date birth;
};

void output_client1(struct client_info1 client);

struct client_info1 input_client1();