#include <stdio.h>
#include <string.h>

#define MAX_LEN 20
#define MAX_NUM 100
void output_client(struct client_info client);
void input_client_pointer(struct client_info* client1);
void input_client_pointer1(struct client_info* client1);
void input_client_pointer2(struct client_info1* client1);
void output_client2(struct client_info1 client);
void input_client_all(struct client_info* client, int num);
void output_client_all(struct client_info client[], int num);
void delete_client(struct client_info* client, int num, char* name);

struct date {
	int year;
	int month;
	int day;
};

struct client_info { // 8 바이트 정렬, 8의 배수로 메모리 할당 : 
	int no; // 4
	char name[20]; // 20
	double pamount; // 8
	struct date birth; // 12
};

struct client_info1 {
	int no;
	char name[MAX_LEN];
	double pamount;
	struct date* birth;
};


struct client_info_test { // 8 바이트 구조체 정렬, 8의 배수로 메모리 할당 
	int no; // 4 바이트 int 정렬, 4
	char tel_no[13]; // 1바이트 char 정렬, 13
	char name[20]; // 1바이트 char 정렬, 20
	int zip_code; // 4바이트 int 정렬, 4배수 40부터 메모리 할당
	double pamount; // 8바이트 double 정렬, 8의 배수 주소 48에서 시작
};

struct client_info_test1 { // 8 바이트 정렬, 8의 배수로 메모리 할당 :  
	int no; // 4 바이트 정렬, 4
	char tel_no[13]; // 1바이트 정렬, 13
	char name[20]; // 1바이트 정렬, 20
	int zip_code; // 4바이트 정렬, 4배수 40부터 메모리 할당(40~43)
	double pamount; // 8바이트 , 8의 배수 주소 48에서 시작(48~55)
	struct date birth; // 4바이트 정렬(56~67)
};

