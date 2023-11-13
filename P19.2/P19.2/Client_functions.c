#include "Client.h"
#include <stdio.h>

void output_client1(struct client_info1 client)
{
	// 문제 3 :  구조체 데이터 타입 struct client_info1을 Client.h 헤더 파일에 정의하고 주석문을 제거한 후
	// output_client() 함수의 내용을 적절하게 작성하시오.
	printf("고객번호: %d\n", client.no);
	printf("고객이름: %s\n", client.name);
	printf("구매금액: %.2f\n", client.pamount);
	printf("생년월일(YYYY/MM/DD): %d/%d/%d\n", client.birth.year, client.birth.month, client.birth.day);
}

struct client_info1 input_client1()
{
	// 문제 4 :  구조체 데이터 타입 struct client_info1을 Client.h 헤더 파일에 정의하고 주석문을 제거한 후
	// input_client() 함수의 내용을 적절하게 작성하시오.
	struct client_info1 client;
	printf("고객번호 :");
	scanf_s("%d", &client.no);
	printf("고객이름 :");
	scanf_s("%s", client.name); 
	printf("구매금액 :");
	scanf_s("%lf", &client.pamount);
	printf("생년월일(YYYY MM DD) :");
	scanf_s("%d %d %d", &client.birth.year, &client.birth.month, &client.birth.day);

	return client;
}


