#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct date {
	int year;
	int month;
	int day;
};

struct client_info_list {
	int no;
	char name[20];
	double pamount;
	struct date* birth;
	struct client_info_list* next; // �ڱ� ����(self-reference) ������
};

typedef struct client_info_list CLIENT; // ����ü ������ Ÿ�� struct client_info_list�� �̸��� CLIENT�� ������
typedef struct date DATE; // ����ü ������ Ÿ�� struct date�� �̸��� DATE�� ������

typedef struct Byte_type
{
	unsigned char first3 : 3; // ������ ��Ʈ
	unsigned char second2 : 2;
	unsigned char third2 : 2;
	unsigned char forth1 : 1; // �ֻ��� ��Ʈ
} BYTE3221; // ����ü ������ Ÿ��  struct Byte_type�� �̸��� BYTE3221�� ������

#define SQUARE(x) (x * x)

#define SET_BIT_ON(w, k) ((w) |= (0x0001 << (k))) // // k-��° ���� ��Ʈ�� 1�� ����
#define SET_BIT_OFF(w, k) ((w) &= ~(0x0001 << (k))) // k-��° ���� ��Ʈ�� 0���� ����