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
	struct client_info_list* next; // 자기 참조(self-reference) 포인터
};

typedef struct client_info_list CLIENT; // 구조체 데이터 타입 struct client_info_list의 이름을 CLIENT로 재정의
typedef struct date DATE; // 구조체 데이터 타입 struct date의 이름을 DATE로 재정의

typedef struct Byte_type
{
	unsigned char first3 : 3; // 최하위 비트
	unsigned char second2 : 2;
	unsigned char third2 : 2;
	unsigned char forth1 : 1; // 최상위 비트
} BYTE3221; // 구조체 데이터 타입  struct Byte_type의 이름을 BYTE3221로 재정의

#define SQUARE(x) (x * x)

#define SET_BIT_ON(w, k) ((w) |= (0x0001 << (k))) // // k-번째 상위 비트를 1로 설정
#define SET_BIT_OFF(w, k) ((w) &= ~(0x0001 << (k))) // k-번째 상위 비트를 0으로 설정