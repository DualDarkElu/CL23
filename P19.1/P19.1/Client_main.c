#include "Client.h"

struct date {
	int year;
	int month;
	int day;
};


// 지역 구조체 멤버 변수를 가지는 구조체 데이터 타입 정의
struct client_info1 { // 구조체 데이터 타입 이름 : struct client_info1
	int no;
	char name[MAX_LEN];
	double pamount;
	struct date birth; // struct date 구조체 멤버 변수 정의
};

void output_client(struct client_info1 client)
{
	// 문제 1 : 구조체 데이터 타입 struct client_info1을 전역 구조체 타입으로 정의하고 주석문을 삭제한 후
	//  함수 내부를 적절하게 작성하시오.
	printf("고객번호 : %d\n", client.no);
	printf("고객이름 : %s\n", client.name);
	printf("구매금액 : %.2f\n", client.pamount);
	printf("생년월일(YYYY/MM/DD): %d/%d/%d\n\n", client.birth.year, client.birth.month, client.birth.day);
}


struct client_info1 input_client() // 반환값의 타입 : struct client_info1
{
	// 문제 2 : 구조체 데이터 타입 struct client_info1을 전역 구조체 타입으로 정의하고 주석문을 삭제한 후
	//  함수 내부를 적절하게 작성하시오.
	struct client_info1 client;
	printf("고객번호 : ");
	scanf_s("%d", &client.no);
	printf("고객이름 : ");
	scanf_s("%s", client.name);
	printf("구매금액 : ");
	scanf_s("%lf", &client.pamount);
	printf("생년월일(YYYY MM DD) : ");
	scanf_s("%d %d %d", &client.birth.year, &client.birth.month, &client.birth.day);

	return client;
}

void main(void)
{

	// 1. 구조체 데이터 타입 정의와 구조체 변수 선언
	
	// 1.1 간단 구조체 데이터 타입 정의와 변수 선언

	struct client_info { // 구조체 데이터 타입 키워드 : struct, 구조체 데이터 타입 이름 : client_info
		int no; // 순번, int 타입 멤버 변수
		char name[MAX_LEN]; // 고객 이름, 문자 배열 멤버 변수
		double pamount; // 구매 금액, double 타입 멤버 변수
		int year; // 생년, int 타입 멤버 변수
		int month; // 생월, int 타입 멤버 변수
		int day; // 생일, int 타입 멤버 변수
	};
	// 질문 1. 구조체 데이터 타입은 무엇을 정의하는가?
	// 질문 2. struct client_info 지역 구조체 타입의 적용 범위는 어디인가?

	// 구조체 변수 선언과 활용
	struct client_info client; // 구조체 지역 변수 선언
	// 질문 3. 구조체 데이터 타입과 구조체 변수는 어떻게 다른가?

	// 구조체 멤버 변수 접근 : 구조체변수.멤버변수

	// 고객 정보 입력
	printf("\n단순 구조체에 의한 고객 정보 입력 :\n");
	printf("고객번호 :");
	scanf_s("%d", &client.no);
	printf("고객이름 :");
	scanf_s("%s", client.name, MAX_LEN);
	printf("구매금액 :");
	scanf_s("%lf", &client.pamount);
	printf("생년월일(YYYY MM DD) :");
	scanf_s("%d %d %d", &client.year, &client.month, &client.day);

	// 고객 정보 출력
	printf("\n단순 구조체에 의한 고객 정보 출력 :\n");
	printf("\n고객 정보 출력 :\n");
	printf("고객번호 : %d\n", client.no);
	printf("고객이름 : %s\n", client.name);
	printf("구매금액 : %.2f\n", client.pamount);
	printf("생년월일(YYYY/MM/DD): %d/%d/%d\n\n", client.year, client.month, client.day);
	// 질문 4. 구조체 멤버 변수는 어떻게 접근하는가?

	/*
	// 지역 구조체 데이터 타입 정의와 변수 선언을 하나의 명령문으로 가능
	struct client_info { 
		int no; // 멤버 변수
		char name[MAX_LEN];
		double pamount;
		int year;
		int month;
		int day;
	} client; // 구조체 변수 선언

	// 이름 없는 구조체 데이터 타입 정의 가능
	struct { 
		int no; // 멤버 변수
		char name[MAX_LEN];
		double pamount;
		int year;
		int month;
		int day;
	} client; // 구조체 변수 선언
	*/

	// 1.2 구조체 멤버 변수를 가지는 구조체 데이터 타입 정의와 변수 선언

	struct client_info1 client1; // 구조체 변수 선언

	// 구조체 멤버 변수 접근 : 구조체변수.구조체멤버변수.멤버변수
	printf("\n구조체 멤버 변수를 가지는 구조체에 의한 고객 정보 입력 :\n");
	printf("고객번호 :");
	scanf_s("%d", &client1.no);
	printf("고객이름 :");
	scanf_s("%s", client1.name, MAX_LEN);
	printf("구매금액 :");
	scanf_s("%lf", &client1.pamount);
	printf("생년월일(YYYY MM DD) :");
	scanf_s("%d %d %d", &client1.birth.year, &client1.birth.month, &client1.birth.day);
	// 질문 5. 구조체 멤버 변수의 멤버 변수는 어떻게 접근하는가?

	// 구조체 멤버 변수 접근 : 고객 정보 출력
	printf("\n구조체 멤버 변수를 가지는 구조체에 의한 고객 정보 출력 :\n");
	printf("고객번호 : %d\n", client1.no);
	printf("고객이름 : %s\n", client1.name);
	printf("구매금액 : %.2f\n", client1.pamount);
	printf("생년월일(YYYY/MM/DD): %d/%d/%d\n\n", client1.birth.year, client1.birth.month, client1.birth.day);
	

	// 2. 구조체와 함수 : 전역 구조체 타입 정의 이해
	
	// 질문 6. 하나의 구조체 데이터 타입을 같은 소스 파일의 2개 이상의 함수에서 사용하려면 구조체 데이터 타입을 어떻게 정의해야 하는가?
	
	// 문제 1 : 구조체 데이터 타입 struct client_info1을 이 파일에서 전역 구조체 타입으로 정의하고 주석문을 삭제한 후
	//  main() 함수 아래의 output_client() 함수를 적절하게 작성하시오.
	
	
	// 구조체 변수를 함수 인자로 전달 
	printf("\n같은 소스 파일 함수에 의한 고객 정보 출력 :\n");
	output_client(client1); 
	// 질문 7. 구조체 변수 함수 인자 전달과 배열 이름 함수 인자 전달이 어떻게 다른가?
	

	
	// 문제 2 : 구조체 데이터 타입 struct client_info1을 이 파일에서 전역 구조체 타입으로 정의하고 주석문을 삭제한 후
	//  main() 함수 아래의 input_client() 함수를 적절하게 작성하시오.

	
	struct client_info1 client2;
	printf("\n같은 소스 파일 함수에 의한 고객 정보 입력 :\n");
	client2 = input_client(); // 구조체 변수 반환 및 대입

	printf("\n같은 소스 파일 함수에 의한 고객 정보 출력 :\n");
	output_client(client2); // 구조체 변수 인자
	


	// 질문 8. 하나의 구조체 데이터 타입을 2개 이상의 소스 파일에서 사용하려면 구조체 데이터 타입을 어떻게 정의해야 하는가?
	
	// 문제 3 :  구조체 데이터 타입 struct client_info1을 Client.h 헤더 파일에 정의하고 주석문을 제거한 후
	// output_client() 함수를 Client_functions.c 소스 파일에 적절하게 작성하시오.
	
	/*
	// 구조체 변수를 함수 인자로 전달
	printf("\n헤더 파일에 정의된 구조체 타입을 사용하는 멀티 소스 파일 함수에 의한 고객 정보 출력 :\n");	
	output_client(client1);
	*/


	// 문제 4 :  구조체 데이터 타입 struct client_info1을 Client.h 헤더 파일에 정의하고 주석문을 제거한 후
	// input_client() 함수를 Client_functions.c 소스 파일에 적절하게 작성하시오.

	/*
	struct client_info1 client3;
	printf("\n헤더 파일에 정의된 구조체 타입을 사용하는 멀티 소스 파일 함수에 의한 고객 정보 입력 :\n");
	
	client3 = input_client1();

	printf("\n헤더 파일에 정의된 구조체 타입을 사용하는 멀티 소스 파일 함수에 의한 고객 정보 출력 :\n");	
	output_client1(client3);
	*/
}




