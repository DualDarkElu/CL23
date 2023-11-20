#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct client_info_list* input_client();
void output_client(struct client_info_list* client);
void add_client(struct client_info_list** headp);
void delete_client(struct client_info_list** headp, char* name);

#define MAX_LEN 20

struct date {
	int year;
	int month;
	int day;
};

struct client_info {
	int no;
	char name[MAX_LEN];
	double pamount;
	struct date *birth;
};

struct client_info_list {
	int no;
	char name[MAX_LEN];
	double pamount;
	struct date* birth;
	struct client_info_list* next; // 자기 참조(self-reference) 포인터
};
