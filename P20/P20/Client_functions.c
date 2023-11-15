#include "Client.h"

// 구조체 포인터 매개변수를 사용하는 input_client_pointer1() 함수 작성
void input_client_pointer1(struct client_info* client1) // 구조체 포인터 매개 변수 선언
{
	// 구조체 포인터 변수의 멤버 변수 접근 : -> 연산자 사용
	printf("고객번호 :");
	scanf_s("%d", &client1->no);
	printf("고객이름 :");
	scanf_s("%s", client1->name, MAX_LEN);
	printf("구매금액 :");
	scanf_s("%lf", &client1->pamount);
	printf("생년월일(YYYY MM DD) :");
	scanf_s("%d %d %d", &(client1->birth.year), &(client1->birth.month), &(client1->birth.day));
}


void output_client(struct client_info client)
{
	printf("고객번호 : %d\n", client.no);
	printf("고객이름 : %s\n", client.name);
	printf("구매금액 : %.2f\n", client.pamount);
	printf("생년월일(YYYY/MM/DD): %d/%d/%d\n\n", client.birth.year, client.birth.month, client.birth.day);
}


// 문제 1 : Client.h에 정의된 struct client_info1 구조체 타입으로 정의된 client3 변수에 고객 정보를 입력하는 
// input_client_pointer2() 함수를 Client_functions.c 소스 파일에 작성하시오.
void input_client_pointer2(struct client_info1* client1)
{
	// 이 위치에 적절한 코드를 채우시오.
	printf("고객번호 :");
	scanf_s("%d", &client1->no);
	printf("고객이름 :");
	scanf_s("%s", client1->name, MAX_LEN);
	printf("구매금액 :");
	scanf_s("%lf", &client1->pamount);
	printf("생년월일(YYYY MM DD) :");
	scanf_s("%d %d %d", &(client1->birth->year), &(client1->birth->month), &(client1->birth->day));
}


// 문제 2 : Client.h에 정의된 struct client_info1 구조체 타입으로 정의된 client3 변수의 고객 정보를 출력하는 
// output_client2() 함수를 Client_functions.c 소스 파일에 작성하시오.
void output_client2(struct client_info1 client)
{
	// 이 위치에 적절한 코드를 채우시오.
	printf("고객번호 : %d\n", client.no);
	printf("고객이름 : %s\n", client.name);
	printf("구매금액 : %.2f\n", client.pamount);
	printf("생년월일(YYYY/MM/DD): %d/%d/%d\n\n", client.birth->year, client.birth->month, client.birth->day);
}

// 문제 3. Client_functions.c 소스 파일에 구조체 배열 매개 변수로 작성된 input_client_all() 함수를 구조체 포인터 매개 변수로 변경하고
// 구조체 포인터 변수를 사용하여 수정하시오.
void input_client_all(struct client_info client[], int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("고객번호 :");
		scanf_s("%d", &client[i].no);
		printf("고객이름 :");
		scanf_s("%s", client[i].name, MAX_LEN);
		printf("구매금액 :");
		scanf_s("%lf", &client[i].pamount);
		printf("생년월일(YYYY MM DD) :");
		scanf_s("%d %d %d", &client[i].birth.year, &client[i].birth.month, &client[i].birth.day);
	}
}


// 문제 4. Client_functions.c 소스 파일에 구조체 배열 매개 변수로 작성된 output_client_all() 함수를 구조체 포인터 매개 변수로 변경하고
// 구조체 포인터 변수를 사용하여 수정하시오.
void output_client_all(struct client_info client[], int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("고객번호 : %d\n", client[i].no);
		printf("고객이름 : %s\n", client[i].name);
		printf("구매금액 : %.2f\n", client[i].pamount);
		printf("생년월일(YYYY/MM/DD): %d/%d/%d\n\n", client[i].birth.year, client[i].birth.month, client[i].birth.day);
	}
}

