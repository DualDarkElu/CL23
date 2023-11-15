#include "Client.h"

int main(void)
{
	// 1. 구조체 멤버 정렬 : 8 바이트 구조체 정렬(Visual Studio)
	
	// 8 바이트 구조체 정렬 : CPU가 8바이트 단위로 메모리를 접근하기 용이하도록 컴파일러가  
	// 구조체 변수에 8의 배수 주소에서 시작하도록 메모리를 할당하고 8의 배수로 구조체 메모리 할당
	// Visual Studio는 8 바이트 구조체 정렬
	
	// 구조체의 멤버 변수 정렬 : char 타입은 1 바이트 정렬, int 타입은 4 바이트 정렬, double 타입은 8 바이트 정렬
	// n 바이트 멤버 정렬 : n의 배수 주소에서 시작 n  바이트 할당
	// n 바이트 멤버 정렬 이유 : 기본 데이터 타입 멤버 변수 전체를 한번의 CPU 구조체 메모리 읽기에 포함시킴으로써
	// 메모리 읽기 횟수를 줄여 처리 속도 향상
	
	struct test_type {
			char c[6]; 
			int i; 
			double d;
	} test_var;
	
	printf("\ntest_var 구조체 크기 : %d\n", sizeof(test_var));
	printf("\ntest_var 구조체 메모리 주소 : %p\n", &test_var);

	// 질문 1. test_var 구조체 변수에 할당된 메모리의 크기가 8의 배수인가?
	// 질문 2. 십진수로 출력한 test_var 구조체 변수의 시작 주소는 8의 배수인가?

	// 위의 구조체 변수 test_var에서 배열 c[6]에 0~5, 변수 i에 6~9, 변수 d에 10~17바이트를 할당하면 
	// 6~9 바이트에 저장된 i 변수는 8바이트 단위로 메모리를 접근하는 CPU에 의해 0~7, 8~15 바이트의 2번 메모리 읽기 필요, 
	// 10~17 바이트에 저장된 d 변수도 8~15, 16~25 바이트의 2번 메모리 읽기 필요.
	// int 변수 i를 4 바이트 정렬하면 8~11바이트에 저장하므로 CPU가 8~15바이트 1번의 메모리 읽기로 i 멤버 변수 처리 가능
	// double 변수 d를 8바이트 정렬하면 16~23 바이트에 저장하므로 CPU가 16~23바이트 1번의 메모리 읽기로 d 멤버 변수 처리 가능
	// 따라서 구조체 변수 test_var의 크기는 24 바이트가 된다.
	

	struct client_info client1;
	// 질문 3. client1 변수의 크기는 얼마인가?

	struct client_info_test client_test;
	// 질문 3. client_test 변수의 크기는 얼마인가? 4

	struct client_info_test1 client_test1;
	// 질문 4. client_test1 변수의 크기는 얼마인가? 56


	// 2. 구조체 포인터 변수와 멤버 변수 접근 연산자 ->

	struct client_info client2;

	// 구조체 포인터 변수의 멤머 변수 접근 연산자 : ->
	// Client.h 파일에 정의된 struct client_info 구조체 타입 변수 client2의 주소를 인자로 초기화하는 함수 input_client_pointer1() 작성
	printf("\n고객 정보 입력:\n");
	 input_client_pointer1(&client2);

	 // 구조체 변수 client2의 멤버 변수 출력
	 printf("\n고객 정보 출력:\n");
	output_client(client2);

	// 질문 5. 다음과 같이 input_client_pointer1() 함수를 호출하면 어떻게 될까?
	/*
	struct client_info* clientp = NULL;
	input_client_pointer1(clientp);
	*/

	// 문제 1 : Client.h에 정의된 struct client_info1 구조체 타입으로 정의된 client3 변수에 고객 정보를 입력하는 
	// input_client_pointer2() 함수를 Client_functions.c 소스 파일에 작성하시오.

	struct client_info1 client3;
	
	// 이 위치에 적절한 코드를 추가하라.

	// input_client_pointer2() 함수를 Client_functions.c 소스 파일에 작성하라.
	input_client_pointer2(&client3);

	// 문제 2 : Client.h에 정의된 struct client_info1 구조체 타입으로 정의된 client3 변수의 고객 정보를 출력하는 
	// output_client2() 함수를 Client_functions.c 소스 파일에 작성하시오.
	output_client2(client3);

	// 3. 구조체 배열과 구조체 포인터 변수

	struct client_info clients[MAX_NUM] = { 0 };
	int num;

	printf("고객 수 : ");
	scanf_s("%d", &num);

	// 문제 3. Client_functions.c 소스 파일에 구조체 배열 매개 변수로 작성된 input_client_all() 함수를 구조체 포인터 매개 변수로 변경하고
	// 구조체 포인터 변수를 사용하여 수정하시오.
	input_client_all(clients, num); 
	printf("\n\n고객 명단 : \n");

	// 문제 4. Client_functions.c 소스 파일에 구조체 배열 매개 변수로 작성된 output_client_all() 함수를 구조체 포인터 매개 변수로 변경하고
	// 구조체 포인터 변수를 사용하여 수정하시오.
	output_client_all(clients, num);

}