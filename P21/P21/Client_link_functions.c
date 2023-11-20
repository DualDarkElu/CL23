#include "Client_link.h"

// 고객 정보 구조체 연결 리스트 생성 후 첫번째 구조체에 대한 포인트(헤드) 반환
struct client_info_list* input_client(int num)
{
	struct client_info_list* head = NULL;
	struct client_info_list* current, * previous = NULL;
	
	// 첫번째 구조체 포인터(head)에 구조체 메모리 할당
	head = (struct client_info_list*)malloc(sizeof(struct client_info_list)); 

	// 현재 포인터(current)에 head 포인터 대입
	// 헤드 포인터는 변경없이 유지, 현재 구조체 포인터를 이동시키면서 다음 구조체 연결
	current = head; 

	// 신규 구조체의 다음 포인터는 항상 NULL : 연결 리스트의 마지막 표시
	current->next = NULL; 

	for(int i = 0; i < num; i++)
	{
		// 고객 구조체에 고객 정보 입력
		printf("고객번호 :");
		scanf_s("%d%*c", &current->no);
		printf("고객이름 :");
		scanf_s("%s", current->name, MAX_LEN);
		printf("구매금액 :");
		scanf_s("%lf", &current->pamount);
		current->birth = (struct date*)malloc(sizeof(struct date));
		printf("생년월일(YYYY MM DD) :");
		scanf_s("%d %d %d", &current->birth->year, &current->birth->month, &current->birth->day);
	
		// 다음 고객 정보를 저장할 구조체 메모리를 할당하고 현재 구조체의 다음에 연결
		current->next = (struct client_info_list*)malloc(sizeof(struct client_info_list));

		// 현재 구조체 포인터(current)를 이전 포인터(previous)로 이동하고 현재 포인터를 다음 구조체로 이동한후 다음 고객 정보 입력
		previous = current;
		current = current->next;
	}

	// 고객 정보가 입력되지 않은 마지막 구조체 메모리 해제
	free(current); 
	//질문 5 : 위의 free() 명령문을 생략하는 경우 어떤 문제가 발생하는가?

	// 이전 구조체의 다음 포인터에 NULL을 대입하여 구조체 연결 리스트의 끝 표시
	previous->next = NULL; 
	//질문 6 : 위의 대입 명령문을 생략하는 경우 어떤 문제가 발생하는가?

	return(head); // 고객 정보 구조체 리스트의 시작 주소(헤드 포인터) 반환
}

void output_client(struct client_info_list *current)
{
	// 현재 포인터가 NULL이 될때까지 고객 정보 출력
	while(current!= NULL)
	{
		printf("고객번호 : %d\n", current->no);
		printf("고객이름 : %s\n", current->name);
		printf("구매금액 : %.2f\n", current->pamount);
		printf("생년월일(YYYY/MM/DD): %d/%d/%d\n\n", current->birth->year, current->birth->month, current->birth->day);

		// 현재 포인터를 다음 구조체로 이동(마지막 구조체의 다음 포인터는 NULL로 설정되어 있음)
		current = current->next;
	}
}

void add_client1(struct client_info_list* headp)
{
	struct client_info_list* current = NULL;

	if (headp == NULL) //첫번째 고객 정보 입력 --> 연결 리스트 헤드 변경(NULL --> 1번째 구조체)
	{
		headp = (struct client_info_list*)malloc(sizeof(struct client_info_list));
		
		printf("고객번호 :");
		scanf_s("%d%*c", &headp->no);
		printf("고객이름 :");
		scanf_s("%s", headp->name, MAX_LEN);
		printf("구매금액 :");
		scanf_s("%lf", &headp->pamount);
		headp->birth = (struct date*)malloc(sizeof(struct date));
		printf("생년월일(YYYY MM DD) :");
		scanf_s("%d %d %d", &headp->birth->year, &headp->birth->month, &headp->birth->day);
		headp->next = NULL; // 마지막 구조체의 다음 포인터는 항상 NULL : 연결 리스트의 마지막 표시
	}
	else // 헤드 변경 없음
	{
		current = headp;
		while (current->next != NULL) // while (current != NULL) 형식 주의 : NULL->next 오류
			current = current->next;
		current->next = (struct client_info_list*)malloc(sizeof(struct client_info_list));
		current = current->next;
		printf("고객번호 :");
		scanf_s("%d%*c", &current->no);
		printf("고객이름 :");
		scanf_s("%s", current->name, MAX_LEN);
		printf("구매금액 :");
		scanf_s("%lf", &current->pamount);
		current->birth = (struct date*)malloc(sizeof(struct date));
		printf("생년월일(YYYY MM DD) :");
		scanf_s("%d %d %d", &current->birth->year, &current->birth->month, &current->birth->day);
		current->next = NULL; // 마지막 구조체의 다음 포인터는 항상 NULL : 연결 리스트의 마지막 표시
	}
}

// 이중 포인터 매개변수 --> 헤드 변경 경우 고려하여 헤드에 대한 포인터 사용
void add_client2(struct client_info_list** headp) // headp : 이중 포인터(포인터에 대한 포인터)
{
	struct client_info_list* current = NULL;

	if (*headp == NULL) // 이중 포인터의 내용(main 함수의 client_head)이 NULL
	{
		*headp = (struct client_info_list*)malloc(sizeof(struct client_info_list)); 
		// 이중 포인터 headp의 내용(main 함수의 client_head)에 고객 구조체 메모리 할당(할당된 메모리 시작 주소 대입)

		// 이중 포인터의 내용 포인터의 구조체에 정보 입력
		printf("고객번호 :");
		scanf_s("%d%*c", &(*headp)->no);
		printf("고객이름 :");
		scanf_s("%s", (*headp)->name, MAX_LEN);
		printf("구매금액 :");
		scanf_s("%lf", &(*headp)->pamount);
		(*headp)->birth = (struct date*)malloc(sizeof(struct date));
		printf("생년월일(YYYY MM DD) :");
		scanf_s("%d %d %d", &(*headp)->birth->year, &(*headp)->birth->month, &(*headp)->birth->day);

		(*headp)->next = NULL; // 마지막 구조체의 다음 포인터는 항상 NULL : 연결 리스트의 마지막 표시
	}
	else // 헤드 변경 없음
	{
		current = *headp; // 이중 포인터(headp)의 내용을 현재 포인터(current)에 대입

		// 현재 포인터를 맨 끝 구조체로 이동
		while (current->next != NULL) 
			current = current->next;

		// 현재 구조체의 다음 포인터에 구조체 메모리 할당
		current->next = (struct client_info_list*)malloc(sizeof(struct client_info_list));

		// 현재 포인터를 다음 구조체로 이동
		current = current->next;

		// 현재 구조체에 고객 정보 입력
		printf("고객번호 :");
		scanf_s("%d%*c", &current->no);
		printf("고객이름 :");
		scanf_s("%s", current->name, MAX_LEN);
		printf("구매금액 :");
		scanf_s("%lf", &current->pamount);
		current->birth = (struct date*)malloc(sizeof(struct date));
		printf("생년월일(YYYY MM DD) :");
		scanf_s("%d %d %d", &current->birth->year, &current->birth->month, &current->birth->day);

		current->next = NULL; // 마지막 구조체의 다음 포인터는 항상 NULL : 연결 리스트의 마지막 표시
	}
}


void delete_client(struct client_info_list** headp, char* name)
{
	// 이 위치에 주어진 문제를 해결하는 적절한 코드를 채우시오.

}
