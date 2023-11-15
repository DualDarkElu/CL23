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

struct client_info { // 8 ����Ʈ ����, 8�� ����� �޸� �Ҵ� : 
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


struct client_info_test { // 8 ����Ʈ ����ü ����, 8�� ����� �޸� �Ҵ� 
	int no; // 4 ����Ʈ int ����, 4
	char tel_no[13]; // 1����Ʈ char ����, 13
	char name[20]; // 1����Ʈ char ����, 20
	int zip_code; // 4����Ʈ int ����, 4��� 40���� �޸� �Ҵ�
	double pamount; // 8����Ʈ double ����, 8�� ��� �ּ� 48���� ����
};

struct client_info_test1 { // 8 ����Ʈ ����, 8�� ����� �޸� �Ҵ� :  
	int no; // 4 ����Ʈ ����, 4
	char tel_no[13]; // 1����Ʈ ����, 13
	char name[20]; // 1����Ʈ ����, 20
	int zip_code; // 4����Ʈ ����, 4��� 40���� �޸� �Ҵ�(40~43)
	double pamount; // 8����Ʈ , 8�� ��� �ּ� 48���� ����(48~55)
	struct date birth; // 4����Ʈ ����(56~67)
};

