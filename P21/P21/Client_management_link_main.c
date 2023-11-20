#include "Client_link.h"

// 구조체 포인터와 동적 메모리 할당, 구조체 연결 리스트, 연결 리스트와 이중 포인터

int main(void)
{
	// 1) 구조체 포인터에 동적 메모리 할당
	
	// 구조체 포인터에 malloc() 함수를 사용하여 구조체 크기만큼(sizeof(struct client_info)) 메모리 할당

	// 구조체 포인터 변수 선언
	struct client_info* clientp = NULL;

	// 구조체 포인터에 구조체 크기의 메모리 할당, 메모리의 구조체 타입 지정(포인터 연산에 필요)
	clientp = (struct client_info*)malloc(sizeof(struct client_info)); 

	// 메모리 할당된 구조체 포인터의 멤버 변수에 값 대입
	clientp->no = 1;
	strcpy_s(clientp->name, MAX_LEN, "Steve");
	clientp->pamount = 10000;

	// 멤버 구조체 포인터에 메모리 할당
	clientp->birth = (struct date*)malloc(sizeof(struct date));

	// 메모리 할당된 멤버 구조체 포인터의 멤버 변수에 값 대입
	clientp->birth->year = 2000;
	clientp->birth->month = 12;
	clientp->birth->day = 31;

	// 구조체 포인터 멤버 변수의 값 출력
	printf("고객번호 : %d\n", clientp->no);
	printf("고객이름 : %s\n", clientp->name);
	printf("구매금액 : %.2f\n", clientp->pamount);
	printf("생년월일(YYYY/MM/DD): %d/%d/%d\n\n", clientp->birth->year, clientp->birth->month, clientp->birth->day);
	
	// 포인터에 할당된 메모리 해제, 사용후 반드시 해제
	free(clientp); 

	// 질문 1 : 이 위치에서 clientp->no = 1; 명령문을 실행하면 어떻게 될까?
	
	// 질문 2 : 동적 메모리 할당의 장점은 무엇인가?

	// 질문 3 : 동적 메모리는 왜 변수 대신 포인터 변수에 할당하는가?

	// 질문 4 : 무한 loop 명령문에서 malloc() 함수를 사용하고 free() 함수를 사용하지 않으면 어떤 문제가 발생하는가?


	// 2) 자기 참조(self-reference) 구조체 포인터 : 구조체 멤버 변수에 구조체 자신의 포인터가 포함된 구조체
	// 예 : struct client_info_list
	
	// struct client_info_list {
	//		int no;
	//		char name[MAX_LEN];
	//		double pamount;
	//		struct date* birth;
	//		struct client_info_list* next; // 자기 참조(self-reference) 포인터
	// };



	// 3) 구조체 연결 리스트(Linked-List of Structures) 
	
	// 다수의 구조체 메모리가 자기 참조 포인터에 의해 연결된 구조체 연결 --> 필요할 때만 구조체 메모리 할당 및 연결
	
	// 고객 구조체 연결 리스트 생성

	// 첫번째 고객 구조체에 대한 포인터 변수 선언 : 헤드 포인터
	struct client_info_list* client_head = NULL; 
	
	int num;
	printf("고객 수 : ");
	scanf_s("%d", &num);

	// 고객 정보를 입력하는 구조체를 구객수만큼 연결하는 구조체 연결 리스트를 만들고 첫번째 구조체의 포인터를 반환하는 함수
	// input_client()를 Client_link_functions.c 파일에 작성

	printf("\n\n고객 수만큼 고객 정보 입력 : \n\n");
	client_head = input_client(num); // 구조체 연결 리스트의 헤드(1번째 구조체에 대한 포인터) 반환
	

	// 고객 구조체 연결 리스트의 각 고객 정보를 출력하는 output_client()함수를 Client_link_functions.c 파일에 작성
	printf("\n\n고객 명단 출력: \n");
	output_client(client_head);


	// 4) 구조체 연결 리스트와 이중(2차원) 포인터 
	// 포인터(주소)에 대한 포인터 : 함수에서 호출자의 포인터가 가르키는 구조체 대상을 변경하고자 할 때
	

	// client_head의 구조체 연결 리스트의 끝에 고객 구조체를 생성하여 추가하는 함수 : add_client()
	// 질문 8 : client_head = NULL인 상태에서 다음과 같이 호출하면 어떤 문제가 발생하는가?

	// 고객 정보 추가
	printf("\n\n비정상 시작 고객 1명 정보 추가 : \n");
	client_head = NULL;
	add_client1(client_head);	
	
	// 질문 9 : 아래 출력값은 얼마인가? 이 문제를 해결하려면 어떻게 해야 하는가?
	printf("\n\n고객 명단 시작 주소(client_head): %p\n", client_head);

	printf("\n\n비정상 시작 고객 입력 후 고객 명단 출력 : \n");
	output_client(client_head);


	// 이중 포인터를 사용하여 구조체 연결 리스트의 끝에 고객 구조체를 생성하여 추가

	printf("\n\n정상 시작 고객 1명 정보 추가 : \n");
	add_client2(&client_head); // 헤드 변경 경우를 고려하여 헤드에 대한 주소(포인터) 인자 전달

	printf("\n\n정상 시작 고객 입력 후 고객 명단 출력 : \n");
	output_client(client_head);

	printf("\n\n정상 고객 3명 정보 추가 : \n");
	for (int i = 0; i < 3; i++) 
		add_client2(&client_head);

	printf("\n\n정상 고객 3명 입력 후고객 명단 출력: \n");
	output_client(client_head);

	
	char name[MAX_LEN];

	printf("\n\n삭제 고객이름 입력(1번째 이외 고객) : ");
	scanf_s("%s", name, MAX_LEN);
	
	// 문제 : client_head 포인터 정보와 삭제 고객 이름 정보를 인자로 넘겨받아 이름에 대응되는 고객 구조체를 
	// 삭제하는 함수  delete_client()를 작성하시오.

	delete_client(&client_head, name); 

	// 평가 1(3점) : 제출
	// 평가 2(3점) : 현재 4명의 고객 정보가 연결된 연결 리스트에서 1번째가 아닌 고객 이름(name)에 대응되는
	// 구조체 정보를 연결 리스트에서 삭제하고 고객 명단을 확인하여 해당 고객 정보가 삭제되었는지 확인하시오.
	
	printf("\n\n1번째 이외의 고객 정보 삭제 후 고객 명단 출력 : \n");
	output_client(client_head);

	printf("\n\n삭제 고객이름 입력(1번째 고객) : ");
	scanf_s("%s", name, MAX_LEN);
	delete_client(&client_head, name);

	//평가 3(4점) : 1명 삭제 후 현재 3명의 고객 정보가 연결된 연결 리스트에서 1번째 객 이름(name)에 대응되는
	// 구조체 정보를 연결 리스트에서 삭제하고 고객 명단을 확인하여 해당 고객 정보가 삭제되었는지 확인하시오.
	printf("\n\n1번째 고객 정보 삭제 후 고객 명단 출력 : \n");
	output_client(client_head);

}